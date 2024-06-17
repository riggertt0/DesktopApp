#include "Importer.h"
#include <QtCore/QString>
#include <qfile.h>
#include <qfileinfo.h>
#include <vector>

std::vector<IDS::Specification*> Importer::Import(const QString& file) {
    QFile* file_ = new QFile(file);
    std::vector<IDS::Specification*> specifications;
    if (!file_->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        
    }
    QXmlStreamReader xml(file_);
    while (!xml.hasError() && !xml.atEnd()) {

        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument) {
            continue;
        }

        if (token == QXmlStreamReader::StartElement) {
            auto tag = xml.name();
            if (tag == u"specification") {
                 auto spec = readSpecification(xml);
                 spec->setFileName(file.toStdString());
                 specifications.push_back(spec);
            }
        }
    }
    return specifications;
}

IDS::Specification* Importer::readSpecification(QXmlStreamReader& xml) {
    IDS::Specification* spec = new IDS::Specification();
    
    QXmlStreamAttributes attributes = xml.attributes();
    if (attributes.hasAttribute("name"))
        spec->setName(IDS::toStdString(attributes.value("name")));
    else {
        spec->setName("Specification name");
    }
    IDS::typeidsspecificationIfcSchemas* schemas = new IDS::typeidsspecificationIfcSchemas();
    if (attributes.hasAttribute("ifcVersion")) {
        auto versions = attributes.value("ifcVersion").split(' ');
        for (auto&& version : versions)
            schemas->addElement(IDS::toStdString(version));
    }
    if (!schemas->size()) {
        schemas->addElement("IFC4");
    }
    spec->setIfcSchemas(schemas);
    if (attributes.hasAttribute("identifier"))
        spec->setIdentifier(IDS::toStdString(attributes.value("identifier")));
    if (attributes.hasAttribute("description"))
        spec->setDescription(IDS::toStdString(attributes.value("description")));
    if (attributes.hasAttribute("instructions"))
        spec->setInstructions(IDS::toStdString(attributes.value("instructions")));

    static QString zero = "0";
    static QString one = "1";
    static QString unbounded = "unbounded";
    QString min = one, max = unbounded;
    if (attributes.hasAttribute("minOccurs"))
        min = attributes.value("minOccurs").toString();
    if (attributes.hasAttribute("maxOccurs"))
        max = attributes.value("maxOccurs").toString();
    IDS::OptionalityEnum optionality;
    if (min == zero && max == unbounded)
        optionality = IDS::OptionalityEnum::IDSOPTIONALITYENUM_NO_MANDATORY;
    else if (min == one && max == unbounded)
        optionality = IDS::OptionalityEnum::IDSOPTIONALITYENUM_MANDATORY;
    else if (min == zero && max == zero)
        optionality = IDS::OptionalityEnum::IDSOPTIONALITYENUM_NEGATION;
    spec->setOptionality(optionality);

    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != u"specification") {
        if (xml.hasError())
            return {};
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"applicability") {
                readApplicability(xml, spec);
                int t = 6;
            }
            else if (tag == u"requirements")
                readRequirements(xml, spec);
        }
        token = xml.readNext();
        tag = xml.name();
    }
    return spec;
}

void Importer::readPartOfPredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type) {
    QXmlStreamAttributes attributes = xml.attributes();
    auto optionality = readRequirementOptionality(attributes);
    IDS::EntityPredicate* entity;
    IDS::RelationEnum relation(IDS::RelationEnum::IDSRELATIONENUM_LAST);
    if (attributes.hasAttribute("relation")) {
        auto rel = attributes.value("relation").toString().toUpper();
        if (rel == "IFCRELAGGREGATES")
            relation = IDS::RelationEnum::IDSRELATIONENUM_IFCRELAGGREGATES;
        else if (rel == "IFCRELASSIGNSTOGROUP")
            relation = IDS::RelationEnum::IDSRELATIONENUM_IFCRELASSIGNSTOGROUP;
        else if (rel == "IFCRELCONTAINEDINSPATIALSTRUCTURE")
            relation = IDS::RelationEnum::IDSRELATIONENUM_IFCRELCONTAINEDINSPATIALSTRUCTURE;
        else if (rel == "IFCRELNESTS")
            relation = IDS::RelationEnum::IDSRELATIONENUM_IFCRELNESTS;
        else if (rel == "IFCRELVOIDSELEMENT")
            relation = IDS::RelationEnum::IDSRELATIONENUM_IFCRELVOIDSELEMENT;
        else if (rel == "IFCRELFILLSELEMENT")
            relation = IDS::RelationEnum::IDSRELATIONENUM_IFCRELFILLSELEMENT;
    }
    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != u"partOf") {
        if (xml.hasError())
            return;
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"entity")
                entity = readEntityPredicate(xml, type);
        }
        token = xml.readNext();
        tag = xml.name();
    }

    if (!entity->isValid()) {
        return;
    }
    IDS::RelationPredicate* partOf = new IDS::RelationPredicate();
    if (type == IDS::Predicate::Type::APPLICABILITY)
        partOf->SetApplicability();
    else
        partOf->SetRequirement();
    //auto partOf = IDS::createIdsRelationPredicate(); //m_docID
    if (optionality != IDS::OptionalityEnum::IDSOPTIONALITYENUM_LAST)
        partOf->setOptionality(optionality);
    if (relation != IDS::RelationEnum::IDSRELATIONENUM_LAST)
        partOf->setRelation(relation);
    partOf->setEntityType(entity);
    parent->addElementToRelations(partOf);
}

void Importer::readClassificationPredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type) {
    auto optionality = readRequirementOptionality(xml.attributes());
    IDS::ValueDomain* system = new IDS::ValueDomain();
    IDS::ValueDomain* value = new IDS::ValueDomain();
    std::string uri;
    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != u"classification") {
        if (xml.hasError())
            return;
        QXmlStreamAttributes attributes = xml.attributes();
        if (attributes.hasAttribute("uri"))
            uri = IDS::toStdString(attributes.value("uri"));
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"system") {
                system = readValue(xml, "system");
            }
            else if (tag == u"value")
                value = readValue(xml, "value");
        }
        token = xml.readNext();
        tag = xml.name();
    }
    IDS::ClassificationPredicate* classification = new IDS::ClassificationPredicate();
    if (type == IDS::Predicate::Type::APPLICABILITY)
        classification->SetApplicability();
    else
        classification->SetRequirement();
    //auto classification = IDS::createIdsClassificationPredicate(); //m_docID
    if (optionality != IDS::OptionalityEnum::IDSOPTIONALITYENUM_LAST)
        classification->setOptionality(optionality);
    if (!system->isUndef() && system->getState() != IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN)
        classification->setSystem(system);
    if (!value->isUndef() && value->getState() != IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN)
        classification->setClassifier(value);
    if (!uri.empty())
        classification->setUri(std::move(uri));
    parent->addElementToClassifications(classification);
}

void Importer::readAttributePredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type) {
    QXmlStreamAttributes attributes = xml.attributes();
    auto optionality = readRequirementOptionality(attributes);
    IDS::ValueDomain* name = new IDS::ValueDomain();
    IDS::ValueDomain* value = new IDS::ValueDomain();
    qint64 line = 0;
    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != u"attribute") {
        if (xml.hasError())
            return;
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"name") {
                line = xml.lineNumber();
                
                name = readValue(xml, "name");
            }
            else if (tag == u"value") {
                value = readValue(xml, "value");
            }
        }
        token = xml.readNext();
        tag = xml.name();
    }
    if (name->isUndef() || name->getState() == IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN) {
        return;
    }
    IDS::AttributePredicate* attribute = new IDS::AttributePredicate();
    if (type == IDS::Predicate::Type::APPLICABILITY)
        attribute->SetApplicability();
    else
        attribute->SetRequirement();
    //auto attribute = IDS::createIdsAttributePredicate(); //m_docID
    if (optionality != IDS::OptionalityEnum::IDSOPTIONALITYENUM_LAST)
        attribute->setOptionality(optionality);
    attribute->setName(name);
    if (!value->isUndef() && value->getState() != IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN)
        attribute->setDomain(value);
    parent->addElementToAttributes(attribute);
}

void Importer::readPropertyPredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type) {
    QXmlStreamAttributes attributes = xml.attributes();
    auto optionality = readRequirementOptionality(attributes);
    IDS::ValueDomain* propertySet = new IDS::ValueDomain();
    IDS::ValueDomain* name = new IDS::ValueDomain();
    IDS::ValueDomain* value = new IDS::ValueDomain();
    std::string dataType, uri;
    if (attributes.hasAttribute("uri"))
        uri = IDS::toStdString(attributes.value("uri"));
    if (!attributes.hasAttribute("datatype")) {
        return;
    }
    dataType = IDS::toStdString(attributes.value("datatype"));

    qint64 lineP = 0, lineN = 0;
    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != u"property") {
        if (xml.hasError())
            return;
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"propertySet") {
                lineP = xml.lineNumber();
                propertySet = readValue(xml, "propertySet");
            }
            else if (tag == u"name") {
                lineN = xml.lineNumber();
                name = readValue(xml, "name");
            }
            else if (tag == u"value")
                value = readValue(xml, "value");
        }
        token = xml.readNext();
        tag = xml.name();
    }
    if (propertySet->isUndef() ||
        propertySet->getState() == IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN) {
        return;
    }
    if (name->isUndef() || name->getState() == IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN) {
        return;
    }

    IDS::PropertyPredicate* property = new IDS::PropertyPredicate();
    if (type == IDS::Predicate::Type::APPLICABILITY)
        property->SetApplicability();
    else
        property->SetRequirement();
    //auto property = IDS::createIdsPropertyPredicate(); //m_docID
    if (optionality != IDS::OptionalityEnum::IDSOPTIONALITYENUM_LAST)
        property->setOptionality(optionality);
    property->setPropertySet(propertySet);
    property->setName(name);
    property->setDataType(dataType);
    if (!uri.empty())
        property->setUri(uri);
    if (!value->isUndef() && value->getState() != IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN)
        property->setDomain(value);
    parent->addElementToProperties(property);
}

void Importer::readMaterialPredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type) {

    auto optionality = readRequirementOptionality(xml.attributes());
    IDS::ValueDomain* value = new IDS::ValueDomain();
    std::string uri;
    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != u"material") {
        if (xml.hasError())
            return;
        QXmlStreamAttributes attributes = xml.attributes();
        if (attributes.hasAttribute("uri"))
            uri = IDS::toStdString(attributes.value("uri"));
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"value")
                value = readValue(xml, "value");
        }
        token = xml.readNext();
        tag = xml.name();
    }
    IDS::MaterialPredicate* material = new IDS::MaterialPredicate();
    if (type == IDS::Predicate::Type::APPLICABILITY)
        material->SetApplicability();
    else
        material->SetRequirement();
    //auto material = IDS::createIdsMaterialPredicate(); //m_docID
    if (optionality != IDS::OptionalityEnum::IDSOPTIONALITYENUM_LAST)
        material->setOptionality(optionality);
    if (!value->isUndef() && value->getState() != IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN)
        material->setDomain(value);
    if (!uri.empty())
        material->setUri(std::move(uri));
    parent->setMaterial(material);
}

void Importer::readApplicability(QXmlStreamReader& xml, IDS::Specification* parent) {
    IDS::Predicate* predicate = new IDS::Predicate();
    //auto predicate = IDS::createIdsPredicate(); //m_docID
    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != u"applicability") {
        
        if (xml.hasError())
            return;
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"entity") {
                auto entity = readEntityPredicate(xml, IDS::Predicate::Type::APPLICABILITY);
                if (entity->isValid())
                    predicate->setCategory(entity);
            }
            else if (tag == u"partOf")
                readPartOfPredicate(xml, predicate, IDS::Predicate::Type::APPLICABILITY);
            else if (tag == u"classification")
                readClassificationPredicate(xml, predicate, IDS::Predicate::Type::APPLICABILITY);
            else if (tag == u"attribute")
                readAttributePredicate(xml, predicate, IDS::Predicate::Type::APPLICABILITY);
            else if (tag == u"property")
                readPropertyPredicate(xml, predicate, IDS::Predicate::Type::APPLICABILITY);
            else if (tag == u"material")
                readMaterialPredicate(xml, predicate, IDS::Predicate::Type::APPLICABILITY);
        }
        token = xml.readNext();
        tag = xml.name();
    }
    parent->setApplicabilities(predicate);
}

IDS::EntityPredicate* Importer::readEntityPredicate(QXmlStreamReader& xml, IDS::Predicate::Type type) {
    QXmlStreamAttributes attributes = xml.attributes();
    auto optionality = readRequirementOptionality(attributes);

    

    IDS::ValueDomain* name = new IDS::ValueDomain();
    IDS::ValueDomain* predefined = new IDS::ValueDomain();
    qint64 line = 0;
    auto token = xml.readNext();
    auto tag = xml.name();

    while (token != QXmlStreamReader::EndElement || tag != u"entity") {
        if (xml.hasError())
            return {};
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"name") {
                line = xml.lineNumber();
                name = readValue(xml, "name");
            }
            else if (tag == u"predefinedType") {
                predefined = readValue(xml, "predefinedType");
            }
        }

        token = xml.readNext();
        tag = xml.name();
    }

    

    if (name->isUndef() || name->getState() == IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN) {

        return new IDS::EntityPredicate();
    }


    IDS::EntityPredicate* entity = new IDS::EntityPredicate();
    if (type == IDS::Predicate::Type::APPLICABILITY)
        entity->SetApplicability();
    else
        entity->SetRequirement();

    //auto entity = IDS::createIdsEntityPredicate(); //m_docID
    if (optionality != IDS::OptionalityEnum::IDSOPTIONALITYENUM_LAST)
        entity->setOptionality(optionality);

    

    entity->setEntities(name);

    if (!predefined->isUndef() &&
        predefined->getState() != IDS::ValueDomain::IdsValueDomainState::LAST_ST_IDSVALUEDOMAIN)
        entity->setPredefined(predefined);

    return entity;
}

void Importer::readRequirements(QXmlStreamReader& xml, IDS::Specification* parent) {
    IDS::Predicate* predicate = new IDS::Predicate();
    //auto predicate = IDS::createIdsPredicate(); //m_docID
    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != u"requirements") {
        
        if (xml.hasError())
            return;
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"entity") {
                
                auto entity = readEntityPredicate(xml, IDS::Predicate::Type::REQUIREMENT);
                if (entity->isValid())
                    predicate->setCategory(entity);
            }
            else if (tag == u"partOf")
                readPartOfPredicate(xml, predicate, IDS::Predicate::Type::REQUIREMENT);
            else if (tag == u"classification")
                readClassificationPredicate(xml, predicate, IDS::Predicate::Type::REQUIREMENT);
            else if (tag == u"attribute")
                readAttributePredicate(xml, predicate, IDS::Predicate::Type::REQUIREMENT);
            else if (tag == u"property")
                readPropertyPredicate(xml, predicate, IDS::Predicate::Type::REQUIREMENT);
            else if (tag == u"material")
                readMaterialPredicate(xml, predicate, IDS::Predicate::Type::REQUIREMENT);
        }
        token = xml.readNext();
        tag = xml.name();
    }
    parent->setClaims(predicate);
}

IDS::OptionalityEnum Importer::readRequirementOptionality(const QXmlStreamAttributes& attributes) {
    static QString zero = "0";
    static QString one = "1";
    QString min = "", max = ""; // missed in applicability
    if (attributes.hasAttribute("minOccurs"))
        min = attributes.value("minOccurs").toString();
    if (attributes.hasAttribute("maxOccurs"))
        max = attributes.value("maxOccurs").toString();
    IDS::OptionalityEnum optionality(IDS::OptionalityEnum::IDSOPTIONALITYENUM_LAST);
    if (min == one && max == one)
        optionality = IDS::OptionalityEnum::IDSOPTIONALITYENUM_MANDATORY;
    else if (min == zero && max == one)
        optionality = IDS::OptionalityEnum::IDSOPTIONALITYENUM_NO_MANDATORY;
    else if (min == zero && max == zero)
        optionality = IDS::OptionalityEnum::IDSOPTIONALITYENUM_NEGATION;
    return optionality;
}

IDS::ValueDomain* Importer::readValue(QXmlStreamReader& xml, const QString& parentTag) {
    IDS::ValueDomain* result = new IDS::ValueDomain();
    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
    restriction_base base = restriction_base::STRING;
    auto token = xml.readNext();
    auto tag = xml.name();
    while (token != QXmlStreamReader::EndElement || tag != parentTag) {
        if (xml.hasError())
            return {};
        if (token == QXmlStreamReader::StartElement) {
            if (tag == u"simpleValue") {
                xml.readNext();
                if (xml.tokenType() != QXmlStreamReader::Characters) {
                    
                    return result;
                }
                IDS::Value* value = new IDS::Value();
                auto input = xml.text();
                switch (base) {
                case Importer::restriction_base::STRING:
                    value->setIdsString(IDS::toStdString(input));
                    break;
                case Importer::restriction_base::INTEGER:
                    value->setIdsInteger(input.toInt());
                    break;
                case Importer::restriction_base::REAL:
                    value->setIdsReal(input.toDouble());
                    break;
                default:
                    break;
                }
                result->setIdsValue(value);
            }
            else if (tag == u"restriction") {
                
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("base")) {
                    auto baseValue = attributes.value("base");
                    
                    if (baseValue == u"xs:integer") {
                        base = restriction_base::INTEGER;
                    }
                    else if (baseValue == u"xs:decimal") {
                        base = restriction_base::REAL;
                    }
                }
            }
            else if (tag == u"pattern") {
                
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto value = attributes.value("value");
                    IDS::Pattern* pattern = new IDS::Pattern();

                    switch (base) {
                    case Importer::restriction_base::STRING:
                        pattern->setStrBase();
                        break;
                    case Importer::restriction_base::INTEGER:
                        pattern->setIntBase();
                        break;
                    case Importer::restriction_base::REAL:
                        pattern->setRealBase();
                        break;
                    default:
                        break;
                    }
                    //auto pattern = IDS::createIdsPattern(); //m_doc
                    pattern->setRegExp(IDS::toStdString(value));
                    result->setIdsPattern(pattern);
                }
            }
            else if (tag == u"length") {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto value = attributes.value("value");
                    IDS::Length* length = new IDS::Length();

                    switch (base) {
                    case Importer::restriction_base::STRING:
                        length->setStrBase();
                        break;
                    case Importer::restriction_base::INTEGER:
                        length->setIntBase();
                        break;
                    case Importer::restriction_base::REAL:
                        length->setRealBase();
                        break;
                    default:
                        break;
                    }
                    //auto length = IDS::createIdsLength(); // m_doc
                    length->setFixLength(value.toInt());
                    result->setIdsLength(length);
                }
            }
            else if (tag == u"minLength") {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto value = attributes.value("value");

                    if (result->getLength()) {
                        result->getLength()->setMinLength(value.toInt());
                    }
                    else {
                        IDS::Length* length = new IDS::Length();
                        switch (base) {
                        case Importer::restriction_base::STRING:
                            length->setStrBase();
                            break;
                        case Importer::restriction_base::INTEGER:
                            length->setIntBase();
                            break;
                        case Importer::restriction_base::REAL:
                            length->setRealBase();
                            break;
                        default:
                            break;
                        }
                        //auto length = IDS::createIdsLength(); // m_doc
                        length->setMinLength(value.toInt());
                        result->setIdsLength(length);
                    }
                }
            }
            else if (tag == u"maxLength") {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto value = attributes.value("value");
 
                    if (result->getLength()) {
                        result->getLength()->setMaxLength(value.toInt());
                    }
                    else {
                        IDS::Length* length = new IDS::Length();
                        switch (base) {
                        case Importer::restriction_base::STRING:
                            length->setStrBase();
                            break;
                        case Importer::restriction_base::INTEGER:
                            length->setIntBase();
                            break;
                        case Importer::restriction_base::REAL:
                            length->setRealBase();
                            break;
                        default:
                            break;
                        }
                        //auto length = IDS::createIdsLength(); // m_doc
                        length->setMaxLength(value.toInt());
                        result->setIdsLength(length);
                    }
                }
            }
            else if (tag == u"minInclusive" && base != restriction_base::STRING) {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto value = attributes.value("value");
                    
                    if (result->getBounds()) {
                        result->getBounds()->setMinInclusive(value.toInt());
                    }
                    else {
                        IDS::Bounds* bounds = new IDS::Bounds();
                        switch (base) {
                        case Importer::restriction_base::STRING:
                            bounds->setStrBase();
                            break;
                        case Importer::restriction_base::INTEGER:
                            bounds->setIntBase();
                            break;
                        case Importer::restriction_base::REAL:
                            bounds->setRealBase();
                            break;
                        default:
                            break;
                        }
                        bounds->setMinInclusive(value.toInt());
                        result->setIdsBounds(bounds);
                    }
                }
            }
            else if (tag == u"minExclusive" && base != restriction_base::STRING) {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto value = attributes.value("value");
                    
                    //auto bounds = IDS::createIdsBounds(); //m_doc
                    if (result->getBounds()) {
                        result->getBounds()->setMinExclusive(value.toInt());
                    }
                    else {
                        IDS::Bounds* bounds = new IDS::Bounds();
                        switch (base) {
                        case Importer::restriction_base::STRING:
                            bounds->setStrBase();
                            break;
                        case Importer::restriction_base::INTEGER:
                            bounds->setIntBase();
                            break;
                        case Importer::restriction_base::REAL:
                            bounds->setRealBase();
                            break;
                        default:
                            break;
                        }
                        bounds->setMinExclusive(value.toInt());
                        result->setIdsBounds(bounds);
                    }
                }
            }
            else if (tag == u"maxInclusive" && base != restriction_base::STRING) {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto value = attributes.value("value");
                    
                    //auto bounds = IDS::createIdsBounds(); //m_doc
                    if (result->getBounds()) {
                        result->getBounds()->setMaxInclusive(value.toInt());
                    }
                    else {
                        IDS::Bounds* bounds = new IDS::Bounds();
                        switch (base) {
                        case Importer::restriction_base::STRING:
                            bounds->setStrBase();
                            break;
                        case Importer::restriction_base::INTEGER:
                            bounds->setIntBase();
                            break;
                        case Importer::restriction_base::REAL:
                            bounds->setRealBase();
                            break;
                        default:
                            break;
                        }
                        bounds->setMaxInclusive(value.toInt());
                        result->setIdsBounds(bounds);
                    }
                }
            }
            else if (tag == u"maxExclusive" && base != restriction_base::STRING) {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto value = attributes.value("value");
                    
                    //auto bounds = IDS::createIdsBounds(); //m_doc
                    if (result->getBounds()) {
                        result->getBounds()->setMaxExclusive(value.toInt());
                    }
                    else {
                        IDS::Bounds* bounds = new IDS::Bounds();
                        switch (base) {
                        case Importer::restriction_base::STRING:
                            bounds->setStrBase();
                            break;
                        case Importer::restriction_base::INTEGER:
                            bounds->setIntBase();
                            break;
                        case Importer::restriction_base::REAL:
                            bounds->setRealBase();
                            break;
                        default:
                            break;
                        }
                        bounds->setMaxExclusive(value.toInt());
                        result->setIdsBounds(bounds);
                    }
                }
            }
            else if (tag == u"enumeration") {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("value")) {
                    auto input = attributes.value("value");
                    IDS::Value* value = new IDS::Value();
                    switch (base) {
                    case Importer::restriction_base::STRING:
                        value->setIdsString(IDS::toStdString(input));
                        break;
                    case Importer::restriction_base::INTEGER:
                        value->setIdsInteger(input.toInt());
                        break;
                    case Importer::restriction_base::REAL:
                        value->setIdsReal(input.toDouble());
                        break;
                    default:
                        break;
                    }
                    enumerationValues->addElement(value);
                }
            }
        }
        token = xml.readNext();
        tag = xml.name();
    }
    if (enumerationValues->size()) {
        IDS::Enumeration* enumeration = new IDS::Enumeration();
        switch (base) {
        case Importer::restriction_base::STRING:
            enumeration->setStrBase();
            break;
        case Importer::restriction_base::INTEGER:
            enumeration->setIntBase();
            break;
        case Importer::restriction_base::REAL:
            enumeration->setRealBase();
            break;
        default:
            break;
        }
        //auto enumeration = IDS::createIdsEnumeration(); //m_doc
        enumeration->setValues(enumerationValues);
        enumeration->getTypeidsenumerationValues();
        result->setIdsEnumeration(enumeration);
    }
    
    return result;
}
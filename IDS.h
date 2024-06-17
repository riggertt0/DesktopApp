#pragma once
#include <qstring.h>
#include <string>
#include <qdebug.h>
#include <qTableWidget>
#include <qTableWidgetItem>

namespace IDS {
	class Predicate;
	class typeidsspecificationIfcSchemas;
	class Value;
	class Pattern;
	class Length;
	class Bounds;
	class ValueDomain;
	class typeidsenumerationValues;
	class typeidsenumerationValues;
	class Identifier;
	class Description;
	class Instruction;
	class Specification;
	class Predicate;
	class Enumeration;

	enum OptionalityEnum {
		IDSOPTIONALITYENUM_NO_MANDATORY,
		IDSOPTIONALITYENUM_MANDATORY,
		IDSOPTIONALITYENUM_NEGATION,
		IDSOPTIONALITYENUM_LAST,
		IDSOPTIONALITYENUM_NO
	};

	enum RelationEnum {
		IDSRELATIONENUM_LAST,
		IDSRELATIONENUM_IFCRELAGGREGATES,
		IDSRELATIONENUM_IFCRELASSIGNSTOGROUP,
		IDSRELATIONENUM_IFCRELCONTAINEDINSPATIALSTRUCTURE,
		IDSRELATIONENUM_IFCRELNESTS,
		IDSRELATIONENUM_IFCRELVOIDSELEMENT,
		IDSRELATIONENUM_IFCRELFILLSELEMENT,
		IDSRELATIONENUM_NO
	};

	enum Base {
		STRING,
		INTEGER,
		REAL
	};


	class typeidsspecificationIfcSchemas {
	public:
		void addElement(std::string str) {
			elements.push_back(str);
		}

		int size() {
			return elements.size();
		}

		std::vector<std::string> getElements() {
			return elements;
		}

	private:
		std::vector<std::string> elements;
	};

	class Value {
	public:
		Value() {
			strValue = "";
			intValue = 0;
			doubleValue = 0.0;
			base = STRING;
		}

		void setIdsString(std::string str) {
			strValue = str;
		}
		void setIdsInteger(int int_) {
			setIntBase();
			intValue = int_;
		}

		void setIdsReal(double double_) {
			setRealBase();
			doubleValue = double_;
		}

		void setIntBase() {
			base = INTEGER;
		}

		void setRealBase() {
			base = REAL;
		}

		void setStrBase() {
			base = STRING;
		}

		std::string getStr() {
			return strValue;
		}

		int getInt() {
			return intValue;
		}

		double getDouble() {
			return doubleValue;
		}

		Base getBase() {
			return base;
		}

	private:

		std::string strValue;
		int intValue;
		double doubleValue;
		Base base;
	};

	class Pattern {
	public:
		Pattern() {
			regExp = "";
		}

		void setRegExp(std::string str) {
			regExp = str;
		}

		std::string getRegExp() {
			return regExp;
		}

		void setIntBase() {
			base = INTEGER;
		}

		void setRealBase() {
			base = REAL;
		}

		void setStrBase() {
			base = STRING;
		}

		Base getBase() {
			return base;
		}

	private:
		std::string regExp;
		Base base;
	};

	class Length {
	public:
		Length() {
			value = -9999999;
			minValue = 0;
			maxValue = 0;
			isFixed = true;
		}

		void setFixLength(int value_) {
			isFixed = true;
			value = value_;
		}

		void setMinLength(int minValue_) {
			isFixed = false;
			minValue = minValue_;
		}

		void setMaxLength(int maxValue_) {
			isFixed = false;
			maxValue = maxValue_;
		}

		void setIsFixed(bool is) {
			isFixed = is;
		}

		int getValue() {
			return value;
		}

		int getMaxValue() {
			return maxValue;
		}

		int getMinValue() {
			return minValue;
		}

		bool getIsFixed() {
			return isFixed;
		}

		void setIntBase() {
			base = INTEGER;
		}

		void setRealBase() {
			base = REAL;
		}

		void setStrBase() {
			base = STRING;
		}

		Base getBase() {
			return base;
		}

	private:
		int value;
		int minValue;
		int maxValue;
		bool isFixed;
		Base base;
	};

	class Bounds {
	public:
		enum MinType {
			MinInclusive,
			MinExclusive
		};

		enum MaxType {
			MaxInclusive,
			MaxExclusive
		};

		Bounds() {
			value = 0;
			minValueInc = 0;
			maxValueInc = 0;
			minValueExc = 0;
			maxValueExc = 0;
			maxType = MaxInclusive;
			minType = MinInclusive;
		}

		void setMinInclusive(int value_) {
			minValueInc = value_;
			minType = MinInclusive;
		}

		void setMaxInclusive(int value_) {
			maxValueInc = value_;
			maxType = MaxInclusive;
		}

		void setMinExclusive(int value_) {
			minValueExc = value_;
			minType = MinExclusive;
		}

		void setMaxExclusive(int value_) {
			maxValueExc = value_;
			maxType = MaxExclusive;
		}

		int getValue() {
			return value;
		}

		int getMinValueInc() {
			return minValueInc;
		}

		int getMaxValueInc() {
			return maxValueInc;
		}

		int getMinValueExc() {
			return minValueExc;
		}

		int getMaxValueExc() {
			return maxValueExc;
		}

		MinType getMinType() {
			return minType;
		}

		MaxType getMaxType() {
			return maxType;
		}

		void setIntBase() {
			base = INTEGER;
		}

		void setRealBase() {
			base = REAL;
		}

		void setStrBase() {
			base = STRING;
		}

		Base getBase() {
			return base;
		}

	private:
		int value;
		int minValueInc;
		int maxValueInc;
		int minValueExc;
		int maxValueExc;

		MaxType maxType;
		MinType minType;
		Base base;
	};

	class ValueDomain {
	public:
		enum IdsValueDomainState {
			LAST_ST_IDSVALUEDOMAIN,
			NO_IDSVALUEDOMAIN
		};

		ValueDomain()
			: value(nullptr), pattern(nullptr), length(nullptr), bounds(nullptr), enumeration(nullptr) {
			state = NO_IDSVALUEDOMAIN;
		}

		bool isUndef() {
			return false;
		}

		IdsValueDomainState getState() {
			return state;
		}

		void setIdsValue(Value* value_) {
			value = value_;
			qDebug() << "--------" << value->getStr();
		}

		void setIdsPattern(Pattern* pattern_) {
			pattern = pattern_;
		}

		void setIdsLength(Length* length_) {
			length = length_;
		}

		void setIdsBounds(Bounds* bounds_) {
			bounds = bounds_;
		}

		void setIdsEnumeration(Enumeration* enumeration_) {
			enumeration = enumeration_;
		}

		Value* getValue() {
			return value;
		}

		Pattern* getPattern() {
			return pattern;
		}

		Length* getLength() {
			return length;
		}

		Bounds* getBounds() {
			return bounds;
		}

		Enumeration* getEnumeration() {
			return enumeration;
		}

		void clear() {
			if (value) {
				delete(value);
				value = nullptr;
			}
			if (pattern) {
				delete(pattern);
				pattern = nullptr;
			}
			if (length) {
				delete(length);
				length = nullptr;
			}
			if (bounds) {
				delete(bounds);
				bounds = nullptr;
			}
			//enumeration->getTypeidsenumerationValues()->clear();
			if (enumeration) {
				delete(enumeration);
				enumeration = nullptr;
			}
		}

	private:
		IdsValueDomainState state;
		Value* value;
		Pattern* pattern;
		Length* length;
		Bounds* bounds;
		Enumeration* enumeration;
	};

	class typeidsenumerationValues {
	public:
		typeidsenumerationValues() {
			elements.clear();
		}

		void addElement(Value* value) {
			elements.push_back(value);
		}

		int size() {
			return elements.size();
		}

		std::vector<Value*> getElements() {
			return elements;
		}

		void clear() {
			elements.clear();
		}

	private:
		std::vector<Value*> elements;
	};

	class Identifier {
	public:
		Identifier(std::string name_ = "") : name(name_) {}

		std::string getName() {
			return name;
		}

	private:
		std::string name;
	};

	class Description {
	public:
		Description(std::string name_ = "") : name(name_) {}

		std::string getName() {
			return name;
		}

	private:
		std::string name;
	};

	class Instruction {
	public:
		Instruction(std::string name_ = "") : name(name_) {}

		std::string getName() {
			return name;
		}

	private:
		std::string name;
	};

	class Predicate {
	public:
		enum Type {
			REQUIREMENT,
			APPLICABILITY
		};

		virtual bool isValid() {
			return true;
		}

		void setCategory(Predicate* entity_) {
			entities.push_back(entity_);
		}

		void addElementToRelations(Predicate* relation_) {
			relations.push_back(relation_);
		}

		void addElementToClassifications(Predicate* classification_) {
			classifications.push_back(classification_);
		}

		void addElementToAttributes(Predicate* attribute_) {
			attributes.push_back(attribute_);
		}

		void addElementToProperties(Predicate* property_) {
			properties.push_back(property_);
		}

		void setMaterial(Predicate* material_) {
			materials.push_back(material_);
		}

		void SetApplicability() {
			if (k == 0) {
				type = APPLICABILITY;
				k = 1;
			}
		}

		void SetRequirement() {
			if (k == 0) {
				type = REQUIREMENT;
				k = 1;
			}
		}

		Type getType() {
			return type;
		}

		std::vector<Predicate*> getEntities() {
			return entities;
		}

		std::vector<Predicate*> getRelations() {
			return relations;
		}

		std::vector<Predicate*> getClassifications() {
			return classifications;
		}

		std::vector<Predicate*> getAttributes() {
			return attributes;
		}

		std::vector<Predicate*> getProperties() {
			return properties;
		}

		std::vector<Predicate*> getMaterials() {
			return materials;
		}

		QTableWidgetItem* getTableWidgetItem() {
			return tableWidgetItem;
		}

		void setTableWidgetItem(QTableWidgetItem* widgetItem) {
			tableWidgetItem = widgetItem;
		}

	private:
		std::vector<Predicate*> entities;
		std::vector<Predicate*> relations;
		std::vector<Predicate*> classifications;
		std::vector<Predicate*> attributes;
		std::vector<Predicate*> properties;
		std::vector<Predicate*> materials;
		QTableWidgetItem* tableWidgetItem;
		Type type;
		int k = 0;
	};

	class Specification {
	public:
		Specification()
			: ident(nullptr), desc(nullptr), instruct(nullptr), shema(nullptr), predic(nullptr), claim(nullptr) {
			name = "null";
			optional = IDSOPTIONALITYENUM_NO;
		}

		void setName(std::string name_) {
			name = name_;
		}

		void setIfcSchemas(typeidsspecificationIfcSchemas* shema_) {
			shema = shema_;
		}

		void setIdentifier(std::string identName) {
			ident = new Identifier(identName);
		}

		void setDescription(std::string descName) {
			desc = new Description(descName);
		}

		void setInstructions(std::string instructName) {
			instruct = new Instruction(instructName);
		}

		void setOptionality(OptionalityEnum optionality) {
			optional = optionality;
		}

		void setApplicabilities(Predicate* predicate) {
			predic = predicate;
		}

		void setClaims(Predicate* claim_) {
			claim = claim_;
		}

		void setFileName(std::string str) {
			fileName = str;
		}

		std::string getFileName() {
			return fileName;
		}

		std::string getName() {
			return name;
		}

		typeidsspecificationIfcSchemas* getShema() {
			return shema;
		}

		Identifier* getIdentifier() {
			return ident;
		}

		Description* getDescription() {
			return desc;
		}

		Instruction* getInstruction() {
			return instruct;
		}

		Predicate* getPredicate() {
			return predic;
		}

		Predicate* getClaim() {
			return claim;
		}

		void createApplicabilityIfNeed() {
			if (!predic) {
				Predicate* applicab = new Predicate();
				setApplicabilities(applicab);
			}
		}

		void createClaimIfNeed() {
			if (!claim) {
				Predicate* cl = new Predicate();
				setClaims(cl);
			}
		}

	private:
		std::string name;
		typeidsspecificationIfcSchemas* shema;
		Identifier* ident;
		Description* desc;
		Instruction* instruct;
		OptionalityEnum optional;
		Predicate* predic;
		Predicate* claim;
		std::string fileName;
	};

	class EntityPredicate : public Predicate {
	public:
		EntityPredicate() : name(nullptr), predefined(nullptr) {
			optional = IDSOPTIONALITYENUM_NO;
		}

		void setOptionality(OptionalityEnum optionality) {
			optional = optionality;
		}

		void setEntities(ValueDomain* name_) {
			name = name_;
		}

		void setPredefined(ValueDomain* predefined_) {
			predefined = predefined_;
		}

		ValueDomain* getName() {
			return name;
		}

		ValueDomain* getPredefined() {
			return predefined;
		}

		void createNameIfNeed() {
			if (!name) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setEntities(valDomain);
			}
		}

		void createPredefinedIfNeed() {
			if (!predefined) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setPredefined(valDomain);
			}
		}

	private:
		OptionalityEnum optional;
		ValueDomain* name;
		ValueDomain* predefined;
	};

	class RelationPredicate : public Predicate {
	public:
		RelationPredicate() : entity(nullptr) {
			optional = IDSOPTIONALITYENUM_NO;
			relat = IDSRELATIONENUM_NO;
		}

		void setOptionality(OptionalityEnum optionality) {
			optional = optionality;
		}

		void setRelation(RelationEnum relation) {
			relat = relation;
		}

		void setEntityType(EntityPredicate* entity_) {
			entity = entity_;
		}

		EntityPredicate* getEntityPredicate() {
			return entity;
		}

		RelationEnum getRelEnum() {
			return relat;
		}

		void createEntityIfNeed() {
			if (!entity) {
				IDS::EntityPredicate* entityPred = new IDS::EntityPredicate();
				setEntityType(entityPred);
			}
		}

	private:
		OptionalityEnum optional;
		RelationEnum relat;
		EntityPredicate* entity;
	};

	class ClassificationPredicate : public Predicate {
	public:
		ClassificationPredicate() : system(nullptr), value(nullptr) {
			optional = IDSOPTIONALITYENUM_NO;
			uri = "";
		}

		void setOptionality(OptionalityEnum optionality) {
			optional = optionality;
		}

		void setSystem(ValueDomain* system_) {
			system = system_;
		}

		void setClassifier(ValueDomain* value_) {
			value = value_;
		}

		void setUri(std::string uri_) {
			uri = uri_;
		}

		ValueDomain* getSystem() {
			return system;
		}

		ValueDomain* getValue() {
			return value;
		}

		std::string getUri() {
			return uri;
		}

		void createSystemIfNeed() {
			if (!system) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setSystem(valDomain);
			}
		}

		void createValueIfNeed() {
			if (!value) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setClassifier(valDomain);
			}
		}

	private:
		OptionalityEnum optional;
		ValueDomain* system;
		ValueDomain* value;
		std::string uri;
	};

	class AttributePredicate : public Predicate {
	public:
		AttributePredicate() : name(nullptr), domain(nullptr) {
			optional = IDSOPTIONALITYENUM_NO;
		}

		void setOptionality(OptionalityEnum optionality) {
			optional = optionality;
		}

		void setName(ValueDomain* name_) {
			name = name_;
		}

		void setDomain(ValueDomain* name_) {
			domain = name_;
		}

		ValueDomain* getDomain() {
			return domain;
		}

		ValueDomain* getName() {
			return name;
		}

		void createNameIfNeed() {
			if (!name) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setName(valDomain);
			}
		}

		void createDomainIfNeed() {
			if (!domain) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setDomain(valDomain);
			}
		}

	private:
		OptionalityEnum optional;
		ValueDomain* name;
		ValueDomain* domain;
	};

	class PropertyPredicate : public Predicate {
	public:
		PropertyPredicate()
			: propertySet(nullptr), name(nullptr), domain(nullptr) {
			optional = IDSOPTIONALITYENUM_NO;
			dataType = "";
			uri = "";
		}

		void setOptionality(OptionalityEnum optionality) {
			optional = optionality;
		}

		void setPropertySet(ValueDomain* propertySet_) {
			propertySet = propertySet_;
		}

		void setName(ValueDomain* name_) {
			name = name_;
		}

		void setDataType(std::string dataType_) {
			dataType = dataType_;
		}

		void setUri(std::string uri_) {
			uri = uri_;
		}

		void setDomain(ValueDomain* value_) {
			domain = value_;
		}

		ValueDomain* getDomain() {
			return domain;
		}

		ValueDomain* getName() {
			return name;
		}

		ValueDomain* getPropertySet() {
			return propertySet;
		}

		std::string getUri() {
			return uri;
		}

		std::string getDataType() {
			return dataType;
		}

		void createPropertySetIfNeed() {
			if (!propertySet) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setPropertySet(valDomain);
			}
		}

		void createNameIfNeed() {
			if (!name) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setName(valDomain);
			}
		}

		void createDomainIfNeed() {
			if (!domain) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setDomain(valDomain);
			}
		}

	private:
		OptionalityEnum optional;
		ValueDomain* propertySet;
		ValueDomain* name;
		std::string dataType;
		std::string uri;
		ValueDomain* domain;
	};

	class MaterialPredicate : public Predicate {
	public:
		MaterialPredicate() : domain(nullptr) {
			optional = IDSOPTIONALITYENUM_NO;
			uri = "";
		}

		void setOptionality(OptionalityEnum optionality) {
			optional = optionality;
		}

		void setDomain(ValueDomain* value_) {
			domain = value_;
		}

		void setUri(std::string uri_) {
			uri = uri_;
		}

		ValueDomain* getDomain() {
			return domain;
		}

		std::string getUri() {
			return uri;
		}

		void createDomainIfNeed() {
			if (!domain) {
				IDS::ValueDomain* valDomain = new IDS::ValueDomain();
				setDomain(valDomain);
			}
		}

	private:
		OptionalityEnum optional;
		std::string uri;
		ValueDomain* domain;
	};

	class Enumeration {
	public:
		Enumeration() : enumerationValues(nullptr) {

		}

		void setValues(IDS::typeidsenumerationValues* enumerationValues_) {
			enumerationValues = enumerationValues_;
		}

		IDS::typeidsenumerationValues* getTypeidsenumerationValues() {
			return enumerationValues;
		}

		void setIntBase() {
			base = INTEGER;
		}

		void setRealBase() {
			base = REAL;
		}

		void setStrBase() {
			base = STRING;
		}

		Base getBase() {
			return base;
		}

	private:
		IDS::typeidsenumerationValues* enumerationValues;
		Base base;
	};

	static std::string toStdString(QStringView view) {
		auto bytes = view.toUtf8();
		return { bytes.constData(), (const unsigned __int64)bytes.length() };
	}
}

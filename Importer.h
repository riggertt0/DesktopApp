#pragma once
#include "IDS.h"
#include <qstring.h>
#include <QtCore/QXmlStreamReader>

class Importer {
public:
	Importer() = default;
	~Importer() = default;

	std::vector<IDS::Specification*> Import(const QString& file);

private:
	enum class restriction_base {
		STRING,
		INTEGER,
		REAL
	};

	IDS::Specification* readSpecification(QXmlStreamReader& xml);
	void readApplicability(QXmlStreamReader& xml, IDS::Specification* parent);
	IDS::EntityPredicate* readEntityPredicate(QXmlStreamReader& xml, IDS::Predicate::Type type);
	void readPartOfPredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type);
	IDS::OptionalityEnum readRequirementOptionality(const QXmlStreamAttributes& attributes);
	void readRequirements(QXmlStreamReader& xml, IDS::Specification* parent);
	void readClassificationPredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type);
	void readAttributePredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type);
	void readPropertyPredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type);
	void readMaterialPredicate(QXmlStreamReader& xml, IDS::Predicate* parent, IDS::Predicate::Type type);
	IDS::ValueDomain* readValue(QXmlStreamReader& xml, const QString& parentTag);
};
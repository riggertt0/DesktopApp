#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DesctopApp.h"
#include "Importer.h"

#include "IDSdialog.h"

class DesctopApp : public QMainWindow
{
    Q_OBJECT

public:
    DesctopApp(QWidget* parent = nullptr);
    ~DesctopApp();

    Importer imp;

    void goRound(IDS::Specification* spec);

    void addSpecification(IDS::Specification* spec);

    void claerSpecification();

    IDS::Specification* getSpecification(std::string name);

    std::vector<IDS::Specification*> getSpecifications() {
        return specifications;
    }

    void Export(QFile& file);
    void writeIDS(QXmlStreamWriter& xmlWriter);
    void writeInfo(QXmlStreamWriter& xmlWriter);
    void writeSpecifications(QXmlStreamWriter& xmlWriter, IDS::Specification* spec);
    void writeApplicability(QXmlStreamWriter& xmlWriter, IDS::Specification* spec);
    void writeRequirements(QXmlStreamWriter& xmlWriter, IDS::Specification* spec);
    void writeEntity(QXmlStreamWriter& xmlWriter, IDS::EntityPredicate* spec);
    void writePartOf(QXmlStreamWriter& xmlWriter, IDS::RelationPredicate* partOf);
    void writeClassification(QXmlStreamWriter& xmlWriter, IDS::ClassificationPredicate* classification);
    void writeAttribute(QXmlStreamWriter& xmlWriter, IDS::AttributePredicate* attribute);
    void writeProperty(QXmlStreamWriter& xmlWriter, IDS::PropertyPredicate* property);
    void writeMaterial(QXmlStreamWriter& xmlWriter, IDS::MaterialPredicate* material);

private:
    Ui::DesctopAppClass ui;
    //QtWidgetsClass myWidget;
    IDSdialog idsDialog;

    std::vector<IDS::Specification*> specifications;

    void convert(IDS::Specification* spec);

    void goRound(IDS::Predicate* pred);
    void goRound(IDS::ValueDomain* val);
    void goRound(IDS::Enumeration* enumeration);
    void goRound(IDS::typeidsenumerationValues* type);
    void goRound(IDS::Bounds* bounds);
    void goRound(IDS::Length* length);
    void goRound(IDS::Pattern* pattern);
    void goRound(IDS::Value* val);

private slots:
    void on_fileButton_clicked();
    void on_addButtonSpecification_clicked();
    void on_removeButtonSpecification_clicked();
    void on_pushButtonSaveFile_clicked();

    void activateOptions(QListWidgetItem* item);
};

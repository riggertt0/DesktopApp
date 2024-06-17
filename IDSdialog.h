#pragma once

#include <QMainWindow>
#include "ui_IDSdialog.h"
#include "IDS.h"

class IDSdialog : public QMainWindow
{
    Q_OBJECT

public:
    IDSdialog(QWidget* parent = nullptr);
    ~IDSdialog();
    void setSpecification(IDS::Specification* specification) {
        spec = specification;
    }
    IDS::Specification* getSpecification() {
        return spec;
    }

    Ui::IDSdialogClass ui;
private:
    void hideAllOptions();
    IDS::Specification* spec;

private slots:
    void conditionListWidgetApplicabilityClicked(QListWidgetItem* item);
    void conditionListWidgetRequirementClicked(QListWidgetItem* item);

    void activateOptions(QTableWidgetItem* item);
    void activateCustomIfcChange(int index);
    void activateCustomPredType(int index);
    void activateCustomMaterial(int index);
    void activateCustomPropertySetChange(int index);
    void activateCustomPropertyChange(int index);
    void activateCustomPropertyValueChange(int index);
    void activateCustomClassSystem(int index);
    void activateCustomClassValue(int index);
    void activateCustomAttributeName(int index);
    void activateCustomAttributeValue(int index);
    void activateCustomPartOfRelation(int index);
    void activateCustomPartOfPredef(int index);

    void activateMaterialLength(int index);
    void activatePartOfRelationLength(int index);
    void activatePartOfPredefLength(int index);
    void activateIfcChangeLength(int index);
    void activatePropertySetChangeLength(int index);
    void activatePredTypeLength(int index);
    void activateAttributeNameLength(int index);
    void activateAttributeValueLength(int index);
    void activateClassSystemLength(int index);
    void activateClassValueLength(int index);
    void activatePropertySetLength(int index);
    void activatePropertyChangeLength(int index);
    void activatePropertyValueChangeLength(int index);

    void on_pushButtonAddConditionApplicability_clicked();
    void on_pushButtonAddConditionRequirement_clicked();

    void on_pushButtonDeleteSelectedConditionApplicability_clicked();
    void on_pushButtonDeleteSelectedConditionRequirement_clicked();

    void on_pushButtonAddEnumEntityIFCType_clicked();
    void on_pushButtonRemoveEnumEntityIFCType_clicked();

    void on_pushButtonAddEnumEntityPredType_clicked();
    void on_pushButtonRemoveEnumEntityPredType_clicked();

    void on_pushButtonAddEnumPropPropertySet_clicked();
    void on_pushButtonRemoveEnumPropPropertySet_clicked();

    void on_pushButtonAddEnumPropType_clicked();
    void on_pushButtonRemoveEnumPropType_clicked();

    void on_pushButtonAddEnumPartOfRelation_clicked();
    void on_pushButtonRemoveEnumPartOfRelation_clicked();

    void on_pushButtonAddEnumPartOfPredef_clicked(void);
    void on_pushButtonRemoveEnumPartOfPredef_clicked(void);

    void on_pushButtonAddEnumPropValue_clicked();
    void on_pushButtonRemoveEnumPropValue_clicked();

    void on_pushButtonAddEnumMaterial_clicked();
    void on_pushButtonRemoveEnumMaterial_clicked();

    void on_pushButtonAddEnumClassSystem_clicked();
    void on_pushButtonRemoveEnumClassSystem_clicked();

    void on_pushButtonAddEnumAttributeName_clicked();
    void on_pushButtonRemoveEnumAttributeName_clicked();

    void on_pushButtonAddEnumAttributeValue_clicked();
    void on_pushButtonRemoveEnumAttributeValue_clicked();

    void on_pushButtonAddEnumClassValue_clicked();
    void on_pushButtonRemoveEnumClassValue_clicked();

    void on_pushButtonSaveEntity_clicked(void);
    void on_pushButtonSaveAttribute_clicked(void);
    void on_pushButtonSaveClassification_clicked(void);
    void on_pushButtonSaveMaterial_clicked(void);
    void on_pushButtonSaveProperty_clicked(void);
    void on_pushButtonSavePartOf_clicked(void);

    bool checkPattern(QString str);
    bool checkLengthInt(QString min, QString max);
    bool checkBoundInt(QString min, QString max);

    void entityIFCPatern();
    void entityIFCPatern_2();
    void entityIFCLength();

    void classSystemPatern();
    void classValuePatern();

    
    void setVisibleLengthDialogPartOfPredef(bool is);
    void setVisibleLengthDialogEntityIFCType(bool is);
   
    void setVisibleLengthDialogEntityPredType(bool is);
    void setVisibleLengthDialogPartOfRelation(bool is);
    void setVisibleLengthDialogPropertySet(bool is);
    void setVisibleLengthDialogProperty(bool is);
    void setVisibleBoundDialogPropertyValue(bool is);
    void setVisibleLengthDialogPropertyValue(bool is);
    void setVisibleLengthDialogMaterial(bool is);
    void setVisibleLengthDialogClass(bool is);
    void setVisibleLengthDialogClassValue(bool is);
    void setVisibleLengthDialogAttributeName(bool is);
    void setVisibleBoundDialogAttributeValue(bool is);
    void setVisibleLengthDialogAttributeValue(bool is);
};

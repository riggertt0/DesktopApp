#include "IDSdialog.h"

IDSdialog::IDSdialog(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.conditionListWidgetApplicability->hide();
    ui.conditionListWidgetRequirement->hide();

    ui.conditionListWidgetApplicability = new QListWidget(this);
    ui.conditionListWidgetApplicability->setFrameShape(QFrame::StyledPanel);
    ui.conditionListWidgetApplicability->setMinimumSize(QSize(150, 120));
    //ui.itemEntityApplicability = new QListWidgetItem("IFC Entity");
    ui.conditionListWidgetApplicability->addItem(new QListWidgetItem("IFC Entity"));
    //ui.itemClassificationApplicability = new QListWidgetItem("Classification");
    ui.conditionListWidgetApplicability->addItem(new QListWidgetItem("Classification"));
    //ui.itemAttributeApplicability = new QListWidgetItem("Attribute");
    ui.conditionListWidgetApplicability->addItem(new QListWidgetItem("Attribute"));
    //ui.itemPropertyApplicability = new QListWidgetItem("Property");
    ui.conditionListWidgetApplicability->addItem(new QListWidgetItem("Property"));
    //ui.itemMaterialApplicability = new QListWidgetItem("Material");
    ui.conditionListWidgetApplicability->addItem(new QListWidgetItem("Material"));
    //ui.itemPartOfApplicability = new QListWidgetItem("PartOf");
    ui.conditionListWidgetApplicability->addItem(new QListWidgetItem("PartOf"));
    ui.conditionListWidgetApplicability->setVisible(false);

    ui.conditionListWidgetRequirement = new QListWidget(this);
    ui.conditionListWidgetRequirement->setFrameShape(QFrame::StyledPanel);
    ui.conditionListWidgetRequirement->setMinimumSize(QSize(150, 120));
    //ui.itemEntityRequirement = new QListWidgetItem("IFC Entity");
    ui.conditionListWidgetRequirement->addItem(new QListWidgetItem("IFC Entity"));
    //ui.itemClassificationRequirement = new QListWidgetItem("Classification");
    ui.conditionListWidgetRequirement->addItem(new QListWidgetItem("Classification"));
    //ui.itemAttributeRequirement = new QListWidgetItem("Attribute");
    ui.conditionListWidgetRequirement->addItem(new QListWidgetItem("Attribute"));
    //ui.itemPropertyRequirement = new QListWidgetItem("Property");
    ui.conditionListWidgetRequirement->addItem(new QListWidgetItem("Property"));
    //ui.itemMaterialRequirement = new QListWidgetItem("Material");
    ui.conditionListWidgetRequirement->addItem(new QListWidgetItem("Material"));
    //ui.itemPartOfRequirement = new QListWidgetItem("PartOf");
    ui.conditionListWidgetRequirement->addItem(new QListWidgetItem("PartOf"));
    ui.conditionListWidgetRequirement->setVisible(false);

    setVisibleLengthDialogEntityIFCType(false);
    ui.lineEditPatternEntityIFCType->hide();
    ui.widgetEntityIFCType->hide();
    ui.widgetEntityPredType->hide();
    ui.widgetPropPropertySet->hide();
    ui.widgetPropType->hide();
    ui.widgetPropValue->hide();
    ui.widgetClassSystem->hide();
    ui.widgetClassValue->hide();
    ui.widgetAttributeName->hide();
    ui.widgetAttributeValue->hide();
    ui.widgetMaterialValue->hide();
    ui.widgetPartOfRelation->hide();
    ui.widgetPartOfPredef->hide();


    ui.comboBox_51->hide();
    ui.lineEditEntityIFCTypeFixed->hide();
    ui.comboBox_50->hide();
    ui.lineEditEntityPredTypeFixed->hide();
    ui.comboBox_24->hide();
    ui.lineEditAttributeNameFixed->hide();
    ui.comboBox_17->hide();
    ui.lineEditAttributeValueFixed->hide();
    ui.comboBox_16->hide();
    ui.lineEditClassSystemFixed->hide();
    ui.comboBox_15->hide();
    ui.lineEditClassValueFixed->hide();
    ui.comboBox_14->hide();
    ui.lineEditPropPropertySetFixed->hide();
    ui.comboBox_13->hide();
    ui.lineEditPropTypeFixed->hide();
    ui.comboBox_12->hide();
    ui.lineEditPropValueFixed->hide();

    ui.labelMin->hide();
    ui.labelMax->hide();
    ui.lineEditLengthMax->hide();
    ui.lineEditLengthMin->hide();

    ui.lineEditPatternEntityPredType->hide();
    ui.labelMin_2->hide();
    ui.lineEditLengthMin_2->hide();
    ui.labelMax_2->hide();
    ui.lineEditLengthMax_2->hide();

    ui.lineEditPatternPropPropertySet->hide();
    ui.labelMin_3->hide();
    ui.lineEditLengthMin_3->hide();
    ui.labelMax_3->hide();
    ui.lineEditLengthMax_3->hide();

    ui.lineEditPatternPropType->hide();
    ui.labelMin_4->hide();
    ui.lineEditLengthMin_4->hide();
    ui.labelMax_4->hide();
    ui.lineEditLengthMax_4->hide();

    ui.lineEditPatternClassSystem->hide();
    ui.labelMin_6->hide();
    ui.lineEditLengthMin_6->hide();
    ui.labelMax_6->hide();
    ui.lineEditLengthMax_6->hide();

    ui.lineEditPatternPropValue->hide();
    ui.labelMin_7->hide();
    ui.lineEditLengthMin_7->hide();
    ui.labelMax_7->hide();
    ui.lineEditLengthMax_7->hide();
    ui.comboBox_42->hide();
    ui.lineEdit_27->hide();
    ui.lineEdit_28->hide();
    ui.comboBox_43->hide();

    ui.lineEditPatternClassValue->hide();
    ui.labelMin_8->hide();
    ui.lineEditLengthMin_8->hide();
    ui.labelMax_8->hide();
    ui.lineEditLengthMax_8->hide();

    ui.lineEditPatternAttributeName->hide();
    ui.labelMin_9->hide();
    ui.lineEditLengthMin_9->hide();
    ui.labelMax_9->hide();
    ui.lineEditLengthMax_9->hide();

    ui.lineEditPatternAttributeValue->hide();
    ui.labelMin_10->hide();
    ui.lineEditLengthMin_10->hide();
    ui.labelMax_10->hide();
    ui.lineEditLengthMax_10->hide();
    ui.comboBox_44->hide();
    ui.lineEdit_39->hide();
    ui.lineEdit_40->hide();
    ui.comboBox_45->hide();

    ui.lineEditPatternMaterialValue->hide();
    ui.comboBox_6->hide();
    ui.lineEditMaterialFixed->hide();
    ui.labelMin_11->hide();
    ui.labelMax_11->hide();
    ui.lineEditLengthMin_11->hide();
    ui.lineEditLengthMax_11->hide();

    ui.lineEditPatternPartOfRelation->hide();
    ui.comboBox_11->hide();
    ui.lineEditPartOfRelationFixed->hide();
    ui.labelMin_13->hide();
    ui.labelMax_13->hide();
    ui.lineEditLengthMin_13->hide();
    ui.lineEditLengthMax_13->hide();

    ui.lineEditPatternPartOfPredef->hide();
    ui.comboBox_10->hide();
    ui.lineEditPartOfPredefFixed->hide();
    ui.labelMin_12->hide();
    ui.labelMax_12->hide();
    ui.lineEditLengthMin_12->hide();
    ui.lineEditLengthMax_12->hide();

    ui.comboBoxDataTypeAttribute->hide();
    ui.comboBoxDataTypeProperty->hide();

    hideAllOptions();

    ui.tableWidgetEntityIFCType->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetRequirement->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetApplicability->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetEntityPredType->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetPropPropertySet->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetPropType->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetPropValue->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetClassSystem->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetAttributeName->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetAttributeValue->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetClassValue->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetMaterialValue->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetPartOfRelation->horizontalHeader()->setStretchLastSection(true);
    ui.tableWidgetPartOfPredef->horizontalHeader()->setStretchLastSection(true);

    ui.tableWidgetRequirement->setEditTriggers(QAbstractItemView::AnyKeyPressed);
    ui.tableWidgetApplicability->setEditTriggers(QAbstractItemView::AnyKeyPressed);

    ui.comboBox_9->setEditable(true);
    ui.comboBox_21->setEditable(true);

    layout()->setSizeConstraint(QLayout::SetFixedSize);

    connect(ui.tableWidgetApplicability, &QTableWidget::itemClicked, this, &IDSdialog::activateOptions);
    connect(ui.tableWidgetRequirement, &QTableWidget::itemClicked, this, &IDSdialog::activateOptions);

    connect(ui.conditionListWidgetApplicability, &QListWidget::itemClicked, this, &IDSdialog::conditionListWidgetApplicabilityClicked);
    connect(ui.conditionListWidgetRequirement, &QListWidget::itemClicked, this, &IDSdialog::conditionListWidgetRequirementClicked);
    connect(ui.comboBox_20, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomIfcChange);
    connect(ui.comboBox_3, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomPredType);
    connect(ui.comboBox_34, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomClassValue);
    connect(ui.lineEditPatternEntityIFCType, &QLineEdit::editingFinished, this, &IDSdialog::entityIFCPatern);
    connect(ui.lineEditPatternEntityPredType, &QLineEdit::editingFinished, this, &IDSdialog::entityIFCPatern_2);
    connect(ui.lineEditPatternClassSystem, &QLineEdit::editingFinished, this, &IDSdialog::classSystemPatern);
    connect(ui.lineEditPatternClassValue, &QLineEdit::editingFinished, this, &IDSdialog::classValuePatern);
    connect(ui.lineEditLengthMin, &QLineEdit::editingFinished, this, &IDSdialog::entityIFCLength);
    connect(ui.lineEditLengthMax, &QLineEdit::editingFinished, this, &IDSdialog::entityIFCLength);
    connect(ui.comboBox_25, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomPropertySetChange);
    connect(ui.comboBox_30, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomPropertyChange);
    connect(ui.comboBox_41, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomPropertyValueChange);
    connect(ui.comboBox_46, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomMaterial);
    connect(ui.comboBox_28, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomClassSystem);
    connect(ui.comboBox_37, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomAttributeName);
    connect(ui.comboBox_40, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomAttributeValue);
    connect(ui.comboBox_48, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomPartOfRelation);
    connect(ui.comboBox_49, &QComboBox::currentIndexChanged, this, &IDSdialog::activateCustomPartOfPredef);


    connect(ui.comboBox_6, &QComboBox::currentIndexChanged, this, &IDSdialog::activateMaterialLength);
    connect(ui.comboBox_11, &QComboBox::currentIndexChanged, this, &IDSdialog::activatePartOfRelationLength);
    connect(ui.comboBox_10, &QComboBox::currentIndexChanged, this, &IDSdialog::activatePartOfPredefLength);
    connect(ui.comboBox_51, &QComboBox::currentIndexChanged, this, &IDSdialog::activateIfcChangeLength);
    connect(ui.comboBox_50, &QComboBox::currentIndexChanged, this, &IDSdialog::activatePredTypeLength);
    connect(ui.comboBox_24, &QComboBox::currentIndexChanged, this, &IDSdialog::activateAttributeNameLength);
    connect(ui.comboBox_17, &QComboBox::currentIndexChanged, this, &IDSdialog::activateAttributeValueLength);
    connect(ui.comboBox_16, &QComboBox::currentIndexChanged, this, &IDSdialog::activateClassSystemLength);
    connect(ui.comboBox_15, &QComboBox::currentIndexChanged, this, &IDSdialog::activateClassValueLength);
    connect(ui.comboBox_14, &QComboBox::currentIndexChanged, this, &IDSdialog::activatePropertySetLength);
    connect(ui.comboBox_13, &QComboBox::currentIndexChanged, this, &IDSdialog::activatePropertyChangeLength);
    connect(ui.comboBox_12, &QComboBox::currentIndexChanged, this, &IDSdialog::activatePropertyValueChangeLength);

}

IDSdialog::~IDSdialog()
{}

void IDSdialog::on_pushButtonAddConditionApplicability_clicked(void)
{
    int x = ui.pushButtonAddConditionApplicability->geometry().x();
    int y = ui.pushButtonAddConditionApplicability->geometry().y();
    ui.conditionListWidgetApplicability->setGeometry(x, y, 1, 1);
    ui.conditionListWidgetApplicability->setVisible(true);
}

void IDSdialog::on_pushButtonAddConditionRequirement_clicked(void)
{
    int x = ui.pushButtonAddConditionRequirement->geometry().x();
    int y = ui.pushButtonAddConditionRequirement->geometry().y();
    ui.conditionListWidgetRequirement->setGeometry(x, y, 1, 1);
    ui.conditionListWidgetRequirement->setVisible(true);
}


void IDSdialog::conditionListWidgetApplicabilityClicked(QListWidgetItem* item)
{
    ui.tableWidgetApplicability->setRowCount(ui.tableWidgetApplicability->rowCount() + 1);
    getSpecification()->createApplicabilityIfNeed();
    if (item == ui.conditionListWidgetApplicability->item(3))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Property");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("PropertyComment");
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::PropertyPredicate* property = new IDS::PropertyPredicate();
        property->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getPredicate()->addElementToProperties(property);
    }
    else if (item == ui.conditionListWidgetApplicability->item(0))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Entity");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("EntityComment");
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 1, newTableWidgetItemComment);
        
        IDS::EntityPredicate* entity = new IDS::EntityPredicate();
        entity->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getPredicate()->setCategory(entity);
    }
    else if (item == ui.conditionListWidgetApplicability->item(2))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Attribute");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("AttributeComment");
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::AttributePredicate* attribute = new IDS::AttributePredicate();
        attribute->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getPredicate()->addElementToAttributes(attribute);
    }
    else if (item == ui.conditionListWidgetApplicability->item(1))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Classification");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("ClassificationComment");
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::ClassificationPredicate* classification = new IDS::ClassificationPredicate();
        classification->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getPredicate()->addElementToClassifications(classification);
    }
    else if (item == ui.conditionListWidgetApplicability->item(4))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Material");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("MaterialComment");
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::MaterialPredicate* material = new IDS::MaterialPredicate();
        material->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getPredicate()->setMaterial(material);
    }
    else if (item == ui.conditionListWidgetApplicability->item(5))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("PartOf");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("PartOfComment");
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetApplicability->setItem(ui.tableWidgetApplicability->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::RelationPredicate* relation = new IDS::RelationPredicate();
        relation->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getPredicate()->addElementToRelations(relation);
    }
    getSpecification();
    ui.conditionListWidgetApplicability->hide();
}

void IDSdialog::conditionListWidgetRequirementClicked(QListWidgetItem* item)
{
    ui.tableWidgetRequirement->setRowCount(ui.tableWidgetRequirement->rowCount() + 1);
    getSpecification()->createClaimIfNeed();
    if (item == ui.conditionListWidgetRequirement->item(3))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Property");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("PropertyComment");
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::PropertyPredicate* property = new IDS::PropertyPredicate();
        
        property->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getClaim()->addElementToProperties(property);
    }
    else if (item == ui.conditionListWidgetRequirement->item(0))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Entity");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("EntityComment");
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::EntityPredicate* entity = new IDS::EntityPredicate();
        
        entity->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getClaim()->setCategory(entity);
    }
    else if (item == ui.conditionListWidgetRequirement->item(2))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Attribute");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("AttributeComment");
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::AttributePredicate* attribute = new IDS::AttributePredicate();
        
        attribute->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getClaim()->addElementToAttributes(attribute);
    }
    else if (item == ui.conditionListWidgetRequirement->item(1))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Classification");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("ClassificationComment");
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::ClassificationPredicate* classification = new IDS::ClassificationPredicate();
        
        classification->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getClaim()->addElementToClassifications(classification);
    }
    else if (item == ui.conditionListWidgetRequirement->item(4))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("Material");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("MaterialComment");
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::MaterialPredicate* material = new IDS::MaterialPredicate();
        
        material->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getClaim()->setMaterial(material);
    }
    else if (item == ui.conditionListWidgetRequirement->item(5))
    {
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem("PartOf");
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem("PartOfComment");
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 0, newTableWidgetItem);
        ui.tableWidgetRequirement->setItem(ui.tableWidgetRequirement->rowCount() - 1, 1, newTableWidgetItemComment);

        IDS::RelationPredicate* relation = new IDS::RelationPredicate();
        
        relation->setTableWidgetItem(newTableWidgetItemComment);
        getSpecification()->getClaim()->addElementToRelations(relation);
    }

    ui.conditionListWidgetRequirement->hide();
}


void IDSdialog::activateOptions(QTableWidgetItem* item) {
    hideAllOptions();
    if (item->column() == 0)
    {
        if (item->text() == "Property")
        {
            ui.widgetProperty->setVisible(true);
        }
        if (item->text() == "Entity")
        {
            ui.widgetEntity->setVisible(true);
        }
        if (item->text() == "Classification")
        {
            ui.widgetClassification->setVisible(true);
        }
        if (item->text() == "Material")
        {
            ui.widgetMaterial->setVisible(true);
        }
        if (item->text() == "PartOf")
        {
            ui.widgetPartOf->setVisible(true);
        }
        if (item->text() == "Attribute")
        {
            ui.widgetAttribute->setVisible(true);
        }
    }
    else
    {
        QTableWidgetItem* firstItem = item->tableWidget()->item(item->row(), 0);
        if (firstItem->text() == "Property")
        {
            ui.widgetProperty->setVisible(true);
        }
        if (firstItem->text() == "Entity")
        {
            ui.widgetEntity->setVisible(true);
        }
        if (firstItem->text() == "Classification")
        {
            ui.widgetClassification->setVisible(true);
        }
        if (firstItem->text() == "Material")
        {
            ui.widgetMaterial->setVisible(true);
        }
        if (firstItem->text() == "PartOf")
        {
            ui.widgetPartOf->setVisible(true);
        }
        if (firstItem->text() == "Attribute")
        {
            ui.widgetAttribute->setVisible(true);
        }
    }
}

void IDSdialog::hideAllOptions() {
    ui.widget->hide();
    ui.widgetAttribute->hide();
    ui.widgetEntity->hide();
    ui.widgetClassification->hide();
    ui.widgetProperty->hide();
    ui.widgetMaterial->hide();
    ui.widgetPartOf->hide();
    ui.widget->hide();
}

void IDSdialog::activateCustomIfcChange(int index) {
    ui.verticalSpacer_2->changeSize(20, 300);
    ui.comboBox_4->setVisible(false);

    ui.lineEditPatternEntityIFCType->setVisible(false);
    setVisibleLengthDialogEntityIFCType(false);
    ui.widgetEntityIFCType->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_2->changeSize(0, 0);
        ui.widgetEntityIFCType->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternEntityIFCType->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogEntityIFCType(true);
        break;
    default:
        ui.comboBox_4->setVisible(true);
        break;
    }
}

void IDSdialog::activateIfcChangeLength(int index) {
    ui.lineEditEntityIFCTypeFixed->setVisible(false);
    ui.lineEditLengthMin->setVisible(false);
    ui.labelMin->setVisible(false);
    ui.lineEditLengthMax->setVisible(false);
    ui.labelMax->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin->setVisible(true);
        ui.labelMin->setVisible(true);
        ui.lineEditLengthMax->setVisible(true);
        ui.labelMax->setVisible(true);
        break;
    default:
        ui.lineEditEntityIFCTypeFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomPropertySetChange(int index) {
    ui.verticalSpacer_4->changeSize(20, 100);
    ui.lineEdit_5->setVisible(false);
    ui.lineEditPatternPropPropertySet->setVisible(false);
    setVisibleLengthDialogPropertySet(false);
    ui.widgetPropPropertySet->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_4->changeSize(0, 0);
        ui.widgetPropPropertySet->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternPropPropertySet->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogPropertySet(true);
        break;
    default:
        ui.lineEdit_5->setVisible(true);
        break;
    }
}

void IDSdialog::activatePropertySetLength(int index) {
    ui.lineEditPropPropertySetFixed->setVisible(false);
    ui.lineEditLengthMin_3->setVisible(false);
    ui.labelMin_3->setVisible(false);
    ui.lineEditLengthMax_3->setVisible(false);
    ui.labelMax_3->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin_3->setVisible(true);
        ui.labelMin_3->setVisible(true);
        ui.lineEditLengthMax_3->setVisible(true);
        ui.labelMax_3->setVisible(true);
        break;
    default:
        ui.lineEditPropPropertySetFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activatePropertySetChangeLength(int index) {
    ui.lineEditPartOfPredefFixed->setVisible(false);
    ui.labelMin_12->setVisible(false);
    ui.labelMax_12->setVisible(false);
    ui.lineEditLengthMin_12->setVisible(false);
    ui.lineEditLengthMax_12->setVisible(false);
    switch (index) {
    case 1:
        ui.labelMin_12->setVisible(true);
        ui.labelMax_12->setVisible(true);
        ui.lineEditLengthMin_12->setVisible(true);
        ui.lineEditLengthMax_12->setVisible(true);
        break;
    default:
        ui.lineEditPartOfPredefFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomPropertyChange(int index) {
    ui.verticalSpacer_5->changeSize(20, 100);
    ui.lineEdit_6->setVisible(false);
    ui.lineEditPatternPropType->setVisible(false);
    setVisibleLengthDialogProperty(false);
    ui.widgetPropType->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_5->changeSize(0, 0);
        ui.widgetPropType->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternPropType->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogProperty(true);
        break;
    default:
        ui.lineEdit_6->setVisible(true);
        break;
    }
}

void IDSdialog::activatePropertyChangeLength(int index) {
    ui.lineEditPropTypeFixed->setVisible(false);
    ui.lineEditLengthMin_4->setVisible(false);
    ui.labelMin_4->setVisible(false);
    ui.lineEditLengthMax_4->setVisible(false);
    ui.labelMax_4->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin_4->setVisible(true);
        ui.labelMin_4->setVisible(true);
        ui.lineEditLengthMax_4->setVisible(true);
        ui.labelMax_4->setVisible(true);
        break;
    default:
        ui.lineEditPropTypeFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomPropertyValueChange(int index)
{
    ui.verticalSpacer_6->changeSize(20, 150);
    ui.lineEdit_26->setVisible(false);
    setVisibleBoundDialogPropertyValue(false);
    ui.lineEditPatternPropValue->setVisible(false);
    setVisibleLengthDialogPropertyValue(false);
    ui.widgetPropValue->setVisible(false);
    switch (index)
    {
    case 1:
        ui.comboBoxDataTypeProperty->setVisible(true);
        ui.verticalSpacer_6->changeSize(0, 0);
        ui.widgetPropValue->setVisible(true);
        break;
    case 2:
        ui.comboBoxDataTypeProperty->setVisible(true);
        ui.lineEditPatternPropValue->setVisible(true);
        break;
    case 3:
        ui.comboBoxDataTypeProperty->setVisible(true);
        setVisibleBoundDialogPropertyValue(true);
        break;
    case 4:
        ui.comboBoxDataTypeProperty->setVisible(true);
        setVisibleLengthDialogPropertyValue(true);
        break;
    default:
        ui.comboBoxDataTypeProperty->setVisible(false);
        ui.lineEdit_26->setVisible(true);
        break;
    }
}

void IDSdialog::activatePropertyValueChangeLength(int index) {
    ui.lineEditPropValueFixed->setVisible(false);
    ui.lineEditLengthMin_7->setVisible(false);
    ui.labelMin_7->setVisible(false);
    ui.lineEditLengthMax_7->setVisible(false);
    ui.labelMax_7->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin_7->setVisible(true);
        ui.labelMin_7->setVisible(true);
        ui.lineEditLengthMax_7->setVisible(true);
        ui.labelMax_7->setVisible(true);
        break;
    default:
        ui.lineEditPropValueFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomMaterial(int index)
{
    ui.verticalSpacer_11->changeSize(20, 470);
    ui.comboBox_19->setVisible(false);
    ui.lineEditPatternMaterialValue->setVisible(false);
    setVisibleLengthDialogMaterial(false);
    ui.widgetMaterialValue->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_11->changeSize(20, 290);
        ui.widgetMaterialValue->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternMaterialValue->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogMaterial(true);
        break;
    default:
        ui.comboBox_19->setVisible(true);
        break;
    }
}

void IDSdialog::activateMaterialLength(int index) {
    ui.lineEditMaterialFixed->setVisible(false);
    ui.labelMin_11->setVisible(false);
    ui.labelMax_11->setVisible(false);
    ui.lineEditLengthMin_11->setVisible(false);
    ui.lineEditLengthMax_11->setVisible(false);
    switch (index) {
    case 1:
        ui.labelMin_11->setVisible(true);
        ui.labelMax_11->setVisible(true);
        ui.lineEditLengthMin_11->setVisible(true);
        ui.lineEditLengthMax_11->setVisible(true);
        break;
    default:
        ui.lineEditMaterialFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomPartOfRelation(int index)
{
    ui.verticalSpacer_12->changeSize(20, 100);
    ui.lineEdit_9->setVisible(false);
    ui.lineEditPatternPartOfRelation->setVisible(false);
    setVisibleLengthDialogPartOfRelation(false);
    ui.widgetPartOfRelation->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_12->changeSize(0, 0);
        ui.widgetPartOfRelation->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternPartOfRelation->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogPartOfRelation(true);
        break;
    default:
        ui.lineEdit_9->setVisible(true);
        break;
    }
}

void IDSdialog::activatePartOfRelationLength(int index) {
    ui.lineEditPartOfRelationFixed->setVisible(false);
    ui.labelMin_13->setVisible(false);
    ui.labelMax_13->setVisible(false);
    ui.lineEditLengthMin_13->setVisible(false);
    ui.lineEditLengthMax_13->setVisible(false);
    switch (index) {
    case 1:
        ui.labelMin_13->setVisible(true);
        ui.labelMax_13->setVisible(true);
        ui.lineEditLengthMin_13->setVisible(true);
        ui.lineEditLengthMax_13->setVisible(true);
        break;
    default:
        ui.lineEditPartOfRelationFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomPartOfPredef(int index)
{
    ui.verticalSpacer_15->changeSize(20, 100);
    ui.lineEdit_4->setVisible(false);
    ui.lineEditPatternPartOfPredef->setVisible(false);
    setVisibleLengthDialogPartOfPredef(false);
    ui.widgetPartOfPredef->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_15->changeSize(0, 0);
        ui.widgetPartOfPredef->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternPartOfPredef->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogPartOfPredef(true);
        break;
    default:
        ui.lineEdit_4->setVisible(true);
        break;
    }
}

void IDSdialog::activatePartOfPredefLength(int index) {
    ui.lineEditPartOfPredefFixed->setVisible(false);
    ui.labelMin_12->setVisible(false);
    ui.labelMax_12->setVisible(false);
    ui.lineEditLengthMin_12->setVisible(false);
    ui.lineEditLengthMax_12->setVisible(false);
    switch (index) {
    case 1:
        ui.labelMin_12->setVisible(true);
        ui.labelMax_12->setVisible(true);
        ui.lineEditLengthMin_12->setVisible(true);
        ui.lineEditLengthMax_12->setVisible(true);
        break;
    default:
        ui.lineEditPartOfPredefFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomPredType(int index)
{
    ui.verticalSpacer_3->changeSize(20, 120);
    ui.lineEdit_3->setVisible(false);
    ui.lineEditPatternEntityPredType->setVisible(false);
    setVisibleLengthDialogEntityPredType(false);
    ui.widgetEntityPredType->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_3->changeSize(0, 0);
        ui.widgetEntityPredType->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternEntityPredType->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogEntityPredType(true);
        break;
    default:
        ui.lineEdit_3->setVisible(true);
        break;
    }
}

void IDSdialog::activatePredTypeLength(int index) {
    ui.lineEditEntityPredTypeFixed->setVisible(false);
    ui.lineEditLengthMin_2->setVisible(false);
    ui.labelMin_2->setVisible(false);
    ui.lineEditLengthMax_2->setVisible(false);
    ui.labelMax_2->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin_2->setVisible(true);
        ui.labelMin_2->setVisible(true);
        ui.lineEditLengthMax_2->setVisible(true);
        ui.labelMax_2->setVisible(true);
        break;
    default:
        ui.lineEditEntityPredTypeFixed->setVisible(true);
        break;
    }
}

void IDSdialog::on_pushButtonAddEnumEntityIFCType_clicked(void)
{
    ui.tableWidgetEntityIFCType->setRowCount(ui.tableWidgetEntityIFCType->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.comboBox_9->currentText());
    ui.tableWidgetEntityIFCType->setItem(ui.tableWidgetEntityIFCType->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumEntityIFCType_clicked(void)
{
    auto row = ui.tableWidgetEntityIFCType->currentRow();
    if (row > -1) {
        ui.tableWidgetEntityIFCType->removeRow(row);
        ui.tableWidgetEntityIFCType->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumEntityPredType_clicked(void)
{
    ui.tableWidgetEntityPredType->setRowCount(ui.tableWidgetEntityPredType->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.comboBox_21->currentText());
    ui.tableWidgetEntityPredType->setItem(ui.tableWidgetEntityPredType->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumEntityPredType_clicked(void)
{
    auto row = ui.tableWidgetEntityPredType->currentRow();
    if (row > -1) {
        ui.tableWidgetEntityPredType->removeRow(row);
        ui.tableWidgetEntityPredType->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::activateCustomClassSystem(int index)
{
    ui.verticalSpacer_7->changeSize(20, 210);
    ui.lineEdit_24->setVisible(false);
    ui.lineEditPatternClassSystem->setVisible(false);
    setVisibleLengthDialogClass(false);
    ui.widgetClassSystem->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_7->changeSize(0, 0);
        ui.widgetClassSystem->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternClassSystem->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogClass(true);
        break;
    default:
        ui.lineEdit_24->setVisible(true);
        break;
    }
}

void IDSdialog::activateClassSystemLength(int index) {
    ui.lineEditClassSystemFixed->setVisible(false);
    ui.lineEditLengthMin_6->setVisible(false);
    ui.labelMin_6->setVisible(false);
    ui.lineEditLengthMax_6->setVisible(false);
    ui.labelMax_6->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin_6->setVisible(true);
        ui.labelMin_6->setVisible(true);
        ui.lineEditLengthMax_6->setVisible(true);
        ui.labelMax_6->setVisible(true);
        break;
    default:
        ui.lineEditClassSystemFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomClassValue(int index)
{
    ui.verticalSpacer_8->changeSize(20, 210);
    ui.lineEdit_30->setVisible(false);
    ui.lineEditPatternClassValue->setVisible(false);
    setVisibleLengthDialogClassValue(false);
    ui.widgetClassValue->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_8->changeSize(0, 0);
        ui.widgetClassValue->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternClassValue->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogClassValue(true);
        break;
    default:
        ui.lineEdit_30->setVisible(true);
        break;
    }
}

void IDSdialog::activateClassValueLength(int index) {
    ui.lineEditClassValueFixed->setVisible(false);
    ui.lineEditLengthMin_8->setVisible(false);
    ui.labelMin_8->setVisible(false);
    ui.lineEditLengthMax_8->setVisible(false);
    ui.labelMax_8->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin_8->setVisible(true);
        ui.labelMin_8->setVisible(true);
        ui.lineEditLengthMax_8->setVisible(true);
        ui.labelMax_8->setVisible(true);
        break;
    default:
        ui.lineEditClassValueFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomAttributeName(int index)
{
    ui.verticalSpacer_9->changeSize(20, 210);
    ui.lineEdit_34->setVisible(false);
    ui.lineEditPatternAttributeName->setVisible(false);
    setVisibleLengthDialogAttributeName(false);
    ui.widgetAttributeName->setVisible(false);
    switch (index)
    {
    case 1:
        ui.verticalSpacer_9->changeSize(0, 0);
        ui.widgetAttributeName->setVisible(true);
        break;
    case 2:
        ui.lineEditPatternAttributeName->setVisible(true);
        break;
    case 3:
        setVisibleLengthDialogAttributeName(true);
        break;
    default:
        ui.lineEdit_34->setVisible(true);
        break;
    }
}

void IDSdialog::activateAttributeNameLength(int index) {
    ui.lineEditAttributeNameFixed->setVisible(false);
    ui.lineEditLengthMin_9->setVisible(false);
    ui.labelMin_9->setVisible(false);
    ui.lineEditLengthMax_9->setVisible(false);
    ui.labelMax_9->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin_9->setVisible(true);
        ui.labelMin_9->setVisible(true);
        ui.lineEditLengthMax_9->setVisible(true);
        ui.labelMax_9->setVisible(true);
        break;
    default:
        ui.lineEditAttributeNameFixed->setVisible(true);
        break;
    }
}

void IDSdialog::activateCustomAttributeValue(int index)
{
    ui.verticalSpacer_10->changeSize(20, 210);
    ui.lineEdit_38->setVisible(false);
    setVisibleBoundDialogAttributeValue(false);
    ui.lineEditPatternAttributeValue->setVisible(false);
    setVisibleLengthDialogAttributeValue(false);
    ui.widgetAttributeValue->setVisible(false);
    switch (index)
    {
    case 1:
        ui.comboBoxDataTypeAttribute->setVisible(true);
        ui.verticalSpacer_10->changeSize(0, 0);
        ui.widgetAttributeValue->setVisible(true);
        break;
    case 2:
        ui.comboBoxDataTypeAttribute->setVisible(true);
        ui.lineEditPatternAttributeValue->setVisible(true);
        break;
    case 3:
        ui.comboBoxDataTypeAttribute->setVisible(true);
        setVisibleBoundDialogAttributeValue(true);
        break;
    case 4:
        ui.comboBoxDataTypeAttribute->setVisible(true);
        setVisibleLengthDialogAttributeValue(true);
        break;
    default:
        ui.comboBoxDataTypeAttribute->setVisible(false);
        ui.lineEdit_38->setVisible(true);
        break;
    }
}

void IDSdialog::activateAttributeValueLength(int index) {
    ui.lineEditAttributeValueFixed->setVisible(false);
    ui.lineEditLengthMin_10->setVisible(false);
    ui.labelMin_10->setVisible(false);
    ui.lineEditLengthMax_10->setVisible(false);
    ui.labelMax_10->setVisible(false);
    switch (index) {
    case 1:
        ui.lineEditLengthMin_10->setVisible(true);
        ui.labelMin_10->setVisible(true);
        ui.lineEditLengthMax_10->setVisible(true);
        ui.labelMax_10->setVisible(true);
        break;
    default:
        ui.lineEditAttributeValueFixed->setVisible(true);
        break;
    }
}

bool IDSdialog::checkPattern(QString str) {
    QRegularExpression re;
    re.setPattern(str);
    return re.isValid();
}

void IDSdialog::entityIFCPatern()
{
    if (!checkPattern(ui.lineEditPatternEntityIFCType->text())) {
        ui.lineEditPatternEntityIFCType->setStyleSheet("QLineEdit"
            "{"
            "background : Pink;"
            "}");
    }
    else {
        ui.lineEditPatternEntityIFCType->setStyleSheet("QLineEdit"
            "{"
            "background : lightGreen;"
            "}");
    }
}

void IDSdialog::entityIFCPatern_2()
{
    if (!checkPattern(ui.lineEditPatternEntityPredType->text())) {
        ui.lineEditPatternEntityPredType->setStyleSheet("QLineEdit"
            "{"
            "background : Pink;"
            "}");
    }
    else {
        ui.lineEditPatternEntityPredType->setStyleSheet("QLineEdit"
            "{"
            "background : lightGreen;"
            "}");
    }
}

void IDSdialog::classSystemPatern()
{
    if (!checkPattern(ui.lineEditPatternClassSystem->text())) {
        ui.lineEditPatternClassSystem->setStyleSheet("QLineEdit"
            "{"
            "background : Pink;"
            "}");
    }
    else {
        ui.lineEditPatternClassSystem->setStyleSheet("QLineEdit"
            "{"
            "background : lightGreen;"
            "}");
    }
}

void IDSdialog::classValuePatern()
{
    if (!checkPattern(ui.lineEditPatternClassValue->text())) {
        ui.lineEditPatternClassValue->setStyleSheet("QLineEdit"
            "{"
            "background : Pink;"
            "}");
    }
    else {
        ui.lineEditPatternClassValue->setStyleSheet("QLineEdit"
            "{"
            "background : lightGreen;"
            "}");
    }
}

bool IDSdialog::checkLengthInt(QString min, QString max)
{

    bool ok;
    int iMax = max.toInt(&ok);
    if (!ok && max != "")
        return false;
    int iMin = min.toInt(&ok);
    if (!ok && min != "")
        return false;

    if (min == "" || max == "")
        return true;
    if (iMax < iMin)
    {
        return false;
    }

    return true;
}

void IDSdialog::entityIFCLength()
{
    if (!checkLengthInt(ui.lineEditLengthMin->text(), ui.lineEditLengthMax->text())) {
        ui.lineEditLengthMin->setStyleSheet("QLineEdit"
            "{"
            "background : Pink;"
            "}");
        ui.lineEditLengthMax->setStyleSheet("QLineEdit"
            "{"
            "background : Pink;"
            "}");
    }
    else {
        ui.lineEditLengthMin->setStyleSheet("QLineEdit"
            "{"
            "background : lightGreen;"
            "}");
        ui.lineEditLengthMax->setStyleSheet("QLineEdit"
            "{"
            "background : lightGreen;"
            "}");
    }
}

bool IDSdialog::checkBoundInt(QString first, QString second)
{

    bool ok;
    int ifirst = first.toInt(&ok);
    if (!ok && first != "")
        return false;
    int iSecond = second.toInt(&ok);
    if (!ok && second != "")
        return false;

    if (first == "" || second == "")
        return true;
    if (ifirst < iSecond)
    {
        return false;
    }

    return true;
}

void IDSdialog::on_pushButtonDeleteSelectedConditionApplicability_clicked(void)
{
    auto row = ui.tableWidgetApplicability->currentRow();
    if (row > -1) {
        ui.tableWidgetApplicability->removeRow(row);
        ui.tableWidgetApplicability->selectionModel()->clearCurrentIndex();
        hideAllOptions();
    }
}

void IDSdialog::on_pushButtonDeleteSelectedConditionRequirement_clicked(void)
{
    auto row = ui.tableWidgetRequirement->currentRow();
    if (row > -1) {
        ui.tableWidgetRequirement->removeRow(row);
        ui.tableWidgetRequirement->selectionModel()->clearCurrentIndex();
        hideAllOptions();
    }
}

void IDSdialog::on_pushButtonAddEnumPropPropertySet_clicked(void)
{
    ui.tableWidgetPropPropertySet->setRowCount(ui.tableWidgetPropPropertySet->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_13->text());
    ui.tableWidgetPropPropertySet->setItem(ui.tableWidgetPropPropertySet->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumPropPropertySet_clicked(void)
{
    auto row = ui.tableWidgetPropPropertySet->currentRow();
    if (row > -1) {
        ui.tableWidgetPropPropertySet->removeRow(row);
        ui.tableWidgetPropPropertySet->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumPropType_clicked(void)
{
    ui.tableWidgetPropType->setRowCount(ui.tableWidgetPropType->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_14->text());
    ui.tableWidgetPropType->setItem(ui.tableWidgetPropType->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumPropType_clicked(void)
{
    auto row = ui.tableWidgetPropType->currentRow();
    if (row > -1) {
        ui.tableWidgetPropType->removeRow(row);
        ui.tableWidgetPropType->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumPropValue_clicked(void)
{
    ui.tableWidgetPropValue->setRowCount(ui.tableWidgetPropValue->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_15->text());
    ui.tableWidgetPropValue->setItem(ui.tableWidgetPropValue->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumPropValue_clicked(void)
{
    auto row = ui.tableWidgetPropValue->currentRow();
    if (row > -1) {
        ui.tableWidgetPropValue->removeRow(row);
        ui.tableWidgetPropValue->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumMaterial_clicked(void)
{
    ui.tableWidgetMaterialValue->setRowCount(ui.tableWidgetMaterialValue->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_43->text());
    ui.tableWidgetMaterialValue->setItem(ui.tableWidgetMaterialValue->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumMaterial_clicked(void)
{
    auto row = ui.tableWidgetMaterialValue->currentRow();
    if (row > -1) {
        ui.tableWidgetMaterialValue->removeRow(row);
        ui.tableWidgetMaterialValue->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumPartOfRelation_clicked(void)
{
    ui.tableWidgetPartOfRelation->setRowCount(ui.tableWidgetPartOfRelation->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_44->text());
    ui.tableWidgetPartOfRelation->setItem(ui.tableWidgetPartOfRelation->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumPartOfRelation_clicked(void)
{
    auto row = ui.tableWidgetPartOfRelation->currentRow();
    if (row > -1) {
        ui.tableWidgetPartOfRelation->removeRow(row);
        ui.tableWidgetPartOfRelation->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumPartOfPredef_clicked(void)
{
    ui.tableWidgetPartOfPredef->setRowCount(ui.tableWidgetPartOfPredef->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_45->text());
    ui.tableWidgetPartOfPredef->setItem(ui.tableWidgetPartOfPredef->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumPartOfPredef_clicked(void)
{
    auto row = ui.tableWidgetPartOfPredef->currentRow();
    if (row > -1) {
        ui.tableWidgetPartOfPredef->removeRow(row);
        ui.tableWidgetPartOfPredef->selectionModel()->clearCurrentIndex();
    }
}


void IDSdialog::on_pushButtonAddEnumClassSystem_clicked(void)
{
    ui.tableWidgetClassSystem->setRowCount(ui.tableWidgetClassSystem->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_33->text());
    ui.tableWidgetClassSystem->setItem(ui.tableWidgetClassSystem->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumClassSystem_clicked(void)
{
    auto row = ui.tableWidgetClassSystem->currentRow();
    if (row > -1) {
        ui.tableWidgetClassSystem->removeRow(row);
        ui.tableWidgetClassSystem->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumAttributeName_clicked(void)
{
    ui.tableWidgetAttributeName->setRowCount(ui.tableWidgetAttributeName->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_41->text());
    ui.tableWidgetAttributeName->setItem(ui.tableWidgetAttributeName->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumAttributeName_clicked(void)
{
    auto row = ui.tableWidgetAttributeName->currentRow();
    if (row > -1) {
        ui.tableWidgetAttributeName->removeRow(row);
        ui.tableWidgetAttributeName->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumAttributeValue_clicked(void)
{
    ui.tableWidgetAttributeValue->setRowCount(ui.tableWidgetAttributeValue->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_42->text());
    ui.tableWidgetAttributeValue->setItem(ui.tableWidgetAttributeValue->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumAttributeValue_clicked(void)
{
    auto row = ui.tableWidgetAttributeValue->currentRow();
    if (row > -1) {
        ui.tableWidgetAttributeValue->removeRow(row);
        ui.tableWidgetAttributeValue->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::on_pushButtonAddEnumClassValue_clicked(void)
{
    ui.tableWidgetClassValue->setRowCount(ui.tableWidgetClassValue->rowCount() + 1);
    QTableWidgetItem* tableWidget = new QTableWidgetItem(ui.lineEdit_36->text());
    ui.tableWidgetClassValue->setItem(ui.tableWidgetClassValue->rowCount() - 1, 0, tableWidget);
}

void IDSdialog::on_pushButtonRemoveEnumClassValue_clicked(void)
{
    auto row = ui.tableWidgetClassValue->currentRow();
    if (row > -1) {
        ui.tableWidgetClassValue->removeRow(row);
        ui.tableWidgetClassValue->selectionModel()->clearCurrentIndex();
    }
}

void IDSdialog::setVisibleLengthDialogEntityIFCType(bool is)
{
    ui.comboBox_51->setVisible(is);
    ui.lineEditEntityIFCTypeFixed->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogEntityPredType(bool is)
{
    ui.lineEditEntityPredTypeFixed->setVisible(is);
    ui.comboBox_50->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogPropertySet(bool is)
{
    ui.lineEditPropPropertySetFixed->setVisible(is);
    ui.comboBox_14->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogProperty(bool is)
{
    ui.lineEditPropTypeFixed->setVisible(is);
    ui.comboBox_13->setVisible(is);
}

void IDSdialog::setVisibleBoundDialogPropertyValue(bool is)
{
    ui.comboBox_42->setVisible(is);
    ui.lineEdit_27->setVisible(is);
    ui.lineEdit_28->setVisible(is);
    ui.comboBox_43->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogPropertyValue(bool is)
{
    ui.lineEditPropValueFixed->setVisible(is);
    ui.comboBox_12->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogMaterial(bool is) {
    ui.comboBox_6->setVisible(is);
    ui.lineEditMaterialFixed->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogPartOfRelation(bool is) {
    ui.comboBox_11->setVisible(is);
    ui.lineEditPartOfRelationFixed->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogPartOfPredef(bool is) {
    ui.comboBox_10->setVisible(is);
    ui.lineEditPartOfPredefFixed->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogClass(bool is)
{
    ui.lineEditClassSystemFixed->setVisible(is);
    ui.comboBox_16->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogClassValue(bool is)
{
    ui.lineEditClassValueFixed->setVisible(is);
    ui.comboBox_15->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogAttributeName(bool is)
{
    ui.lineEditAttributeNameFixed->setVisible(is);
    ui.comboBox_24->setVisible(is);
}

void IDSdialog::setVisibleLengthDialogAttributeValue(bool is)
{
    ui.lineEditAttributeValueFixed->setVisible(is);
    ui.comboBox_17->setVisible(is);
}

void IDSdialog::setVisibleBoundDialogAttributeValue(bool is)
{
    ui.comboBox_44->setVisible(is);
    ui.lineEdit_39->setVisible(is);
    ui.lineEdit_40->setVisible(is);
    ui.comboBox_45->setVisible(is);
}

void IDSdialog::on_pushButtonSaveEntity_clicked(void)
{
    
    switch (ui.comboBox_20->currentIndex())
    {
    case 0:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto entity : getSpecification()->getPredicate()->getEntities())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                    dynamic_cast<IDS::EntityPredicate*>(entity)->createNameIfNeed();
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.comboBox_4->currentText()).toStdString());
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->getValue()->getStr();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto entity : getSpecification()->getClaim()->getEntities())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                    dynamic_cast<IDS::EntityPredicate*>(entity)->createNameIfNeed();
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.comboBox_4->currentText()).toStdString());
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->getValue()->getStr();
                    break;
                }
            }
        }
        break;
    case 1:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto entity : getSpecification()->getPredicate()->getEntities())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                    dynamic_cast<IDS::EntityPredicate*>(entity)->createNameIfNeed();
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    //dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->getEnumeration()->getTypeidsenumerationValues()->clear();
                    for (int i = 0; i < ui.tableWidgetEntityIFCType->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetEntityIFCType->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto entity : getSpecification()->getClaim()->getEntities())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                    dynamic_cast<IDS::EntityPredicate*>(entity)->createNameIfNeed();
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    //dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->getEnumeration()->getTypeidsenumerationValues()->clear();
                    for (int i = 0; i < ui.tableWidgetEntityIFCType->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetEntityIFCType->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        break;
    case 2:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto entity : getSpecification()->getPredicate()->getEntities())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                    dynamic_cast<IDS::EntityPredicate*>(entity)->createNameIfNeed();
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternEntityIFCType->text()).toStdString());
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->setIdsPattern(pattern);
                    qDebug() << dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto entity : getSpecification()->getClaim()->getEntities())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                    dynamic_cast<IDS::EntityPredicate*>(entity)->createNameIfNeed();
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternEntityIFCType->text()).toStdString());
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->setIdsPattern(pattern);
                    qDebug() << dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        break;
    case 3:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto entity : getSpecification()->getPredicate()->getEntities())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                    dynamic_cast<IDS::EntityPredicate*>(entity)->createNameIfNeed();
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->clear();
                    IDS::Length* length = new IDS::Length();
                    if (ui.comboBox_51->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditEntityIFCTypeFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax->text()).toInt());
                    }
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->setIdsLength(length);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto entity : getSpecification()->getClaim()->getEntities())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                    dynamic_cast<IDS::EntityPredicate*>(entity)->createNameIfNeed();
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->clear();
                    IDS::Length* length = new IDS::Length();
                    if (ui.comboBox_51->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditEntityIFCTypeFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax->text()).toInt());
                    }
                    dynamic_cast<IDS::EntityPredicate*>(entity)->getName()->setIdsLength(length);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }


    switch (ui.comboBox_3->currentIndex())
    {
    case 0:
        if (ui.lineEdit_3->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto entity : getSpecification()->getPredicate()->getEntities())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                        dynamic_cast<IDS::EntityPredicate*>(entity)->createPredefinedIfNeed();
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->clear();
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.lineEdit_3->text()).toStdString());
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->setIdsValue(val);
                        qDebug() << dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->getValue()->getStr();
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto entity : getSpecification()->getClaim()->getEntities())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                        dynamic_cast<IDS::EntityPredicate*>(entity)->createPredefinedIfNeed();
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->clear();
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.lineEdit_3->text()).toStdString());
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->setIdsValue(val);
                        qDebug() << dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->getValue()->getStr();
                        break;
                    }
                }
            }
        }
        break;
    case 1:
        if (ui.tableWidgetEntityPredType->rowCount() != 0) {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto entity : getSpecification()->getPredicate()->getEntities())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                        dynamic_cast<IDS::EntityPredicate*>(entity)->createPredefinedIfNeed();
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->clear();
                        IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                        IDS::Enumeration* enumer = new IDS::Enumeration();
                        for (int i = 0; i < ui.tableWidgetEntityPredType->rowCount(); ++i) {
                            IDS::Value* val = new IDS::Value();
                            val->setIdsString((ui.tableWidgetEntityPredType->item(i, 0)->text()).toStdString());
                            enumerationValues->addElement(val);
                        }
                        enumer->setValues(enumerationValues);
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->setIdsEnumeration(enumer);
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto entity : getSpecification()->getClaim()->getEntities())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                        dynamic_cast<IDS::EntityPredicate*>(entity)->createPredefinedIfNeed();
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->clear();
                        IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                        IDS::Enumeration* enumer = new IDS::Enumeration();
                        for (int i = 0; i < ui.tableWidgetEntityPredType->rowCount(); ++i) {
                            IDS::Value* val = new IDS::Value();
                            val->setIdsString((ui.tableWidgetEntityPredType->item(i, 0)->text()).toStdString());
                            enumerationValues->addElement(val);
                        }
                        enumer->setValues(enumerationValues);
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->setIdsEnumeration(enumer);
                        break;
                    }
                }
            }
        }
        break;
    case 2:
        if (ui.lineEditPatternEntityPredType->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto entity : getSpecification()->getPredicate()->getEntities())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                        dynamic_cast<IDS::EntityPredicate*>(entity)->createPredefinedIfNeed();
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->clear();
                        IDS::Pattern* pattern = new IDS::Pattern();
                        pattern->setRegExp((ui.lineEditPatternEntityPredType->text()).toStdString());
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->setIdsPattern(pattern);
                        qDebug() << dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->getPattern()->getRegExp();
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto entity : getSpecification()->getClaim()->getEntities())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                        dynamic_cast<IDS::EntityPredicate*>(entity)->createPredefinedIfNeed();
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->clear();
                        IDS::Pattern* pattern = new IDS::Pattern();
                        pattern->setRegExp((ui.lineEditPatternEntityPredType->text()).toStdString());
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->setIdsPattern(pattern);
                        qDebug() << dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->getPattern()->getRegExp();
                        break;
                    }
                }
            }
        }
        break;
    case 3:
        if (ui.lineEditEntityPredTypeFixed->text() != "" || ui.lineEditLengthMin_2->text() != "") {
            qDebug() << "**===**";
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto entity : getSpecification()->getPredicate()->getEntities())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                        dynamic_cast<IDS::EntityPredicate*>(entity)->createPredefinedIfNeed();
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->clear();
                        IDS::Length* length = new IDS::Length();
                        if (ui.comboBox_50->currentIndex() == 0) {
                            length->setIsFixed(true);
                            length->setFixLength((ui.lineEditEntityPredTypeFixed->text()).toInt());
                        }
                        else {
                            length->setIsFixed(false);
                            length->setMinLength((ui.lineEditLengthMin_2->text()).toInt());
                            length->setMaxLength((ui.lineEditLengthMax_2->text()).toInt());
                        }
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->setIdsLength(length);
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto entity : getSpecification()->getClaim()->getEntities())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::EntityPredicate*>(entity)->getTableWidgetItem()) {
                        dynamic_cast<IDS::EntityPredicate*>(entity)->createPredefinedIfNeed();
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->clear();
                        IDS::Length* length = new IDS::Length();
                        if (ui.comboBox_50->currentIndex() == 0) {
                            length->setIsFixed(true);
                            length->setFixLength((ui.lineEditEntityPredTypeFixed->text()).toInt());
                        }
                        else {
                            length->setIsFixed(false);
                            length->setMinLength((ui.lineEditLengthMin_2->text()).toInt());
                            length->setMaxLength((ui.lineEditLengthMax_2->text()).toInt());
                        }
                        dynamic_cast<IDS::EntityPredicate*>(entity)->getPredefined()->setIdsLength(length);
                        break;
                    }
                }
            }
        }
        break;
    default:
        break;
    }
}

void IDSdialog::on_pushButtonSaveAttribute_clicked(void)
{
    switch (ui.comboBox_37->currentIndex())
    {
    case 0:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto attribute : getSpecification()->getPredicate()->getAttributes())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->createNameIfNeed();
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_34->text()).toStdString());
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->getValue()->getStr();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto attribute : getSpecification()->getClaim()->getAttributes())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->createNameIfNeed();
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_34->text()).toStdString());
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->getValue()->getStr();
                    break;
                }
            }
        }
        break;
    case 1:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto attribute : getSpecification()->getPredicate()->getAttributes())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->createNameIfNeed();
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetAttributeName->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetAttributeName->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto attribute : getSpecification()->getClaim()->getAttributes())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->createNameIfNeed();
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetAttributeName->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetAttributeName->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        break;
    case 2:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto attribute : getSpecification()->getPredicate()->getAttributes())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->createNameIfNeed();
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternAttributeName->text()).toStdString());
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto attribute : getSpecification()->getClaim()->getAttributes())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->createNameIfNeed();
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternAttributeName->text()).toStdString());
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        break;
    case 3:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto attribute : getSpecification()->getPredicate()->getAttributes())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->createNameIfNeed();
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_24->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditAttributeNameFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_9->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_9->text()).toInt());
                    }
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->setIdsLength(length);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto attribute : getSpecification()->getClaim()->getAttributes())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->createNameIfNeed();
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_24->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditAttributeNameFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_9->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_9->text()).toInt());
                    }
                    dynamic_cast<IDS::AttributePredicate*>(attribute)->getName()->setIdsLength(length);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }


    switch (ui.comboBox_40->currentIndex())
    {
    case 0:
        if (ui.lineEdit_38->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto attribute : getSpecification()->getPredicate()->getAttributes())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::Value* val = new IDS::Value();

                        val->setIdsString((ui.lineEdit_38->text()).toStdString());
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsValue(val);
                        qDebug() << dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->getValue()->getStr();
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto attribute : getSpecification()->getClaim()->getAttributes())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::Value* val = new IDS::Value();

                        val->setIdsString((ui.lineEdit_38->text()).toStdString());
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsValue(val);
                        qDebug() << dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->getValue()->getStr();
                        break;
                    }
                }
            }
        }
        break;
    case 1:
        if (ui.tableWidgetAttributeValue->rowCount() != 0) {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto attribute : getSpecification()->getPredicate()->getAttributes())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                        IDS::Enumeration* enumer = new IDS::Enumeration();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            enumer->setStrBase();
                            break;
                        case 1:
                            enumer->setIntBase();
                            break;
                        case 2:
                            enumer->setRealBase();
                            break;
                        default:
                            break;
                        }
                        for (int i = 0; i < ui.tableWidgetAttributeValue->rowCount(); ++i) {
                            IDS::Value* val = new IDS::Value();
                            val->setIdsString((ui.tableWidgetAttributeValue->item(i, 0)->text()).toStdString());
                            enumerationValues->addElement(val);
                        }
                        enumer->setValues(enumerationValues);
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsEnumeration(enumer);

                        for (auto a : dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
                            qDebug() << a->getStr();
                        }
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto attribute : getSpecification()->getClaim()->getAttributes())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                        IDS::Enumeration* enumer = new IDS::Enumeration();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            enumer->setStrBase();
                            break;
                        case 1:
                            enumer->setIntBase();
                            break;
                        case 2:
                            enumer->setRealBase();
                            break;
                        default:
                            break;
                        }
                        for (int i = 0; i < ui.tableWidgetAttributeValue->rowCount(); ++i) {
                            IDS::Value* val = new IDS::Value();
                            val->setIdsString((ui.tableWidgetAttributeValue->item(i, 0)->text()).toStdString());
                            enumerationValues->addElement(val);
                        }
                        enumer->setValues(enumerationValues);
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsEnumeration(enumer);
                        break;
                    }
                }
            }
        }
        break;
    case 2:
        if (ui.lineEditPatternAttributeValue->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto attribute : getSpecification()->getPredicate()->getAttributes())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::Pattern* pattern = new IDS::Pattern();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            pattern->setStrBase();
                            break;
                        case 1:
                            pattern->setIntBase();
                            break;
                        case 2:
                            pattern->setRealBase();
                            break;
                        default:
                            break;
                        }
                        pattern->setRegExp((ui.lineEditPatternAttributeValue->text()).toStdString());
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsPattern(pattern);
                        qDebug() << dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->getPattern()->getRegExp();
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto attribute : getSpecification()->getClaim()->getAttributes())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::Pattern* pattern = new IDS::Pattern();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            pattern->setStrBase();
                            break;
                        case 1:
                            pattern->setIntBase();
                            break;
                        case 2:
                            pattern->setRealBase();
                            break;
                        default:
                            break;
                        }
                        pattern->setRegExp((ui.lineEditPatternAttributeValue->text()).toStdString());
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsPattern(pattern);
                        qDebug() << dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->getPattern()->getRegExp();
                        break;
                    }
                }
            }
        }
        break;
    case 3:
        if (ui.lineEdit_39->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto attribute : getSpecification()->getPredicate()->getAttributes())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::Bounds* bounds = new IDS::Bounds();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            bounds->setStrBase();
                            break;
                        case 1:
                            bounds->setIntBase();
                            break;
                        case 2:
                            bounds->setRealBase();
                            break;
                        default:
                            break;
                        }
                        if (ui.comboBox_44->currentIndex() == 0) {
                            bounds->setMinInclusive((ui.lineEdit_39->text()).toInt());
                        }
                        else {
                            bounds->setMinExclusive((ui.lineEdit_39->text()).toInt());
                        }

                        if (ui.comboBox_45->currentIndex() == 0) {
                            bounds->setMaxInclusive((ui.lineEdit_40->text()).toInt());
                        }
                        else {
                            bounds->setMaxExclusive((ui.lineEdit_40->text()).toInt());
                        }
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsBounds(bounds);
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto attribute : getSpecification()->getClaim()->getAttributes())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::Bounds* bounds = new IDS::Bounds();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            bounds->setStrBase();
                            break;
                        case 1:
                            bounds->setIntBase();
                            break;
                        case 2:
                            bounds->setRealBase();
                            break;
                        default:
                            break;
                        }
                        if (ui.comboBox_44->currentIndex() == 0) {
                            bounds->setMinInclusive((ui.lineEdit_39->text()).toInt());
                        }
                        else {
                            bounds->setMinExclusive((ui.lineEdit_39->text()).toInt());
                        }

                        if (ui.comboBox_45->currentIndex() == 0) {
                            bounds->setMaxInclusive((ui.lineEdit_40->text()).toInt());
                        }
                        else {
                            bounds->setMaxExclusive((ui.lineEdit_40->text()).toInt());
                        }
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsBounds(bounds);
                        break;
                    }
                }
            }
        }
        break;
    case 4:
        if (ui.lineEditAttributeValueFixed->text() != "" || ui.lineEditLengthMin_10->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto attribute : getSpecification()->getPredicate()->getAttributes())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::Length* length = new IDS::Length();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            length->setStrBase();
                            break;
                        case 1:
                            length->setIntBase();
                            break;
                        case 2:
                            length->setRealBase();
                            break;
                        default:
                            break;
                        }
                        if (ui.comboBox_17->currentIndex() == 0) {
                            length->setIsFixed(true);
                            length->setFixLength((ui.lineEditAttributeValueFixed->text()).toInt());
                        }
                        else {
                            length->setIsFixed(false);
                            length->setMinLength((ui.lineEditLengthMin_10->text()).toInt());
                            length->setMaxLength((ui.lineEditLengthMax_10->text()).toInt());
                        }
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsLength(length);
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto attribute : getSpecification()->getClaim()->getAttributes())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::AttributePredicate*>(attribute)->getTableWidgetItem()) {
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->createDomainIfNeed();
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->clear();
                        IDS::Length* length = new IDS::Length();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            length->setStrBase();
                            break;
                        case 1:
                            length->setIntBase();
                            break;
                        case 2:
                            length->setRealBase();
                            break;
                        default:
                            break;
                        }
                        if (ui.comboBox_17->currentIndex() == 0) {
                            length->setIsFixed(true);
                            length->setFixLength((ui.lineEditAttributeValueFixed->text()).toInt());
                        }
                        else {
                            length->setIsFixed(false);
                            length->setMinLength((ui.lineEditLengthMin_10->text()).toInt());
                            length->setMaxLength((ui.lineEditLengthMax_10->text()).toInt());
                        }
                        dynamic_cast<IDS::AttributePredicate*>(attribute)->getDomain()->setIdsLength(length);
                        break;
                    }
                }
            }
        }
        break;
    default:
        break;
    }
}

void IDSdialog::on_pushButtonSaveClassification_clicked(void)
{
    switch (ui.comboBox_28->currentIndex())
    {
    case 0:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto classification : getSpecification()->getPredicate()->getClassifications())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->createSystemIfNeed();
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_24->text()).toStdString());
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->getValue()->getStr();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto classification : getSpecification()->getClaim()->getClassifications())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->createSystemIfNeed();
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_24->text()).toStdString());
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->getValue()->getStr();
                    break;
                }
            }
        }
        break;
    case 1:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto classification : getSpecification()->getPredicate()->getClassifications())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->createSystemIfNeed();
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetClassSystem->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetClassSystem->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto classification : getSpecification()->getClaim()->getClassifications())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->createSystemIfNeed();
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetClassSystem->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetClassSystem->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        break;
    case 2:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto classification : getSpecification()->getPredicate()->getClassifications())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->createSystemIfNeed();
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternClassSystem->text()).toStdString());
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto classification : getSpecification()->getClaim()->getClassifications())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->createSystemIfNeed();
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternClassSystem->text()).toStdString());
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        break;
    case 3:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto classification : getSpecification()->getPredicate()->getClassifications())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->createSystemIfNeed();
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_16->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditClassSystemFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_6->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_6->text()).toInt());
                    }
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->setIdsLength(length);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto classification : getSpecification()->getClaim()->getClassifications())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->createSystemIfNeed();
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_16->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditClassSystemFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_6->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_6->text()).toInt());
                    }
                    dynamic_cast<IDS::ClassificationPredicate*>(classification)->getSystem()->setIdsLength(length);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }


    switch (ui.comboBox_34->currentIndex())
    {
    case 0:
        if (ui.lineEdit_30->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto classification : getSpecification()->getPredicate()->getClassifications())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->createValueIfNeed();
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->clear();
                        IDS::Value* val = new IDS::Value();

                        val->setIdsString((ui.lineEdit_30->text()).toStdString());
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->setIdsValue(val);
                        qDebug() << dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->getValue()->getStr();
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto classification : getSpecification()->getClaim()->getClassifications())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->createValueIfNeed();
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->clear();
                        IDS::Value* val = new IDS::Value();

                        val->setIdsString((ui.lineEdit_30->text()).toStdString());
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->setIdsValue(val);
                        qDebug() << dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->getValue()->getStr();
                        break;
                    }
                }
            }
        }
        break;
    case 1:
        if (ui.tableWidgetClassValue->rowCount() != 0) {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto classification : getSpecification()->getPredicate()->getClassifications())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->createValueIfNeed();
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->clear();
                        IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                        IDS::Enumeration* enumer = new IDS::Enumeration();
                        for (int i = 0; i < ui.tableWidgetClassValue->rowCount(); ++i) {
                            IDS::Value* val = new IDS::Value();
                            val->setIdsString((ui.tableWidgetClassValue->item(i, 0)->text()).toStdString());
                            enumerationValues->addElement(val);
                        }
                        enumer->setValues(enumerationValues);
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->setIdsEnumeration(enumer);

                        for (auto a : dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
                            qDebug() << a->getStr();
                        }
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto classification : getSpecification()->getClaim()->getClassifications())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->createValueIfNeed();
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->clear();
                        IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                        IDS::Enumeration* enumer = new IDS::Enumeration();
                        for (int i = 0; i < ui.tableWidgetClassValue->rowCount(); ++i) {
                            IDS::Value* val = new IDS::Value();
                            val->setIdsString((ui.tableWidgetClassValue->item(i, 0)->text()).toStdString());
                            enumerationValues->addElement(val);
                        }
                        enumer->setValues(enumerationValues);
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->setIdsEnumeration(enumer);
                        break;
                    }
                }
            }
        }
        break;
    case 2:
        if (ui.lineEditPatternClassValue->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto classification : getSpecification()->getPredicate()->getClassifications())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->createValueIfNeed();
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->clear();
                        IDS::Pattern* pattern = new IDS::Pattern();

                        pattern->setRegExp((ui.lineEditPatternClassValue->text()).toStdString());
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->setIdsPattern(pattern);
                        qDebug() << dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->getPattern()->getRegExp();
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto classification : getSpecification()->getClaim()->getClassifications())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->createValueIfNeed();
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->clear();
                        IDS::Pattern* pattern = new IDS::Pattern();

                        pattern->setRegExp((ui.lineEditPatternClassValue->text()).toStdString());
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->setIdsPattern(pattern);
                        qDebug() << dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->getPattern()->getRegExp();
                        break;
                    }
                }
            }
        }
        break;
    case 3:
        if (ui.lineEditClassValueFixed->text() != "" || ui.lineEditLengthMin_8->text() != "") {
            qDebug() << "**===**";
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto classification : getSpecification()->getPredicate()->getClassifications())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->createValueIfNeed();
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->clear();
                        IDS::Length* length = new IDS::Length();

                        if (ui.comboBox_15->currentIndex() == 0) {
                            length->setIsFixed(true);
                            length->setFixLength((ui.lineEditClassValueFixed->text()).toInt());
                        }
                        else {
                            length->setIsFixed(false);
                            length->setMinLength((ui.lineEditLengthMin_8->text()).toInt());
                            length->setMaxLength((ui.lineEditLengthMax_8->text()).toInt());
                        }
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->setIdsLength(length);
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto classification : getSpecification()->getClaim()->getClassifications())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::ClassificationPredicate*>(classification)->getTableWidgetItem()) {
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->createValueIfNeed();
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->clear();
                        IDS::Length* length = new IDS::Length();

                        if (ui.comboBox_15->currentIndex() == 0) {
                            length->setIsFixed(true);
                            length->setFixLength((ui.lineEditClassValueFixed->text()).toInt());
                        }
                        else {
                            length->setIsFixed(false);
                            length->setMinLength((ui.lineEditLengthMin_8->text()).toInt());
                            length->setMaxLength((ui.lineEditLengthMax_8->text()).toInt());
                        }
                        dynamic_cast<IDS::ClassificationPredicate*>(classification)->getValue()->setIdsLength(length);
                        break;
                    }
                }
            }
        }
        break;
    default:
        break;
    }
}

void IDSdialog::on_pushButtonSaveMaterial_clicked(void)
{
    switch (ui.comboBox_46->currentIndex())
    {
    case 0:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto material : getSpecification()->getPredicate()->getMaterials())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::MaterialPredicate*>(material)->getTableWidgetItem()) {
                    dynamic_cast<IDS::MaterialPredicate*>(material)->createDomainIfNeed();
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.comboBox_19->currentText()).toStdString());
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->getValue()->getStr();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto material : getSpecification()->getClaim()->getMaterials())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::MaterialPredicate*>(material)->getTableWidgetItem()) {
                    dynamic_cast<IDS::MaterialPredicate*>(material)->createDomainIfNeed();
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.comboBox_19->currentText()).toStdString());
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->getValue()->getStr();
                    break;
                }
            }
        }
        break;
    case 1:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto material : getSpecification()->getPredicate()->getMaterials())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::MaterialPredicate*>(material)->getTableWidgetItem()) {
                    dynamic_cast<IDS::MaterialPredicate*>(material)->createDomainIfNeed();
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetMaterialValue->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetMaterialValue->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto material : getSpecification()->getClaim()->getMaterials())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::MaterialPredicate*>(material)->getTableWidgetItem()) {
                    dynamic_cast<IDS::MaterialPredicate*>(material)->createDomainIfNeed();
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetMaterialValue->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetMaterialValue->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        break;
    case 2:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto material : getSpecification()->getPredicate()->getMaterials())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::MaterialPredicate*>(material)->getTableWidgetItem()) {
                    dynamic_cast<IDS::MaterialPredicate*>(material)->createDomainIfNeed();
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternMaterialValue->text()).toStdString());
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto material : getSpecification()->getClaim()->getMaterials())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::MaterialPredicate*>(material)->getTableWidgetItem()) {
                    dynamic_cast<IDS::MaterialPredicate*>(material)->createDomainIfNeed();
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternMaterialValue->text()).toStdString());
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        break;
    case 3:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto material : getSpecification()->getPredicate()->getMaterials())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::MaterialPredicate*>(material)->getTableWidgetItem()) {
                    dynamic_cast<IDS::MaterialPredicate*>(material)->createDomainIfNeed();
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_6->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditMaterialFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_11->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_11->text()).toInt());
                    }
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->setIdsLength(length);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto material : getSpecification()->getClaim()->getMaterials())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::MaterialPredicate*>(material)->getTableWidgetItem()) {
                    dynamic_cast<IDS::MaterialPredicate*>(material)->createDomainIfNeed();
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_6->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditMaterialFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_11->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_11->text()).toInt());
                    }
                    dynamic_cast<IDS::MaterialPredicate*>(material)->getDomain()->setIdsLength(length);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}

void IDSdialog::on_pushButtonSaveProperty_clicked(void)
{
    switch (ui.comboBox_25->currentIndex())
    {
    case 0:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto property : getSpecification()->getPredicate()->getProperties())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createPropertySetIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_5->text()).toStdString());
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->getValue()->getStr();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto property : getSpecification()->getClaim()->getProperties())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createPropertySetIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_5->text()).toStdString());
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->getValue()->getStr();
                    break;
                }
            }
        }
        break;
    case 1:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto property : getSpecification()->getPredicate()->getProperties())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createPropertySetIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetPropPropertySet->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetPropPropertySet->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto property : getSpecification()->getClaim()->getProperties())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createPropertySetIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetPropPropertySet->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetPropPropertySet->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        break;
    case 2:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto property : getSpecification()->getPredicate()->getProperties())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createPropertySetIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternPropPropertySet->text()).toStdString());
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto property : getSpecification()->getClaim()->getProperties())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createPropertySetIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternPropPropertySet->text()).toStdString());
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        break;
    case 3:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto property : getSpecification()->getPredicate()->getProperties())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createPropertySetIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->clear();
                    IDS::Length* length = new IDS::Length();
                    if (ui.comboBox_14->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditPropPropertySetFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_3->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_3->text()).toInt());
                    }
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->setIdsLength(length);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto property : getSpecification()->getClaim()->getProperties())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createPropertySetIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->clear();
                    IDS::Length* length = new IDS::Length();
                    if (ui.comboBox_14->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditPropPropertySetFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_3->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_3->text()).toInt());
                    }
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getPropertySet()->setIdsLength(length);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }

    switch (ui.comboBox_30->currentIndex())
    {
    case 0:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto property : getSpecification()->getPredicate()->getProperties())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createNameIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_6->text()).toStdString());
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->getValue()->getStr();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto property : getSpecification()->getClaim()->getProperties())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createNameIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_6->text()).toStdString());
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->getValue()->getStr();
                    break;
                }
            }
        }
        break;
    case 1:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto property : getSpecification()->getPredicate()->getProperties())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createNameIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetPropType->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetPropType->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto property : getSpecification()->getClaim()->getProperties())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createNameIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetPropType->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetPropType->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        break;
    case 2:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto property : getSpecification()->getPredicate()->getProperties())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createNameIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternPropType->text()).toStdString());
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto property : getSpecification()->getClaim()->getProperties())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createNameIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternPropType->text()).toStdString());
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        break;
    case 3:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto property : getSpecification()->getPredicate()->getProperties())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createNameIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_13->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditPropTypeFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_4->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_4->text()).toInt());
                    }
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->setIdsLength(length);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto property : getSpecification()->getClaim()->getProperties())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                    dynamic_cast<IDS::PropertyPredicate*>(property)->createNameIfNeed();
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_13->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditPropTypeFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_4->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_4->text()).toInt());
                    }
                    dynamic_cast<IDS::PropertyPredicate*>(property)->getName()->setIdsLength(length);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }

    switch (ui.comboBox_41->currentIndex())
    {
    case 0:
        if (ui.lineEdit_26->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto property : getSpecification()->getPredicate()->getProperties())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.lineEdit_26->text()).toStdString());
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsValue(val);
                        qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->getValue()->getStr();
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto property : getSpecification()->getClaim()->getProperties())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.lineEdit_26->text()).toStdString());
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsValue(val);
                        qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->getValue()->getStr();
                        break;
                    }
                }
            }
        }
        break;
    case 1:
        if (ui.tableWidgetPropValue->rowCount() != 0) {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto property : getSpecification()->getPredicate()->getProperties())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                        IDS::Enumeration* enumer = new IDS::Enumeration();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            enumer->setStrBase();
                            break;
                        case 1:
                            enumer->setIntBase();
                            break;
                        case 2:
                            enumer->setRealBase();
                            break;
                        default:
                            break;
                        }
                        for (int i = 0; i < ui.tableWidgetPropValue->rowCount(); ++i) {
                            IDS::Value* val = new IDS::Value();
                            val->setIdsString((ui.tableWidgetPropValue->item(i, 0)->text()).toStdString());
                            enumerationValues->addElement(val);
                        }
                        enumer->setValues(enumerationValues);
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsEnumeration(enumer);

                        for (auto a : dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
                            qDebug() << a->getStr();
                        }
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto property : getSpecification()->getClaim()->getProperties())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                        IDS::Enumeration* enumer = new IDS::Enumeration();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            enumer->setStrBase();
                            break;
                        case 1:
                            enumer->setIntBase();
                            break;
                        case 2:
                            enumer->setRealBase();
                            break;
                        default:
                            break;
                        }
                        for (int i = 0; i < ui.tableWidgetPropValue->rowCount(); ++i) {
                            IDS::Value* val = new IDS::Value();
                            val->setIdsString((ui.tableWidgetPropValue->item(i, 0)->text()).toStdString());
                            enumerationValues->addElement(val);
                        }
                        enumer->setValues(enumerationValues);
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsEnumeration(enumer);
                        break;
                    }
                }
            }
        }
        break;
    case 2:
        if (ui.lineEditPatternPropValue->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto property : getSpecification()->getPredicate()->getProperties())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::Pattern* pattern = new IDS::Pattern();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            pattern->setStrBase();
                            break;
                        case 1:
                            pattern->setIntBase();
                            break;
                        case 2:
                            pattern->setRealBase();
                            break;
                        default:
                            break;
                        }
                        QString str = ui.comboBoxDataTypeProperty->currentText();
                        pattern->setRegExp((ui.lineEditPatternPropValue->text()).toStdString());
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsPattern(pattern);
                        qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->getPattern()->getRegExp();
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto property : getSpecification()->getClaim()->getProperties())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::Pattern* pattern = new IDS::Pattern();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            pattern->setStrBase();
                            break;
                        case 1:
                            pattern->setIntBase();
                            break;
                        case 2:
                            pattern->setRealBase();
                            break;
                        default:
                            break;
                        }
                        pattern->setRegExp((ui.lineEditPatternPropValue->text()).toStdString());
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsPattern(pattern);
                        qDebug() << dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->getPattern()->getRegExp();
                        break;
                    }
                }
            }
        }
        break;
    case 3:
        if (ui.lineEdit_27->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto property : getSpecification()->getPredicate()->getProperties())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::Bounds* bounds = new IDS::Bounds();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            bounds->setStrBase();
                            break;
                        case 1:
                            bounds->setIntBase();
                            break;
                        case 2:
                            bounds->setRealBase();
                            break;
                        default:
                            break;
                        }
                        if (ui.comboBox_44->currentIndex() == 0) {
                            bounds->setMinInclusive((ui.lineEdit_27->text()).toInt());
                        }
                        else {
                            bounds->setMinExclusive((ui.lineEdit_27->text()).toInt());
                        }

                        if (ui.comboBox_45->currentIndex() == 0) {
                            bounds->setMaxInclusive((ui.lineEdit_28->text()).toInt());
                        }
                        else {
                            bounds->setMaxExclusive((ui.lineEdit_28->text()).toInt());
                        }
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsBounds(bounds);
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto property : getSpecification()->getClaim()->getProperties())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::Bounds* bounds = new IDS::Bounds();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            bounds->setStrBase();
                            break;
                        case 1:
                            bounds->setIntBase();
                            break;
                        case 2:
                            bounds->setRealBase();
                            break;
                        default:
                            break;
                        }
                        if (ui.comboBox_44->currentIndex() == 0) {
                            bounds->setMinInclusive((ui.lineEdit_27->text()).toInt());
                        }
                        else {
                            bounds->setMinExclusive((ui.lineEdit_27->text()).toInt());
                        }

                        if (ui.comboBox_45->currentIndex() == 0) {
                            bounds->setMaxInclusive((ui.lineEdit_28->text()).toInt());
                        }
                        else {
                            bounds->setMaxExclusive((ui.lineEdit_28->text()).toInt());
                        }
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsBounds(bounds);
                        break;
                    }
                }
            }
        }
        break;
    case 4:
        if (ui.lineEditPropValueFixed->text() != "" || ui.lineEditLengthMin_7->text() != "") {
            if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
                for (auto property : getSpecification()->getPredicate()->getProperties())
                {
                    if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::Length* length = new IDS::Length();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            length->setStrBase();
                            break;
                        case 1:
                            length->setIntBase();
                            break;
                        case 2:
                            length->setRealBase();
                            break;
                        default:
                            break;
                        }
                        if (ui.comboBox_12->currentIndex() == 0) {
                            length->setIsFixed(true);
                            length->setFixLength((ui.lineEditPropValueFixed->text()).toInt());
                        }
                        else {
                            length->setIsFixed(false);
                            length->setMinLength((ui.lineEditLengthMin_7->text()).toInt());
                            length->setMaxLength((ui.lineEditLengthMax_7->text()).toInt());
                        }
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsLength(length);
                        break;
                    }
                }
            }
            else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
                for (auto property : getSpecification()->getClaim()->getProperties())
                {
                    if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(property)->getTableWidgetItem()) {
                        dynamic_cast<IDS::PropertyPredicate*>(property)->createDomainIfNeed();
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->clear();
                        IDS::Length* length = new IDS::Length();
                        switch (ui.comboBoxDataTypeProperty->currentIndex())
                        {
                        case 0:
                            length->setStrBase();
                            break;
                        case 1:
                            length->setIntBase();
                            break;
                        case 2:
                            length->setRealBase();
                            break;
                        default:
                            break;
                        }
                        if (ui.comboBox_12->currentIndex() == 0) {
                            length->setIsFixed(true);
                            length->setFixLength((ui.lineEditPropValueFixed->text()).toInt());
                        }
                        else {
                            length->setIsFixed(false);
                            length->setMinLength((ui.lineEditLengthMin_7->text()).toInt());
                            length->setMaxLength((ui.lineEditLengthMax_7->text()).toInt());
                        }
                        dynamic_cast<IDS::PropertyPredicate*>(property)->getDomain()->setIdsLength(length);
                        break;
                    }
                }
            }
        }
        break;
    default:
        break;
    }

    if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
        for (auto attribute : getSpecification()->getPredicate()->getProperties())
        {
            if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(attribute)->getTableWidgetItem()) {
                dynamic_cast<IDS::PropertyPredicate*>(attribute)->setDataType((ui.comboBox_18->currentText()).toStdString());
                break;
            }
        }
    }
    else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
        for (auto attribute : getSpecification()->getClaim()->getProperties())
        {
            if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::PropertyPredicate*>(attribute)->getTableWidgetItem()) {
                dynamic_cast<IDS::PropertyPredicate*>(attribute)->setDataType((ui.comboBox_18->currentText()).toStdString());
                break;
            }
        }
    }
}

void IDSdialog::on_pushButtonSavePartOf_clicked(void)
{
    if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
        for (auto relation : getSpecification()->getPredicate()->getRelations())
        {
            if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                if (ui.comboBox_47->currentText() == "communications IFCRELAGGREGATES")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELAGGREGATES);
                } else if (ui.comboBox_47->currentText() == "communications IFCRELASSIGNSTOGROUP")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELASSIGNSTOGROUP);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELCONTAINEDINSPATIALSTRUCTURE")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELCONTAINEDINSPATIALSTRUCTURE);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELNESTS")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELNESTS);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELVOIDSELEMENT")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELVOIDSELEMENT);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELFILLSELEMENT")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELFILLSELEMENT);
                }
                break;
            }
        }
    }
    else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
        for (auto relation : getSpecification()->getClaim()->getRelations())
        {
            if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                if (ui.comboBox_47->currentText() == "communications IFCRELAGGREGATES")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELAGGREGATES);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELASSIGNSTOGROUP")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELASSIGNSTOGROUP);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELCONTAINEDINSPATIALSTRUCTURE")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELCONTAINEDINSPATIALSTRUCTURE);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELNESTS")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELNESTS);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELVOIDSELEMENT")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELVOIDSELEMENT);
                }
                else if (ui.comboBox_47->currentText() == "communications IFCRELFILLSELEMENT")
                {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->setRelation(IDS::RelationEnum::IDSRELATIONENUM_IFCRELFILLSELEMENT);
                }
                break;
            }
        }
    }

    switch (ui.comboBox_48->currentIndex())
    {
    case 0:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto relation : getSpecification()->getPredicate()->getRelations())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createNameIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_9->text()).toStdString());
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->getValue()->getStr();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto relation : getSpecification()->getClaim()->getRelations())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createNameIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_9->text()).toStdString());
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->getValue()->getStr();
                    break;
                }
            }
        }
        break;
    case 1:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto relation : getSpecification()->getPredicate()->getRelations())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createNameIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetPartOfRelation->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetPartOfRelation->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto relation : getSpecification()->getClaim()->getRelations())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createNameIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetPartOfRelation->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetPartOfRelation->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        break;
    case 2:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto relation : getSpecification()->getPredicate()->getRelations())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createNameIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternPartOfRelation->text()).toStdString());
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto relation : getSpecification()->getClaim()->getRelations())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createNameIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternPartOfRelation->text()).toStdString());
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        break;
    case 3:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto relation : getSpecification()->getPredicate()->getRelations())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createNameIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_11->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditPartOfRelationFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_13->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_13->text()).toInt());
                    }
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->setIdsLength(length);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto relation : getSpecification()->getClaim()->getRelations())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createNameIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_11->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditPartOfRelationFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_13->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_13->text()).toInt());
                    }
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getName()->setIdsLength(length);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }

    switch (ui.comboBox_49->currentIndex())
    {
    case 0:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto relation : getSpecification()->getPredicate()->getRelations())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createPredefinedIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_4->text()).toStdString());
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->getValue()->getStr();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto relation : getSpecification()->getClaim()->getRelations())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createPredefinedIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->clear();
                    IDS::Value* val = new IDS::Value();
                    val->setIdsString((ui.lineEdit_4->text()).toStdString());
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->setIdsValue(val);
                    qDebug() << dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->getValue()->getStr();
                    break;
                }
            }
        }
        break;
    case 1:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto relation : getSpecification()->getPredicate()->getRelations())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createPredefinedIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetPartOfPredef->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetPartOfPredef->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto relation : getSpecification()->getClaim()->getRelations())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createPredefinedIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->clear();
                    IDS::typeidsenumerationValues* enumerationValues = new IDS::typeidsenumerationValues();
                    IDS::Enumeration* enumer = new IDS::Enumeration();
                    for (int i = 0; i < ui.tableWidgetPartOfPredef->rowCount(); ++i) {
                        IDS::Value* val = new IDS::Value();
                        val->setIdsString((ui.tableWidgetPartOfPredef->item(i, 0)->text()).toStdString());
                        enumerationValues->addElement(val);
                    }
                    enumer->setValues(enumerationValues);
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->setIdsEnumeration(enumer);
                    break;
                }
            }
        }
        break;
    case 2:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto relation : getSpecification()->getPredicate()->getRelations())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createPredefinedIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternPartOfPredef->text()).toStdString());
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto relation : getSpecification()->getClaim()->getRelations())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createPredefinedIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->clear();
                    IDS::Pattern* pattern = new IDS::Pattern();
                    pattern->setRegExp((ui.lineEditPatternPartOfPredef->text()).toStdString());
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->setIdsPattern(pattern);

                    qDebug() << dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->getPattern()->getRegExp();
                    break;
                }
            }
        }
        break;
    case 3:
        if (ui.tabWidget->currentWidget()->objectName() == "tabApplicability") {
            for (auto relation : getSpecification()->getPredicate()->getRelations())
            {
                if (ui.tableWidgetApplicability->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createPredefinedIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_10->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditPartOfPredefFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_12->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_12->text()).toInt());
                    }
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->setIdsLength(length);
                    break;
                }
            }
        }
        else if (ui.tabWidget->currentWidget()->objectName() == "tabRequirement") {
            for (auto relation : getSpecification()->getClaim()->getRelations())
            {
                if (ui.tableWidgetRequirement->selectedItems()[0] == dynamic_cast<IDS::RelationPredicate*>(relation)->getTableWidgetItem()) {
                    dynamic_cast<IDS::RelationPredicate*>(relation)->createEntityIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->createPredefinedIfNeed();
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->clear();
                    IDS::Length* length = new IDS::Length();

                    if (ui.comboBox_10->currentIndex() == 0) {
                        length->setIsFixed(true);
                        length->setFixLength((ui.lineEditPartOfPredefFixed->text()).toInt());
                    }
                    else {
                        length->setIsFixed(false);
                        length->setMinLength((ui.lineEditLengthMin_12->text()).toInt());
                        length->setMaxLength((ui.lineEditLengthMax_12->text()).toInt());
                    }
                    dynamic_cast<IDS::RelationPredicate*>(relation)->getEntityPredicate()->getPredefined()->setIdsLength(length);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}
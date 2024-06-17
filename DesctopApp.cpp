#include "DesctopApp.h"
#include "ui_DesctopApp.h"
#include <qfile.h>
#include <qfiledialog.h>

DesctopApp::DesctopApp(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    showMaximized();
    connect(ui.listWidgetSpecifications, &QListWidget::itemClicked, this, &DesctopApp::activateOptions);
}

DesctopApp::~DesctopApp()
{}

void DesctopApp::goRound(IDS::Value* val) {

    if (!val) {
        qDebug() << "no val" << '\n';
        return;
    }

    //val->getStr();
    //val->getInt();
    //val->getDouble();

}

void DesctopApp::goRound(IDS::Pattern* pattern) {
    if (!pattern) {
        qDebug() << "no pattern" << '\n';
        return;
    }
    //pattern->getRegExp();

}

void DesctopApp::goRound(IDS::Length* length) {
    if (!length) {
        qDebug() << "no length" << '\n';
        return;
    }
    //length->getValue();
    //length->getMinValue();
    //length->getMaxValue();

}

void DesctopApp::goRound(IDS::Bounds* bounds) {
    if (!bounds) {
        qDebug() << "no bounds" << '\n';
        return;
    }
    //bounds->getValue();
    //bounds->getMinValueInc();
    //bounds->getMaxValueInc();
    //bounds->getMinValueExc();
    //bounds->getMaxValueExc();

}

void DesctopApp::goRound(IDS::typeidsenumerationValues* type) {
    if (!type) {
        qDebug() << "no typeidsenumerationValues" << '\n';
        return;
    }
    for (auto a : type->getElements()) {
        goRound(a);
    }
}

void DesctopApp::goRound(IDS::Enumeration* enumeration) {
    if (!enumeration) {
        qDebug() << "no enumeration" << '\n';
        return;
    }
    qDebug() << "Enumeration: ";
    goRound(enumeration->getTypeidsenumerationValues());
}

void DesctopApp::goRound(IDS::ValueDomain* val) {
    qDebug() << "valueDomain1: ";
    if (!val) {
        qDebug() << "no value" << '\n';
        return;
    }
    goRound(val->getValue());

    goRound(val->getPattern());

    goRound(val->getLength());

    goRound(val->getBounds());

    goRound(val->getEnumeration());
    qDebug() << "valueDomain: ";
}

void DesctopApp::goRound(IDS::Predicate* pred) {
    if (!pred) {
        qDebug() << "no Predicate" << '\n';
        return;
    }
    for (auto p : pred->getEntities()) {
        goRound(p);
    }
    for (auto p : pred->getRelations()) {
        goRound(p);
    }
    for (auto p : pred->getClassifications()) {
        goRound(p);
    }
    for (auto p : pred->getAttributes()) {
        goRound(p);
    }
    for (auto p : pred->getProperties()) {
        goRound(p);
    }
    for (auto p : pred->getMaterials()) {
        goRound(p);
    }

    QListWidget* listWidget = ui.listWidgetApplicability;
    QTableWidget* tableWidget = idsDialog.ui.tableWidgetApplicability;

    if (pred->getType() == IDS::Predicate::Type::REQUIREMENT) {
        listWidget = ui.listWidgetRequirements;
        tableWidget = idsDialog.ui.tableWidgetRequirement;
    }

    if (IDS::EntityPredicate* entityPred = dynamic_cast<IDS::EntityPredicate*>(pred)) {
        qDebug() << "EntityPredicate1: ";
        QString tableItemName = "Entity";
        QString strName = "no initialization";
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem(tableItemName);
        tableWidget->setRowCount(tableWidget->rowCount() + 1);
        tableWidget->setItem(tableWidget->rowCount() - 1, 0, newTableWidgetItem);

        if (entityPred->getName()) {
            auto name = entityPred->getName();
            if (name->getValue()) {
                idsDialog.ui.comboBox_20->setCurrentIndex(0);
                switch (name->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = "classes " + QString::fromUtf8(name->getValue()->getStr());
                    idsDialog.ui.comboBox_4->addItem(QString::fromUtf8(name->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = "classes " + QString::number(name->getValue()->getInt());
                    idsDialog.ui.comboBox_4->addItem(QString::number(name->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName = "classes " + QString::number(name->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.comboBox_4->addItem(QString::number(name->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
                idsDialog.ui.comboBox_4->setCurrentIndex(idsDialog.ui.comboBox_4->count() - 1);
            }
            else if (name->getPattern()) {
                idsDialog.ui.comboBox_20->setCurrentIndex(2);
                strName = "regular expression classes " + QString::fromUtf8(name->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternEntityIFCType->setText(QString::fromUtf8(name->getPattern()->getRegExp()));
            }
            else if (name->getLength()) {
                idsDialog.ui.comboBox_20->setCurrentIndex(3);
                if (name->getLength()->getIsFixed()) {
                    strName = "classes with length= " + QString::number(name->getLength()->getValue());
                    idsDialog.ui.comboBox_51->setCurrentIndex(0);
                    idsDialog.ui.lineEditEntityIFCTypeFixed->setText(QString::number(name->getLength()->getValue()));
                }
                else {
                    strName = "classes with minLength= " + QString::number(name->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(name->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_51->setCurrentIndex(1);
                    idsDialog.ui.lineEditLengthMin->setText(QString::number(name->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax->setText(QString::number(name->getLength()->getMaxValue()));
                }
            }
            else if (name->getEnumeration()) {
                idsDialog.ui.comboBox_20->setCurrentIndex(1);
                if (name->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = "classes ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());

                        tableWidgetItem->setText(QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetEntityIFCType->setRowCount(idsDialog.ui.tableWidgetEntityIFCType->rowCount() + 1);
                    idsDialog.ui.tableWidgetEntityIFCType->setItem(idsDialog.ui.tableWidgetEntityIFCType->rowCount() - 1, 0, tableWidgetItem);

                    if (name->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < name->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetEntityIFCType->setRowCount(idsDialog.ui.tableWidgetEntityIFCType->rowCount() + 1);
                            idsDialog.ui.tableWidgetEntityIFCType->setItem(idsDialog.ui.tableWidgetEntityIFCType->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";

                    }
                }
            }
            qDebug() << "EntityPredicateName: ";
            goRound(entityPred->getName());
        }
        if (entityPred->getPredefined()) {
            auto predefined = entityPred->getPredefined();
            if (predefined->getValue()) {
                idsDialog.ui.comboBox_3->setCurrentIndex(0);
                switch (predefined->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = strName + " and types " + QString::fromUtf8(predefined->getValue()->getStr());
                    idsDialog.ui.lineEdit_3->setText(QString::fromUtf8(predefined->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = strName + " and types " + QString::number(predefined->getValue()->getInt());
                    idsDialog.ui.lineEdit_3->setText(QString::number(predefined->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName = strName + " and types " + QString::number(predefined->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.lineEdit_3->setText(QString::number(predefined->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
                //idsDialog.ui.lineEdit_3->setText();
                //idsDialog.ui.comboBox_3->setCurrentIndex(idsDialog.ui.comboBox_3->count() - 1);
            }
            else if (predefined->getPattern()) {
                idsDialog.ui.comboBox_3->setCurrentIndex(2);
                strName = strName + " and types with regular expression " + QString::fromUtf8(predefined->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternEntityPredType->setText(QString::fromUtf8(predefined->getPattern()->getRegExp()));
            }
            else if (predefined->getLength()) {
                idsDialog.ui.comboBox_3->setCurrentIndex(3);
                if (predefined->getLength()->getIsFixed()) {
                    strName = strName + " and types with length= " + QString::number(predefined->getLength()->getValue());
                    idsDialog.ui.comboBox_50->setCurrentIndex(0);
                    idsDialog.ui.lineEditEntityPredTypeFixed->setText(QString::number(predefined->getLength()->getValue()));
                }
                else {
                    strName = strName + " and types with minLength= " + QString::number(predefined->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(predefined->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_50->setCurrentIndex(1);
                    idsDialog.ui.lineEditLengthMin_2->setText(QString::number(predefined->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_2->setText(QString::number(predefined->getLength()->getMaxValue()));
                }
            }
            else if (predefined->getEnumeration()) {
                idsDialog.ui.comboBox_3->setCurrentIndex(1);
                if (predefined->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = strName + " and types ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetEntityPredType->setRowCount(idsDialog.ui.tableWidgetEntityPredType->rowCount() + 1);
                    idsDialog.ui.tableWidgetEntityPredType->setItem(idsDialog.ui.tableWidgetEntityPredType->rowCount() - 1, 0, tableWidgetItem);
                    if (predefined->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < predefined->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetEntityPredType->setRowCount(idsDialog.ui.tableWidgetEntityPredType->rowCount() + 1);
                            idsDialog.ui.tableWidgetEntityPredType->setItem(idsDialog.ui.tableWidgetEntityPredType->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
            qDebug() << "EntityPredicatePredefined: ";
            goRound(entityPred->getPredefined());
        }
        listWidget->addItem(strName);
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem(strName);
        tableWidget->setItem(tableWidget->rowCount() - 1, 1, newTableWidgetItemComment);
        entityPred->setTableWidgetItem(newTableWidgetItemComment);
        qDebug() << "EntityPredicate: ";
    }
    else if (IDS::RelationPredicate* relationPred = dynamic_cast<IDS::RelationPredicate*>(pred)) {
        qDebug() << "RelationPredicate1 ";
        QString tableItemName = "PartOf";
        QString strName = "no initialization";
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem(tableItemName);
        tableWidget->setRowCount(tableWidget->rowCount() + 1);
        tableWidget->setItem(tableWidget->rowCount() - 1, 0, newTableWidgetItem);

        switch (relationPred->getRelEnum())
        {
        case IDS::RelationEnum::IDSRELATIONENUM_IFCRELAGGREGATES:
            strName = "communications IFCRELAGGREGATES";
            break;
        case IDS::RelationEnum::IDSRELATIONENUM_IFCRELASSIGNSTOGROUP:
            strName = "communications IFCRELASSIGNSTOGROUP";
            break;
        case IDS::RelationEnum::IDSRELATIONENUM_IFCRELCONTAINEDINSPATIALSTRUCTURE:
            strName = "communications IFCRELCONTAINEDINSPATIALSTRUCTURE";
            break;
        case IDS::RelationEnum::IDSRELATIONENUM_IFCRELNESTS:
            strName = "communications IFCRELNESTS";
            break;
        case IDS::RelationEnum::IDSRELATIONENUM_IFCRELVOIDSELEMENT:
            strName = "communications IFCRELVOIDSELEMENT";
            break;
        case IDS::RelationEnum::IDSRELATIONENUM_IFCRELFILLSELEMENT:
            strName = "communications IFCRELFILLSELEMENT";
            break;
        default:
            break;
        }

        if (relationPred->getEntityPredicate()->getName()) {
            auto name = relationPred->getEntityPredicate()->getName();
            if (name->getValue()) {
                idsDialog.ui.comboBox_48->setCurrentIndex(0);
                switch (name->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = strName + " with class objects " + QString::fromUtf8(name->getValue()->getStr());
                    idsDialog.ui.lineEdit_9->setText(QString::fromUtf8(name->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = strName + " with class objects " + QString::number(name->getValue()->getInt());
                    idsDialog.ui.lineEdit_9->setText(QString::number(name->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName = strName + " with class objects " + QString::number(name->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.lineEdit_9->setText(QString::number(name->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
            }
            else if (name->getPattern()) {
                idsDialog.ui.comboBox_48->setCurrentIndex(2);


                strName = strName + " with class objects with regular expression " + QString::fromUtf8(name->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternPartOfRelation->setText(QString::fromUtf8(name->getPattern()->getRegExp()));
            }
            else if (name->getLength()) {
                idsDialog.ui.comboBox_48->setCurrentIndex(3);
                if (name->getLength()->getIsFixed()) {
                    strName = strName + " with class objects with length= " + QString::number(name->getLength()->getValue());
                    idsDialog.ui.comboBox_11->setCurrentIndex(0);
                    idsDialog.ui.lineEditPartOfRelationFixed->setText(QString::number(name->getLength()->getValue()));
                }
                else {
                    strName = strName + " with class objects with minLength= " + QString::number(name->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(name->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_11->setCurrentIndex(1);
                    idsDialog.ui.lineEditLengthMin_13->setText(QString::number(name->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_13->setText(QString::number(name->getLength()->getMaxValue()));
                }
            }
            else if (name->getEnumeration()) {
                idsDialog.ui.comboBox_48->setCurrentIndex(1);
                if (name->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = strName + " with class objects ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetPartOfRelation->setRowCount(idsDialog.ui.tableWidgetPartOfRelation->rowCount() + 1);
                    idsDialog.ui.tableWidgetPartOfRelation->setItem(idsDialog.ui.tableWidgetPartOfRelation->rowCount() - 1, 0, tableWidgetItem);
                    if (name->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < name->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetPartOfRelation->setRowCount(idsDialog.ui.tableWidgetPartOfRelation->rowCount() + 1);
                            idsDialog.ui.tableWidgetPartOfRelation->setItem(idsDialog.ui.tableWidgetPartOfRelation->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
            qDebug() << "EntityPredicatePredefined: ";
            goRound(relationPred->getEntityPredicate()->getName());
        }

        if (relationPred->getEntityPredicate()->getPredefined()) {
            auto predefined = relationPred->getEntityPredicate()->getPredefined();
            if (predefined->getValue()) {
                idsDialog.ui.comboBox_49->setCurrentIndex(0);
                switch (predefined->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.lineEdit_4->setText(QString::fromUtf8(predefined->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.lineEdit_4->setText(QString::number(predefined->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.lineEdit_4->setText(QString::number(predefined->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
            }
            else if (predefined->getPattern()) {
                idsDialog.ui.comboBox_49->setCurrentIndex(2);

                idsDialog.ui.lineEditPatternPartOfPredef->setText(QString::fromUtf8(predefined->getPattern()->getRegExp()));
            }
            else if (predefined->getLength()) {
                idsDialog.ui.comboBox_49->setCurrentIndex(3);
                if (predefined->getLength()->getIsFixed()) {

                    idsDialog.ui.comboBox_10->setCurrentIndex(0);
                    idsDialog.ui.lineEditPartOfPredefFixed->setText(QString::number(predefined->getLength()->getValue()));
                }
                else {

                    idsDialog.ui.comboBox_10->setCurrentIndex(1);
                    idsDialog.ui.lineEditLengthMin_12->setText(QString::number(predefined->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_12->setText(QString::number(predefined->getLength()->getMaxValue()));
                }
            }
            else if (predefined->getEnumeration()) {
                idsDialog.ui.comboBox_49->setCurrentIndex(1);
                if (predefined->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = strName + " and types ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetPartOfPredef->setRowCount(idsDialog.ui.tableWidgetPartOfPredef->rowCount() + 1);
                    idsDialog.ui.tableWidgetPartOfPredef->setItem(idsDialog.ui.tableWidgetPartOfPredef->rowCount() - 1, 0, tableWidgetItem);
                    if (predefined->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < predefined->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(predefined->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetPartOfPredef->setRowCount(idsDialog.ui.tableWidgetPartOfPredef->rowCount() + 1);
                            idsDialog.ui.tableWidgetPartOfPredef->setItem(idsDialog.ui.tableWidgetPartOfPredef->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
        }
        listWidget->addItem(strName);
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem(strName);
        tableWidget->setItem(tableWidget->rowCount() - 1, 1, newTableWidgetItemComment);
        relationPred->setTableWidgetItem(newTableWidgetItemComment);
        qDebug() << "RelationPredicate1 ";
    }
    else if (IDS::ClassificationPredicate* classificationPred = dynamic_cast<IDS::ClassificationPredicate*>(pred)) {
        qDebug() << "ClassificationPredicate1 ";
        QString tableItemName = "Classification";
        QString strName = "no initialization";
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem(tableItemName);
        tableWidget->setRowCount(tableWidget->rowCount() + 1);
        tableWidget->setItem(tableWidget->rowCount() - 1, 0, newTableWidgetItem);

        if (classificationPred->getSystem()) {
            auto system = classificationPred->getSystem();
            if (system->getValue()) {
                idsDialog.ui.comboBox_28->setCurrentIndex(0);
                switch (system->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = "classifiers " + QString::fromUtf8(system->getValue()->getStr());
                    idsDialog.ui.lineEdit_24->setText(QString::fromUtf8(system->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = "classifiers " + QString::number(system->getValue()->getInt());
                    idsDialog.ui.lineEdit_24->setText(QString::number(system->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName = "classifiers " + QString::number(system->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.lineEdit_24->setText(QString::number(system->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
            }
            else if (system->getPattern()) {
                idsDialog.ui.comboBox_28->setCurrentIndex(2);
                strName = "classifiers with regular expression " + QString::fromUtf8(system->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternClassSystem->setText(QString::fromUtf8(system->getPattern()->getRegExp()));
            }
            else if (system->getLength()) {
                idsDialog.ui.comboBox_28->setCurrentIndex(3);
                if (system->getLength()->getIsFixed()) {
                    strName = "classifiers with length= " + QString::number(system->getLength()->getValue());
                    idsDialog.ui.comboBox_16->setCurrentIndex(0);
                    idsDialog.ui.lineEditClassSystemFixed->setText(QString::number(system->getLength()->getValue()));
                }
                else {
                    strName = "classifiers with minLength= " + QString::number(system->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(system->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_16->setCurrentIndex(1);
                    idsDialog.ui.lineEditLengthMin_6->setText(QString::number(system->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_6->setText(QString::number(system->getLength()->getMaxValue()));
                }
            }
            else if (system->getEnumeration()) {
                idsDialog.ui.comboBox_28->setCurrentIndex(1);
                if (system->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = "classifiers ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (system->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetClassSystem->setRowCount(idsDialog.ui.tableWidgetClassSystem->rowCount() + 1);
                    idsDialog.ui.tableWidgetClassSystem->setItem(idsDialog.ui.tableWidgetClassSystem->rowCount() - 1, 0, tableWidgetItem);
                    if (system->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        tableWidgetItem = new QTableWidgetItem("");
                        for (int i = 1; i < system->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            switch (system->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(system->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetClassSystem->setRowCount(idsDialog.ui.tableWidgetClassSystem->rowCount() + 1);
                            idsDialog.ui.tableWidgetClassSystem->setItem(idsDialog.ui.tableWidgetClassSystem->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
            goRound(classificationPred->getSystem());
        }
        if (classificationPred->getValue()) {
            auto value = classificationPred->getValue();
            if (value->getValue()) {
                idsDialog.ui.comboBox_34->setCurrentIndex(0);
                switch (value->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = strName + "." + QString::fromUtf8(value->getValue()->getStr());
                    idsDialog.ui.lineEdit_30->setText(QString::fromUtf8(value->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = strName + "." + QString::number(value->getValue()->getInt());
                    idsDialog.ui.lineEdit_30->setText(QString::number(value->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName = strName + "." + QString::number(value->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.lineEdit_30->setText(QString::number(value->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
            }
            else if (value->getPattern()) {
                idsDialog.ui.comboBox_34->setCurrentIndex(2);
                strName = strName + +". with regular expression " + QString::fromUtf8(value->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternClassValue->setText(QString::fromUtf8(value->getPattern()->getRegExp()));
            }
            else if (value->getLength()) {
                idsDialog.ui.comboBox_34->setCurrentIndex(3);
                if (value->getLength()->getIsFixed()) {
                    strName = strName + ". with length= " + QString::number(value->getLength()->getValue());
                    idsDialog.ui.comboBox_15->setCurrentIndex(0);
                    idsDialog.ui.lineEditClassValueFixed->setText(QString::number(value->getLength()->getValue()));
                }
                else {
                    strName = strName + ". with minLength= " + QString::number(value->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(value->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_15->setCurrentIndex(0);
                    idsDialog.ui.lineEditLengthMin_8->setText(QString::number(value->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_8->setText(QString::number(value->getLength()->getMaxValue()));
                }
            }
            else if (value->getEnumeration()) {
                idsDialog.ui.comboBox_34->setCurrentIndex(1);
                if (value->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = strName + ".";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (value->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetClassValue->setRowCount(idsDialog.ui.tableWidgetClassValue->rowCount() + 1);
                    idsDialog.ui.tableWidgetClassValue->setItem(idsDialog.ui.tableWidgetClassValue->rowCount() - 1, 0, tableWidgetItem);
                    if (value->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < value->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (value->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(value->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetClassValue->setRowCount(idsDialog.ui.tableWidgetClassValue->rowCount() + 1);
                            idsDialog.ui.tableWidgetClassValue->setItem(idsDialog.ui.tableWidgetClassValue->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
            goRound(classificationPred->getValue());
        }

        listWidget->addItem(strName);
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem(strName);
        tableWidget->setItem(tableWidget->rowCount() - 1, 1, newTableWidgetItemComment);
        classificationPred->setTableWidgetItem(newTableWidgetItemComment);
        qDebug() << "ClassificationPredicate ";
    }
    else if (IDS::AttributePredicate* attributePred = dynamic_cast<IDS::AttributePredicate*>(pred)) {
        qDebug() << "AttributePredicate1 ";
        QString tableItemName = "Attribute";
        QString strName = "no initialization";
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem(tableItemName);
        tableWidget->setRowCount(tableWidget->rowCount() + 1);
        tableWidget->setItem(tableWidget->rowCount() - 1, 0, newTableWidgetItem);

        if (attributePred->getName()) {
            idsDialog.ui.comboBox_37->setCurrentIndex(0);
            auto name = attributePred->getName();
            if (name->getValue()) {
                switch (name->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = "attributes " + QString::fromUtf8(name->getValue()->getStr()) + " with values";
                    idsDialog.ui.lineEdit_34->setText(QString::fromUtf8(name->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = "attributes " + QString::number(name->getValue()->getInt()) + " with values";
                    idsDialog.ui.lineEdit_34->setText(QString::number(name->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName = "attributes " + QString::number(name->getValue()->getDouble(), 'g', 6) + " with values";
                    idsDialog.ui.lineEdit_34->setText(QString::number(name->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
            }
            else if (name->getPattern()) {
                idsDialog.ui.comboBox_37->setCurrentIndex(2);
                strName = "attributes with regular expression " + QString::fromUtf8(name->getPattern()->getRegExp()) + " with values";
                idsDialog.ui.lineEditPatternAttributeName->setText(QString::fromUtf8(name->getPattern()->getRegExp()));
            }
            else if (name->getLength()) {
                idsDialog.ui.comboBox_37->setCurrentIndex(3);
                if (name->getLength()->getIsFixed()) {
                    strName = "attributes with length= " + QString::number(name->getLength()->getValue()) + " with values";
                    idsDialog.ui.comboBox_24->setCurrentIndex(0);
                    idsDialog.ui.lineEditAttributeNameFixed->setText(QString::number(name->getLength()->getValue()));
                }
                else {
                    strName = "attributes with minLength= " + QString::number(name->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(name->getLength()->getMaxValue()) + " with values";
                    idsDialog.ui.comboBox_24->setCurrentIndex(1);
                    idsDialog.ui.lineEditLengthMin_9->setText(QString::number(name->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_9->setText(QString::number(name->getLength()->getMaxValue()));
                }
            }
            else if (name->getEnumeration()) {
                idsDialog.ui.comboBox_37->setCurrentIndex(1);
                if (name->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = "attributes ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetAttributeName->setRowCount(idsDialog.ui.tableWidgetAttributeName->rowCount() + 1);
                    idsDialog.ui.tableWidgetAttributeName->setItem(idsDialog.ui.tableWidgetAttributeName->rowCount() - 1, 0, tableWidgetItem);
                    if (name->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < name->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetAttributeName->setRowCount(idsDialog.ui.tableWidgetAttributeName->rowCount() + 1);
                            idsDialog.ui.tableWidgetAttributeName->setItem(idsDialog.ui.tableWidgetAttributeName->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                    strName += " with values";
                    listWidget->addItem(strName);
                }
            }
            goRound(attributePred->getName());
        }
        if (attributePred->getDomain()) {
            idsDialog.ui.comboBox_40->setCurrentIndex(0);
            auto domain = attributePred->getDomain();
            if (domain->getValue()) {
                switch (domain->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = strName + " " + QString::fromUtf8(domain->getValue()->getStr());
                    idsDialog.ui.lineEdit_38->setText(QString::fromUtf8(domain->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = strName + " " + QString::number(domain->getValue()->getInt());
                    idsDialog.ui.lineEdit_38->setText(QString::number(domain->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName = strName + " " + QString::number(domain->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.lineEdit_38->setText(QString::number(domain->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }

            }
            else if (domain->getPattern()) {
                idsDialog.ui.comboBox_40->setCurrentIndex(2);
                switch (domain->getPattern()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(0);
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(1);
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(2);
                    break;
                default:
                    break;
                }
                
                strName = strName + " with regular expression " + QString::fromUtf8(domain->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternAttributeValue->setText(QString::fromUtf8(domain->getPattern()->getRegExp()));
            }
            else if (domain->getLength()) {
                idsDialog.ui.comboBox_40->setCurrentIndex(4);
                switch (domain->getLength()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(0);
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(1);
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(2);
                    break;
                default:
                    break;
                }
                if (domain->getLength()->getIsFixed()) {
                    strName = strName + " with length= " + QString::number(domain->getLength()->getValue());
                    idsDialog.ui.comboBox_17->setCurrentIndex(0);
                    idsDialog.ui.lineEditAttributeValueFixed->setText(QString::number(domain->getLength()->getValue()));
                }
                else {
                    strName = strName + " with minLength= " + QString::number(domain->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(domain->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_17->setCurrentIndex(1);
                    idsDialog.ui.lineEditLengthMin_10->setText(QString::number(domain->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_10->setText(QString::number(domain->getLength()->getMaxValue()));
                }
            }
            else if (domain->getBounds()) {
                idsDialog.ui.comboBox_40->setCurrentIndex(3);
                switch (domain->getBounds()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(0);
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(1);
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(2);
                    break;
                default:
                    break;
                }
                strName = strName + " in the interval ";
                if (domain->getBounds()->getMinType() == IDS::Bounds::MinType::MinExclusive) {
                    idsDialog.ui.comboBox_44->setCurrentIndex(1);
                    strName += QString::number(domain->getBounds()->getMinValueExc()) + "< value ";
                    idsDialog.ui.lineEdit_39->setText(QString::number(domain->getBounds()->getMinValueExc()));
                }
                else {
                    idsDialog.ui.comboBox_44->setCurrentIndex(0);
                    strName += QString::number(domain->getBounds()->getMinValueInc()) + "<= value ";
                    idsDialog.ui.lineEdit_39->setText(QString::number(domain->getBounds()->getMinValueInc()));
                }

                if (domain->getBounds()->getMaxType() == IDS::Bounds::MaxType::MaxExclusive) {
                    idsDialog.ui.comboBox_45->setCurrentIndex(1);
                    strName += " <" + QString::number(domain->getBounds()->getMaxValueExc());
                    idsDialog.ui.lineEdit_40->setText(QString::number(domain->getBounds()->getMaxValueExc()));
                }
                else {
                    idsDialog.ui.comboBox_45->setCurrentIndex(0);
                    strName += " <=" + QString::number(domain->getBounds()->getMaxValueInc());
                    idsDialog.ui.lineEdit_40->setText(QString::number(domain->getBounds()->getMaxValueInc()));
                }
            }
            else if (domain->getEnumeration()) {
                idsDialog.ui.comboBox_40->setCurrentIndex(1);
                switch (domain->getEnumeration()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(0);
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(1);
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.comboBoxDataTypeAttribute->setCurrentIndex(2);
                    break;
                default:
                    break;
                }
                if (domain->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = strName + " ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetAttributeValue->setRowCount(idsDialog.ui.tableWidgetAttributeValue->rowCount() + 1);
                    idsDialog.ui.tableWidgetAttributeValue->setItem(idsDialog.ui.tableWidgetAttributeValue->rowCount() - 1, 0, tableWidgetItem);
                    if (domain->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < domain->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetAttributeValue->setRowCount(idsDialog.ui.tableWidgetAttributeValue->rowCount() + 1);
                            idsDialog.ui.tableWidgetAttributeValue->setItem(idsDialog.ui.tableWidgetAttributeValue->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
            goRound(attributePred->getDomain());
        }
        listWidget->addItem(strName);
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem(strName);
        tableWidget->setItem(tableWidget->rowCount() - 1, 1, newTableWidgetItemComment);
        attributePred->setTableWidgetItem(newTableWidgetItemComment);
        qDebug() << "AttributePredicate ";
    }
    else if (IDS::PropertyPredicate* propertyPred = dynamic_cast<IDS::PropertyPredicate*>(pred)) {
        qDebug() << "PropertyPredicate ";
        QString tableItemName = "Property";
        QString strName = "no initialization";
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem(tableItemName);
        tableWidget->setRowCount(tableWidget->rowCount() + 1);
        tableWidget->setItem(tableWidget->rowCount() - 1, 0, newTableWidgetItem);

        if (propertyPred->getPropertySet()) {
            auto name = propertyPred->getPropertySet();
            if (name->getValue()) {
                idsDialog.ui.comboBox_25->setCurrentIndex(0);
                switch (name->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = "properties " + QString::fromUtf8(name->getValue()->getStr());
                    idsDialog.ui.lineEdit_5->setText(QString::fromUtf8(name->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = "properties " + QString::number(name->getValue()->getInt());
                    idsDialog.ui.lineEdit_5->setText(QString::number(name->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName = "properties " + QString::number(name->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.lineEdit_5->setText(QString::number(name->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
            }
            else if (name->getPattern()) {
                idsDialog.ui.comboBox_25->setCurrentIndex(2);
                strName = "properties with regular expression " + QString::fromUtf8(name->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternPropPropertySet->setText(QString::fromUtf8(name->getPattern()->getRegExp()));
            }
            else if (name->getLength()) {
                idsDialog.ui.comboBox_25->setCurrentIndex(3);
                if (name->getLength()->getIsFixed()) {
                    strName = "properties with length= " + QString::number(name->getLength()->getValue());
                    idsDialog.ui.comboBox_14->setCurrentIndex(0);
                    idsDialog.ui.lineEditPropPropertySetFixed->setText(QString::number(name->getLength()->getValue()));
                }
                else {
                    strName = "properties with minLength= " + QString::number(name->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(name->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_14->setCurrentIndex(1);

                    idsDialog.ui.lineEditLengthMin_3->setText(QString::number(name->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_3->setText(QString::number(name->getLength()->getMaxValue()));
                }
            }
            else if (name->getEnumeration()) {
                idsDialog.ui.comboBox_25->setCurrentIndex(1);
                if (name->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = "properties ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetPropPropertySet->setRowCount(idsDialog.ui.tableWidgetPropPropertySet->rowCount() + 1);
                    idsDialog.ui.tableWidgetPropPropertySet->setItem(idsDialog.ui.tableWidgetPropPropertySet->rowCount() - 1, 0, tableWidgetItem);
                    if (name->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < name->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(name->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetPropPropertySet->setRowCount(idsDialog.ui.tableWidgetPropPropertySet->rowCount() + 1);
                            idsDialog.ui.tableWidgetPropPropertySet->setItem(idsDialog.ui.tableWidgetPropPropertySet->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                    listWidget->addItem(strName);
                }
            }
            qDebug() << "EntityPredicateName: ";
            goRound(propertyPred->getName());
        }
        strName += " type " + QString::fromUtf8(propertyPred->getDataType());

        if (propertyPred->getName()) {
            auto propSet = propertyPred->getName();
            if (propSet->getValue()) {
                idsDialog.ui.comboBox_30->setCurrentIndex(0);
                switch (propSet->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName += " in PSET " + QString::fromUtf8(propSet->getValue()->getStr());
                    idsDialog.ui.lineEdit_6->setText(QString::fromUtf8(propSet->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName += " in PSET " + QString::number(propSet->getValue()->getInt());
                    idsDialog.ui.lineEdit_6->setText(QString::number(propSet->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName += " in PSET " + QString::number(propSet->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.lineEdit_6->setText(QString::number(propSet->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }

            }
            else if (propSet->getPattern()) {
                idsDialog.ui.comboBox_30->setCurrentIndex(2);
                strName += " in PSET with regular expression " + QString::fromUtf8(propSet->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternPropType->setText(QString::fromUtf8(propSet->getPattern()->getRegExp()));
            }
            else if (propSet->getLength()) {
                idsDialog.ui.comboBox_30->setCurrentIndex(3);
                if (propSet->getLength()->getIsFixed()) {
                    strName += " in PSET with length= " + QString::number(propSet->getLength()->getValue());
                    idsDialog.ui.comboBox_13->setCurrentIndex(0);
                    idsDialog.ui.lineEditPropTypeFixed->setText(QString::number(propSet->getLength()->getValue()));
                }
                else {
                    strName += " in PSET with minLength= " + QString::number(propSet->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(propSet->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_13->setCurrentIndex(1);

                    idsDialog.ui.lineEditLengthMin_4->setText(QString::number(propSet->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_4->setText(QString::number(propSet->getLength()->getMaxValue()));
                }
            }
            else if (propSet->getEnumeration()) {
                idsDialog.ui.comboBox_30->setCurrentIndex(1);
                if (propSet->getEnumeration()->getTypeidsenumerationValues()) {
                    strName += " in PSET ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetPropType->setRowCount(idsDialog.ui.tableWidgetPropType->rowCount() + 1);
                    idsDialog.ui.tableWidgetPropType->setItem(idsDialog.ui.tableWidgetPropType->rowCount() - 1, 0, tableWidgetItem);
                    if (propSet->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < propSet->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(propSet->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetPropType->setRowCount(idsDialog.ui.tableWidgetPropType->rowCount() + 1);
                            idsDialog.ui.tableWidgetPropType->setItem(idsDialog.ui.tableWidgetPropType->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
            goRound(propertyPred->getPropertySet());
        }
        if (propertyPred->getDomain()) {
            auto domain = propertyPred->getDomain();
            if (domain->getValue()) {
                idsDialog.ui.comboBox_41->setCurrentIndex(0);
                switch (domain->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName += " and value " + QString::fromUtf8(domain->getValue()->getStr());
                    idsDialog.ui.lineEdit_26->setText(QString::fromUtf8(domain->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName += " and value " + QString::number(domain->getValue()->getInt());
                    idsDialog.ui.lineEdit_26->setText(QString::number(domain->getValue()->getInt()));
                    break;
                case IDS::Base::REAL:
                    strName += " and value " + QString::number(domain->getValue()->getDouble(), 'g', 6);
                    idsDialog.ui.lineEdit_26->setText(QString::number(domain->getValue()->getDouble(), 'g', 6));
                    break;
                default:
                    break;
                }
            }
            else if (domain->getPattern()) {
                idsDialog.ui.comboBox_41->setCurrentIndex(2);
                switch (domain->getPattern()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(0);
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(1);
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(2);
                    break;
                default:
                    break;
                }
                strName += " and value with regular expression " + QString::fromUtf8(domain->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternPropValue->setText(QString::fromUtf8(domain->getPattern()->getRegExp()));
            }
            else if (domain->getLength()) {
                idsDialog.ui.comboBox_41->setCurrentIndex(4);
                switch (domain->getLength()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(0);
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(1);
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(2);
                    break;
                default:
                    break;
                }
                if (domain->getLength()->getIsFixed()) {
                    strName += " and value with length= " + QString::number(domain->getLength()->getValue());
                    idsDialog.ui.comboBox_12->setCurrentIndex(0);
                    idsDialog.ui.lineEditPropValueFixed->setText(QString::number(domain->getLength()->getValue()));
                }
                else {
                    strName += " and value with minLength= " + QString::number(domain->getLength()->getMinValue())
                        + " and value and maxLength= " + QString::number(domain->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_12->setCurrentIndex(1);

                    idsDialog.ui.lineEditLengthMin_7->setText(QString::number(domain->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_7->setText(QString::number(domain->getLength()->getMaxValue()));
                }
            }
            else if (domain->getBounds()) {
                idsDialog.ui.comboBox_41->setCurrentIndex(3);
                switch (domain->getBounds()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(0);
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(1);
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(2);
                    break;
                default:
                    break;
                }
                strName += " and value in the interval ";
                if (domain->getBounds()->getMinType() == IDS::Bounds::MinType::MinExclusive) {
                    idsDialog.ui.comboBox_42->setCurrentIndex(1);
                    strName += QString::number(domain->getBounds()->getMinValueExc()) + "< value ";
                    idsDialog.ui.lineEdit_27->setText(QString::number(domain->getBounds()->getMinValueExc()));
                }
                else {
                    idsDialog.ui.comboBox_42->setCurrentIndex(0);
                    strName += QString::number(domain->getBounds()->getMinValueInc()) + "<= value ";
                    idsDialog.ui.lineEdit_27->setText(QString::number(domain->getBounds()->getMinValueInc()));
                }

                if (domain->getBounds()->getMaxType() == IDS::Bounds::MaxType::MaxExclusive) {
                    idsDialog.ui.comboBox_43->setCurrentIndex(1);
                    strName += " <" + QString::number(domain->getBounds()->getMaxValueExc());
                    idsDialog.ui.lineEdit_28->setText(QString::number(domain->getBounds()->getMaxValueExc()));
                }
                else {
                    idsDialog.ui.comboBox_43->setCurrentIndex(0);
                    strName += " <=" + QString::number(domain->getBounds()->getMaxValueInc());
                    idsDialog.ui.lineEdit_28->setText(QString::number(domain->getBounds()->getMaxValueInc()));
                }

            }
            else if (domain->getEnumeration()) {
                idsDialog.ui.comboBox_41->setCurrentIndex(1);
                switch (domain->getEnumeration()->getBase())
                {
                case IDS::Base::STRING:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(0);
                    break;
                case IDS::Base::INTEGER:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(1);
                    break;
                case IDS::Base::REAL:
                    idsDialog.ui.comboBoxDataTypeProperty->setCurrentIndex(2);
                    break;
                default:
                    break;
                }
                if (domain->getEnumeration()->getTypeidsenumerationValues()) {
                    strName += " and value ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetPropValue->setRowCount(idsDialog.ui.tableWidgetPropValue->rowCount() + 1);
                    idsDialog.ui.tableWidgetPropValue->setItem(idsDialog.ui.tableWidgetPropValue->rowCount() - 1, 0, tableWidgetItem);
                    if (domain->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        tableWidgetItem = new QTableWidgetItem("");
                        for (int i = 1; i < domain->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            switch (domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetPropValue->setRowCount(idsDialog.ui.tableWidgetPropValue->rowCount() + 1);
                            idsDialog.ui.tableWidgetPropValue->setItem(idsDialog.ui.tableWidgetPropValue->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
            goRound(propertyPred->getDomain());
        }
        idsDialog.ui.comboBox_18->addItem(QString::fromUtf8(propertyPred->getDataType()));
        idsDialog.ui.comboBox_18->setCurrentIndex(idsDialog.ui.comboBox_18->count() - 1);
        listWidget->addItem(strName);
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem(strName);
        tableWidget->setItem(tableWidget->rowCount() - 1, 1, newTableWidgetItemComment);
        propertyPred->setTableWidgetItem(newTableWidgetItemComment);
        qDebug() << "PropertyPredicate1 ";
    }
    else if (IDS::MaterialPredicate* materialPred = dynamic_cast<IDS::MaterialPredicate*>(pred)) {
        qDebug() << "MaterialPredicate1 ";
        QString tableItemName = "Material";
        QString strName = "no initialization";
        QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem(tableItemName);
        tableWidget->setRowCount(tableWidget->rowCount() + 1);
        tableWidget->setItem(tableWidget->rowCount() - 1, 0, newTableWidgetItem);

        if (materialPred->getDomain()) {
            auto domain = materialPred->getDomain();
            if (domain->getValue()) {
                idsDialog.ui.comboBox_46->setCurrentIndex(0);
                switch (domain->getValue()->getBase())
                {
                case IDS::Base::STRING:
                    strName = "materials " + QString::fromUtf8(domain->getValue()->getStr());
                    idsDialog.ui.comboBox_19->setCurrentIndex(idsDialog.ui.comboBox_19->findText(QString::fromUtf8(domain->getValue()->getStr())));
                    //idsDialog.ui.lineEdit_26->setText(QString::fromUtf8(domain->getValue()->getStr()));
                    break;
                case IDS::Base::INTEGER:
                    strName = "materials " + QString::number(domain->getValue()->getInt());
                    break;
                case IDS::Base::REAL:
                    strName = "materials " + QString::number(domain->getValue()->getDouble(), 'g', 6);
                    break;
                default:
                    break;
                }
            }
            else if (domain->getPattern()) {
                idsDialog.ui.comboBox_46->setCurrentIndex(2);
                strName = "materials with regular expression " + QString::fromUtf8(domain->getPattern()->getRegExp());
                idsDialog.ui.lineEditPatternMaterialValue->setText(QString::fromUtf8(domain->getPattern()->getRegExp()));
            }
            else if (domain->getLength()) {
                idsDialog.ui.comboBox_46->setCurrentIndex(3);
                if (domain->getLength()->getIsFixed()) {
                    strName = "materials with length= " + QString::number(domain->getLength()->getValue());
                    idsDialog.ui.comboBox_6->setCurrentIndex(0);
                    idsDialog.ui.lineEditMaterialFixed->setText(QString::number(domain->getLength()->getValue()));
                }
                else {
                    strName = "materials with minLength= " + QString::number(domain->getLength()->getMinValue())
                        + " and maxLength= " + QString::number(domain->getLength()->getMaxValue());
                    idsDialog.ui.comboBox_6->setCurrentIndex(1);

                    idsDialog.ui.lineEditLengthMin_11->setText(QString::number(domain->getLength()->getMinValue()));
                    idsDialog.ui.lineEditLengthMax_11->setText(QString::number(domain->getLength()->getMaxValue()));
                }
            }
            else if (domain->getEnumeration()) {
                idsDialog.ui.comboBox_46->setCurrentIndex(1);
                if (domain->getEnumeration()->getTypeidsenumerationValues()) {
                    strName = "materials ";
                    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem("");
                    switch (domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getBase())
                    {
                    case IDS::Base::STRING:
                        strName += QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr());
                        tableWidgetItem->setText(QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getStr()));
                        break;
                    case IDS::Base::INTEGER:
                        strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt());
                        tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getInt()));
                        break;
                    case IDS::Base::REAL:
                        strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6);
                        tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[0]->getDouble(), 'g', 6));
                        break;
                    default:
                        break;
                    }
                    idsDialog.ui.tableWidgetMaterialValue->setRowCount(idsDialog.ui.tableWidgetMaterialValue->rowCount() + 1);
                    idsDialog.ui.tableWidgetMaterialValue->setItem(idsDialog.ui.tableWidgetMaterialValue->rowCount() - 1, 0, tableWidgetItem);
                    if (domain->getEnumeration()->getTypeidsenumerationValues()->getElements().size() > 1) {
                        strName += " (";
                        for (int i = 1; i < domain->getEnumeration()->getTypeidsenumerationValues()->getElements().size(); ++i) {
                            strName += " or ";
                            tableWidgetItem = new QTableWidgetItem("");
                            switch (domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getBase())
                            {
                            case IDS::Base::STRING:
                                strName += QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr());
                                tableWidgetItem->setText(QString::fromUtf8(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getStr()));
                                break;
                            case IDS::Base::INTEGER:
                                strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt());
                                tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getInt()));
                                break;
                            case IDS::Base::REAL:
                                strName += QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6);
                                tableWidgetItem->setText(QString::number(domain->getEnumeration()->getTypeidsenumerationValues()->getElements()[i]->getDouble(), 'g', 6));
                                break;
                            default:
                                break;
                            }
                            idsDialog.ui.tableWidgetMaterialValue->setRowCount(idsDialog.ui.tableWidgetMaterialValue->rowCount() + 1);
                            idsDialog.ui.tableWidgetMaterialValue->setItem(idsDialog.ui.tableWidgetMaterialValue->rowCount() - 1, 0, tableWidgetItem);
                        }
                        strName += ")";
                    }
                }
            }
            qDebug() << "EntityPredicateName: ";
            goRound(materialPred->getDomain());
        }
        listWidget->addItem(strName);
        QTableWidgetItem* newTableWidgetItemComment = new QTableWidgetItem(strName);
        tableWidget->setItem(tableWidget->rowCount() - 1, 1, newTableWidgetItemComment);
        materialPred->setTableWidgetItem(newTableWidgetItemComment);
        qDebug() << "MaterialPredicate ";
    }
}

void DesctopApp::goRound(IDS::Specification* spec) {
    if (!spec) {
        qDebug() << "no Specification" << '\n';
        return;
    }
    //qDebug() << spec->getName() << '\n';
    if (spec->getInstruction())
        qDebug() << spec->getInstruction()->getName() << '\n';
    if (spec->getDescription())
        qDebug() << spec->getDescription()->getName() << '\n';
    if (spec->getIdentifier())
        qDebug() << spec->getIdentifier()->getName();

    ui.labelSpecification->setText(QString::fromUtf8(spec->getName()));
    ui.labelIFCversionText->setText(QString::fromUtf8(spec->getShema()->getElements()[0]));

    goRound(spec->getPredicate());
    goRound(spec->getClaim());
}



void DesctopApp::convert(IDS::Specification* spec) {
    ui.listWidgetApplicability->clear();
    ui.listWidgetRequirements->clear();
    idsDialog.ui.tableWidgetApplicability->clear();
    idsDialog.ui.tableWidgetRequirement->clear();
    idsDialog.ui.tableWidgetApplicability->setRowCount(0);
    idsDialog.ui.tableWidgetRequirement->setRowCount(0);
    idsDialog.setSpecification(spec);
    goRound(spec);
}

void DesctopApp::on_fileButton_clicked() {
    QDir dir(QDir::currentPath());
    QString fileName = QFileDialog::getOpenFileName(this, "choose File", QDir::currentPath(), "*.ids");
    fileName = dir.relativeFilePath(fileName);
    ui.lineEditFileName->setText(fileName);

    claerSpecification();
    ui.listWidgetSpecifications->clear();
    auto specifications = imp.Import(fileName);
    for (auto spec : specifications) {
        addSpecification(spec);
        ui.listWidgetSpecifications->addItem(QString::fromUtf8(spec->getName()));
    }
}

void DesctopApp::writeInfo(QXmlStreamWriter& xmlWriter) {
    xmlWriter.writeStartElement("info");
    xmlWriter.writeTextElement("title", ui.lineEditTitle->text());
    xmlWriter.writeTextElement("copyright", "buildingSMART International Ltd");
    xmlWriter.writeTextElement("date", ui.lineEditDate->text());
    xmlWriter.writeEndElement();
}

void DesctopApp::writeEntity(QXmlStreamWriter& xmlWriter, IDS::EntityPredicate* entity) {
    xmlWriter.writeStartElement("entity");
    xmlWriter.writeStartElement("name");
    if (entity->getName()->getValue()) {
        xmlWriter.writeTextElement("simpleValue", entity->getName()->getValue()->getStr());
    }
    else if (entity->getName()->getEnumeration()) {
        xmlWriter.writeStartElement("xs:restriction");

        xmlWriter.writeAttribute("base", "xs:string");
        for (auto val : entity->getName()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
            xmlWriter.writeEmptyElement("xs:enumeration");
            xmlWriter.writeAttribute("value", val->getStr());
        }
        xmlWriter.writeEndElement();
    }
    else if (entity->getName()->getPattern()) {
        xmlWriter.writeStartElement("xs:restriction");
        xmlWriter.writeEmptyElement("xs:pattern");
        xmlWriter.writeAttribute("value", entity->getName()->getPattern()->getRegExp());
        xmlWriter.writeEndElement();
    }
    else if (entity->getName()->getLength()) {
        xmlWriter.writeStartElement("xs:restriction");
        if (entity->getName()->getLength()->getIsFixed()) {
            xmlWriter.writeEmptyElement("xs:length");
            xmlWriter.writeAttribute("value", std::to_string(entity->getName()->getLength()->getValue()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minLength");
            xmlWriter.writeAttribute("value", std::to_string(entity->getName()->getLength()->getMinValue()));
            xmlWriter.writeEmptyElement("xs:maxLength");
            xmlWriter.writeAttribute("value", std::to_string(entity->getName()->getLength()->getMaxValue()));
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();

    if (entity->getPredefined()) {
        xmlWriter.writeStartElement("predefinedType");
        if (entity->getPredefined()->getValue()) {
            xmlWriter.writeTextElement("simpleValue", entity->getPredefined()->getValue()->getStr());
        }
        else if (entity->getPredefined()->getEnumeration()) {
            xmlWriter.writeStartElement("xs:restriction");

            xmlWriter.writeAttribute("base", "xs:string");
            for (auto val : entity->getPredefined()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
                xmlWriter.writeEmptyElement("xs:enumeration");
                xmlWriter.writeAttribute("value", val->getStr());
            }
            xmlWriter.writeEndElement();
        }
        else if (entity->getPredefined()->getPattern()) {
            xmlWriter.writeStartElement("xs:restriction");
            xmlWriter.writeEmptyElement("xs:pattern");
            xmlWriter.writeAttribute("value", entity->getPredefined()->getPattern()->getRegExp());
            xmlWriter.writeEndElement();
        }
        else if (entity->getPredefined()->getLength()) {
            xmlWriter.writeStartElement("xs:restriction");
            if (entity->getPredefined()->getLength()->getIsFixed()) {
                xmlWriter.writeEmptyElement("xs:length");
                xmlWriter.writeAttribute("value", std::to_string(entity->getPredefined()->getLength()->getValue()));
            }
            else {
                xmlWriter.writeEmptyElement("xs:minLength");
                xmlWriter.writeAttribute("value", std::to_string(entity->getPredefined()->getLength()->getMinValue()));
                xmlWriter.writeEmptyElement("xs:maxLength");
                xmlWriter.writeAttribute("value", std::to_string(entity->getPredefined()->getLength()->getMaxValue()));
            }
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
}

void DesctopApp::writePartOf(QXmlStreamWriter& xmlWriter, IDS::RelationPredicate* partOf) {
    xmlWriter.writeStartElement("partOf");
    switch (partOf->getRelEnum())
    {
    case IDS::RelationEnum::IDSRELATIONENUM_LAST:
        xmlWriter.writeAttribute("relation", "LAST");
        break;
    case IDS::RelationEnum::IDSRELATIONENUM_IFCRELAGGREGATES:
        xmlWriter.writeAttribute("relation", "IFCRELAGGREGATES");
        break;
    case IDS::RelationEnum::IDSRELATIONENUM_IFCRELASSIGNSTOGROUP:
        xmlWriter.writeAttribute("relation", "IFCRELASSIGNSTOGROUP");
        break;
    case IDS::RelationEnum::IDSRELATIONENUM_IFCRELCONTAINEDINSPATIALSTRUCTURE:
        xmlWriter.writeAttribute("relation", "IFCRELCONTAINEDINSPATIALSTRUCTURE");
        break;
    case IDS::RelationEnum::IDSRELATIONENUM_IFCRELNESTS:
        xmlWriter.writeAttribute("relation", "IFCRELNESTS");
        break;
    case IDS::RelationEnum::IDSRELATIONENUM_IFCRELVOIDSELEMENT:
        xmlWriter.writeAttribute("relation", "IFCRELVOIDSELEMENT");
        break;
    case IDS::RelationEnum::IDSRELATIONENUM_IFCRELFILLSELEMENT:
        xmlWriter.writeAttribute("relation", "IFCRELFILLSELEMENT");
        break;
    default:
        break;
    }
    
    writeEntity(xmlWriter, partOf->getEntityPredicate());
    xmlWriter.writeEndElement();
}

void DesctopApp::writeClassification(QXmlStreamWriter& xmlWriter, IDS::ClassificationPredicate* classification) {
    xmlWriter.writeStartElement("classification");
    xmlWriter.writeStartElement("value");
    if (classification->getValue()->getValue()) {
        xmlWriter.writeTextElement("simpleValue", classification->getValue()->getValue()->getStr());
    }
    else if (classification->getValue()->getEnumeration()) {
        xmlWriter.writeStartElement("xs:restriction");

        xmlWriter.writeAttribute("base", "xs:string");
        for (auto val : classification->getValue()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
            xmlWriter.writeEmptyElement("xs:enumeration");
            xmlWriter.writeAttribute("value", val->getStr());
        }
        xmlWriter.writeEndElement();
    }
    else if (classification->getValue()->getPattern()) {
        xmlWriter.writeStartElement("xs:restriction");
        xmlWriter.writeEmptyElement("xs:pattern");
        xmlWriter.writeAttribute("value", classification->getValue()->getPattern()->getRegExp());
        xmlWriter.writeEndElement();
    }
    else if (classification->getValue()->getLength()) {
        xmlWriter.writeStartElement("xs:restriction");
        if (classification->getValue()->getLength()->getIsFixed()) {
            xmlWriter.writeEmptyElement("xs:length");
            xmlWriter.writeAttribute("value", std::to_string(classification->getValue()->getLength()->getValue()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minLength");
            xmlWriter.writeAttribute("value", std::to_string(classification->getValue()->getLength()->getMinValue()));
            xmlWriter.writeEmptyElement("xs:maxLength");
            xmlWriter.writeAttribute("value", std::to_string(classification->getValue()->getLength()->getMaxValue()));
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    
    xmlWriter.writeStartElement("system");
    if (classification->getSystem()->getValue()) {
        xmlWriter.writeTextElement("simpleValue", classification->getSystem()->getValue()->getStr());
    }
    else if (classification->getSystem()->getEnumeration()) {
        xmlWriter.writeStartElement("xs:restriction");

        xmlWriter.writeAttribute("base", "xs:string");
        for (auto val : classification->getSystem()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
            xmlWriter.writeEmptyElement("xs:enumeration");
            xmlWriter.writeAttribute("value", val->getStr());
        }
        xmlWriter.writeEndElement();
    }
    else if (classification->getSystem()->getPattern()) {
        xmlWriter.writeStartElement("xs:restriction");
        xmlWriter.writeEmptyElement("xs:pattern");
        xmlWriter.writeAttribute("value", classification->getSystem()->getPattern()->getRegExp());
        xmlWriter.writeEndElement();
    }
    else if (classification->getSystem()->getLength()) {
        xmlWriter.writeStartElement("xs:restriction");
        if (classification->getSystem()->getLength()->getIsFixed()) {
            xmlWriter.writeEmptyElement("xs:length");
            xmlWriter.writeAttribute("value", std::to_string(classification->getSystem()->getLength()->getValue()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minLength");
            xmlWriter.writeAttribute("value", std::to_string(classification->getSystem()->getLength()->getMinValue()));
            xmlWriter.writeEmptyElement("xs:maxLength");
            xmlWriter.writeAttribute("value", std::to_string(classification->getSystem()->getLength()->getMaxValue()));
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}

void DesctopApp::writeAttribute(QXmlStreamWriter& xmlWriter, IDS::AttributePredicate* attribute) {
    xmlWriter.writeStartElement("attribute");
    xmlWriter.writeStartElement("name");

    if (attribute->getName()->getValue()) {
        xmlWriter.writeTextElement("simpleValue", attribute->getName()->getValue()->getStr());
    }
    else if (attribute->getName()->getEnumeration()) {
        xmlWriter.writeStartElement("xs:restriction");

        xmlWriter.writeAttribute("base", "xs:string");
        for (auto val : attribute->getName()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
            xmlWriter.writeEmptyElement("xs:enumeration");
            xmlWriter.writeAttribute("value", val->getStr());
        }
        xmlWriter.writeEndElement();
    }
    else if (attribute->getName()->getPattern()) {
        xmlWriter.writeStartElement("xs:restriction");
        xmlWriter.writeEmptyElement("xs:pattern");
        xmlWriter.writeAttribute("value", attribute->getName()->getPattern()->getRegExp());
        xmlWriter.writeEndElement();
    }
    else if (attribute->getName()->getLength()) {
        xmlWriter.writeStartElement("xs:restriction");
        if (attribute->getName()->getLength()->getIsFixed()) {
            xmlWriter.writeEmptyElement("xs:length");
            xmlWriter.writeAttribute("value", std::to_string(attribute->getName()->getLength()->getValue()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minLength");
            xmlWriter.writeAttribute("value", std::to_string(attribute->getName()->getLength()->getMinValue()));
            xmlWriter.writeEmptyElement("xs:maxLength");
            xmlWriter.writeAttribute("value", std::to_string(attribute->getName()->getLength()->getMaxValue()));
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("value");
    if (attribute->getDomain()) {
        if (attribute->getDomain()->getValue()) {
            xmlWriter.writeTextElement("simpleValue", attribute->getDomain()->getValue()->getStr());
        }
        else if (attribute->getDomain()->getEnumeration()) {
            xmlWriter.writeStartElement("xs:restriction");
            switch (attribute->getDomain()->getEnumeration()->getBase())
            {
            case IDS::Base::STRING:
                xmlWriter.writeAttribute("base", "xs:string");
                break;
            case IDS::Base::INTEGER:
                xmlWriter.writeAttribute("base", "xs:integer");
                break;
            case IDS::Base::REAL:
                xmlWriter.writeAttribute("base", "xs:decimal");
                break;
            default:
                break;
            }

            for (auto val : attribute->getDomain()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
                xmlWriter.writeEmptyElement("xs:enumeration");
                xmlWriter.writeAttribute("value", val->getStr());
            }
            xmlWriter.writeEndElement();
        }
        else if (attribute->getDomain()->getPattern()) {
            xmlWriter.writeStartElement("xs:restriction");
            switch (attribute->getDomain()->getPattern()->getBase())
            {
            case IDS::Base::STRING:
                xmlWriter.writeAttribute("base", "xs:string");
                break;
            case IDS::Base::INTEGER:
                xmlWriter.writeAttribute("base", "xs:integer");
                break;
            case IDS::Base::REAL:
                xmlWriter.writeAttribute("base", "xs:decimal");
                break;
            default:
                break;
            }
            xmlWriter.writeEmptyElement("xs:pattern");
            xmlWriter.writeAttribute("value", attribute->getDomain()->getPattern()->getRegExp());
            xmlWriter.writeEndElement();
        }
        else if (attribute->getDomain()->getLength()) {
            xmlWriter.writeStartElement("xs:restriction");
            switch (attribute->getDomain()->getLength()->getBase())
            {
            case IDS::Base::STRING:
                xmlWriter.writeAttribute("base", "xs:string");
                break;
            case IDS::Base::INTEGER:
                xmlWriter.writeAttribute("base", "xs:integer");
                break;
            case IDS::Base::REAL:
                xmlWriter.writeAttribute("base", "xs:decimal");
                break;
            default:
                break;
            }
            if (attribute->getDomain()->getLength()->getIsFixed()) {
                xmlWriter.writeEmptyElement("xs:length");
                xmlWriter.writeAttribute("value", std::to_string(attribute->getDomain()->getLength()->getValue()));
            }
            else {
                xmlWriter.writeEmptyElement("xs:minLength");
                xmlWriter.writeAttribute("value", std::to_string(attribute->getDomain()->getLength()->getMinValue()));
                xmlWriter.writeEmptyElement("xs:maxLength");
                xmlWriter.writeAttribute("value", std::to_string(attribute->getDomain()->getLength()->getMaxValue()));
            }
            xmlWriter.writeEndElement();
        }
        else if (attribute->getDomain()->getBounds()) {
            xmlWriter.writeStartElement("xs:restriction");
            switch (attribute->getDomain()->getBounds()->getBase())
            {
            case IDS::Base::STRING:
                xmlWriter.writeAttribute("base", "xs:string");
                break;
            case IDS::Base::INTEGER:
                xmlWriter.writeAttribute("base", "xs:integer");
                break;
            case IDS::Base::REAL:
                xmlWriter.writeAttribute("base", "xs:decimal");
                break;
            default:
                break;
            }
            switch (attribute->getDomain()->getValue()->getBase())
            {
            case IDS::Base::STRING:
                xmlWriter.writeAttribute("base", "xs:string");
                break;
            case IDS::Base::INTEGER:
                xmlWriter.writeAttribute("base", "xs:integer");
                break;
            case IDS::Base::REAL:
                xmlWriter.writeAttribute("base", "xs:decimal");
                break;
            default:
                break;
            }
            if (attribute->getDomain()->getBounds()->getMinType() == IDS::Bounds::MinInclusive) {
                xmlWriter.writeEmptyElement("xs:minInclusive");
                xmlWriter.writeAttribute("value", std::to_string(attribute->getDomain()->getBounds()->getMinValueInc()));
            }
            else {
                xmlWriter.writeEmptyElement("xs:minExclusive");
                xmlWriter.writeAttribute("value", std::to_string(attribute->getDomain()->getBounds()->getMinValueExc()));
            }
            if (attribute->getDomain()->getBounds()->getMaxType() == IDS::Bounds::MaxInclusive) {
                xmlWriter.writeEmptyElement("xs:maxInclusive");
                xmlWriter.writeAttribute("value", std::to_string(attribute->getDomain()->getBounds()->getMaxValueInc()));
            }
            else {
                xmlWriter.writeEmptyElement("xs:maxExclusive");
                xmlWriter.writeAttribute("value", std::to_string(attribute->getDomain()->getBounds()->getMaxValueExc()));
            }
            xmlWriter.writeEndElement();
        }
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}

void DesctopApp::writeProperty(QXmlStreamWriter& xmlWriter, IDS::PropertyPredicate* property) {
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("datatype", property->getDataType());
    xmlWriter.writeStartElement("propertySet");
    if (property->getPropertySet()->getValue()) {
        xmlWriter.writeTextElement("simpleValue", property->getPropertySet()->getValue()->getStr());
    }
    else if (property->getPropertySet()->getEnumeration()) {
        xmlWriter.writeStartElement("xs:restriction");

        xmlWriter.writeAttribute("base", "xs:string");
        for (auto val : property->getPropertySet()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
            xmlWriter.writeEmptyElement("xs:enumeration");
            xmlWriter.writeAttribute("value", val->getStr());
        }
        xmlWriter.writeEndElement();
    }
    else if (property->getPropertySet()->getPattern()) {
        xmlWriter.writeStartElement("xs:restriction");
        xmlWriter.writeEmptyElement("xs:pattern");
        xmlWriter.writeAttribute("value", property->getPropertySet()->getPattern()->getRegExp());
        xmlWriter.writeEndElement();
    }
    else if (property->getPropertySet()->getLength()) {
        xmlWriter.writeStartElement("xs:restriction");
        if (property->getPropertySet()->getLength()->getIsFixed()) {
            xmlWriter.writeEmptyElement("xs:length");
            xmlWriter.writeAttribute("value", std::to_string(property->getPropertySet()->getLength()->getValue()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minLength");
            xmlWriter.writeAttribute("value", std::to_string(property->getPropertySet()->getLength()->getMinValue()));
            xmlWriter.writeEmptyElement("xs:maxLength");
            xmlWriter.writeAttribute("value", std::to_string(property->getPropertySet()->getLength()->getMaxValue()));
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("name");
    if (property->getName()->getValue()) {
        xmlWriter.writeTextElement("simpleValue", property->getName()->getValue()->getStr());
    }
    else if (property->getName()->getEnumeration()) {
        xmlWriter.writeStartElement("xs:restriction");

        xmlWriter.writeAttribute("base", "xs:string");
        for (auto val : property->getName()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
            xmlWriter.writeEmptyElement("xs:enumeration");
            xmlWriter.writeAttribute("value", val->getStr());
        }
        xmlWriter.writeEndElement();
    }
    else if (property->getName()->getPattern()) {
        xmlWriter.writeStartElement("xs:restriction");
        xmlWriter.writeEmptyElement("xs:pattern");
        xmlWriter.writeAttribute("value", property->getName()->getPattern()->getRegExp());
        xmlWriter.writeEndElement();
    }
    else if (property->getName()->getLength()) {
        xmlWriter.writeStartElement("xs:restriction");
        if (property->getName()->getLength()->getIsFixed()) {
            xmlWriter.writeEmptyElement("xs:length");
            xmlWriter.writeAttribute("value", std::to_string(property->getName()->getLength()->getValue()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minLength");
            xmlWriter.writeAttribute("value", std::to_string(property->getName()->getLength()->getMinValue()));
            xmlWriter.writeEmptyElement("xs:maxLength");
            xmlWriter.writeAttribute("value", std::to_string(property->getName()->getLength()->getMaxValue()));
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("value");
    if (property->getDomain()->getValue()) {
        xmlWriter.writeTextElement("simpleValue", property->getDomain()->getValue()->getStr());
    }
    else if (property->getDomain()->getEnumeration()) {
        xmlWriter.writeStartElement("xs:restriction");
        switch (property->getDomain()->getEnumeration()->getBase())
        {
        case IDS::Base::STRING:
            xmlWriter.writeAttribute("base", "xs:string");
            break;
        case IDS::Base::INTEGER:
            xmlWriter.writeAttribute("base", "xs:integer");
            break;
        case IDS::Base::REAL:
            xmlWriter.writeAttribute("base", "xs:decimal");
            break;
        default:
            break;
        }

        for (auto val : property->getDomain()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
            xmlWriter.writeEmptyElement("xs:enumeration");
            xmlWriter.writeAttribute("value", val->getStr());
        }
        xmlWriter.writeEndElement();
    }
    else if (property->getDomain()->getPattern()) {
        xmlWriter.writeStartElement("xs:restriction");
        switch (property->getDomain()->getPattern()->getBase())
        {
        case IDS::Base::STRING:
            xmlWriter.writeAttribute("base", "xs:string");
            break;
        case IDS::Base::INTEGER:
            xmlWriter.writeAttribute("base", "xs:integer");
            break;
        case IDS::Base::REAL:
            xmlWriter.writeAttribute("base", "xs:decimal");
            break;
        default:
            break;
        }
        xmlWriter.writeEmptyElement("xs:pattern");
        xmlWriter.writeAttribute("value", property->getDomain()->getPattern()->getRegExp());
        xmlWriter.writeEndElement();
    }
    else if (property->getDomain()->getLength()) {
        xmlWriter.writeStartElement("xs:restriction");
        switch (property->getDomain()->getLength()->getBase())
        {
        case IDS::Base::STRING:
            xmlWriter.writeAttribute("base", "xs:string");
            break;
        case IDS::Base::INTEGER:
            xmlWriter.writeAttribute("base", "xs:integer");
            break;
        case IDS::Base::REAL:
            xmlWriter.writeAttribute("base", "xs:decimal");
            break;
        default:
            break;
        }
        if (property->getDomain()->getLength()->getIsFixed()) {
            xmlWriter.writeEmptyElement("xs:length");
            xmlWriter.writeAttribute("value", std::to_string(property->getDomain()->getLength()->getValue()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minLength");
            xmlWriter.writeAttribute("value", std::to_string(property->getDomain()->getLength()->getMinValue()));
            xmlWriter.writeEmptyElement("xs:maxLength");
            xmlWriter.writeAttribute("value", std::to_string(property->getDomain()->getLength()->getMaxValue()));
        }
        xmlWriter.writeEndElement();
    }
    else if (property->getDomain()->getBounds()) {
        xmlWriter.writeStartElement("xs:restriction");
        switch (property->getDomain()->getBounds()->getBase())
        {
        case IDS::Base::STRING:
            xmlWriter.writeAttribute("base", "xs:string");
            break;
        case IDS::Base::INTEGER:
            xmlWriter.writeAttribute("base", "xs:integer");
            break;
        case IDS::Base::REAL:
            xmlWriter.writeAttribute("base", "xs:decimal");
            break;
        default:
            break;
        }
        if (property->getDomain()->getBounds()->getMinType() == IDS::Bounds::MinInclusive) {
            xmlWriter.writeEmptyElement("xs:minInclusive");
            xmlWriter.writeAttribute("value", std::to_string(property->getDomain()->getBounds()->getMinValueInc()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minExclusive");
            xmlWriter.writeAttribute("value", std::to_string(property->getDomain()->getBounds()->getMinValueExc()));
        }
        if (property->getDomain()->getBounds()->getMaxType() == IDS::Bounds::MaxInclusive) {
            xmlWriter.writeEmptyElement("xs:maxInclusive");
            xmlWriter.writeAttribute("value", std::to_string(property->getDomain()->getBounds()->getMaxValueInc()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:maxExclusive");
            xmlWriter.writeAttribute("value", std::to_string(property->getDomain()->getBounds()->getMaxValueExc()));
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}

void DesctopApp::writeMaterial(QXmlStreamWriter& xmlWriter, IDS::MaterialPredicate* material) {
    xmlWriter.writeStartElement("material");
    xmlWriter.writeStartElement("value");
    if (material->getDomain()->getValue()) {
        xmlWriter.writeTextElement("simpleValue", material->getDomain()->getValue()->getStr());
    }
    else if (material->getDomain()->getEnumeration()) {
        xmlWriter.writeStartElement("xs:restriction");

        xmlWriter.writeAttribute("base", "xs:string");
        for (auto val : material->getDomain()->getEnumeration()->getTypeidsenumerationValues()->getElements()) {
            xmlWriter.writeEmptyElement("xs:enumeration");
            xmlWriter.writeAttribute("value", val->getStr());
        }
        xmlWriter.writeEndElement();
    }
    else if (material->getDomain()->getPattern()) {
        xmlWriter.writeStartElement("xs:restriction");
        xmlWriter.writeEmptyElement("xs:pattern");
        xmlWriter.writeAttribute("value", material->getDomain()->getPattern()->getRegExp());
        xmlWriter.writeEndElement();
    }
    else if (material->getDomain()->getLength()) {
        xmlWriter.writeStartElement("xs:restriction");
        if (material->getDomain()->getLength()->getIsFixed()) {
            xmlWriter.writeEmptyElement("xs:length");
            xmlWriter.writeAttribute("value", std::to_string(material->getDomain()->getLength()->getValue()));
        }
        else {
            xmlWriter.writeEmptyElement("xs:minLength");
            xmlWriter.writeAttribute("value", std::to_string(material->getDomain()->getLength()->getMinValue()));
            xmlWriter.writeEmptyElement("xs:maxLength");
            xmlWriter.writeAttribute("value", std::to_string(material->getDomain()->getLength()->getMaxValue()));
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}

void DesctopApp::writeApplicability(QXmlStreamWriter& xmlWriter, IDS::Specification* spec) {
    xmlWriter.writeStartElement("applicability");
    if (spec->getPredicate()) {
        for (auto entity : spec->getPredicate()->getEntities()) {
            writeEntity(xmlWriter, (dynamic_cast<IDS::EntityPredicate*>(entity)));
        }
        for (auto partOf : spec->getPredicate()->getRelations()) {
            writePartOf(xmlWriter, (dynamic_cast<IDS::RelationPredicate*>(partOf)));
        }
        for (auto classification : spec->getPredicate()->getClassifications()) {
            writeClassification(xmlWriter, (dynamic_cast<IDS::ClassificationPredicate*>(classification)));
        }
        for (auto attribute : spec->getPredicate()->getAttributes()) {
            writeAttribute(xmlWriter, (dynamic_cast<IDS::AttributePredicate*>(attribute)));
        }
        for (auto property : spec->getPredicate()->getProperties()) {
            writeProperty(xmlWriter, (dynamic_cast<IDS::PropertyPredicate*>(property)));
        }
        for (auto material : spec->getPredicate()->getMaterials()) {
            writeMaterial(xmlWriter, (dynamic_cast<IDS::MaterialPredicate*>(material)));
        }
    }
    xmlWriter.writeEndElement();
}

void DesctopApp::writeRequirements(QXmlStreamWriter& xmlWriter, IDS::Specification* spec) {
    xmlWriter.writeStartElement("requirements");
    if (spec->getClaim()) {
        for (auto entity : spec->getClaim()->getEntities()) {
            writeEntity(xmlWriter, (dynamic_cast<IDS::EntityPredicate*>(entity)));
        }
        for (auto partOf : spec->getClaim()->getRelations()) {
            writePartOf(xmlWriter, (dynamic_cast<IDS::RelationPredicate*>(partOf)));
        }
        for (auto classification : spec->getClaim()->getClassifications()) {
            writeClassification(xmlWriter, (dynamic_cast<IDS::ClassificationPredicate*>(classification)));
        }
        for (auto attribute : spec->getClaim()->getAttributes()) {
            writeAttribute(xmlWriter, (dynamic_cast<IDS::AttributePredicate*>(attribute)));
        }
        for (auto property : spec->getClaim()->getProperties()) {
            writeProperty(xmlWriter, (dynamic_cast<IDS::PropertyPredicate*>(property)));
        }
        for (auto material : spec->getClaim()->getMaterials()) {
            writeMaterial(xmlWriter, (dynamic_cast<IDS::MaterialPredicate*>(material)));
        }
    }
    xmlWriter.writeEndElement();
}

void DesctopApp::writeSpecifications(QXmlStreamWriter& xmlWriter, IDS::Specification* spec) {
    xmlWriter.writeStartElement("specifications");
    xmlWriter.writeStartElement("specification");
    
    xmlWriter.writeAttribute("name", spec->getName());
    xmlWriter.writeAttribute("ifcVersion", spec->getShema()->getElements()[0]);
    xmlWriter.writeAttribute("minOccurs", "no");
    xmlWriter.writeAttribute("maxOccurs", "no");

    writeApplicability(xmlWriter, spec);
    writeRequirements(xmlWriter, spec);

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}

void DesctopApp::writeIDS(QXmlStreamWriter& xmlWriter) {
    xmlWriter.writeStartElement("ids");

    writeInfo(xmlWriter);
    for (auto spec : getSpecifications()) {
        writeSpecifications(xmlWriter, spec);
    }

    xmlWriter.writeEndElement();
}

void DesctopApp::Export(QFile &file) {
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    writeIDS(xmlWriter);
}

void DesctopApp::on_pushButtonSaveFile_clicked() {
    QFile mFile("MyFile.ids");
    mFile.open(QIODevice::WriteOnly);
    Export(mFile);

    mFile.close();
}

void DesctopApp::addSpecification(IDS::Specification* spec) {
    specifications.push_back(spec);
}
void DesctopApp::claerSpecification() {
    for (auto spec : specifications) {
        delete(spec);
    }
    specifications.clear();
}


IDS::Specification* DesctopApp::getSpecification(std::string name) {
    for (auto spec : specifications) {
        if (spec->getName() == name) {
            return spec;
        }
    }
    return nullptr;
}

void DesctopApp::on_addButtonSpecification_clicked()
{
    IDS::Specification* spec = new IDS::Specification();
    IDS::typeidsspecificationIfcSchemas* schemas = new IDS::typeidsspecificationIfcSchemas();
    schemas->addElement("IFC4");
    spec->setName("Specification name");
    spec->setIfcSchemas(schemas);
    addSpecification(spec);
    ui.listWidgetSpecifications->addItem("Specification name");
}

void DesctopApp::on_removeButtonSpecification_clicked()
{
    delete ui.listWidgetSpecifications->takeItem(ui.listWidgetSpecifications->currentRow());
}

void DesctopApp::activateOptions(QListWidgetItem* item) {
    convert(getSpecification((item->text()).toStdString()));
    idsDialog.show();
}


/********************************************************************************
** Form generated from reading UI file 'heatview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEATVIEW_H
#define UI_HEATVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeatView
{
public:

    void setupUi(QWidget *HeatView)
    {
        if (HeatView->objectName().isEmpty())
            HeatView->setObjectName(QStringLiteral("HeatView"));
        HeatView->resize(400, 300);
		//HeatView->setFixedSize(400, 300);
        retranslateUi(HeatView);

        QMetaObject::connectSlotsByName(HeatView);
    } // setupUi

    void retranslateUi(QWidget *HeatView)
    {
        HeatView->setWindowTitle(QApplication::translate("HeatView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HeatView: public Ui_HeatView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEATVIEW_H

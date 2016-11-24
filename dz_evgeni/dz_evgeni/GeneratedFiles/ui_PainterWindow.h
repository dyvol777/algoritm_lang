/********************************************************************************
** Form generated from reading UI file 'PainterWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTERWINDOW_H
#define UI_PAINTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PainterWindow
{
public:

    void setupUi(QWidget *PainterWindow)
    {
        if (PainterWindow->objectName().isEmpty())
            PainterWindow->setObjectName(QStringLiteral("PainterWindow"));
        PainterWindow->resize(1960, 1123);

        retranslateUi(PainterWindow);

        QMetaObject::connectSlotsByName(PainterWindow);
    } // setupUi

    void retranslateUi(QWidget *PainterWindow)
    {
        PainterWindow->setWindowTitle(QApplication::translate("PainterWindow", "PainterWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class PainterWindow: public Ui_PainterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTERWINDOW_H

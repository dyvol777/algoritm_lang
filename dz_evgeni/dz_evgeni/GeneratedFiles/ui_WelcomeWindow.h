/********************************************************************************
** Form generated from reading UI file 'WelcomeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindowClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WelcomeWindowClass)
    {
        if (WelcomeWindowClass->objectName().isEmpty())
            WelcomeWindowClass->setObjectName(QStringLiteral("WelcomeWindowClass"));
        WelcomeWindowClass->resize(916, 432);
        centralWidget = new QWidget(WelcomeWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 30, 421, 25));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 30, 221, 34));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 70, 221, 34));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 70, 421, 301));
        WelcomeWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WelcomeWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 916, 31));
        WelcomeWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WelcomeWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WelcomeWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WelcomeWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WelcomeWindowClass->setStatusBar(statusBar);

        retranslateUi(WelcomeWindowClass);

        QMetaObject::connectSlotsByName(WelcomeWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeWindowClass)
    {
        WelcomeWindowClass->setWindowTitle(QApplication::translate("WelcomeWindowClass", "WelcomeWindow", 0));
        pushButton->setText(QApplication::translate("WelcomeWindowClass", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \320\270 \320\275\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", 0));
        pushButton_2->setText(QApplication::translate("WelcomeWindowClass", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \321\201\321\205\320\265\320\274\321\203", 0));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindowClass: public Ui_WelcomeWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H

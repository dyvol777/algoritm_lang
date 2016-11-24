#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WelcomeWindow.h"
#include "PainterWindow.h"
#include "Pancer.h"
namespace Ui {
	class WelcomeWindow;
}
class QLineEdit;
class QListWidget;
class WelcomeWindow : public QMainWindow
{
    Q_OBJECT
public slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	
signals:
	void formula(const QString&);

public:
	void tableTrue(const QString&);
	vector<char> searchVariables(string&);
    WelcomeWindow(QWidget *parent = Q_NULLPTR);
	~WelcomeWindow();

private:
    Ui::WelcomeWindowClass ui;
	PainterWindow* mPWindow;
};

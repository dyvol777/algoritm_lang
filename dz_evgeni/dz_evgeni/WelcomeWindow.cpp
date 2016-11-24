#include "WelcomeWindow.h"
#include <qlineedit.h>
#include <qlistwidget.h>
#include "Pancer.h"
WelcomeWindow::WelcomeWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	mPWindow = new PainterWindow;
	connect(this, SIGNAL(formula(QString)), mPWindow, SLOT(drawTree(QString)));
}
WelcomeWindow::~WelcomeWindow()
{
	mPWindow->close();
	delete mPWindow;

}
void WelcomeWindow::on_pushButton_clicked()
{
	QString text = ui.lineEdit->text();
	emit formula(text);
	tableTrue(text);

}
void WelcomeWindow::tableTrue(const QString& text) {
	string str=text.toStdString();
	vector<char> Variables = searchVariables(str);
	vector<vector<char>> values;
	ui.listWidget->clear();
	for (int i = 0;i < Variables.size();i++) {
		int count = 0;
		//int currentIndex = 0;
		vector<char> tempToPush;
		while (count != pow(2, i + 1)) {
			for (int j = 0;j < pow(2, Variables.size()-(i+1));j++) {
				if (count % 2 == 0)
					//values[i][j + currentIndex] = '0';
					tempToPush.push_back('0');
				else
					//values[i][j + currentIndex] = '1';
					tempToPush.push_back('1');
			}
			count++;
			//currentIndex = currentIndex + pow(2, Variables.size() - (i + 1));
		}
		values.push_back(tempToPush);
	}
	QString table;
	for (int i = 0;i < Variables.size();i++) {
		table = "";
		table += Variables[i];
		table += " ";
		for (int j = 0;j < values[i].size();j++) {
			table += values[i][j];
			table += " ";
		}
		ui.listWidget->addItem(table);
	}
	Parcer mParcer(str);
	mParcer.goPolish();
	ui.listWidget->addItem(mParcer.count(Variables, values));


}
vector<char> WelcomeWindow::searchVariables(string& str) {
	vector<char> tempVariables;
	int compares = 0;
	Parcer toCheck;
	for (auto ch : str)
	{
		if (toCheck.isVariable(ch)) {
			for (auto v : tempVariables)
				if (ch == v)
					compares++;
			if (!compares)
				tempVariables.push_back(ch);
			compares = 0;
		}
	}
	return tempVariables;
}
void WelcomeWindow::on_pushButton_2_clicked()
{
	mPWindow->show();
}

#include "PainterWindow.h"
#include <QGraphicsItem>
#include "WelcomeWindow.h"


PainterWindow::PainterWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setupScene();

}

PainterWindow::~PainterWindow()
{
}
void PainterWindow::drawTree(const QString& input)
{
	Parcer data(input.toStdString());
	data.goPolish();
	data.logPolish();
	mScene->clear();
	tree head;
	head.set(data);
	head.data = head.tempOutput.back();
	head.tempOutput.pop_back();
	tree::biggestLevel = 0;
	head.buildTree(head.current);
	head.coord.first = 1000;
	head.coord.second = 0;
	head.setCoord(head.current);
	QRectF blok(head.coord.first, head.coord.second, 40, 40);
	mScene->addRect(blok);
	auto mText = new QGraphicsSimpleTextItem();

	mText->setPos(blok.center());
	QString str;
	str+=head.data;
	mText->setText(str);
	mScene->addItem(mText);
	drawTree1(head.current);
}
void PainterWindow::drawTree1(tree* current) {

	//current->right = new tree;
	//current->right->data = tempOutput.back();
	//tempOutput.pop_back();
	//current->right->level = current->level + 1;
	//if (current->right->level > biggestLevel)
	//	biggestLevel = current->right->level;
	//current->right->top = current;
	
	QRectF blok(current->right->coord.first, current->right->coord.second, 40, 40);
	mScene->addRect(blok);
	auto mText = new QGraphicsSimpleTextItem();
	mText->setPos(blok.center());
	QString str;
	str += current->right->data;
	mText->setText(str);
	mScene->addItem(mText);
	QLineF line(current->coord.first + 20, current->coord.second + 40, current->right->coord.first + 20, current->right->coord.second);
	mScene->addLine(line);
	if (current->isOperator(current->right->data))
	{
		drawTree1(current->right);
		//current->left = new tree;
		//current->left->data = tempOutput.back();
		//tempOutput.pop_back();
		//current->left->level = current->level + 1;
		//if (current->left->level > biggestLevel)
		//	biggestLevel = current->left->level;
		//current->left->top = current;
		QRectF blok1(current->left->coord.first, current->left->coord.second, 40, 40);
		mScene->addRect(blok1);
		auto mText1 = new QGraphicsSimpleTextItem();
		mText1->setPos(blok1.center());
		QString str1;
		str1 += current->left->data;
		mText1->setText(str1);
		mScene->addItem(mText1);
		QLineF line1(current->coord.first + 20, current->coord.second + 40, current->left->coord.first + 20, current->left->coord.second);
		mScene->addLine(line1);
		if (current->isOperator(current->left->data))
		{
			drawTree1(current->left);
		}
		else
			return;
	}
	else {
		//current->left = new tree;
		//current->left->data = tempOutput.back();
		//tempOutput.pop_back();
		//current->left->level = current->level + 1;
		//if (current->left->level > biggestLevel)
		//	biggestLevel = current->left->level;
		//current->left->top = current;
		QRectF blok1(current->left->coord.first, current->left->coord.second, 40, 40);
		mScene->addRect(blok1);
		auto mText1 = new QGraphicsSimpleTextItem();
		mText1->setPos(blok1.center());
		QString str1;
		str1 += current->left->data;
		mText1->setText(str1);
		mScene->addItem(mText1);
		QLineF line1(current->coord.first + 20, current->coord.second + 40, current->left->coord.first + 20, current->left->coord.second);
		mScene->addLine(line1);
		if (!current->isOperator(current->left->data))
			return;
		drawTree1(current->left);
	}
}
void PainterWindow::setupScene() {
	mScene = new QGraphicsScene(this);
	mScene->setSceneRect(0, 0, 2000, 2000);
	mView = new QGraphicsView(this);
	mView->setScene(mScene);
	

}
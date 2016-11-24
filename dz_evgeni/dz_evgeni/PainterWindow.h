#pragma once

#include <QWidget>
#include "ui_PainterWindow.h"
#include "qgraphicsview.h"
#include "Pancer.h"
namespace Ui {
	class PainterWindow;
}

class PainterWindow : public QWidget
{
	Q_OBJECT

public:
	PainterWindow(QWidget *parent = Q_NULLPTR);
	~PainterWindow();
	void drawTree1(tree*);
	void setupScene();

private:
	Ui::PainterWindow ui;
	QGraphicsScene* mScene;
	QGraphicsView* mView;
public slots:
	void drawTree(const QString&);
};

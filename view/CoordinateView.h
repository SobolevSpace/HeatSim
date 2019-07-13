#pragma once

#include <QWidget>
#include "ui_CoordinateView.h"
#include "QPainter"
class CoordinateView : public QWidget
{
	Q_OBJECT

public:
	CoordinateView(QWidget *parent = Q_NULLPTR);
	~CoordinateView();
	void paintEvent(QPaintEvent *) {
		QPainter painter(this);
		painter.drawImage(0, 0, *image);
	}
	void Paint();
	void Update();
	void set_AverageData(const std::shared_ptr<std::vector<double>> sp);
private:
	Ui::CoordinateView ui;
	std::shared_ptr<std::vector<double>> AverageData;
	QImage* image;
	QPoint O;
	int width;
	int height;
};

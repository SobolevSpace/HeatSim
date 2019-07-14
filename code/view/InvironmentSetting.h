#pragma once

#include <QWidget>
#include "ui_InvironmentSetting.h"

class InvironmentSetting : public QWidget
{
	Q_OBJECT

public:
	InvironmentSetting(QWidget *parent = Q_NULLPTR);
	~InvironmentSetting();
public Q_SLOTS:
	void set_Invironment();
signals:
	void sendTemAndAlpha(double T, double Alpha);
public:
	void init();
private:
	Ui::InvironmentSetting ui;
	double Temperature;
	double Alpha;
};

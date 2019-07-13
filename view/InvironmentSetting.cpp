#include "InvironmentSetting.h"

InvironmentSetting::InvironmentSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Temperature = 20;
	Alpha = 0.2;
	connect(ui.pushButton, SIGNAL(clicked()) ,this,SLOT(set_Invironment()) );
}

InvironmentSetting::~InvironmentSetting()
{

}

void InvironmentSetting::set_Invironment() {
	Temperature = ui.InvironmentTemp->text().toDouble() - 273;
	Alpha = ui.Alpha->text().toDouble();
	emit sendTemAndAlpha(Temperature, Alpha);
	close();
}

void InvironmentSetting::init() {
	ui.InvironmentTemp->textEdited(QString::number(Temperature+273) );
	ui.Alpha->textEdited(QString::number(Alpha));
	show();
}
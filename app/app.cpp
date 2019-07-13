#include "app.h"
#include <iostream>

app::app() {
	;
}

app::~app() {
	;
}

bool app::init() {
	m_wndMain.init();

	std::shared_ptr<HeatDataModel> spModel(std::make_shared<HeatDataModel>());
	m_spViewModel = std::make_shared<HeatViewModel>();
	m_spViewModel->SetModel(spModel);

	m_wndMain.set_CalcCommand(m_spViewModel->getCalcCommand());
	m_wndMain.set_AverageCommand(m_spViewModel->getAvgCommand());
	
	m_spViewModel->AddPropertyNotification(m_wndMain.get_PropertySink());
	m_spViewModel->AddCommandNotification(m_wndMain.get_CommandSink());


	m_wndMain.view->set_Heatdim(m_spViewModel->getResult());
	m_wndMain.Coorview->set_AverageData(m_spViewModel->getAverage());
	return true;
}

void app::show() {
	m_wndMain.show();
}


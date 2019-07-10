#pragma once
#include "MainWindow.h"
#include "viewmodel/HeatViewModel.h"

class app {
private:
	MainWindow m_wndMain;
	std::shared_ptr<HeatViewModel> m_spViewModel;
public:
	app();
	~app();

	bool init();
	void show();
};
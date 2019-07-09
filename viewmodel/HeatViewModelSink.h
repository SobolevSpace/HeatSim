#pragma once

#include "../others/ETL/include/etlbase.h"

class HeatViewModel;

class HeatViewModelSink : public IPropertyNotification
{
public:
	HeatViewModelSink(HeatViewModel* p);

	virtual void OnPropertyChanged(const std::string& str);

private:
	HeatViewModel * m_pVM;
};
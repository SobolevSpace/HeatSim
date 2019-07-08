#pragma once
#include "../others/ETL/include/etlbase.h"

#include "../common/workboard.h"

class HeatDataModel : public Proxy_PropertyNotification<HeatDataModel>
{
public:
	HeatDataModel();


private:
	workboard initcondi;
	double padT;
	double alpha;
	int sec20;

};
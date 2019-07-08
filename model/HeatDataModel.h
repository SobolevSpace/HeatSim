#pragma once
#include "../others/ETL/include/etlbase.h"

#include "../common/workboard.h"

class HeatDataModel : public Proxy_PropertyNotification<HeatDataModel>
{
public:
	HeatDataModel();

	void setInitCondi(const workboard condi);
	std::shared_ptr<workboard> getInitCondi();
	void setPadTemperature(const double temp);
	double getPadTemperature() const;
	void setAlpha(const double alp);
	double getAlpha() const;
	void setTime20(const int time);
	int getTime20() const;
	
	std::shared_ptr<workboard> getResult();

private:
	std::shared_ptr<workboard> initcondi;
	double padTemperature;
	double alpha;

	std::shared_ptr<workboard> midcondi[401];

	int time20;
	std::shared_ptr<workboard> result;
};
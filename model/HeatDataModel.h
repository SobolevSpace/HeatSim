#pragma once
#include "etlbase.h"

#include "../common/workboard.h"
#include "../common/parameter.h"

class HeatDataModel : public Proxy_PropertyNotification<HeatDataModel>
{
public:
	HeatDataModel();

	void setInitCondi(const workboard condi);
	void setInitCondi(const std::shared_ptr<workboard> condi);
	std::shared_ptr<workboard> getInitCondi();
	void setPadTemperature(const double temp);
	double getPadTemperature() const;
	void setAlpha(const double alp);
	double getAlpha() const;
	void setTime20(const int time);
	int getTime20() const;
	bool setPointParameters(const pointParameters& p1, const pointParameters& p2);
	void getPointParameters(pointParameters& p1, pointParameters& p2);
	
	bool Calc(const workboardPass& para);
	bool CalcAvg(const pointParameters p1, const pointParameters p2);

	std::shared_ptr<workboard> getResult();
	std::shared_ptr<std::vector<double> > getAverage();

private:
	void calculateMidcondi();
	void calculateAverage();

	double padTemperature;
	double alpha;
	pointParameters p1, p2;

	std::shared_ptr<workboard> midcondi[401];
	std::shared_ptr<std::vector<double> > avgres;

	std::shared_ptr<timeParameters> time20;
	std::shared_ptr<workboard> result;
};
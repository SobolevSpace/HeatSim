#include "HeatDataModel.h"


HeatDataModel::HeatDataModel() : initcondi(std::make_shared<workboard>()), padTemperature(20), alpha(0.2), time20(0)
{
	for (int i = 0; i <= 401; ++i) midcondi[i] = std::make_shared<workboard>();
	result = midcondi[0];
}

void setInitCondi(const workboard condi);
std::shared_ptr<workboard> getInitCondi();
void setPadTemperature(const double temp);
double getPadTemperature() const;
void setAlpha(const double alp);
double getAlpha() const;
void setTime20(const int time);
int getTime20() const;

std::shared_ptr<workboard> getResult();
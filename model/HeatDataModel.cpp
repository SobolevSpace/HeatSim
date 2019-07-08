#include "HeatDataModel.h"


HeatDataModel::HeatDataModel() : initcondi(std::make_shared<workboard>()), padTemperature(20), alpha(0.2), time20(0)
{
	for (int i = 0; i <= 401; ++i) midcondi[i] = std::make_shared<workboard>();
	result = midcondi[0];
	calculateMidcondi();
}

void HeatDataModel::setInitCondi(const workboard condi)
{
	*initcondi = *condi;
	calculateMidcondi();
	Fire_OnPropertyChanged("heat_Result");
}

std::shared_ptr<workboard> HeatDataModel::getInitCondi()
{
	return initcondi;
}

void HeatDataModel::setPadTemperature(const double temp)
{
	padTemperature = temp;
	calculateMidcondi();
	Fire_OnPropertyChanged("heat_Result");
}

double HeatDataModel::getPadTemperature() const
{
	return padTemperature;
}

void HeatDataModel::setAlpha(const double alp)
{
	alpha = alp;
	calculateMidcondi();
	Fire_OnPropertyChanged("heat_Result");
}

double HeatDataModel::getAlpha() const
{
	return alpha;
}

void HeatDataModel::setTime20(const int time)
{
	time20 = time;
	result = midcondi[time20];
	Fire_OnPropertyChanged("heat_Result");
}

int HeatDataModel::getTime20() const
{
	return time20;
}

std::shared_ptr<workboard> HeatDataModel::getResult()
{
	return result;
}

void HeatDataModel::calculateMidcondi()
{
	int i, j, k, size, newsize;
	size = midcondi[0]->getSize();
	newsize = initcondi->getSize();
	*(midcondi[0]) = *initcondi;
	for (i = 1; i < 401; ++i)
	{
		if (size != newsize) midcondi[i].resize(newsize);
		for (j = 0; j < newsize; ++j)
			for (k = 0; k < newsize; ++k) {
				double lef, rig, up, bot, ori;
				lef = j == 0 ? padTemperature : midcondi[i - 1]->t_matrix[j - 1][k];
				rig = j == newsize - 1 ? padTemperature : midcondi[i - 1]->t_matrix[j + 1][k];
				up = k == 0 ? padTemperature : midcondi[i - 1]->t_matrix[j][k - 1];
				bot = k == newsize - 1 ? padTemperature : midcondi[i - 1]->t_matrix[j][k + 1];
				ori = midcondi[i - 1]->t_matrix[j][k];
				midcondi[i]->t_matrix[j][k] = alpha * (lef + rig + up + bot) + (1 - alpha)*ori;
			}
	}
}
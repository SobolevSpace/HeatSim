#include "HeatDataModel.h"

#include <vector>

HeatDataModel::HeatDataModel() : initcondi(std::make_shared<workboard>()), padTemperature(20), alpha(0.2), time20(std::make_shared<timeParameters>())
{
	for (int i = 0; i <= 401; ++i) midcondi[i] = std::make_shared<workboard>();
	result = midcondi[0];
	calculateMidcondi();
}

void HeatDataModel::setInitCondi(const workboard condi)
{
	*initcondi = condi;
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
	time20->setPara(time);
	result = midcondi[time];
	Fire_OnPropertyChanged("heat_Result");
}

int HeatDataModel::getTime20() const
{
	return time20->get();
}

std::shared_ptr<workboard> HeatDataModel::getResult()
{
	return result;
}

void HeatDataModel::calculateMidcondi()
{
	int i, j, k, size, newsize;
	std::vector<std::vector<point> > mat, newmat;
	midcondi[0]->getPointMat(mat);
	initcondi->getPointMat(newmat);
	newsize = newmat.size();
	*(midcondi[0]) = *initcondi;
	for (i = 1; i < 401; ++i)
	{
		midcondi[i - 1]->getPointMat(mat);
		for (j = 0; j < newsize; ++j)
			for (k = 0; k < newsize; ++k) {
				double lef, rig, up, bot, ori;
				lef = j == 0 ? padTemperature : mat[j - 1][k].getTemperature();
				rig = j == newsize - 1 ? padTemperature : mat[j + 1][k].getTemperature();
				up = k == 0 ? padTemperature : mat[j][k - 1].getTemperature();
				bot = k == newsize - 1 ? padTemperature : mat[j][k + 1].getTemperature();
				ori = mat[j][k].getTemperature();
				newmat[j][k].setTemperature(alpha * (lef + rig + up + bot) + (1 - alpha)*ori);
			}
		*midcondi[i] = newmat;
	}
}
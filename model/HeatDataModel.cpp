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

void HeatDataModel::setInitCondi(const std::shared_ptr<workboard> condi)
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
	time20->setPara(time);
	result = midcondi[time];
	std::string str = "heat_Result";
	Fire_OnPropertyChanged(str);
}

void HeatDataModel::setTime20(const timeParameters time)
{
	*time20 = time;
	result = midcondi[time20->get()];
	Fire_OnPropertyChanged("heat_Result");
}

void HeatDataModel::setTime20(const std::shared_ptr<timeParameters> time)
{
	*time20 = *time;
	result = midcondi[time20->get()];
	Fire_OnPropertyChanged("heat_Result");
}

int HeatDataModel::getTime20() const
{
	return time20->get();
}

bool HeatDataModel::Query(workboardPass para)
{
	switch (para.getChangeType()) {
	case NOCHANGE:
		return true;
	case ALPHA:
		setAlpha(para.getChangeValue());
		return true;
	case TIME:
		setTime20((int)(para.getChangeValue()*20+0.1));
		return true;
	case INITIALCOND:
		setInitCondi(para.getWorkBoard());
		return true;
	}
}

std::shared_ptr<workboard> HeatDataModel::getResult()
{
	return result;
}

void HeatDataModel::calculateMidcondi()
{
	int i, j, k, size;
	std::vector<std::vector<point> > mat, newmat;
	int lefp, rigp, upp, botp, midp;
	double lef, rig, up, bot, mid;

	initcondi->getPointMat(mat);
	initcondi->getPointMat(newmat);
	size = mat.size();
	*(midcondi[0]) = *initcondi;

	for (i = 1; i < 401; ++i)
	{
		midcondi[i - 1]->getPointMat(mat);
		for (j = 0; j < size; ++j)
			for (k = 0; k < size; ++k) {
				midp = mat[j][k].getProperty();
				if (midp != 0) {
					//newmat[j][k].setProperty(midp);
					//newmat[j][k].setTemperature(mid);
					continue;
				}
				mid = mat[j][k].getTemperature();

				lefp = j == 0 ? 0 : mat[j - 1][k].getProperty();
				lef = j == 0 ? padTemperature : mat[j - 1][k].getTemperature();
				// When the left point is adiabatic, set the temperature to the temperature of mid point.
				if (lefp == -1) lef = mid;

				rigp = j == size - 1 ? 0 : mat[j + 1][k].getProperty();
				rig = j == size - 1 ? padTemperature : mat[j + 1][k].getTemperature();
				if (rigp == -1) rig = mid;

				upp = k == 0 ? 0 : mat[j][k - 1].getProperty();
				up = k == 0 ? padTemperature : mat[j][k - 1].getTemperature();

				if (upp == -1) up = mid;

				botp = k == size - 1 ? 0 : mat[j][k + 1].getProperty();
				bot = k == size - 1 ? padTemperature : mat[j][k + 1].getTemperature();
				if (botp == -1) bot = mid;

				newmat[j][k].setTemperature(alpha * (lef + rig + up + bot) + (1 - 4 * alpha) * mid);

			}
		*midcondi[i] = newmat;
	}
}
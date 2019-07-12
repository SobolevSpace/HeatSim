#include "HeatDataModel.h"

#include <vector>

HeatDataModel::HeatDataModel() : padTemperature(20), alpha(0.2), time20(std::make_shared<timeParameters>()),
	result(std::make_shared<workboard>())
{
	for (int i = 0; i <= 401; ++i) midcondi[i] = std::make_shared<workboard>();
	avgres = std::make_shared<std::vector<double> >();
	avgres->resize(401);

	result = midcondi[0];
	p1 = pointParameters(0, 0);
	p2 = pointParameters(midcondi[0]->getSize() - 1, midcondi[0]->getSize() - 1);
	calculateMidcondi();
}

void HeatDataModel::setInitCondi(const workboard condi)
{
	*midcondi[0] = condi;
	calculateMidcondi();
	Fire_OnPropertyChanged("heat_Result");
	Fire_OnPropertyChanged("avg_Result");
}

void HeatDataModel::setInitCondi(const std::shared_ptr<workboard> condi)
{
	*midcondi[0] = *condi;
	calculateMidcondi();
	Fire_OnPropertyChanged("heat_Result");
	Fire_OnPropertyChanged("avg_Result");
}

std::shared_ptr<workboard> HeatDataModel::getInitCondi()
{
	return midcondi[0];
}

void HeatDataModel::setPadTemperature(const double temp)
{
	padTemperature = temp;
	calculateMidcondi();
	Fire_OnPropertyChanged("heat_Result");
	Fire_OnPropertyChanged("avg_Result");
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
	Fire_OnPropertyChanged("avg_Result");
}

double HeatDataModel::getAlpha() const
{
	return alpha;
}

void HeatDataModel::setTime20(const int time)
{
	time20->setPara(time);
	*result = *midcondi[time];
	Fire_OnPropertyChanged("heat_Result");
}

int HeatDataModel::getTime20() const
{
	return time20->get();
}

bool HeatDataModel::setPointParameters(const pointParameters& p1, const pointParameters& p2)
{
	int x1, x2, y1, y2, size;
	x1 = p1.getX();
	x2 = p2.getX();
	y1 = p1.getY();
	y2 = p2.getY();
	
	size = midcondi[0]->getSize();
	if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) return false;
	if (x1 >= size || x2 >= size || y1 >= size || y2 >= size) return false;

	this->p1.setXY(x1 < x2 ? x1 : x2, y1 < y2 ? y1 : y2);
	this->p2.setXY(x1 > x2 ? x1 : x2, y1 > y2 ? y1 : y2);
	calculateAverage();
	Fire_OnPropertyChanged("avg_Result");
	return true;
}

void HeatDataModel::getPointParameters(pointParameters& p1, pointParameters& p2)
{
	p1 = this->p1;
	p2 = this->p2;
	return;
}

bool HeatDataModel::Calc(const workboardPass& para)
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
	default:
		throw(std::runtime_error("NO SUCH PARAMETER CHANGE LOADED"));
		break;
	}
	return false;
}

bool HeatDataModel::CalcAvg(const pointParameters p1, const pointParameters p2)
{
	return this->setPointParameters(p1, p2);
}

std::shared_ptr<workboard> HeatDataModel::getResult()
{
	return result;
}

std::shared_ptr<std::vector<double> > HeatDataModel::getAverage()
{
	return avgres;
}

void HeatDataModel::calculateMidcondi()
{
	int i, j, k, size;
	std::vector<std::vector<point> > mat, newmat;
	int lefp, rigp, upp, botp, midp;
	int avgLefBnd, avgRigBnd, avgTopBnd, avgBotBnd, avgArea;
	double lef, rig, up, bot, mid;
	double frameavg;

	midcondi[0]->getPointMat(mat);
	midcondi[0]->getPointMat(newmat);
	size = mat.size();

	avgLefBnd = p1.getX();
	avgRigBnd = p2.getX();
	avgTopBnd = p1.getY();
	avgBotBnd = p2.getY();
	avgArea = (avgRigBnd - avgLefBnd + 1) * (avgBotBnd - avgTopBnd + 1);

	for (i = 1; i < 401; ++i)
	{
		frameavg = 0;
		midcondi[i - 1]->getPointMat(mat);
		for (j = 0; j < size; ++j)
			for (k = 0; k < size; ++k) {
				if (j >= avgLefBnd && j <= avgRigBnd && k >= avgTopBnd && k <= avgBotBnd) frameavg += mat[j][k].getTemperature();
				midp = mat[j][k].getProperty();
				if (midp != 0) continue;
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
		(*avgres)[i] = frameavg / avgArea;
	}
}

void HeatDataModel::calculateAverage()
{
	int i, j, k, size;
	int avgLefBnd, avgRigBnd, avgTopBnd, avgBotBnd, avgArea;
	double frameavg;
	std::vector<std::vector<point> > mat;

	avgLefBnd = p1.getX();
	avgRigBnd = p2.getX();
	avgTopBnd = p1.getY();
	avgBotBnd = p2.getY();
	avgArea = (avgRigBnd - avgLefBnd + 1) * (avgBotBnd - avgTopBnd + 1);

	midcondi[0]->getPointMat(mat);
	size = mat.size();
	for (i = 0; i < 401; ++i) {
		frameavg = 0;
		midcondi[i]->getPointMat(mat);
		for (j = 0; j < size; ++j)
			for (k = 0; k < size; ++k) {
				if (j >= avgLefBnd && j <= avgRigBnd && k >= avgTopBnd && k <= avgBotBnd)
					frameavg += mat[j][k].getTemperature();

			}
		(*avgres)[i] = frameavg / avgArea;
	}
	return;
}
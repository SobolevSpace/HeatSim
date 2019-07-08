#pragma once
#include <vector>

class point {
private:
	double temperature;
	int propertyID;

public:
	point();
	point(double T);
	point(double T, int propertyID);
	double getTemperature();
	int getProperty();
	void setTemperature(double T);
	void setProperty(int PID);
	~point();
};

class workboard {
private:
	const int size;
	std::vector<std::vector<point> > t_matrix;

public:
	workboard();
	workboard& operator= (const workboard& s);
	void getPointMat(std::vector<std::vector<point> >& ret);
	void __show();//FOR TEST ONLY
	~workboard();
};
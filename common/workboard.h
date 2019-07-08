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
	void __show();//FOR TEST ONLY
	~workboard();
};
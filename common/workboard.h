#ifndef WORKBOARD_H
#define WORKBOARD_H

#include <vector>

#define MAT_SIZE 100

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
	int getSize();
	workboard& operator= (const workboard& s);
	workboard& operator= (const std::vector<std::vector<point> >& mat);
	void getPointMat(std::vector<std::vector<point> >& ret);
	void __show();//FOR TEST ONLY
	~workboard();
};


enum CType {NOCHANGE = 0, ALPHA = 1, TIME=2, INITIALCOND = 3};


class workboardPass {
private:
	workboard wb;
	CType changeType;
	double changeValue;

public:
	workboardPass();
	workboardPass(const workboard& w);
	CType getChangeType();
	void setChangeType(CType c);
	double getChangeValue();
	void setChangeValue(double val);
	workboard getWorkBoard();
	void setWorkBoard(const workboard& w);
	~workboardPass();
};
#endif // !WORKBOARD_H
#include "workboard.h"
#include <iostream>

point::point():temperature(0),propertyID(0) {
	;
}

point::point(double T) : temperature(T), propertyID(0) {
	;
}

point::point(double T, int PID) : temperature(T), propertyID(PID) {
	;
}

double point::getTemperature() {
	return temperature;
}

int point::getProperty() {
	return propertyID;
}

void point::setTemperature(double T) {
	temperature = T;
}

void point::setProperty(int PID) {
	propertyID = PID;
}

point::~point() {
	;
}

workboard::workboard():size(100),t_matrix() {
	t_matrix.resize(size);
	for (int i = 0; i < size; i++) {
		t_matrix[i].resize(size);
	}
}

workboard::~workboard() {
	;
}

void workboard::__show() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << t_matrix[i][j].getTemperature() << " ";
		}
		std::cout << std::endl;
	}
}

workboard& workboard::operator= (const workboard& s) {
	//DONOT CHECK whether size is fitable or not
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			t_matrix[i][j] = s.t_matrix[i][j];
		}
	}
	return *this;
}

void workboard::getPointMat(std::vector<std::vector<point> >& ret) {
	ret.resize(size);
	for (int i = 0; i < size; i++) {
		ret[i].resize(size);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ret[i][j] = t_matrix[i][j];
		}
	}
}

int workboard::getSize() {
	return size;
}

workboard& workboard::operator= (const std::vector<std::vector<point> >& mat) {
	if (mat.size() != size) {
		std::cout << "Size not fit" << std::endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				t_matrix[i][j] = mat[i][j];
			}
		}
	}
	return *this;
}
#include "parameter.h"

timeParameters::timeParameters() {
	flameNo = 0;
}

timeParameters::timeParameters(const timeParameters& src) {
	flameNo = src.flameNo;
}

timeParameters::timeParameters(timeParameters&& src) noexcept
{
	flameNo = src.flameNo;
}

timeParameters& timeParameters::operator=(const timeParameters& src) {
	flameNo = src.flameNo;
	return *this;
}

timeParameters& timeParameters::operator=(timeParameters&& src) noexcept
{
	flameNo = src.flameNo;
	return *this;
}

int timeParameters::get() const{
	return flameNo;
}

void timeParameters::setPara(int t) {
	if (t < 0) t = 0;
	flameNo = t;
}

timeParameters::~timeParameters() {
	;
}

pointParameters::pointParameters() :x(0), y(0) {
	;
}

pointParameters::pointParameters(const pointParameters& src) {
	x = src.x;
	y = src.y;
}

pointParameters::pointParameters(pointParameters&& src) noexcept{
	x = src.x;
	y = src.y;
}

pointParameters::pointParameters(int x, int y) {
	this->x = x;
	this->y = y;
}

pointParameters::~pointParameters() {
	;
}

pointParameters& pointParameters::operator= (const pointParameters& src) {
	this->x = src.x;
	this->y = src.y;
	return *this;
}

pointParameters& pointParameters::operator= (pointParameters&& src) noexcept{
	this->x = src.x;
	this->y = src.y;
	return *this;
}

int pointParameters::getX() const {
	return x;
}

int pointParameters::getY() const {
	return y;
}

std::pair<int, int> pointParameters::getPair() const{
	std::pair<int, int> ret(x, y);
	return ret;
}

void pointParameters::setX(int x) {
	this->x = x;
}

void pointParameters::setY(int y) {
	this->y = y;
}

void pointParameters::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}

alphaParameters::alphaParameters() :val(0) {
	;
}

alphaParameters::alphaParameters(const alphaParameters& src) {
	val = src.val;
}

alphaParameters::alphaParameters(alphaParameters&& src) {
	val = src.val;
}

alphaParameters::alphaParameters(double val) {
	this->val = val;
}

alphaParameters::~alphaParameters() {
	;
}

alphaParameters& alphaParameters::operator=(const alphaParameters& src) {
	this->val = src.val;
	return *this;
}

alphaParameters& alphaParameters::operator=(alphaParameters&& src) noexcept{
	val = src.val;
	return *this;
}

double alphaParameters::get() const {
	return val;
}

void alphaParameters::set(double val) {
	this->val = val;
}


padTempParameters::padTempParameters() : padTemperature(0) {
	;
}

padTempParameters::padTempParameters(const padTempParameters& src) {
	padTemperature = src.padTemperature;
}

padTempParameters::padTempParameters(padTempParameters&& src) {
	padTemperature = src.padTemperature;
}

padTempParameters::padTempParameters(double val) {
	this->padTemperature = val;
}

padTempParameters& padTempParameters::operator= (const padTempParameters& src) {
	this->padTemperature = src.padTemperature;
	return *this;
}

padTempParameters& padTempParameters::operator= (padTempParameters&& src) noexcept{
	this->padTemperature = src.padTemperature;
	return *this;
}

double padTempParameters::get() const {
	return padTemperature;
}

void padTempParameters::set(double val) {
	padTemperature = val;
}
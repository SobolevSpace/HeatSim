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

int timeParameters::get() {
	return flameNo;
}

void timeParameters::setPara(int t) {
	if (t < 0) t = 0;
	flameNo = t;
}

timeParameters::~timeParameters() {
	;
}
#pragma once

class timeParameters {
private:
	int flameNo;
public:
	timeParameters();
	timeParameters(const timeParameters& src);
	timeParameters(timeParameters&& src) noexcept;
	~timeParameters();

	timeParameters& operator= (const timeParameters& src);
	timeParameters& operator= (timeParameters&& src) noexcept;

	int get();
	void setPara(int t);
};
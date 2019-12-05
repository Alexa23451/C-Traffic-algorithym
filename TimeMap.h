#pragma once
class TimeMap
{
public:
	TimeMap(){}
	~TimeMap(){}

	void setHours(int);
	int getHours();
	void setMinutes(int);
	int getMinutes();
	void setTime();
private:
	int hours;
	int minutes;
};


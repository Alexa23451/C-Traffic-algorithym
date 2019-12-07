#pragma once
class TimeMap
{
public:

	~TimeMap(){}

	static TimeMap* getInstance();

	void setHours(int);
	int getHours();
	void setMinutes(int);
	int getMinutes();
	void setTime();
private:
	static TimeMap* instance;
	int hours;
	int minutes;
	TimeMap();
};


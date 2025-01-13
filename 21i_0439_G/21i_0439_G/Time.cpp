#include "Time.h"
#include <string>
using namespace std;

Time::Time()
{
	hours = 0;
	minutes = 0;
}

Time::Time(int hours, int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}

void Time::display()
{
	cout << hours << ':' << minutes;
}

string Time::to_String()
{
	return to_string(hours)+':'+to_string(minutes);
}
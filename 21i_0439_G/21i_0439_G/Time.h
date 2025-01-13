#pragma once
#include<iostream>
using namespace std;

class Time
{
private:
	int hours; int minutes;
public:
	Time();
	Time(int hours, int minutes);
	void display();
	string to_String();
};


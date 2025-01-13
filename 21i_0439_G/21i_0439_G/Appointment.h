#pragma once
#include"Time.h"
class Appointment
{
private:
	string status;
	Time* appointment_start_time;
	Time* appointment_end_time;
public:
	void set_appointment_time(int starting_hour, int starting_minute, int ending_hour, int ending_time);
	Time* get_starting_time();
	Time* get_ending_time();
};

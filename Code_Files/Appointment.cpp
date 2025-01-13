#include "Appointment.h"

void Appointment::set_appointment_time(int starting_hour, int starting_minute, int ending_hour, int ending_time)
{
	appointment_start_time = new Time(starting_hour, starting_minute);
	appointment_end_time = new Time(ending_hour, ending_time);
}

Time* Appointment::get_starting_time()
{
	return appointment_start_time;
}

Time* Appointment::get_ending_time()
{
	return appointment_end_time;
}
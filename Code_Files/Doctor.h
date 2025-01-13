#pragma once
#include<iostream>
#include"User.h"
#include"Appointment.h"
using namespace std;
class Doctor : public User
{
private:
	int number_of_appointments;
	string hosp_name;
	string location;
	string specialization;
	Appointment* doctor_appointments;
public:
	Doctor();
	Doctor(string Username, string Email, string CNIC, string Password, string hosp_name, string location, string specialization, int number_of_appointments);
	void set_hospital(string hosp);
	string get_hospital() const;
	void set_location(string location);
	string get_location() const;
	void set_specialization(string specialization);
	string get_specialization()const;
	const Doctor& const operator=(const Doctor& other);
	void Display();
	void set_num_appointments(int n);
	int get_num_appointments() const;
	void create_number_appointments();
	Appointment* get_created_appointment();
	void display_timings();
};


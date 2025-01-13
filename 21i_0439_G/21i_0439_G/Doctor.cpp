#include "Doctor.h"


Doctor::Doctor() : User(), hosp_name(" "), specialization(" "), location(" "), number_of_appointments(0)
{
	this->set_hospital(" ");
	this->set_specialization(" ");
	this->set_location(" ");
	this->set_num_appointments(0);
}

Doctor::Doctor(string Username, string Email, string CNIC, string Password, string hosp_name, string location, string specialization, int number_of_appointments) : User(Username, Email, CNIC, Password)
{
	this->hosp_name = hosp_name;
	this->location = location;
	this->specialization = specialization;
	this->number_of_appointments = number_of_appointments;
	this->set_hospital(hosp_name);
	this->set_specialization(specialization);
	this->set_location(location);
	this->set_num_appointments(number_of_appointments);
}

void Doctor::set_hospital(string hosp)
{
	this->hosp_name = hosp;
}

string Doctor::get_hospital() const
{
	return this->hosp_name;
}

void Doctor::set_location(string location)
{
	this->location = location;
}

string Doctor::get_location() const
{
	return this->location;
}

void Doctor::set_specialization(string specialization)
{
	this->specialization = specialization;
}

string Doctor::get_specialization() const
{
	return this->specialization;
}

const Doctor& Doctor::operator=(const Doctor& other)
{
	this->setname(other.getname());
	this->setemail(other.getemail());
	this->setcnic(other.getcnic());
	this->setpass(other.getpass());
	this->set_hospital(other.get_hospital());
	this->set_specialization(other.get_specialization());
	this->set_location(other.get_location());
	this->set_num_appointments(other.get_num_appointments());
	return *this;
}

void Doctor::Display()
{
	cout << this->getname() << "\t\t\t\t" << this->get_location() << "\t\t\t\t\t" << this->get_specialization() << "\t\t\t\t\t" << this->get_hospital() << '\n';
}

void Doctor::set_num_appointments(int n)
{
	this->number_of_appointments = n;
}

int Doctor::get_num_appointments() const
{
	return number_of_appointments;
}

void Doctor::create_number_appointments()
{
	doctor_appointments = new Appointment[number_of_appointments];
}

Appointment* Doctor::get_created_appointment()
{
	return doctor_appointments;
}

void Doctor::display_timings()
{
	cout<<"THE STARTING TIME OF THE APPOINTMENT IS:\n"<<doctor_appointments->get_starting_time()->to_String()<<'\n';
	cout << "THE ENDING TIME OF THE APPOINTMENT IS:\n" << doctor_appointments->get_ending_time()->to_String()<<'\n'<<'\n';
}
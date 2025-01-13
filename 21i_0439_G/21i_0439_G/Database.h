#pragma once
#include<iostream>
#include"Patient.h"
#include"Doctor.h"
using namespace std;
class Database
{
private:
	int doctor_loggedin_index;
	int patient_loggedin_index;
	int user_type;
	int patient_count;
	int doctor_count;
	Patient* patient_arr;
	Doctor* doctor_arr;
public:
	string ask_pass();
	string ask_cnic();
	string ask_username();
	string ask_Email();
	void main_menu();
	Database();
	bool Register();
	bool CNIC_validator(string cnic);
	bool Pass_validator(string pass);
	bool Email_validation(string email);
	bool cnic_taken(string cnic);
	bool username_taken(string name);
	int select_usertype();
	int Login();
	int login_or_register();
	void welcome_to_odaloc();
	bool time_validator(int hour, int minute);
	int to_Int_start(string);
	int to_Int_end(string);

};


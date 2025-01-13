#pragma once
#include<iostream>
using namespace std;

class User
{
private:
	//Basic Data members which a user of any website may have
	string Username;
	string Password;
	string Email;
	string CNIC;
public:
	//Default Constructor 
	User();

	//Parametrized Constructor to initialize Data members
	User(string Username, string Email, string CNIC, string Password);

	//Setters and Getters
	void setname(const string&);
	const string& getname() const;
	void setpass(const string&);
	const string& getpass() const;
	void setemail(const string&);
	const string& getemail() const;
	void setcnic(const string&);
	const string& getcnic() const;
};


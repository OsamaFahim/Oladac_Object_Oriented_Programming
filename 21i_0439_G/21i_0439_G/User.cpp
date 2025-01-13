#include "User.h"
#include<iostream>
using namespace std;

User::User() : Email(" "), Password(" "), CNIC(" "), Username(" ")
{
	this->setname(" ");
	this->setemail(" ");
	this->setcnic(" ");
	this->setpass(" ");
}

User::User(string Username, string Email, string CNIC, string Password) : Username(Username), Email(Email), CNIC(CNIC), Password(Password)
{
	this->setname(Username);
	this->setemail(Email);
	this->setcnic(CNIC);
	this->setpass(Password);
}

void User::setname(const string& Username)
{
	this->Username = Username;
}

const string& User::getname() const
{
	return this->Username;
}

void User::setpass(const string& Password)
{
	this->Password = Password;
}
const string& User::getpass() const
{
	return this->Password;
}

void User::setemail(const string& Email)
{
	this->Email = Email;
}

const string& User::getemail() const
{
	return this->Email;
}

void User::setcnic(const string& CNIC)
{
	this->CNIC = CNIC;
}

const string& User::getcnic() const
{
	return this->CNIC;
}
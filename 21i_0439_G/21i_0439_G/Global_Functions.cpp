#include"Global_Functions.h"
#include<iostream>

void Spacing(int i)
{
	for (int j = 0; j < i; j++)
	{
		cout << ' ';
	}
}

void lines(int i)
{
	for (int j = 0; j < i; j++)
	{
		cout << '\n';
	}
}

ostream& operator<<(ostream& out, const Doctor& other)
{
	out << other.getname() << " " << other.getemail() << " " << other.getcnic() << " " << other.getpass() << " " << other.get_hospital() << " " << other.get_location() << " " << other.get_specialization()<<" ";
	return out;
}

ostream& operator<<(ostream& out, const Patient& other)
{
	out << other.getname() << " " << other.getemail() << " " << other.getcnic() << " " << other.getpass() << '\n';
	return out;
}

istream& operator>>(istream& in, Patient& other)
{
	string name, email, cnic, password;
	in >> name;
	in >> email;
	in >> cnic;
	in >> password;
	other.setname(name);
	other.setemail(email);
	other.setcnic(cnic);
	other.setpass(password);
	return in;
}

istream& operator>>(istream& in, Doctor& other)
{
	string name, email, cnic, password, hospital, location, specialization;
	in >> name;
	in >> email;
	in >> cnic;
	in >> password;
	in >> hospital;
	in >> location;
	in >> specialization;
	other.setname(name);
	other.setemail(email);
	other.setcnic(cnic);
	other.setpass(password);
	other.set_hospital(hospital);
	other.set_location(location);
	other.set_specialization(specialization);
	return in;
}
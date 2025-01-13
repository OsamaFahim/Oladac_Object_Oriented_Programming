#include<fstream>
#include "Patient.h"

Patient::Patient(string Username, string Email, string CNIC, string Password) : User(Username, Email, CNIC, Password)
{

}

const Patient& Patient::operator= (const Patient& other)
{
	this->setname(other.getname());
	this->setemail(other.getemail());
	this->setcnic(other.getcnic());
	this->setpass(other.getpass());
	return *this;
}
int Patient::getindex()
{
	return search_doc_index;
}
int* Patient::search_doctor(string compare, int type)
{
	ifstream file2("Doctors.txt");
	if (file2.is_open())
	{
		string username;
		string email;
		string pass;
		string cnic;
		string location;
		string specialization;
		string hospital;
		int number_of_appointments;
		int counter = 0;
		int index = 0;
		while (file2 >> username && file2 >> email && file2 >> cnic && file2 >> pass && file2 >> hospital && file2 >> location && file2 >> specialization && file2 >> number_of_appointments)
		{

			string* arr_start = new string[number_of_appointments];
			for (int i = 0; i < number_of_appointments; i++)
			{
				file2 >> arr_start[i];
			}

			string* arr_end = new string[number_of_appointments];
			for (int i = 0; i < number_of_appointments; i++)
			{
				file2 >> arr_end[i];
			}
			if (type == 1)
			{
				if (compare == location)
				{
					int* temp = new int[counter + 1];
					for (int i = 0; i < counter; i++)
					{
						temp[i] = searched_docs[i];
					}
					temp[counter] = index;
					searched_docs = temp;
					counter++;
					search_doc_index = counter;
				}
				index++;
			}
			else if (type == 2)
			{
				if (compare == hospital)
				{
					int* temp = new int[counter + 1];
					for (int i = 0; i < counter; i++)
					{
						temp[i] = searched_docs[i];
					}
					temp[counter] = index;
					searched_docs = temp;
					counter++;
					search_doc_index = counter;
				}
				index++;
			}
			else if (type == 3)
			{
				if (compare == specialization)
				{
					int* temp = new int[counter + 1];
					for (int i = 0; i < counter; i++)
					{
						temp[i] = searched_docs[i];
					}
					temp[counter] = index;
					searched_docs = temp;
					counter++;
					search_doc_index = counter;
				}
				index++;
			}

		}
		return searched_docs;
	}
}

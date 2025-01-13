#pragma once
#include"User.h"
#include"Doctor.h"
class Patient : public User
{
	int* searched_docs;
	int search_doc_index;
public:
	Patient() :User() {}
	Patient(string Username, string Email, string CNIC, string Password);
	const Patient& const operator=(const Patient& other);
	int* search_doctor(string compare, int type);
	int getindex();
};

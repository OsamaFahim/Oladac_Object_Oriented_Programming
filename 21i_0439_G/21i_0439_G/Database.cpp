#include<string>
#include "Database.h"
#include"Patient.h"
#include"Doctor.h"
#include"Global_Functions.h"
#include<fstream>
#include<iostream>
#include <cstdlib>
using namespace std;

Database::Database()
{
	main_menu();
	user_type = select_usertype();
	system("CLS");
	patient_count = 0;
	ifstream file1("Patients.txt");
	if (file1.is_open())
	{
		string username;
		string email;
		string pass;
		string cnic;
		while (file1 >> username && file1 >> email && file1 >> cnic && file1 >> pass)
		{
			Patient* temp = new Patient[patient_count + 1];
			for (int i = 0; i < patient_count; i++)
			{
				temp[i] = patient_arr[i];
			}
			temp[patient_count] = Patient(username, email, cnic, pass);
			patient_count++;
			patient_arr = temp;
		}
	}
	else
	{
		cout << "FILE COULD NOT BE OPENED SUCCESSFULLY:\n";
		patient_arr = nullptr;
	}

	doctor_count = 0;
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

		while (file2 >> username && file2 >> email && file2 >> cnic && file2 >> pass && file2 >> hospital && file2 >> location && file2 >> specialization && file2 >> number_of_appointments)
		{
			
			string* arr_start = new string[number_of_appointments];
			for (int i = 0; i < number_of_appointments; i++)
			{
				file2>>arr_start[i];
			}

			string* arr_end = new string[number_of_appointments];
			for (int i = 0; i < number_of_appointments; i++)
			{
				file2 >> arr_end[i];
			}

			int* start_hour_int = new int[number_of_appointments];
			for (int i = 0; i < number_of_appointments; i++)
			{
				start_hour_int[i] = to_Int_start(arr_start[i]);
			}

			int* start_mint_int = new int[number_of_appointments];
			for (int i = 0; i < number_of_appointments; i++)
			{
				start_mint_int[i] = to_Int_end(arr_start[i]);
			}

			int* end_hour_int = new int[number_of_appointments];
			for (int i = 0; i < number_of_appointments; i++)
			{
				end_hour_int[i] = to_Int_start(arr_end[i]);
			}

			int* end_mint_int = new int[number_of_appointments];
			for (int i = 0; i < number_of_appointments; i++)
			{
				end_mint_int[i] = to_Int_end(arr_end[i]);
			}

			Doctor* temp = new Doctor[doctor_count + 1];
			for (int i = 0; i < doctor_count; i++)
			{
				temp[i] = doctor_arr[i];
			}
			temp[doctor_count] = Doctor(username, email, cnic, pass, hospital, location, specialization, number_of_appointments);
			temp[doctor_count].create_number_appointments();
			for (int i = 0; i < number_of_appointments; i++)
			{
				temp[doctor_count].get_created_appointment()[i].set_appointment_time(start_hour_int[i], start_mint_int[i], end_hour_int[i], end_mint_int[i]);
			}
			doctor_count++;
			doctor_arr = temp;
		}
	}
	else
	{
		cout << "FILE COULD NOT BE OPENED SUCCESSFULLY:\n";
		doctor_arr = nullptr;
	}

}

string Database::ask_cnic()
{
	string cnic;
	cout << "ENTER YOUR CNIC:\n";
	Spacing(40);
	cin >> cnic;
	return cnic;
}

string Database::ask_pass()
{
	string pass;
	cout << "ENTER YOUR PASSWORD:\n";
	Spacing(40);
	cin >> pass;
	return pass;
}

string Database::ask_username()
{
	string username;
	cout << "ENTER YOUR USERNAME:\n";
	Spacing(40);
	cin >> username;
	return username;
}

string Database::ask_Email()
{
	string Email;
	cout << "ENTER YOUR EMAIL:\n";
	Spacing(40);
	cin >> Email;
	return Email;
}

bool Database::Register()
{
	system("CLS");
	bool first_time = true;
	string username;
	bool name_again = false;
	while (!name_again)
	{
		if (first_time)
		{
			lines(10);
			Spacing(40);
			username = ask_username();
			name_again = username_taken(username);
			first_time = false;
		}
		else
		{
			system("CLS");
			lines(10);
			Spacing(40);
			cout << "THE USERNAME IS ALREADY TAKEN , TRY DIFFERENT NAME.\n";
			Spacing(40);
			username = ask_username();
			name_again = username_taken(username);
		}
		cout << '\n';
	}

	string Email;
	first_time = true;
	bool email_validation = false;
	while (!email_validation)
	{
		if (first_time)
		{
			Spacing(40);
			Email = ask_Email();
			email_validation = Email_validation(Email);
			first_time = false;
		}
		else
		{
			system("CLS");
			lines(10);
			Spacing(30);
			cout << "YOU HAVE WRITTEN INVALID EMAIL,YOUR EMAIL MUST BE OF THIS FORM.\n";
			Spacing(30);
			cout << "abc@gmail.com. \n";
			Spacing(40);
			Email = ask_Email();
			email_validation = Email_validation(Email);
		}
	}
	string cnic;
	first_time = true;
	bool cnic_validation = false;
	bool cnic_valid_storer = false;
	bool cnic_again = false;
	while (!cnic_validation)
	{
		if (first_time)
		{
			cout << '\n';
			Spacing(40);
			cnic = ask_cnic();
			cnic_validation = CNIC_validator(cnic);
			cnic_again = cnic_taken(cnic);
			first_time = false;
			cnic_valid_storer = cnic_validation;
			if (!cnic_again)
			{
				cnic_validation = cnic_again;
			}
		}
		else
		{
			if (!cnic_again)
			{
				system("CLS");
				lines(10);
				Spacing(30);
				cout << "THE CNIC IS ALREADY TAKEN LOGIN IF YOU ARE ALREADY A MEMBER\n";
			}
			if (!cnic_valid_storer)
			{
				system("CLS");
				lines(10);
				Spacing(30);
				cout << "YOU HAVE WRITTEN INVALID CNIC NUMBER,YOUR CNIC NUMBER MUST BE OF THIS FORM.\n";
				Spacing(30);
				cout << "XXXXX-XXXXXXX-X WHERE X IS AN INTEGER. \n";
			}

			Spacing(40);
			cnic = ask_cnic();
			cnic_validation = CNIC_validator(cnic);
			cnic_again = cnic_taken(cnic);
			cnic_valid_storer = cnic_validation;
			if (!cnic_again)
				cnic_validation = cnic_again;
		}
	}
	first_time = true;
	string Password;
	bool pass_validation = false;
	while (!pass_validation)
	{
		if (first_time)
		{
			cout << '\n';
			Spacing(40);
			Password = ask_pass();
			pass_validation = Pass_validator(Password);
			first_time = false;
		}
		else
		{
			system("CLS");
			lines(10);
			Spacing(20);
			cout << "YOU HAVE WRITTEN  INVALID PASSWORD,YOUR PASSWORD NUMBER MUST BE 8 CHARACTERS LONG AND\n"; Spacing(20);
			cout << "THE USE OF A MINIMUM OF ONE SPECIAL CHARACTER, UPPERCASE\n";
			Spacing(20);
			cout << "LOWERCASE, AND THE NUMERIC DIGIT IS A MUST..\n";
			Spacing(40);
			Password = ask_pass();
			pass_validation = Pass_validator(Password);
		}
	}
	if (cnic_validation && pass_validation && email_validation && name_again)
	{
		if (user_type == 1)
		{
			Patient* tmp = new Patient[patient_count + 1];
			for (int i = 0; i < patient_count; i++)
			{
				tmp[i] = patient_arr[i];
			}
			tmp[patient_count] = Patient(username, Email, cnic, Password);
			patient_arr = tmp;
			fstream file("Patients.txt", ios::out | ios::app);
			if (file)
			{
				file << tmp[patient_count];
			}
			else
			{
				cout << "File could not be opened:\n";
			}
			patient_count++;
			return true;
		}
		else
		{
			string area;
			string specialization;
			string hospital;
			int starting_hour;
			int starting_minute;
			int ending_hour;
			int ending_minute;
			int number_of_appointments;
			bool first_time = true;
			bool start_time_validator = false;
			bool end_time_validator = false;


			cout << '\n';
			Spacing(40);
			cout << "ENTER YOUR HOSPITAL NAME:\n";
			Spacing(40);
			cin >> hospital;
			cout << '\n';
			Spacing(40);
			cout << "ENTER YOUR SPECIALIZATION:\n";
			Spacing(40);
			cin >> specialization;
			Spacing(40);
			cout << '\n';
			Spacing(40);
			cout << "ENTER YOUR LOCATION:\n";
			Spacing(40);
			cin >> area;
			system("CLS");
			lines(10);
			Spacing(40);
			cout << "ENTER THE NUMBER OF APPOINTMENTS PER DAY:\n";
			Spacing(40);
			cin >> number_of_appointments;
			Spacing(40);
			cout << "FILL THE SLOTS FOR " << number_of_appointments << " appointment :\n";
			Spacing(40);
			Doctor* tmp = new Doctor[doctor_count + 1];
			for (int i = 0; i < doctor_count; i++)
			{
				tmp[i] = doctor_arr[i];
			}
			tmp[doctor_count] = Doctor(username, Email, cnic, Password, hospital, area, specialization, number_of_appointments);
			tmp[doctor_count].create_number_appointments();
			for (int i = 0; i < number_of_appointments; i++)
			{
				cout << '\n';
				Spacing(40);
				end_time_validator = false;
				start_time_validator = false;
				first_time = true;
				while (!start_time_validator)
				{
					if (first_time)
					{
						cout << "ENTER THE STARTIG TIME FOR " << i +1<< " APPOINTMENT:\n";
						Spacing(40);
						cin >> starting_hour;
						system("CLS");
						lines(10);
						Spacing(40);
						cout << "ENTER THE STARTIG TIME FOR " << i + 1<< " APPOINTMENT:\n";
						Spacing(40);
						cout << starting_hour << ':';
						cin >> starting_minute;
						start_time_validator = time_validator(starting_hour, starting_minute);
						first_time = false;
					}
					else
					{
						system("CLS");
						lines(10);
						lines(10);
						Spacing(40);
						cout << "INVALID, ENTER THE STARTIG TIME FOR " << i +1<< " APPOINTMENT:\n";
						Spacing(40);
						cin >> starting_hour;
						system("CLS");
						lines(10);
						Spacing(40);
						cout << "INVALID, ENTER THE STARTIG TIME FOR " << i + 1<< " APPOINTMENT:\n";
						Spacing(40);
						cout << starting_hour << ':';
						cin >> starting_minute;
						start_time_validator = time_validator(starting_hour, starting_minute);
					}
				}
				first_time = true;
				while (!end_time_validator)
				{
					if (first_time)
					{
						Spacing(40);
						cout << "ENTER THE ENDING TIME FOR " << i + 1<< " APPOINTMENT:\n";
						Spacing(40);
						cin >> ending_hour;
						system("CLS");
						lines(10);
						Spacing(40);
						cout << "ENTER THE STARTIG TIME FOR " << i +1<< " APPOINTMENT:\n";
						Spacing(40);
						cout << ending_hour << ':';
						cin >> ending_minute;
						end_time_validator = time_validator(ending_hour, ending_minute);
						first_time = false;
					}
					else
					{
						system("CLS");
						lines(10);
						Spacing(40);
						cout << "INVALID, ENTER THE STARTIG TIME FOR " << i << " APPOINTMENT:\n";
						Spacing(40);
						cin >> ending_hour;
						system("CLS");
						lines(10);
						Spacing(40);
						cout << "INVALID, ENTER THE STARTIG TIME FOR " << i << " APPOINTMENT:\n";
						Spacing(40);
						cout << ending_hour << ':';
						cin >> ending_minute;
						end_time_validator = time_validator(ending_hour, ending_minute);
					}
				}
				tmp[doctor_count].get_created_appointment()[i].set_appointment_time(starting_hour, starting_minute, ending_hour, ending_minute);
			}
			system("CLS");
			doctor_arr = tmp;
			fstream file1("Doctors.txt", ios::out | ios::app);
			if (file1)
			{
				file1 << tmp[doctor_count];
				file1 << number_of_appointments<<" ";
				for (int i = 0; i < number_of_appointments; i++)
				{
					file1 << tmp[doctor_count].get_created_appointment()[i].get_starting_time()->to_String()<<" ";
				}

				for (int i = 0; i < number_of_appointments; i++)
				{
					file1 << tmp[doctor_count].get_created_appointment()[i].get_ending_time()->to_String() << " ";
				}
				file1 << endl;
			}
			else
			{
				cout << "File could not be opened:\n";
			}
			doctor_count++;
			return true;
		}
	}
	return false;
}

int Database::Login()
{
	string username;
	string pass;
	bool flag_pass = false, flag_name = false;
	bool first_time = true;
	if (user_type == 1)
	{
		while (!flag_name)
		{
			if (first_time)
			{
				system("CLS");
				lines(10);
				Spacing(40);
				username = ask_username();
				for (int i = 0; i < patient_count; i++)
				{
					if (patient_arr[i].getname() == username)
					{
						flag_name = true;
						patient_loggedin_index = i;
					}
				}
				first_time = false;
			}
			else
			{
				system("CLS");
				lines(10);
				Spacing(40);
				cout << "INVALID USERNAME, TRY AGAIN:\n";
				Spacing(40);
				username = ask_username();
				for (int i = 0; i < patient_count; i++)
				{
					if (patient_arr[i].getname() == username)
					{
						flag_name = true;
					}
				}
			}
		}
		first_time = true;
		while (!flag_pass)
		{
			if (first_time)
			{
				cout << '\n';
				Spacing(40);
				pass = ask_pass();
				for (int i = 0; i < patient_count; i++)
				{
					if (patient_arr[i].getpass() == pass)
					{
						flag_pass = true;
					}
				}
				first_time = false;
			}
			else
			{
				system("CLS");
				lines(10);
				Spacing(40);
				cout << "INVALID PASSWORD, TRY AGAIN:\n";
				Spacing(40);
				pass = ask_pass();
				for (int i = 0; i < patient_count; i++)
				{
					if (patient_arr[i].getpass() == pass)
					{
						flag_pass = true;
					}
				}
			}
		}
	}
	else
	{
		while (!flag_name)
		{
			if (first_time)
			{
				system("CLS");
				lines(10);
				Spacing(40);
				username = ask_username();
				for (int i = 0; i < doctor_count; i++)
				{
					if (doctor_arr[i].getname() == username)
					{
						flag_name = true;
						doctor_loggedin_index = i;
					}
				}
				first_time = false;
			}
			else
			{
				system("CLS");
				lines(10);
				Spacing(40);
				cout << "INVALID USERNAME, TRY AGAIN:\n";
				Spacing(40);
				username = ask_username();
				for (int i = 0; i < doctor_count; i++)
				{
					if (doctor_arr[i].getname() == username)
					{
						flag_name = true;
					}
				}
			}
		}
		first_time = true;
		while (!flag_pass)
		{
			if (first_time)
			{
				system("CLS");
				lines(10);
				Spacing(40);
				pass = ask_pass();
				for (int i = 0; i < doctor_count; i++)
				{
					if (doctor_arr[i].getpass() == pass)
					{
						flag_pass = true;
					}
				}
			}
			else
			{
				system("CLS");
				lines(10);
				Spacing(40);
				cout << "INVALID PASSWORD, TRY AGAIN:\n";
				Spacing(40);
				username = ask_pass();
				for (int i = 0; i < doctor_count; i++)
				{
					if (doctor_arr[i].getpass() == pass)
					{
						flag_name = true;
					}
				}
			}
		}
	}
	return user_type;
}

bool Database::CNIC_validator(string cnic)
{
	int counter = 0;
	for (int i = 0; cnic[i] != '\0'; i++)
	{
		if (cnic[i] >= 48 && cnic[i] <= 57 || cnic[i] == '-')
		{
			counter++;
		}
		else
		{
			return false;
		}

		if (counter == 5 || counter == 13)
		{
			if (cnic[counter] != '-')
			{
				return false;
			}
		}
	}
	if (counter != 15)
	{
		return false;
	}
}

bool Database::Pass_validator(string pass)
{
	int counter = 0;
	bool upper_valid = false, lower_valid = false, numeric_valid = false, special_valid = false;

	for (int i = 0; pass[i] != '\0'; i++)
	{
		if (pass[i] >= 65 && pass[i] <= 90)
		{
			counter++;
			upper_valid = true;
		}

		if (pass[i] >= 97 && pass[i] <= 122)
		{
			counter++;
			lower_valid = true;
		}

		if ((pass[i] >= 32 && pass[i] <= 47) ||
			(pass[i] >= 58 && pass[i] <= 64) ||
			(pass[i] >= 91 && pass[i] <= 96) ||
			(pass[i] >= 123 && pass[i] <= 126))
		{
			counter++;
			special_valid = true;
		}

		if (pass[i] >= 48 && pass[i] <= 57)
		{
			counter++;
			numeric_valid = true;
		}
	}

	if (counter < 8 || !numeric_valid || !upper_valid || !lower_valid || !special_valid)
	{
		return false;
	}
	return true;
}

bool Database::Email_validation(string email)
{
	int counter = 0;
	bool at_the_rate = false;
	for (int i = 0; email[i] != '\0'; i++)
	{
		if (email[i] == '@')
		{
			return true;
		}
	}
	return false;
}

bool Database::cnic_taken(string cnic)
{
	for (int i = 0; i < patient_count; i++)
	{
		if (patient_arr[i].getcnic() == cnic)
		{
			return false;
		}
	}

	for (int i = 0; i < doctor_count; i++)
	{
		if (doctor_arr[i].getcnic() == cnic)
		{
			return false;
		}
	}
	return true;
}

bool Database::username_taken(string name)
{
	for (int i = 0; i < patient_count; i++)
	{
		if (patient_arr[i].getname() == name)
		{
			return false;
		}
	}

	for (int i = 0; i < doctor_count; i++)
	{
		if (doctor_arr[i].getname() == name)
		{
			return false;
		}
	}
	return true;
}

void Database::main_menu()
{
	lines(5);
	Spacing(10);
	cout << "=============================================================================================\n";
	Spacing(20);
	cout << "WELCOME TO OLADOC WHERE YOU WANT TO BECOME SICK AGAIN AND AGAIN:\n";
	Spacing(10);
	cout << "=============================================================================================\n";
}

int Database::select_usertype()
{
	int choice;
	lines(5);
	Spacing(20);
	cout << "PRESS 1 IF YOU ARE A PATIENT?:\n";
	Spacing(20);
	cout << "PRESS 2 IF YOU ARE A DOCTOR?:\n";
	Spacing(20);
	cin >> choice;
	return choice;
}

int Database::login_or_register()
{
	int choice;
	lines(10);
	Spacing(40);
	cout << "PRESS 1 FOR LOGIN:\n";
	Spacing(40);
	cout << "PRESS 2 FOR REGISTER:\n";
	Spacing(40);
	cin >> choice;
	return choice;
}

void Database::welcome_to_odaloc()
{
	int patient_navigate;
	int type;
	int choice;
	choice = login_or_register();
	if (choice == 1)
	{
		type = Login();
		if (type == 1)
		{
			system("CLS");
			lines(10);
			Spacing(40);
			cout << "PRESS 1 TO BOOK AN APPOINTMENT.\n";
			Spacing(40);
			cin >> patient_navigate;
			if (patient_navigate == 1)
			{
				int doc_search;
				system("CLS");
				lines(10);
				Spacing(20);
				cout << "FOR AN APPOINTMENT, YOU WANT TO SEARCH A DOCTOR BY AREA, HOSPITAL, OR \n"; Spacing(20); cout << "SPECIALIZAION ? (1.AREA / 2.HOSPITAL / 3.SPECIALIZATION) \n";
				Spacing(40);
				cin >> doc_search;
				if (doc_search == 1)
				{
					int* index_docs;
					string area;
					Spacing(40);
					cout << "ENTER THE AREA YOU WANT TO SEARCH BY:\n";
					Spacing(40);
					cin >> area;
					index_docs = patient_arr[patient_loggedin_index].search_doctor(area, doc_search);
					system("CLS");
					lines(5);
					Spacing(30);
					cout << "THE DOCTORS ACCORDING TO REQUIREMENTS ARE:\n\n";
					cout << "NAMES				LOCATION				SPECIALIZATION			HOSPITAL   \n";
					for (int i = 0; i < patient_arr[patient_loggedin_index].getindex(); i++)
					{
						doctor_arr[index_docs[i]].Display();
					}
					int choose_doc;
					cout << "\n\n";
					Spacing(40);
					cout << "WHICH DOCTOR WHOULD YOU LIKE TO TAKE AN APPOINTMENT WITH ? \n";
					Spacing(40);
					cin >> choose_doc;
					choose_doc = choose_doc - 1;
					cout << "THE TIMINGS OF THE DOCTOR IS:\n";
					for (int i = 0; i<doctor_arr[index_docs[choose_doc]].get_num_appointments(); i++)
					{
						cout << "THE STARTING TIME OF THE DOCTOR APPOINTMENT " << i + 1 << " IS:\n" << doctor_arr[index_docs[choose_doc]].get_created_appointment()[i].get_starting_time()->to_String() << '\n';
						cout << "THE ENDING TIME OF THE DOCTOR APPOINTMENT " << i + 1 << " is:\n" << doctor_arr[index_docs[choose_doc]].get_created_appointment()[i].get_starting_time()->to_String() << '\n';
					}
				}
				else if (doc_search == 2)
				{
					int* index_docs;
					string hospital;
					Spacing(40);
					cout << "ENTER THE HOSPITAL YOU WANT TO SEARCH BY:\n";
					Spacing(40);
					cin >> hospital;
					index_docs = patient_arr[patient_loggedin_index].search_doctor(hospital, doc_search);
					system("CLS");
					lines(5);
					Spacing(30);
					cout << "THE DOCTORS ACCORDING TO REQUIREMENTS ARE:\n\n";
					cout << "NAMES				LOCATION				SPECIALIZATION			HOSPITAL   \n";
					for (int i = 0; i < patient_arr[patient_loggedin_index].getindex(); i++)
					{
						doctor_arr[index_docs[i]].Display();
					}
				}
				else if (doc_search == 3)
				{
					int* index_docs;
					string specialization;
					Spacing(40);
					cout << "ENTER THE SPECIALIZATION YOU WANT TO SEARCH BY:\n";
					Spacing(40);
					cin >> specialization;
					index_docs = patient_arr[patient_loggedin_index].search_doctor(specialization, doc_search);
					system("CLS");
					lines(5);
					Spacing(30);
					cout << "THE DOCTORS ACCORDING TO REQUIREMENTS ARE:\n\n";
					cout << "NAMES\t\t\t\tLOCATION\t\t\t\tSPECIALIZATION\t\t\tHOSPITAL\n";
					for (int i = 0; i < patient_arr[patient_loggedin_index].getindex(); i++)
					{
						doctor_arr[index_docs[i]].Display();
					}
				}
			}
		}

	}
	else
	{
		Register();
	}
}

bool Database::time_validator(int hour, int minute)
{
	if (hour > 24 || minute>60)
	{
		return false;
	}
}

int Database::to_Int_start(string s)
{
	string tmp="";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ':')
		{
			tmp += s[i];
		}
		else
		{
			break;
		}
	}
	return stoi(tmp);
}

int Database::to_Int_end(string s)
{
	int counter = 0;
	string tmp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ':')
		{
			counter++;
		}
		else
		{
			break;
		}
	}

	for (int i = counter + 1; i < s.length(); i++)
	{
		tmp += s[i];
	}
	return stoi(tmp);
}
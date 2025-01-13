#pragma once
#include"Patient.h"
#include"Doctor.h"
#include<iostream>
using namespace std;

void Spacing(int i);
void lines(int i);

ostream& operator<<(ostream& out, const Patient& other);
istream& operator>>(istream& in, const Patient& other);

ostream& operator<<(ostream& out, const Doctor& other);
istream& operator>>(istream& in, const Doctor& other);
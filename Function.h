#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Staff.h"
#include "Teacher.h"
#include "Employee.h"

using namespace std;

int readFile(vector<Person>&,vector<Student>&, vector<Employee>&, vector<Teacher>& teachers, vector<Person*> &all, ofstream& fout);
void printVector(vector<Person>, ofstream& fout);
void printVector(vector<Student>, ofstream& fout);
void printVector(vector<Employee>, ofstream& fout);
void printVector(vector<Teacher>, ofstream& fout);
void printVector(vector<Person*>, ofstream& fout);

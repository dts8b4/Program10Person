#pragma once
#include "Staff.h"

class Employee : public Staff {
private:
  int vacDays;

public:
  Employee();
  Employee(string lName, string fName, int age, float rate, int hours, int vacDays);

  int getVacDays(){ return vacDays; }
  void  setVacDays(int days) { vacDays = days; }

  void print(ofstream& fout);
  static int totalEmployees;
};
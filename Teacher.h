#pragma once
#include "Staff.h"

class Teacher : public Staff {
private:
  string subject;

public:
  Teacher();
  Teacher(string lName, string fName, int age, float rate, int hours, string subject);

  string getSubject(){ return subject; }
  void  setSubject(string s) { subject = s; }

  void print(ofstream& fout);
  static int totalTeachers;
};
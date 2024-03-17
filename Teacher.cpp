#include "Teacher.h"

Teacher::Teacher() : Staff() {
  type = 'T';
  subject = " ";
  totalTeachers++;
}

Teacher::Teacher(string l, string f, int a, float r, int h, string s)
  : Staff('T', l, f, a, h, r) {
  subject = s;
  totalTeachers++;
}

void Teacher::print(ofstream& fout) {
    fout << type << left << setw(4) << " "
    << setw(15) << lname
    << setw(15) << fname
    << setw(5) << right << age 
    << setw(10) << "Hours: " << hours << ", Rate: " << hrlyRate
    << ", Subject: " << subject << endl;
}
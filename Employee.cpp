#include "Employee.h"

Employee::Employee() : Staff() {
  type = 'E';
  vacDays = 0;
  totalEmployees++;
}

Employee::Employee(string l, string f, int a, float r, int h, int v)
  : Staff('E', l, f, a, h, r) {
  vacDays = v;
  totalEmployees++;
}

void Employee::print(ofstream& fout) {
    fout << type << left << setw(4) << " "
    << setw(15) << lname
    << setw(15) << fname
    << setw(5) << right << age 
    << setw(10) << "Hours: " << hours << ", Rate: " << hrlyRate
    << ", Vac. Days: " << vacDays << endl;
}
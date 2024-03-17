#include "Function.h"

int readFile(vector<Person>& people, vector<Student>& students, 
             vector<Employee>& employees, vector<Teacher>& teachers, vector<Person*>& allPeople, ofstream& fout) {

  //OPEN THE INPUT FILE
  ifstream inFile;
  inFile.open("people.txt");
  if (!inFile.is_open()) {
    cout << "File is not open" << endl;
    return 1;
  }

  //SET TEMPORARY VARIABLES FOR INPUTTING PERSON INFORMATION
  string inRec, tempStr;
  vector <string> row;

  //LOOP THROUGH THE INPUT FILE
  while (getline(inFile, inRec)) {
    //CHANGE THE INPUT RECORD inRec TO BECOME STRING STREAM inSS
    //THIS WILL ALLOW US TO USE THE RECORD inRec AS THOUGH IT IS
    //AN INPUT STREAM (USEFUL WHEN INPUT IS NOT FIXED)
    stringstream inSS(inRec);
    row.clear();
    while (getline(inSS, tempStr, ',')) {  // Loop over stringstream, delimited by commas
      row.push_back(tempStr);              // Push line to row
    }
    try{
      if (row[0][0] == 'S') {                                                         // If Student
        Student* tempSP = new Student(row[1], row[2], stoi(row[3]), stof(row[4]));    // Make new student pointer
        students.push_back(*tempSP);                                                  // Push object to student vector
        allPeople.push_back(tempSP);                                                  // Push pointer to all people vector
      }
      else if (row[0][0] == 'E') {                                                                                // If Employee
        Employee* tempEP = new Employee(row[1], row[2], stoi(row[3]), stof(row[5]), stoi(row[4]), stoi(row[6]));  // Make new employee pointer
        employees.push_back(*tempEP);                                                                             // Push object to employees vector
        allPeople.push_back(tempEP);                                                                              // Push pointer to all people vector
      } else if (row[0][0] == 'T') {                                                                      // If Teacher
        Teacher* tempTP = new Teacher(row[1], row[2], stoi(row[3]), stof(row[5]), stoi(row[4]), row[6]);  // Make new teacher pointer
        teachers.push_back(*tempTP);                                                                      // Push object to teachers vector
        allPeople.push_back(tempTP);                                                                      // Push pointer to all people vector
      }
      else  {                                                       // Else, generic person
        Person* tempPP = new Person(row[1], row[2], stoi(row[3]));  // Make new person pointer
        people.push_back(*tempPP);                                  // Push object to people vector
        allPeople.push_back(tempPP);                                // Push pointer on all people vector
      }
    }
    catch(...){                                         // Any errors in reading the file
      fout << "RECORD: " << inRec << " IS IN ERROR\n";  // Prints error to console
    }
  }
  inFile.close(); // Close the file
  return 0;
}

// Printing Generic People Vector to Out File
void printVector(vector<Person> people, ofstream& fout) {
  // Headers
  fout << "\n\nTYPE" << setw(11) << "LAST NAME"
  << setw(17) << "FIRST NAME" << setw(8) << "AGE"
  << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  // Data
  for (int i = 0; i < people.size(); i++)
      people.at(i).print(fout); 
  // Total (Gives total of generic people, not all people)
  fout << "\nTOTAL PEOPLE: " << people.size() << endl;
}

// Printing Student Vector to Out File
void printVector(vector<Student> student, ofstream& fout) {
  // Headers
  fout << "\n\nTYPE" << setw(11) << "LAST NAME"
    << setw(17) << "FIRST NAME" << setw(8) << "AGE"
    << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  // Data
  for (int i = 0; i < student.size(); i++)
    student.at(i).print(fout);
  // Total
  fout << "\nTOTAL STUDENTS: " << Student::totalStudents << endl;
}

// Printing Employee Vector to Out File
void printVector(vector<Employee> employee, ofstream& fout) {
  // Headers
  fout << "\n\nTYPE" << setw(11) << "LAST NAME"
    << setw(17) << "FIRST NAME" << setw(8) << "AGE"
    << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  // Data
  for (int i = 0; i < employee.size(); i++)
    employee.at(i).print(fout);
  // Total
  fout << "\nTOTAL EMPLOYEES: " << Employee::totalEmployees << endl;
}

// Printing Teacher Vector to Out File
void printVector(vector<Teacher> teacher, ofstream& fout) {
  // Headers
  fout << "\n\nTYPE" << setw(11) << "LAST NAME"
    << setw(17) << "FIRST NAME" << setw(8) << "AGE"
    << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  // Data
  for (int i = 0; i < teacher.size(); i++)
    teacher.at(i).print(fout);
  // Total
  fout << "\nTOTAL TEACHERS: " << Teacher::totalTeachers << endl;
}

// Printing All People Vector to Out File
void printVector(vector<Person*> allPeople, ofstream& fout) {
  // Headers
  fout << "\n\nTYPE" << setw(11) << "LAST NAME"
    << setw(17) << "FIRST NAME" << setw(8) << "AGE"
    << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  // Data
  for (int i = 0; i < allPeople.size(); i++)
    allPeople.at(i)->print(fout);
  // Total (total of ALL people)
  fout << "\nTOTAL PEOPLE: " << Person::totalPeople << endl;
}


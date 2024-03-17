/*
Name: Dylan Sullins
Email: dts8b4@umsystem.edu
Date: 03/17/2024
Program 10: Person Class

All work either provided by the instructor or written by Dylan Sullins in VSCode and compiled with G++.

Compiles without error using G++ version 10.3.1 20210520 on a Windows 11 Desktop.
To replicate the process, simply open the directory in a command prompt and enter the following commands: 
    "g++ *.cpp -o main" followed by "./main" 
The output.txt will be populated with the results. 

Main Program
    Create vectors for generic people, students, 
        employees, teachers, and all people
    Create and open output file
    Read input file
        Load each row as an object into correct vectors based on first character
            S = Student
            T = Teacher
            E = Employee
            P = Generic Person
        Each object pointer is pushed to the all people vector
        If an error occurs, error is written to output file
    Print each vector
        Print headers
        Print each record in vector 
    Close output file
End Main
*/

#include "Function.h"


//add Static Member initialization
int Person::totalPeople = 0;
int Student::totalStudents = 0;
int Teacher::totalTeachers = 0;
int Employee::totalEmployees = 0;
int Staff::totalStaff = 0;


int main()
{
    //create a vector of Person type
    vector<Person> myPeople;
    vector<Student> myStudents;
    vector<Employee> myEmployees;
    vector<Teacher> myTeachers;
    vector<Person*> allPeople;
    ofstream fileOutput;

    // Open outfile
    fileOutput.open("output.txt");

    // read the file & load into vector of Personal type
    readFile(myPeople, myStudents, myEmployees, myTeachers, allPeople, fileOutput);

    // print the vectors
    printVector(myPeople, fileOutput);
    printVector(myStudents, fileOutput);
    printVector(myEmployees, fileOutput);
    printVector(myTeachers, fileOutput);
    printVector(allPeople, fileOutput);

    // Close outfile
    fileOutput.close();
}

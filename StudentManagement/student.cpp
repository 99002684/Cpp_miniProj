#include"student.h"
#include <string>


Student::Student():Student_ID(0),Student_Name(""),Student_Percentage(0.0), Gender(""){}

Student::Student(int Student_ID, std::string Student_Name, double Student_Percentage, std::string Gender) : Student_ID(Student_ID),Student_Name(Student_Name),Student_Percentage(Student_Percentage), Gender(Gender) {}



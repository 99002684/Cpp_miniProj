#include <string>
#include "student.h"
#include "highSchoolStudent.h"


HighSchoolStudent::HighSchoolStudent():Student(),Standard(""),Student_Address(""){}


HighSchoolStudent::HighSchoolStudent(int Student_ID, std::string Student_Name, double Student_Percentage, std::string Gender,std::string Standard,std::string Student_Address):
    Student(Student_ID,Student_Name,Student_Percentage,Gender),Standard(Standard),Student_Address(Student_Address){

    }


int HighSchoolStudent::getID(){

    return Student_ID;

}


std::string HighSchoolStudent::getGender(){

    return Gender;

}


std::string HighSchoolStudent::getName(){

    return Student_Name;

}


double HighSchoolStudent::getPercantage(){

    return Student_Percentage;

}




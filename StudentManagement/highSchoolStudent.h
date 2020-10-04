#include <string>
#include "student.h"
#pragma once


class HighSchoolStudent : public Student {

private :
    std::string Standard;
    std::string Student_Address;

public :
    HighSchoolStudent();
    HighSchoolStudent(int ,std::string,double , std::string,std::string,std::string);
    int getID();
    std::string getGender();
    std::string getName();
    double getPercantage();
//    int getDistance();
};


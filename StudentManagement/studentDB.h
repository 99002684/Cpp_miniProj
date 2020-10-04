#include<string>
#include<cstdint>
#include "student.h"
#include "highSchoolStudent.h"
#pragma once
#include <list>
#include <iterator>
#pragma once


class StudentDB :  public HighSchoolStudent {

public :
    std::list <HighSchoolStudent> highschool_student;

    void addStudent(int , std::string , double , std::string ,std::string, std::string);
    void removeStudent(std::string);
    HighSchoolStudent* findStudentById(int);
    double getMaxPercantage();
    int getStudentsBygender(std::string);
    int getAll();

};








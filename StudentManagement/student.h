#include <string>
#pragma once


class Student
{
    public:
        int Student_ID;
        std::string Student_Name;
        double Student_Percentage;
        std::string Gender;

    public:
        Student();
        Student(int Student_ID, std::string Student_Name, double Student_Percentage, std::string Gender);
        virtual double getPercantage()=0;
};




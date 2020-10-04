#include "highSchoolStudent.h"
#include "student.h"
#include "studentDB.h"
#include <string>
#include <list>
#include <iterator>
#include <thread>
#include <semaphore.h>
#include <iostream>


void StudentDB::addStudent(int Student_ID, std::string Student_Name, double Student_Percantage, std::string Gender,std::string Standard, std::string Student_Address){

    highschool_student.push_back(HighSchoolStudent(Student_ID, Student_Name, Student_Percantage, Gender, Standard, Student_Address));

}


void StudentDB::removeStudent(std::string Student_Name){

    std::list<HighSchoolStudent> :: iterator iter;
    for(iter=highschool_student.begin();iter!=highschool_student.end();iter++)
    {
        if(iter->getName()== Student_Name)
        {
           highschool_student.erase(iter);
           break;
        }
    }
}


double StudentDB::getMaxPercantage(){

    std:: list<HighSchoolStudent> :: iterator iter = highschool_student.begin();
    auto maxPerc  = iter->getPercantage();

    iter++;
    for(;iter!=highschool_student.end();++iter)
    {
        if(maxPerc < iter->getPercantage())
        {
            maxPerc = iter->getPercantage();
           // maxiter = iter;
        }

    }
    return maxPerc;
}


int StudentDB::getStudentsBygender(std::string Gender){

    int m_count = 0;
    std::list<HighSchoolStudent> :: iterator iter;
    for(iter=highschool_student.begin();iter!=highschool_student.end();iter++)
    {
        if(Gender == iter->getGender())
        {
            m_count++;
        }
    }
    return m_count;
}


int StudentDB::getAll(){

          return highschool_student.size();
}




#include "student.h"
#include "highSchoolStudent.h"
#include "studentDB.h"
#include <gtest/gtest.h>
#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<list>
#include<iterator>
#include<cstdint>


pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;
StudentDB students;


void* efun1(void* pv){

        pthread_mutex_lock(&m1);
        students.addStudent(1,"Parth", 90.64 , "M", "A","Thane");
        students.addStudent(2,"Priti", 96.89 , "F", "A","Mumbai");
        students.addStudent(3,"Nachiket", 94.53 , "M", "B","Lonavala");
        students.addStudent(4,"Ankita", 88.93 , "F", "A","Airoli");
        students.addStudent(5,"Swastik", 78.13 , "M", "C","Pune");
        students.addStudent(6,"Savita", 60.21 , "F", "A","Thane");
        pthread_mutex_unlock(&m1);
        sem_post(&s1);
}


void* efun2(void* pv)
{
        sem_wait(&s1);
        pthread_mutex_lock(&m1);
        std::cout<<"\n";
        std::cout<<"The producer added :"<<students.getAll()<<" SavingsAccountDetails\n";
        std::cout<<"\n";
        pthread_mutex_unlock(&m1);
}


namespace {
class HighSchoolStudentDbTest : public ::testing::Test {

protected:
  void SetUp() {
  }

  void TearDown() {}
};

TEST_F(HighSchoolStudentDbTest, AddStudentTest) {

    pthread_t pt1,pt2;
    sem_init(&s1,0,0);
    pthread_create(&pt1,NULL,efun1,NULL);
    pthread_create(&pt2,NULL,efun2,NULL);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);
    students.addStudent(7,"Shrey", 80.21 , "M", "A","Mumbai");
    EXPECT_EQ(7, students.getAll());
    sem_destroy(&s1);
    pthread_mutex_destroy(&m1);
}


TEST_F(HighSchoolStudentDbTest, RemoveTripTest) {
  students.removeStudent("Parth");
  EXPECT_EQ(6, students.getAll());
}


TEST_F(HighSchoolStudentDbTest, CountTest) {
  EXPECT_EQ(6, students.getAll());
}


TEST_F(HighSchoolStudentDbTest, getStudentsBygender) {
  int count = students.getStudentsBygender("F");
  EXPECT_EQ(3, count);
}


TEST_F(HighSchoolStudentDbTest, MaxFareTest) {
  double maxPerc = students.getMaxPercantage();
  EXPECT_EQ(96.89, maxPerc);
}


TEST_F(HighSchoolStudentDbTest, AnotherTest) {
  students.addStudent(8,"Kajal", 84.21 , "F", "A","Pune");
  students.addStudent(9,"Kaivalya", 90.21 , "M", "A","Mumbai");
  int count = students.getStudentsBygender("M");
  double maxPerc = students.getMaxPercantage();
  EXPECT_EQ(8, students.getAll());
  EXPECT_EQ(4, count);
  EXPECT_EQ(96.89, maxPerc);
}
}




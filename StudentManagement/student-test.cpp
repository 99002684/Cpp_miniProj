#include "student.h"
#include "highSchoolStudent.h"
#include "studentDB.h"
#include <gtest/gtest.h>

namespace {

class StudentTest : public ::testing::Test {

protected:
  void SetUp() {
    ptr = new HighSchoolStudent(1,"Parth", 90.64 , "M", "A","Thane");
  }
  void TearDown() {
    delete ptr;
  }
  Student *ptr;
};

TEST_F(StudentTest, DefaultConstructor) {
  HighSchoolStudent ft;
  EXPECT_EQ(0, ft.getID());
  EXPECT_EQ(0, ft.getGender().length());
  EXPECT_EQ(0, ft.getName().length());
  EXPECT_EQ(0, ft.getPercantage());

}


TEST_F(StudentTest, ParameterizedConstructor) {
  HighSchoolStudent *fptr = dynamic_cast<HighSchoolStudent*>(ptr);
  EXPECT_EQ( 1, fptr->getID());
  EXPECT_STREQ("M", fptr->getGender().c_str());
  EXPECT_STREQ("Parth", fptr->getName().c_str());
  EXPECT_EQ(90.64, fptr->getPercantage());

}


TEST_F(StudentTest, AnotherTest) {
  HighSchoolStudent ft(2,"Priti", 96.89 , "F", "A","Mumbai");
  Student *pt = &ft;
  EXPECT_EQ( 2, ft.getID());
  EXPECT_STREQ("F", ft.getGender().c_str());
  EXPECT_STREQ("Priti", ft.getName().c_str());
  EXPECT_EQ(96.89, ft.getPercantage());
}

}




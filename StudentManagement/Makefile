all: all.out
all.out : student.o highSchoolStudent.o studentDB.o student-test.o student-testDB.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
student-testDB.o: student-testDB.cpp student.h highSchoolStudent.h studentDB.h
	g++ $< -c
student-test.o: student-test.cpp student.h highSchoolStudent.h
	g++ $< -c
studentDB.o: studentDB.cpp studentDB.h highSchoolStudent.h student.h
	g++ $< -c
highSchoolStudent.o: highSchoolStudent.cpp highSchoolStudent.h student.h
	g++ $< -c
student.o: student.cpp student.h
	g++ $< -c
clean:
	rm -rf *.o *.out

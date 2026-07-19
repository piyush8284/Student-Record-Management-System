#include "Student.h"

Student::Student()
{
    rollNo = 0;
    name = "";
    branch = "";
    semester = 0;
    marks = 0;
}

Student::Student(int rollNo, string name, string branch, int semester, float marks)
{
    this->rollNo = rollNo;
    this->name = name;
    this->branch = branch;
    this->semester = semester;
    this->marks = marks;
}
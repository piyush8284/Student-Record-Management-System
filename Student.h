#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    string branch;
    int semester;
    float marks;

    Student();

    Student(int rollNo, string name, string branch, int semester, float marks);
};

#endif
#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"

#include <vector>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

class StudentManager
{
private:

    vector<Student> students;

    // Stores Roll Number -> Index
    map<int, int> studentMap;


    // Rebuild map after sorting/deleting
    void rebuildMap();


    // Binary Search Function
    int binarySearch(int roll);


public:

    StudentManager();


    // CRUD Operations

    void addStudent();

    void displayStudents();

    void searchStudent();

    void updateStudent();

    void deleteStudent();



    // Sorting Operations

    void sortByName();

    void sortByMarks();

    void sortByRoll();



    // Filtering

    void filterStudents();



    // File Handling

    void saveToFile();

    void loadFromFile();

};

#endif
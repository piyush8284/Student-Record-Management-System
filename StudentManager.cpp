#include "StudentManager.h"
#include <iomanip>
#include <sstream>
using namespace std;


// Constructor
StudentManager::StudentManager()
{
    loadFromFile();
}


// Rebuild Map after sorting/deleting
void StudentManager::rebuildMap()
{
    studentMap.clear();

    for(int i = 0; i < students.size(); i++)
    {
        studentMap[students[i].rollNo] = i;
    }
}


// Binary Search
int StudentManager::binarySearch(int roll)
{
    int low = 0;
    int high = students.size() - 1;


    while(low <= high)
    {
        int mid = (low + high) / 2;


        if(students[mid].rollNo == roll)
        {
            return mid;
        }

        else if(students[mid].rollNo < roll)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }


    return -1;
}



// Add Student
void StudentManager::addStudent()
{
    int roll;
    string name;
    string branch;
    int sem;
    float marks;


    cout << "\nEnter Roll Number : ";
    cin >> roll;


    if(studentMap.find(roll) != studentMap.end())
    {
        cout << "\nRoll Number Already Exists!\n";
        return;
    }


    cin.ignore();


    cout << "Enter Name : ";
    getline(cin,name);


    cout << "Enter Branch : ";
    getline(cin,branch);


    cout << "Enter Semester : ";
    cin >> sem;


    cout << "Enter Marks : ";
    cin >> marks;



    Student s(roll,name,branch,sem,marks);


    students.push_back(s);


    rebuildMap();


    cout << "\nStudent Added Successfully.\n";
}



// Display Students
void StudentManager::displayStudents()
{
    if(students.empty())
    {
        cout << "\nNo Student Records Found.\n";
        return;
    }


    cout << "\n=====================================================================\n";


    cout << left
         << setw(10) << "Roll"
         << setw(25) << "Name"
         << setw(15) << "Branch"
         << setw(12) << "Semester"
         << setw(10) << "Marks";


    cout << "\n=====================================================================\n";


    for(Student s : students)
    {
        cout << left
             << setw(10) << s.rollNo
             << setw(25) << s.name
             << setw(15) << s.branch
             << setw(12) << s.semester
             << setw(10) << s.marks
             << endl;
    }
}



// Search Student using Binary Search
void StudentManager::searchStudent()
{
    int roll;


    sortByRoll();


    cout << "\nEnter Roll Number : ";
    cin >> roll;


    int index = binarySearch(roll);



    if(index == -1)
    {
        cout << "\nStudent Not Found.\n";
        return;
    }


    Student s = students[index];


    cout << "\n========== Student Details ==========\n";


    cout << "Roll Number : " << s.rollNo << endl;
    cout << "Name        : " << s.name << endl;
    cout << "Branch      : " << s.branch << endl;
    cout << "Semester    : " << s.semester << endl;
    cout << "Marks       : " << s.marks << endl;
}



// Update Student
void StudentManager::updateStudent()
{
    int roll;


    cout << "\nEnter Roll Number : ";
    cin >> roll;



    if(studentMap.find(roll) == studentMap.end())
    {
        cout << "\nStudent Not Found.\n";
        return;
    }


    int index = studentMap[roll];


    cin.ignore();


    cout << "Enter New Name : ";
    getline(cin,students[index].name);


    cout << "Enter New Branch : ";
    getline(cin,students[index].branch);


    cout << "Enter New Semester : ";
    cin >> students[index].semester;


    cout << "Enter New Marks : ";
    cin >> students[index].marks;



    cout << "\nStudent Updated Successfully.\n";
}



// Delete Student
void StudentManager::deleteStudent()
{
    int roll;


    cout << "\nEnter Roll Number : ";
    cin >> roll;



    if(studentMap.find(roll)==studentMap.end())
    {
        cout << "\nStudent Not Found.\n";
        return;
    }


    int index = studentMap[roll];


    students.erase(students.begin()+index);



    rebuildMap();



    cout << "\nStudent Deleted Successfully.\n";
}



// Sort by Name
void StudentManager::sortByName()
{
    sort(students.begin(),
         students.end(),

    [](Student a, Student b)
    {
        return a.name < b.name;
    });


    rebuildMap();


    cout << "\nSorted By Name.\n";
}



// Sort by Marks
void StudentManager::sortByMarks()
{
    sort(students.begin(),
         students.end(),

    [](Student a, Student b)
    {
        return a.marks > b.marks;
    });



    rebuildMap();


    cout << "\nSorted By Marks.\n";
}



// Sort by Roll
void StudentManager::sortByRoll()
{
    sort(students.begin(),
         students.end(),

    [](Student a, Student b)
    {
        return a.rollNo < b.rollNo;
    });



    rebuildMap();
}



// Filter Students
void StudentManager::filterStudents()
{
    float marks;


    cout << "\nEnter Minimum Marks : ";
    cin >> marks;



    bool found=false;



    for(Student s:students)
    {
        if(s.marks >= marks)
        {
            found=true;


            cout << "\nRoll : " << s.rollNo;
            cout << "\nName : " << s.name;
            cout << "\nMarks : " << s.marks;
            cout << "\n-------------------------\n";
        }
    }



    if(!found)
    {
        cout << "\nNo Students Found.\n";
    }
}



// Save Data
void StudentManager::saveToFile()
{
     ofstream file("students.txt");


    for(Student s : students)
    {
        file << s.rollNo << ","
             << s.name << ","
             << s.branch << ","
             << s.semester << ","
             << s.marks
             << endl;
    }


    file.close();


    cout << "\nData Saved Successfully.\n";
}



// Load Data
void StudentManager::loadFromFile()
{ifstream file("students.txt");

    if(!file)
        return;


    students.clear();


    string line;


    while(getline(file,line))
    {
        try
        {
            stringstream ss(line);

            string roll;
            string name;
            string branch;
            string semester;
            string marks;


            getline(ss,roll,',');
            getline(ss,name,',');
            getline(ss,branch,',');
            getline(ss,semester,',');
            getline(ss,marks,',');


            Student s(
                stoi(roll),
                name,
                branch,
                stoi(semester),
                stof(marks)
            );


            students.push_back(s);

        }
        catch(...)
        {
            cout << "\nInvalid record skipped: " << line << endl;
        }
    }


    file.close();

    rebuildMap();
}
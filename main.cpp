#include <iostream>
#include "StudentManager.h"

using namespace std;

int main()
{
    StudentManager manager;

    int choice;


    do
    {
        cout << "\n====================================================\n";
        cout << "          STUDENT RECORD MANAGEMENT SYSTEM\n";
        cout << "====================================================\n";

        cout << "1.  Add Student\n";
        cout << "2.  Display Students\n";
        cout << "3.  Search Student\n";
        cout << "4.  Update Student\n";
        cout << "5.  Delete Student\n";
        cout << "6.  Sort By Name\n";
        cout << "7.  Sort By Marks\n";
        cout << "8.  Sort By Roll Number\n";
        cout << "9.  Filter Students\n";
        cout << "10. Save Data\n";
        cout << "11. Load Data\n";
        cout << "0.  Exit\n";

        cout << "====================================================\n";

        cout << "Enter Choice : ";
        cin >> choice;



        switch(choice)
        {

        case 1:
            manager.addStudent();
            break;


        case 2:
            manager.displayStudents();
            break;


        case 3:
            manager.searchStudent();
            break;


        case 4:
            manager.updateStudent();
            break;


        case 5:
            manager.deleteStudent();
            break;


        case 6:
            manager.sortByName();
            break;


        case 7:
            manager.sortByMarks();
            break;


        case 8:
            manager.sortByRoll();
            break;


        case 9:
            manager.filterStudents();
            break;


        case 10:
            manager.saveToFile();
            break;


        case 11:
            manager.loadFromFile();
            break;


        case 0:
            manager.saveToFile();
            cout << "\nThank You For Using System.\n";
            break;


        default:
            cout << "\nInvalid Choice!\n";

        }


    }while(choice != 0);


    return 0;
}
#include <cstring>
#include <iostream>

using namespace std;

struct Student {
    char* firstName;
    char* lastName;
    int id;
    float gpa;
    
    Student(const char* _firstName, const char* _lastName, int _id, float _gpa) {
        firstName = strcpy(new char[strlen(_firstName) + 1], _firstName);
        lastName = strcpy(new char[strlen(_lastName) + 1], _lastName);
        id = _id;
        gpa = _gpa;
    }
    
    ~Student() {
        delete[] firstName;
        delete[] lastName;
    }
    
    void info() {
        cout << lastName << ", " << firstName << " / " << "ID: " << id << " / " << "GPA: " << gpa;
        cout << setprecision(2) << fixed << gpa << endl;
    }
};

struct Node {
    
};

class HashTable {
    
};
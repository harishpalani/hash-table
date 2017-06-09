#include <cstring>
#include <iomanip>
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
        cout << lastName << ", " << firstName << " / " << "ID: " << id << " / " << "GPA: ";
        cout << setprecision(2) << fixed << gpa << endl;
    }
};

struct Node {
    Student* data;
    Node* next;
    
    Node(Student* data) : data(data), next(0) {} // Constructing w/ initialization list
    ~Node() {}
};

class HashTable {
    public:
        HashTable();
        ~HashTable();
        
        Student* find(int id);
        void add(char* firstName, char* lastName, int id, float gpa);
        void add(Student* student);
        bool remove(int id);
        void print();
        
    private:
        Node** table;
        int size;
        
        int hash(int id);
};
#include "HashTable.h"

using namespace std;

HashTable::HashTable() {
    size = 100;
    table = new Node*[100];
}

HashTable::~HashTable() { }

Student* HashTable::find(int id) {
    Node* current = table[hash(id)];
    while (true) {
        if (current == 0) { return 0; }
        else if (current->data->id == id) {
            return current->data;
        } else {
            current = current->next;
        }
    }
}

void HashTable::add(char* firstName, char* lastName, int id, float gpa) {
    Node** current = &table[hash(id)];
    int count = 0;
    
    // Count collisions in chaining
    while (*current != 0) {
        current = &(*current)->next;
        count++;
    }
    
    /* If >= 3 collisions when you are chaining (or the table is more than half 
    full using other techniques), create a table to have double the number of slots, 
    then rehash your students into the new table. (Your hash should alter based on the 
    size of the table, by the way, and it should spread out the data as you resize the 
    table.  Make it so.) */ 
    if (count >= 3) {
        size *= 2;
        Node** old = table;
        table = new Node*[size];
        
        for (int i = 0; i < size / 2; i++) {
            Node* current = old[i];
            while (current) {
                add(current->data);
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        
        delete[] old;
        add(firstName, lastName, id, gpa);
    } else {
        *current = new Node(new Student(firstName, lastName, id, gpa));
    }
}

void HashTable::add(Student* student) {
    add(student->firstName, student->lastName, student->id, student->gpa);
    delete student;
}

bool HashTable::remove(int id) {
    Node** current = &table[hash(id)];
    while (*current != 0) {
        if ((*current)->data->id == id) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp->data;
            delete temp;
            return true;
        } else {
            current = &((*current)->next);
        }
    }
    return false;
}

void HashTable::print() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current != 0) {
            current->data->info();
            current = current->next;
        }
    }
}

// Helper functions
int HashTable::hash(int id) { return (id % size); }
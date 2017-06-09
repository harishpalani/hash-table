#include "HashTable.h"

using namespace std;

HashTable::HashTable() {
    size = 100;
    table = new Node*[100];
}

HashTable::HashTable() { }

Student* HashTable::find(int id) {
    Node* current = table[id % size];
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
    Node** current = &table[id % size];
    int count = 0;
    
    // Count elements in hash table
    while (*current != 0) {
        current = &(*current)->next;
        count++;
    }
    
    // If >= 3 elements in table...
    if (count >= 3) {
        size *= 2;
        Node** old = list;
        list = new Node*[size];
        
        for (int i = 0; i < size / 2; i++) {
            add(current->data);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        
        delete[] old;
        add(firstName, lastName, id, gpa);
    } else {
        *current = new Node(new Student(firstName, lastName, id, gpa));
    }
}

bool HashTable::remove(int id) {
    Node** current = &table[id % size];
    while (*current != 0) {
        if ((*current)->data->id == id) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp->data;
            delete temp;
            return true
        } else {
            current = &((*current)->next);
        }
    }
    return false;
}

void HashTable::print() {
    for (int i = 0; i < size; i++) {
        Node* current = list[i];
        while (current != 0) {
            current->data->info();
            current = current->next;
        }
    }
}
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
    
}

bool HashTable::remove(int id) {
    
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
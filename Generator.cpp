#include "Generator.h"

Generator::Generator(const char* firstNameFile, const char* lastNameFile) : id(100001) {
    srand(time(0));
    ifstream streamfirstNames, streamlastNames;
    streamfirstNames.open(firstNameFile);
    streamlastNames.open(lastNameFile);
    
    if (streamfirstNames.is_open()) {
        while (!streamfirstNames.eof()) {
            char* current = new char[16];
            streamfirstNames.getline(current, 16);
            firstNames.push_back(current);
        }
    }
    
    if(streamlastNames.is_open()){
        while(!streamlastNames.eof()) {
            char* current = new char[16];
            streamlastNames.getline(current, 16);
            lastNames.push_back(current);
        }
    }
}

Generator::~Generator() { }

char* Generator::getFirstName() { return firstNames[rand() % firstNames.size()]; }
char* Generator::getLastName() { return lastNames[rand() % lastNames.size()]; }
int Generator::getID(){ return id++; }
float Generator::getGPA() { return (1 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX / 3))); }
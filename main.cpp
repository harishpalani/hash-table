/**
 * HASH TABLE
 * Hash table with random student generator.
 * 
 * @author Harish Palani
 * @version June 2017
 */
 
#include "HashTable.h"
#include "Generator.h"

using namespace std;

int main() {
    HashTable table;
    Generator generator("firstNames.txt", "lastNames.txt");
    
    while (true) {
        char response;
        cout << "\n1 | Add a student\n2 | Remove a student\n3 | Print all students\n4 | Generate random students\nq | quit" << endl;
        cin >> response;
        
        if (response == '1') { // Add a student
            char firstName[16], lastName[16];
            int id;
            float gpa;
            
            cout << "First name: ";
            cin >> firstName;
            
            cout << "Last name: ";
            cin >> lastName;
            
            cout << "ID: ";
            cin >> id;
            
            cout << "GPA: ";
            cin >> gpa;
            
            table.add(firstName, lastName, id, gpa);
            cout << firstName << " was added." << endl;
            
        } else if (response == '2') { // Remove a student
            int id;
            cout << "ID of student to remove: ";
            cin >> id;
            
            if (table.remove(id)) {
                cout << id << " was successfully removed." << endl;
            } else {
                cout << id << " could not be found." << endl;
            }
        } else if (response == '3') { // Print the table
            table.print();
        } else if (response == '4') { // Add randomly generated students
            int numStudents;
            cout << "# students to add: ";
            cin >> numStudents;
            for (int i = 0; i < numStudents; i++) {
                table.add(generator.getFirstName(), generator.getLastName(), generator.getID(), generator.getGPA());
            }
        } else {
            return 0;
        }
    }
}
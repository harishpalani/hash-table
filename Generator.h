#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

class Generator {
    public:
        Generator(const char* firstNameFile, const char* lastNameFile);
        ~Generator();
        char* getFirstName();
        char* getLastName();
        int getID();
        float getGPA();
        
    private:
        vector<char*> firstNames;
        vector<char*> lastNames;
        int id;
};
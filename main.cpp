#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PersonInfo {
    protected:
        string name;
        
    public:
        PersonInfo (string name): name(name) {}
        virtual ~PersonInfo () {}
        virtual void output() = 0;
};

class StudentInfo: public PersonInfo{
    int year;
    public:
        StudentInfo(string name, int year) : PersonInfo(name), year(year){}
        void output(){
            cout << "Student: " << name << " / Studied since: " << year << '\n';
        }
};

class FacultyInfo : public PersonInfo{
    int year;
    public:
        FacultyInfo(string name, int year) : PersonInfo(name), year(year) {}
        void output(){
            cout << "Faculty: " << name << " / Employed since: " << year << '\n';
        }
};


int main () {
    vector<PersonInfo*> record;
    record.push_back(new StudentInfo("Harry Potter", 2007));
    record.push_back(new FacultyInfo("Remus Lupin", 2017));

    for(int i=0;i<record.size();i++){
    record[i]->output();
    }

    for(int i=0;i<record.size();i++){
    delete record[i];
    }
 return 0;
}
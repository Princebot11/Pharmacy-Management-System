#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    string phone;
public:
    Person();
    Person(int personId, string personName, string personPhone);
    virtual ~Person();
    virtual void display() const = 0;
    int getId() const;
    string getName() const;
    string getPhone() const;
};
#endif

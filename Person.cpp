#include "Person.h"
Person::Person() : id(0), name(""), phone("") {}
Person::Person(int personId, string personName, string personPhone)
    : id(personId), name(personName), phone(personPhone) {}
Person::~Person() {}
int Person::getId() const { return id; }
string Person::getName() const { return name; }
string Person::getPhone() const { return phone; }

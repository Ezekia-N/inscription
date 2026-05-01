#include "Person.h"

Person::Person(){}

Person::Person(QString name, QString fname, int age)
{
    this->name = name;
    this->firstname = fname;
    this->age = age;
}

Person::~Person(){}

void Person::setName(QString name)
{
    this->name = name;
}

void Person::setFirstName(QString fname)
{
    this->firstname = fname;
}

void Person::setAge(int age)
{
    this->age = age;
}

QString Person::getName() const
{
    return name;
}

QString Person::getFirstName() const
{
    return firstname;
}

int Person::getAge() const 
{
    return age;
}

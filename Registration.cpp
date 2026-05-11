#include "Registration.h"
#include <iostream>
#include <algorithm>
#include <QDebug>

using namespace std;

Registration::Registration(){}

Registration::~Registration(){}

void Registration::ajouter(Person p)
{
    liste.push_back(p);
}

vector<Person> Registration::getListePerson()
{
    return liste;
}

void Registration::setListePerson(vector<Person> liste)
{
    this->liste.clear();
    this->liste.assign(liste.begin(), liste.end());
}

void Registration::modifier(QString editedString, int row, int col)
{
    switch(col)
    {
        case 0:
            liste[row].setName(editedString);
            break;
        case 1:
            liste[row].setFirstName(editedString);
            break;
        case 2:
            bool ok;
            liste[row].setAge(editedString.toInt(&ok));
            break;
        default:
            break;
    }
    historique.push_back(liste);
}

vector<Person> Registration::rechercher(QString findString)
{
    vector<Person> found{};

    for(const Person &p : liste)
    {
        if (p.getName().toLower().contains(findString.toLower())      ||
            p.getFirstName().toLower().contains(findString.toLower()) ||
            QString::number(p.getAge()).toLower().contains(findString.toLower()))
        {
            found.push_back(p);
        }
    }

    return found;
}

void Registration::supprimer(Person p)
{
    auto it = find(liste.begin(),liste.end(), p);
    if (it != liste.end())
    {
        liste.erase(it);
    }
}

void Registration::lister(vector<Person> listOfPerson)
{
    for(vector<Person>::iterator i = listOfPerson.begin(); i!=listOfPerson.end(); i++)
    {
        qDebug() << "==============================";
        qDebug() << "Nom    : " << i->getName();
        qDebug() << "Prénom : " << i->getFirstName();
        qDebug() << "Age    : " << i->getAge();
        qDebug() << "==============================";
    }
}

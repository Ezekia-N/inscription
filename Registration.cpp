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
}

void Registration::rechercher(Person p)
{
    // vector<Person>::iterator t = find(liste.begin(), liste.end(), p);
    // if (t != liste.end())
    // {
    //     qDebug() << "Recherche trouvé";
    //     qDebug() << "==============================";
    //     qDebug() << "Nom    : " << t->getNom();
    //     qDebug() << "Prénom : " << t->getPrenom();
    //     qDebug() << "Age    : " << t->getAge();
    //     qDebug() << "==============================";
    // }
}

void Registration::supprimer(Person p)
{
    auto it = find(liste.begin(),liste.end(), p);
    if (it != liste.end())
    {
        liste.erase(it);
    }
}

void Registration::lister()
{
    qDebug() << "\nListe des étudiants inscris";

    for(vector<Person>::iterator i = liste.begin(); i!=liste.end(); i++)
    {
        qDebug() << "==============================";
        qDebug() << "Nom    : " << i->getName();
        qDebug() << "Prénom : " << i->getFirstName();
        qDebug() << "Age    : " << i->getAge();
        qDebug() << "==============================";
    }
}

#include "Person.h"
#include <vector>
using namespace std;

class Registration
{
    private:
        vector<Person> liste;

    public:
        vector<vector<Person>> historique;
        Registration();
        void ajouter(Person p);
        void setListePerson(vector<Person> liste);
        vector<Person> getListePerson();
        void modifier(QString editedString, int row, int col);
        void supprimer(Person p);
        void rechercher(Person p);
        void lister();
        ~Registration();
};

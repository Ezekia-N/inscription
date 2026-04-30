#include "Person.h"
#include <vector>
using namespace std;

class Registration
{
    private:
        vector<Person> liste;

    public:
        Registration();
        void ajouter(Person p);
        vector<Person> getListePerson();
        void modifier(QString editedString, int row, int col);
        void supprimer(Person p);
        void rechercher(Person p);
        void lister();
        ~Registration();
};

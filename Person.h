#include <QString>
using namespace std;

class Person
{
    private:
        QString name, firstname;
        int age;
             
    public:
        Person();
        Person(QString name, QString fname, int age);
        void setName(QString name);
        void setFirstName(QString fname);
        void setAge(int age);
        QString getName() const;
        QString getFirstName() const;
        int getAge() const;
        ~Person();

        bool operator==(const Person& autre) const
        {
            return (this->getName() == autre.getName() && 
             this->getFirstName() == autre.getFirstName() &&
             this->getAge() == autre.getAge());
        }
};

//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {

  public:
    //constructor
    Person(QString n, QString cn, QString e = "");
    //returns a string representation of a person
    QString toString() const;

    //getters
    QString getName() const;
    QString getContactNo() const;
    QString getEmail() const;

private:
    //data members
    QString _name;
    QString _contactNo;
    QString _email;

};
#endif // PERSON_H

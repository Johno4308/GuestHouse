//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include "person.h"

//3-arg constructorc
Person::Person(QString n, QString cn, QString e):
    _name(n),
    _contactNo(cn),
    _email(e)
{}

//creates and returns a string equivalent of a Person object
QString Person::toString() const {
    return "Name: " + _name + "\n\tContact number: " + _contactNo + "\n\tEmail: " + _email;
}

QString Person::getName() const
{
    return _name;
}

QString Person::getContactNo() const
{
    return _contactNo;
}

QString Person::getEmail() const
{
    return _email;
}



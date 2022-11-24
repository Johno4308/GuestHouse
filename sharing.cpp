//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include "sharing.h"
#include "person.h"

//5-arg constructor
Sharing::Sharing(Person *c, QDate a, QDate d, Person *g1, Person *g2):
    Booking(c, a, d),
    _guest1(g1),
    _guest2(g2)
{}

Sharing::~Sharing()
{
    delete _guest1;
    delete _guest2;
}

//creates and returns a string equivalent of a Sharing object
QString Sharing::toString() const {
    return Booking::toString() + "\nGuest 1: " + _guest1->toString() +"\nGuest 2: "
    + _guest2->toString();
}

//computes and returns the rate of a shared booking
double Sharing::rate()const{
    return 2 * Booking::SHARING_PPPN;
}

Person *Sharing::getGuest1() const
{
    return _guest1;
}

Person *Sharing::getGuest2() const
{
    return _guest2;
}

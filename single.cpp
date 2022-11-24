//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include "single.h"
#include "person.h"

//4-arg constructor
Single::Single(Person *c, QDate a, QDate d, Person *g):
    Booking(c, a, d),
    _guest(g)
{}

Single::~Single()
{
    delete _guest;
}

//creates and returns a string equivalent of a Single object
QString Single::toString() const {
    return Booking::toString() + "\nGuest: " + _guest->toString();
}

//computes and returns the rate of a single booking
double Single::rate() const{
    return Booking::SINGLE_PPPN;
}

Person *Single::getGuest() const
{
    return _guest;
}

//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include "booking.h"
#include "person.h"

//3-arg constructor
Booking::Booking(Person *c, QDate a, QDate d):
    SINGLE_PPPN{300},
    SHARING_PPPN{500},
    _Contact{c},
    _ArrivalDate{a},
    _DepartureDate{d}
{}

Booking::~Booking()
{
    delete _Contact;
}

//checks and returns whether a booking is made for a given date
bool Booking::booked(QDate d) const{
    return d >= _ArrivalDate && d < _DepartureDate;
}
//creates and returns a string representation of a Booking instance
QString Booking::toString() const {
    return "Contact: " + _Contact->toString() + "\nDate of arrival: " +
    _ArrivalDate.toString() + "\nDate of departure: " +
            _DepartureDate.toString();
}

Person *Booking::getPerson() const
{
    return _Contact;
}

QDate Booking::getArrival() const
{
    return _ArrivalDate;
}

QDate Booking::getDeparture() const
{
    return _DepartureDate;
}



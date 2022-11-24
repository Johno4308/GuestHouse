//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include "bookinglist.h"
#include "sharing.h"
#include "single.h"
#include "booking.h"

//no-arg constructor
BookingList::BookingList():
    _NO_OF_ROOMS(5)
{}

//destructor
BookingList::~BookingList(){
    qDeleteAll(_listBooking);
    _listBooking.clear();
}

//checks and returns the number of rooms of available for a given date
int BookingList::roomsAvailable(QDate d) const {
    int result = _NO_OF_ROOMS;
    foreach (Booking * b, _listBooking) {
        if (b->booked(d)) {
            result--;
        }
    }
    return result;
}

//checks and returns whether there is room available in a given period
bool BookingList::vacancy(QDate a, QDate d) const {
    if (a.isValid() && d.isValid() && a < d) {
        for (QDate i = a; i < d; i = i.addDays(1)) {
            if (roomsAvailable(i) <= 0) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

//creates a booking instance if there is vacancy
bool BookingList::addBooking(Person *c, QDate a, QDate d, Person* g1, Person*g2) {
    Booking* b = nullptr;
    if(vacancy(a,d) == true){
        if (g2 == nullptr) {
            b = new Single(c, a, d, g1);
        } else {
            b = new Sharing(c, a, d, g1, g2);
        }
        _listBooking.append(b);
        return true;
    }
    return false;
}

void BookingList::addBooking(Booking *b)
{
    _listBooking.append(b);
}

//returns a string representation of the entire booking list
QString BookingList::toString() const{
    QString result;
    foreach (Booking *b, _listBooking) {
        result.append(b->toString());
        result.append("\n-------------------------------\n");
    }
    return result;
}

Booking *BookingList::at(int i) const
{
    return _listBooking.at(i);
}

int BookingList::size() const
{
    return _listBooking.size();
}

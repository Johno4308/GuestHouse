//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#ifndef BOOKINGLIST_H
#define BOOKINGLIST_H

#include <QList>
#include <QDate>

class Booking;
class Person;

class BookingList {

public:
    //constructor
    BookingList();
    //destructor
    ~BookingList();
    //checks whether a room is available for a given date
    int roomsAvailable(QDate d) const;
    //checks whether there is a vacancy in the given period
    bool vacancy(QDate a, QDate d) const;
    //create, add and return a booking to the list
    bool addBooking(Person *c, QDate a, QDate d, Person *g1, Person *g2 = nullptr);
    void addBooking(Booking *b);
    QString toString() const;
    Booking* at(int i) const;
    int size() const;
private:
    QList<Booking*> _listBooking;
    const int _NO_OF_ROOMS;
};
#endif // BOOKINGLIST_H


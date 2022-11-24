//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#ifndef SINGLE_H
#define SINGLE_H

#include "booking.h"
class Person;

class Single : public Booking {
    Q_OBJECT
  public:
    //constructor
    Single(Person *c, QDate a, QDate d, Person *g);
    //destructor
    ~Single();
    //returns a string representation of a Single object
    QString toString() const;
    //computes and returns the rate of a Single booking
    double rate() const;

    //getter
    Person* getGuest() const;

private:
    //data member
    Person *_guest;
};
#endif // SINGLE_H

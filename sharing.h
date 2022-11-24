//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#ifndef SHARING_H
#define SHARING_H

#include "booking.h"
class Person;

class Sharing : public Booking {
    Q_OBJECT
  public:
    //constructor
    Sharing(Person *c, QDate a, QDate d, Person *g1, Person *g2);
    //destructor
    ~Sharing();
    //returns a string representation of a sharing object
    QString toString() const;
    //computes and returns the rate of a shared booking
    double rate() const;

    //getters
    Person* getGuest1() const;
    Person* getGuest2() const;
private:
    //data members
    Person *_guest1;
    Person *_guest2;

};
#endif // SHARING_H

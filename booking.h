//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#ifndef BOOKING_H
#define BOOKING_H

#include <QDate>
#include <QObject>
class Person;

class Booking :public QObject {
    Q_OBJECT

public:
    //constructor
    Booking(Person *c, QDate a, QDate d);
    //destructor
    virtual ~Booking();
    //checks whether a give date is between the arrival date and departure date
    bool booked(QDate d) const;
    //returns a string representation of a booking
    virtual QString toString() const;
    //abstract function
    virtual double rate() const = 0;

    //ADD CODE
    //getters
    Person* getPerson() const;
    QDate getArrival() const;
    QDate getDeparture() const;

protected:
    //const data members
    const double SINGLE_PPPN;
    const double SHARING_PPPN;

private:
    //data members
    Person *_Contact;
    QDate _ArrivalDate;
    QDate _DepartureDate;


};
#endif // BOOKING_H

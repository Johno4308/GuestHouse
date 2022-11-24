#ifndef BOOKINGLISTFROMXML_H
#define BOOKINGLISTFROMXML_H

#include <QDomDocument>
#include <QList>

class Booking;
class Person;

class BookingListFromXml
{
public:
    BookingListFromXml();
    ~BookingListFromXml();
    QList<Booking*> readXML(QString f);

private:
    QDomDocument _DOMdoc;
    QList<Booking*> _bookingList;
    Person* _processPerson(QDomElement entry);
};

#endif // BOOKINGLISTFROMXML_H

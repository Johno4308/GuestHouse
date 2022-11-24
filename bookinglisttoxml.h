#ifndef BOOKINGLISTTOXML_H
#define BOOKINGLISTTOXML_H

#include <QString>
#include <QDomDocument>
#include <QDate>

class BookingList;
class Person;

class BookingListToXml
{
public:
    BookingListToXml();
    QString write(BookingList* list);

private:
    QDomDocument _DOMdoc;
    QDomElement _rootElement;

    void writePerson(QDomElement element, QString type, Person* p);
    void writeDateText(QDomElement element, QString type, QDate d);
};

#endif // BOOKINGLISTTOXML_H

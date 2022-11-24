#include "bookinglisttoxml.h"
#include "single.h"
#include "sharing.h"
#include "bookinglist.h"
#include "person.h"

BookingListToXml::BookingListToXml()
{
    _rootElement = _DOMdoc.createElement("bookinglist");
    _DOMdoc.appendChild(_rootElement);
}

QString BookingListToXml::write(BookingList *list)
{
    for(int i = 0; i < list->size(); i++)
    {
        Booking *booking = list->at(i);

        const QMetaObject* meta = booking->metaObject();
        QString className = QString(meta->className());

        //booking tag
        QDomElement bookingElement = _DOMdoc.createElement("booking");
        bookingElement.setAttribute("type", className);
        _rootElement.appendChild(bookingElement);

        //add contact person to booking tag
        writePerson(bookingElement, "contact", booking->getPerson());
        //add dates to booking tage
        writeDateText(bookingElement, "arrivaldate", booking->getArrival());
        writeDateText(bookingElement, "departureDate", booking->getDeparture());
        //add guests to booking tag
        if(className == "Single")
        {
            Single* single = qobject_cast<Single*>(booking);
            writePerson(bookingElement, "guest", single->getGuest());
        }
        else
        {
            Sharing* sharing = qobject_cast<Sharing*>(booking);
            writePerson(bookingElement, "guest", sharing->getGuest1());
            writePerson(bookingElement, "guest", sharing->getGuest2());
        }
    }
    return _DOMdoc.toString();
}

void BookingListToXml::writePerson(QDomElement element, QString type, Person *p)
{
    QDomElement personElement = _DOMdoc.createElement(type);
    personElement.setAttribute("email", p->getEmail());
    personElement.setAttribute("name", p->getName());
    personElement.setAttribute("telnumber", p->getContactNo());
    element.appendChild(personElement);
}

void BookingListToXml::writeDateText(QDomElement element, QString type, QDate d)
{
    QDomElement dateElement = _DOMdoc.createElement(type);
    QDomText dateText = _DOMdoc.createTextNode(d.toString("yyyy/MM/dd"));
    dateElement.appendChild(dateText);
    element.appendChild(dateElement);
}

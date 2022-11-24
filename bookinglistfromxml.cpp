#include "bookinglistfromxml.h"
#include "person.h"
#include "single.h"
#include "sharing.h"
#include "booking.h"
#include <QFile>
#include <QDate>

BookingListFromXml::BookingListFromXml()
{}

BookingListFromXml::~BookingListFromXml()
{}

QList<Booking *> BookingListFromXml::readXML(QString f)
{
    QFile file(f);
    if(!file.open(QIODevice::ReadOnly))
    {
        return QList<Booking*>();
    }
    if(!_DOMdoc.setContent(&file))
    {
        file.close();
        return QList<Booking*>();
    }

    QStringList data;
    QDomElement root = _DOMdoc.documentElement();
    if(root.tagName() == "bookinglist")
    {
        QDomNode bookingNode = root.firstChild();
        while(!bookingNode.isNull())
        {
            QDomElement bookingElement = bookingNode.toElement();
            if(bookingElement.isNull())
            {
                if(bookingElement.tagName() == "booking")
                {
                    QString type = bookingElement.attribute("type", "");

                    QDomNodeList contactNodes = bookingElement.elementsByTagName("contact");
                    QDomElement contactElement = contactNodes.at(0).toElement();
                    Person *contactPerson = _processPerson(contactElement);

                    QDomNodeList arrivalNodes = bookingElement.elementsByTagName("arrivalDate");
                    QDomElement arrivalElement = arrivalNodes.at(0).toElement();
                    QDate arrivalDate = QDate::fromString(arrivalElement.text(),"yyyy/MM/dd");

                    QDomNodeList departureNodes = bookingElement.elementsByTagName("departureDate");
                    QDomElement departureElement = departureNodes.at(0).toElement();
                    QDate departureDate = QDate::fromString(arrivalElement.text(),"yyyy/MM/dd");

                    QDomNodeList guestNodes = bookingElement.elementsByTagName("guest");
                    QDomElement guest1Element = guestNodes.at(0).toElement();
                    Person *guest1 = _processPerson(guest1Element);
                    if(guestNodes.size()==1)
                    {
                        Booking* b = new Single(contactPerson, arrivalDate, departureDate, guest1);
                        _bookingList.append(b);
                    }
                    else
                    {
                        QDomElement guest2Element = guestNodes.at(1).toElement();
                        Person *guest2 = _processPerson(guest2Element);
                        Booking* b = new Sharing(contactPerson, arrivalDate, departureDate, guest1, guest2);
                        _bookingList.append(b);
                    }
                }
            }
            bookingNode = bookingNode.nextSibling();
        }
    }
    return _bookingList;
}

Person *BookingListFromXml::_processPerson(QDomElement entry)
{
    QString name = entry.attribute("name", "");
    QString telnumber = entry.attribute("telnumber", "");
    QString email = entry.attribute("email", "");
    Person *p = new Person(name, telnumber, email);
    return p;
}

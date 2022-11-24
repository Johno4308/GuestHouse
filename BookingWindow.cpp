//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include "BookingWindow.h"
#include "bookinglistfromxml.h"
#include "bookinglisttoxml.h"
#include "person.h"

#include <QFile>
#include <QFileDialog>
#include <QDebug>

//constructor
BookingWindow::BookingWindow():
    _bookingLayout{new QGridLayout},
    _info1{new QLabel},
    _info2{new QLabel},
    _info3{new QLabel},
    _info4{new QLabel},
    _name1{new QLabel},
    _number1{new QLabel},
    _email1{new QLabel},
    _name2{new QLabel},
    _number2{new QLabel},
    _email2{new QLabel},
    _name3{new QLabel},
    _number3{new QLabel},
    _email3{new QLabel},
    _guest1{new QLabel},
    _guest2{new QLabel},
    //lineedits
    _contactName{new QLineEdit},
    _contactNumber{new QLineEdit},
    _contactEmail{new QLineEdit},
    _guest1Name{new QLineEdit},
    _guest1Number{new QLineEdit},
    _guest1Email{new QLineEdit},
    _guest2Name{new QLineEdit},
    _guest2Number{new QLineEdit},
    _guest2Email{new QLineEdit},
    //radio buttons
    _singleRadio{new QRadioButton},
    _sharingRadio{new QRadioButton},
    _saveButton{new QPushButton},
    _closeButton{new QPushButton},
    _dateButton{new QPushButton},
    _checkDateButton{new QPushButton},
    _copyDetailsButton{new QPushButton},
    _checkVacanyButton{new QPushButton},
    _dateWindow{new DateWindow},
    _arrivalDate{new QDateEdit},
    _departureDate{new QDateEdit},
    _queryArrival{new QDateEdit},
    _queryDeparture{new QDateEdit},
    _roomsAvaliable{new QDateEdit}
{
    _bookingList = new BookingList;
    createFromFile();

    QDate today(QDate::currentDate());
    QDate tomorrow(today.addDays(1));
    _queryArrival->setDate(today);
    _departureDate->setDate(tomorrow);
    _queryArrival->setDate(today);
    _queryDeparture->setDate(tomorrow);
    _roomsAvaliable->setDate(today);

    //booking detail UI title and size
    setWindowTitle("Booking");
    setFixedSize(1000, 800);
    // calling of UI
    makeBookingWindow();
}

BookingWindow::~BookingWindow()
{
    delete _bookingList;
}

void BookingWindow::copyDetails()
{
    _guest1Name->setText(_contactName->text());
    _guest1Number->setText(_contactNumber->text());
    _guest1Email->setText(_contactEmail->text());
}

void BookingWindow::autoUpdateDepartureDate(QDate d)
{
    _departureDate->setDate(d.addDays(1));
}

void BookingWindow::addBooking()
{
    if(_contactName->text().size() > 0 && _guest1Name->text().size() > 0){
        _arrivalDate = _dateWindow->getArrival();
        _departureDate = _dateWindow->getDeparture();
        bool success;
        Person *guest2 = nullptr;

        Person *contact(new Person(_contactName->text(), _contactNumber->text(), _contactEmail->text()));
        Person *guest1(new Person(_guest1Name->text(), _guest1Number->text(), _guest1Email->text()));
        if(_guest2Name->text().size() == 0)
        {
            success = _bookingList->addBooking(contact, _arrivalDate->date(), _departureDate->date(), guest1);
        }else
        {
            guest2 = new Person(_guest2Name->text(), _guest2Number->text(), _guest2Email->text());
            success = _bookingList->addBooking(contact, _arrivalDate->date(), _departureDate->date(), guest1, guest2);
        }
        if(success)
        {
            QMessageBox::information(this, "Add Booking", "Booking added successfully");
            _contactName->clear();
            _contactNumber->clear();
            _contactEmail->clear();
            _guest1Name->clear();
            _guest1Number->clear();
            _guest1Email->clear();
            _guest2Name->clear();
            _guest2Number->clear();
            _guest2Email->clear();
            _contactName->setFocus();
        }else
        {
            QMessageBox::critical(this, "Add booking", "This booking was not added");
            delete contact;
            delete guest1;

            if(_guest2Name->text().size() > 0)
                delete guest2;
        }
    }
    else
        QMessageBox::warning(this, "Add booking", "Enter at least the contact and first guests names");

    saveToFile();

}

void BookingWindow::checkVacancy()
{
    if(_queryArrival->date() >= _queryDeparture->date())
    {
        QMessageBox::warning(this, "Check vacancy", "Departure must be after arrival");
    }else{
        //**********************************************
        _info3->setText(_bookingList->vacancy(_queryArrival->date(), _queryDeparture->date())?"Yes":"No");
    }
}

void BookingWindow::checkRooms()
{
    //**************************************************
    _info4->setText(QString::number(_bookingList->roomsAvailable(_roomsAvaliable->date())));
}

void BookingWindow::dateWindow()
{
    _dateWindow->show();
}


void BookingWindow::sharing()
{
    if(_sharingRadio->isChecked()){
        _guest2Name->setEnabled(true);
        _guest2Number->setEnabled(true);
        _guest2Email->setEnabled(true);
    }
}

void BookingWindow::single()
{
    if(_singleRadio->isChecked()){
        _guest2Name->setEnabled(false);
        _guest2Number->setEnabled(false);
        _guest2Email->setEnabled(false);
    }
}

void BookingWindow::createFromFile()
{
    _fileName = QFileDialog::getOpenFileName(this, "Open file", ".", "XML files (* .xml)");
    if(_fileName.size() > 0)
    {
        BookingListFromXml *readXML(new BookingListFromXml);
        QList<Booking*> temp = readXML->readXML(_fileName);
        foreach(Booking *b, temp)
            _bookingList->addBooking(b);
        delete readXML;
    }else
        QMessageBox::information(this, "create from file", "Booking list not created from file");
}

void BookingWindow::saveToFile()
{
    if(_bookingList->size() > 0)
    {
        if(_fileName.size() > 0)
        {
            BookingListToXml writer;
            QString xml = writer.write(_bookingList);

            FileWriter fw(_fileName);
            fw.write(xml);
        }
        else
            QMessageBox::information(this, "Save to file", "Booking list not saved to file");
    }
}

//setting up for UI for booking screen
//title labels
//adding css
//creating signals and slots
void BookingWindow::makeBookingWindow()
{
    _info1->setText("MAKE A BOOKING");
    _info2->setText("Details of the person making the booking: ");
    _info3->setText("Check avaliablity of selected date range");
    _info4->setText("Check rooms avaliable on arrival date");
    _name1->setText("Name:");
    _number1->setText("Number (XXX-XXXXXXX):");
    _email1->setText("Email:");
    _name2->setText("Name:");
    _number2->setText("Number (XXX-XXXXXXX):");
    _email2->setText("Email:");
    _name3->setText("Name:");
    _number3->setText("Number (XXX-XXXXXXX):");
    _email3->setText("Email:");
    _guest1->setText("Guest 1");
    _guest2->setText("Guest 2");
    _singleRadio->setText("Single Room");
    _sharingRadio->setText("Sharing");
    _saveButton->setText("Save");
    _closeButton->setText("Back");
    _checkDateButton->setText("Check Date Range");
    _checkVacanyButton->setText("Check Rooms");
    _dateButton->setText("Add a Date");
    _copyDetailsButton->setText("Same as Guest");
    _singleRadio->setChecked(true);
    if(_singleRadio->isChecked()){
        _guest2Name->setEnabled(false);
        _guest2Number->setEnabled(false);
       _guest2Email->setEnabled(false);
    }


    //title and info
    _info1->setFixedWidth(980);
    _info1->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                              "             font-size: 40px;"
                              "             padding: 12px 28px;"
                              "             border: 2px solid #000000;"
                              "             font-weight: bold;"
                              "             text-align: center;"
                              "             color: #000000;}");
    _bookingLayout->addWidget(_info1, 0, 0);
    _info2->setFixedSize(980, 50);
    _info2->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 20px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _bookingLayout->addWidget(_info2, 1, 0);
    //customer input details
    _name1->setFixedSize(240, 50);
    _name1->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 12px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _bookingLayout->addWidget(_name1, 2, 0);
    _number1->setFixedSize(240, 50);
    _number1->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 12px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _bookingLayout->addWidget(_number1, 3, 0);
    _email1->setFixedSize(240, 50);
    _email1->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 12px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _bookingLayout->addWidget(_email1, 4, 0);
    _contactName->setFixedSize(240, 50);
    _contactName->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                           "             font-size: 12px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #47B5FF;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #47B5FF;}");
    _bookingLayout->addWidget(_contactName, 2, 1);
    _contactNumber->setFixedSize(240, 50);
    _contactNumber->setInputMask("0DD-9999999"); //used for validation
    _contactNumber->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                           "             font-size: 12px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #47B5FF;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #47B5FF;}");
    _bookingLayout->addWidget(_contactNumber, 3, 1);
    _contactEmail->setFixedSize(240, 50);
    _contactEmail->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                           "             font-size: 12px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #47B5FF;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #47B5FF;}");
    _bookingLayout->addWidget(_contactEmail, 4, 1);
    //guest option
    _singleRadio->isChecked();
    _singleRadio->setFixedSize(240, 50);
    _singleRadio->setStyleSheet(" QRadioButton {background-color: #FFFFFF;"
                           "             font-size: 20px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #06283D;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #1363DF;}");
    _bookingLayout->addWidget(_singleRadio, 5, 0);
    _sharingRadio->setFixedSize(240, 50);
    _sharingRadio->setStyleSheet(" QRadioButton {background-color: #FFFFFF;"
                           "             font-size: 20px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #06283D;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #1363DF;}");
    _bookingLayout->addWidget(_sharingRadio, 5, 2);
    //guest 1 input
    _guest1->setFixedSize(240, 50);
    _guest1->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 16px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _bookingLayout->addWidget(_guest1, 6, 0);
    _name2->setFixedSize(240, 50);
    _name2->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                          "             font-size: 12px;"
                          "             padding: 12px 28px;"
                          "             border: 2px solid #000000;"
                          "             font-weight: bold;"
                          "             text-align: center;"
                          "             color: #000000;}");
    _bookingLayout->addWidget(_name2, 7, 0);
    _number2->setFixedSize(240, 50);
    _number2->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                            "             font-size: 12px;"
                            "             padding: 12px 28px;"
                            "             border: 2px solid #000000;"
                            "             font-weight: bold;"
                            "             text-align: center;"
                            "             color: #000000;}");
    _bookingLayout->addWidget(_number2, 8, 0);
    _email2->setFixedSize(240, 50);
    _email2->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 12px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _bookingLayout->addWidget(_email2, 9, 0);
    _guest1Name->setFixedSize(240, 50);
    _guest1Name->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                               "             font-size: 12px;"
                               "             padding: 12px 28px;"
                               "             border-radius: 12px;"
                               "             border: 2px solid #47B5FF;"
                               "             font-weight: bold;"
                               "             text-align: center;"
                               "             color: #47B5FF;}");
    _bookingLayout->addWidget(_guest1Name, 7, 1);
    _guest1Number->setFixedSize(240, 50);
    _guest1Number->setInputMask("0DD-9999999"); //used for validation
    _guest1Number->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                                 "             font-size: 12px;"
                                 "             padding: 12px 28px;"
                                 "             border-radius: 12px;"
                                 "             border: 2px solid #47B5FF;"
                                 "             font-weight: bold;"
                                 "             text-align: center;"
                                 "             color: #47B5FF;}");
    _bookingLayout->addWidget(_guest1Number, 8 ,1);
    _guest1Email->setFixedSize(240, 50);
    _guest1Email->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                                "             font-size: 12px;"
                                "             padding: 12px 28px;"
                                "             border-radius: 12px;"
                                "             border: 2px solid #47B5FF;"
                                "             font-weight: bold;"
                                "             text-align: center;"
                                "             color: #47B5FF;}");
    _bookingLayout->addWidget(_guest1Email, 9, 1);
    //guest 2 input
    _guest2->setFixedSize(240, 50);
    _guest2->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 16px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _bookingLayout->addWidget(_guest2, 6, 2);
    _name3->setFixedSize(240, 50);
    _name3->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                          "             font-size: 12px;"
                          "             padding: 12px 28px;"
                          "             border: 2px solid #000000;"
                          "             font-weight: bold;"
                          "             text-align: center;"
                          "             color: #000000;}");
    _bookingLayout->addWidget(_name3, 7, 2);
    _number3->setFixedSize(240, 50);
    _number3->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                            "             font-size: 12px;"
                            "             padding: 12px 28px;"
                            "             border: 2px solid #000000;"
                            "             font-weight: bold;"
                            "             text-align: center;"
                            "             color: #000000;}");
    _bookingLayout->addWidget(_number3, 8, 2);
    _email3->setFixedSize(240, 50);
    _email3->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 12px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _bookingLayout->addWidget(_email3, 9, 2);
    _guest2Name->setFixedSize(240, 50);
    _guest2Name->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                               "             font-size: 12px;"
                               "             padding: 12px 28px;"
                               "             border-radius: 12px;"
                               "             border: 2px solid #47B5FF;"
                               "             font-weight: bold;"
                               "             text-align: center;"
                               "             color: #47B5FF;}");
    _bookingLayout->addWidget(_guest2Name, 7, 3);
    _guest2Number->setFixedSize(240, 50);
    _guest2Number->setInputMask("0DD-9999999"); //used for validation
    _guest2Number->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                                 "             font-size: 12px;"
                                 "             padding: 12px 28px;"
                                 "             border-radius: 12px;"
                                 "             border: 2px solid #47B5FF;"
                                 "             font-weight: bold;"
                                 "             text-align: center;"
                                 "             color: #47B5FF;}");
    _bookingLayout->addWidget(_guest2Number, 8 ,3);
    _guest2Email->setFixedSize(240, 50);
    _guest2Email->setStyleSheet(" QLineEdit {background-color: #FFFFFF;"
                                "             font-size: 12px;"
                                "             padding: 12px 28px;"
                                "             border-radius: 12px;"
                                "             border: 2px solid #47B5FF;"
                                "             font-weight: bold;"
                                "             text-align: center;"
                                "             color: #47B5FF;}");
   _bookingLayout->addWidget(_guest2Email, 9, 3);
    //checkdate

    _info3->setFixedSize(480, 50);
    _info3->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 20px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #06283D;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #1363DF;}");
    _bookingLayout->addWidget(_info3, 10, 1);
    _info4->setFixedSize(480, 50);
    _info4->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 20px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #06283D;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #1363DF;}");
    _bookingLayout->addWidget(_info4, 11, 1);
    _dateButton->setFixedSize(240, 50);
    _dateButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                               "             color: #AE5EE6;"
                               "             letter-spacing: 1.5px;"
                               "             font-size: 16px;"
                               "             padding: 12px 28px;"
                               "             border: 1px solid #AE5EE6;"
                               "             font-weight: bold}");
    _bookingLayout->addWidget(_dateButton, 2, 3);

    _copyDetailsButton->setFixedSize(240, 50);
    _copyDetailsButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                                      "             color: #AE5EE6;"
                                      "             letter-spacing: 1.5px;"
                                      "             font-size: 16px;"
                                      "             padding: 12px 28px;"
                                      "             border: 1px solid #AE5EE6;"
                                      "             font-weight: bold}");
    _bookingLayout->addWidget(_copyDetailsButton, 2, 2);

    _checkDateButton->setFixedSize(240, 50);
    _checkDateButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                                    "             color: #AE5EE6;"
                                    "             letter-spacing: 1.5px;"
                                    "             font-size: 16px;"
                                    "             padding: 12px 28px;"
                                    "             border: 1px solid #AE5EE6;"
                                    "             font-weight: bold}");

    _bookingLayout->addWidget(_checkDateButton, 10, 0);

    _checkVacanyButton->setFixedSize(240, 50);
    _checkVacanyButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                                      "             color: #AE5EE6;"
                                      "             letter-spacing: 1.5px;"
                                      "             font-size: 16px;"
                                      "             padding: 12px 28px;"
                                      "             border: 1px solid #AE5EE6;"
                                      "             font-weight: bold}");
    _bookingLayout->addWidget(_checkVacanyButton, 11, 0);


    _saveButton->setFixedSize(240, 50);
    _saveButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                               "             color: #AE5EE6;"
                               "             letter-spacing: 1.5px;"
                               "             font-size: 16px;"
                               "             padding: 12px 28px;"
                               "             border: 1px solid #AE5EE6;"
                               "             font-weight: bold}");
    _bookingLayout->addWidget(_saveButton, 10, 3);
    _closeButton->setFixedSize(240, 50);
    _closeButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                                "             color: #AE5EE6;"
                                "             letter-spacing: 1.5px;"
                                "             font-size: 16px;"
                                "             padding: 12px 28px;"
                                "             border: 1px solid #AE5EE6;"
                                "             font-weight: bold}");
    _bookingLayout->addWidget(_closeButton, 11, 3);

    this->setLayout(_bookingLayout);


    connect(_dateButton, SIGNAL(clicked()), this, SLOT(dateWindow()));
    connect(_closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(_sharingRadio, SIGNAL(clicked()), this, SLOT(sharing()));
    connect(_singleRadio, SIGNAL(clicked()), this, SLOT(single()));



    connect(_saveButton, SIGNAL(clicked()), this, SLOT(addBooking()));
    connect(_checkDateButton, SIGNAL(clicked()), this, SLOT(checkVacancy()));
    connect(_checkVacanyButton, SIGNAL(clicked()), this, SLOT(checkRooms()));
    connect(_copyDetailsButton, SIGNAL(clicked()), this, SLOT(copyDetails()));

}







//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include "datewindow.h"
//constructor
DateWindow::DateWindow():
    _calenderLayout{new QGridLayout},
    _bookDate{new QLabel},
    _arrive{new QLabel},
    _depart{new QLabel},
    _arriveCal{new QCalendarWidget},
    _departCal{new QCalendarWidget},
    _reserveButton{new QPushButton},
    _arrivalDate{new QDateEdit},
    _departureDate{new QDateEdit}
{

    setWindowTitle("Dates");
    setFixedSize(1000, 800);


    calenderWindow();
}

void DateWindow::captureDate()
{
    _arrivalDate->setDate(_arriveCal->selectedDate());
    _departureDate->setDate(_departCal->selectedDate());
    QMessageBox::information(this, "Date range", "Selected date range has been Stored");
    this->close();
}

QDateEdit* DateWindow::getArrival() const
{
    return _arrivalDate;
}

QDateEdit* DateWindow::getDeparture() const
{
    return _departureDate;
}


//function to set up UI
//title labels
//adding css
//creating signals and slots
void DateWindow::calenderWindow()
{
    _bookDate->setText("CONFIRM A DATE");
    _arrive->setText("Date of Arrival");
    _depart->setText("Date of Departure");
    _reserveButton->setText("Store/Close");

    //logo
    _bookDate->setFixedWidth(980);
    _bookDate->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                             "             font-size: 40px;"
                             "             padding: 12px 28px;"
                             "             border: 2px solid #000000;"
                             "             font-weight: bold;"
                             "             text-align: center;"
                             "             color: #000000;}");
    _calenderLayout->addWidget(_bookDate, 0, 0);
    //arrive leave labels
    _arrive->setFixedSize(300, 50);
    _arrive->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 20px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _calenderLayout->addWidget(_arrive, 1, 0);
    _depart->setFixedSize(300, 50);
    _depart->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                           "             font-size: 20px;"
                           "             padding: 12px 28px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _calenderLayout->addWidget(_depart, 1, 3);
    //calenders
    _arriveCal->setFixedSize(300, 300);
    _arriveCal->setMinimumDate(QDate::currentDate()); //used for validation
    _arriveCal->setStyleSheet(" QCalendarWidget {background-color: #FFFFFF;"
                           "             font-size: 10px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _calenderLayout->addWidget(_arriveCal, 2, 0);
    _departCal->setFixedSize(300, 300);
    _departCal->setMinimumDate(QDate::currentDate()); //used for validation
    _departCal->setStyleSheet(" QCalendarWidget {background-color: #FFFFFF;"
                           "             font-size: 10px;"
                           "             padding: 12px 28px;"
                           "             border-radius: 12px;"
                           "             border: 2px solid #000000;"
                           "             font-weight: bold;"
                           "             text-align: center;"
                           "             color: #000000;}");
    _calenderLayout->addWidget(_departCal, 2, 3);
    //buttons
    _reserveButton->setFixedSize(240, 50);
    _reserveButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                                  "             color: #AE5EE6;"
                                  "             letter-spacing: 1.5px;"
                                  "             font-size: 16px;"
                                  "             padding: 12px 28px;"
                                  "             border: 1px solid #AE5EE6;"
                                  "             font-weight: bold}");
    _calenderLayout->addWidget(_reserveButton, 4, 4);


    this->setLayout(_calenderLayout);

    connect(_reserveButton, SIGNAL(clicked()), this, SLOT(captureDate()));

}



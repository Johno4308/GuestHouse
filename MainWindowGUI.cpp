//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#include "MainWindowGUI.h"

//main window constructor
MainWindowGUI::MainWindowGUI():
    _layout{new QGridLayout(this)},
    _logo1{new QLabel},
    _logo2{new QLabel},
    _bookedButton{new QPushButton},
    _closeButton{new QPushButton},
    _bookWindow{new BookingWindow}
{
    setWindowTitle("The Guest House");
    setFixedSize(1000, 800);

    setupGUI();
}

//slot to booking UI
void MainWindowGUI::addbooking()
{
    _bookWindow->show();
}



//slot to show check date UI
void MainWindowGUI::date()
{
    _dateWindow->show();
}

//function to set up main window UI
//title labels
//adding css
//creating signals and slots
void MainWindowGUI::setupGUI()
{
    //label information
    _logo1->setText("THE GUEST HOUSE");
    _logo2->setText("MAKE A BOOKING:");

    _bookedButton->setText("BOOK NOW!");

    _closeButton->setText("CLOSE");

    _logo1->setFixedWidth(980);
    _logo1->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                              "             font-size: 70px;"
                              "             border-radius: 12px;"
                              "             border: 4px solid #000000;"
                              "             font-weight: bold;"
                              "             text-align: center;"
                              "             color: #000000;}");
    _layout->addWidget(_logo1, 0, 0);
    _logo2->setFixedSize(700, 50);
    _logo2->setStyleSheet(" QLabel {background-color: #FFFFFF;"
                              "             font-size: 20px;"
                              "             border-radius: 12px;"
                              "             border: 1px solid #000000;"
                              "             font-weight: bold;"
                              "             text-align: center;"
                              "             left: 2px;"
                              "             color: #000000;}");
    _layout->addWidget(_logo2, 1, 0);

    _bookedButton->setFixedSize(240, 50);
    _bookedButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                              "             color: #AE5EE6;"
                              "             letter-spacing: 1.5px;"
                              "             font-size: 16px;"
                              "             padding: 12px 28px;"
                              "             border: 1px solid #AE5EE6;"
                              "             font-weight: bold}");

    _layout->addWidget(_bookedButton, 1, 1);

    _closeButton->setFixedSize(240, 50);
    _closeButton->setStyleSheet(" QPushButton {background-color: #FFFFFF;"
                                "             color: #AE5EE6;"
                                "             letter-spacing: 1.5px;"
                                "             font-size: 16px;"
                                "             padding: 12px 28px;"
                                "             border: 1px solid #AE5EE6;"
                                "             font-weight: bold}");
    _layout->addWidget(_closeButton, 5, 1);


    this->setLayout(_layout);

    connect(_bookedButton, SIGNAL(clicked()), this, SLOT(addbooking()));
    connect(_closeButton, SIGNAL(clicked()), this, SLOT(close()));
}




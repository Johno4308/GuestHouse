//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#ifndef BOOKINGWINDOW_H
#define BOOKINGWINDOW_H
//UI for adding a booking + choice of single and double + vacancy for time period check
//Widget includes
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <QDateEdit>
//header file includes
#include "datewindow.h"
#include "filewriter.h"
#include "bookinglist.h"


class BookingWindow : public QWidget
{
    Q_OBJECT
public:
    BookingWindow();
    ~BookingWindow();

public slots:
    void copyDetails(); //
    void autoUpdateDepartureDate(QDate d);
    void addBooking(); //
    void checkVacancy();    //
    void checkRooms();  //
    void dateWindow(); //
    void sharing(); //
    void single();  //


private:
    void createFromFile();
    void saveToFile();
    void makeBookingWindow(); //function to set UI
    QGridLayout* _bookingLayout; //for layout
    //labels
    QLabel *_info1; //Various UI labels
    QLabel *_info2;
    QLabel *_info3;
    QLabel *_info4;
    // contact labels
    QLabel *_name1;
    QLabel *_number1;
    QLabel *_email1;
    // guest 1 labels
    QLabel *_name2;
    QLabel *_number2;
    QLabel *_email2;
    // guest 2 labels
    QLabel *_name3;
    QLabel *_number3;
    QLabel *_email3;
    QLabel *_guest1;
    QLabel *_guest2;
    //lineedits
    // contact lineEdit
    QLineEdit *_contactName;
    QLineEdit *_contactNumber;
    QLineEdit *_contactEmail;
    // guest 1 lineEdit
    QLineEdit *_guest1Name;
    QLineEdit *_guest1Number;
    QLineEdit *_guest1Email;
    // guest 2 lineEdit
    QLineEdit *_guest2Name;
    QLineEdit *_guest2Number;
    QLineEdit *_guest2Email;
    //radio buttons for single or sharing
    QRadioButton *_singleRadio;
    QRadioButton *_sharingRadio;
    //pushbuttons for signals
    QPushButton *_saveButton;
    QPushButton *_closeButton;
    QPushButton *_dateButton;
    QPushButton *_checkDateButton;
    QPushButton *_copyDetailsButton;
    QPushButton *_checkVacanyButton;
    // arrive and departure date UI
    DateWindow *_dateWindow;
    // fileDialog
    QString _fileName;
    FileWriter* _fileWriter;

    QDateEdit *_arrivalDate;
    QDateEdit *_departureDate;
    QDateEdit *_queryArrival;
    QDateEdit *_queryDeparture;
    QDateEdit *_roomsAvaliable;
    BookingList *_bookingList;
    DateWindow *_datewindow;

};





#endif // BOOKINGWINDOW_H

//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#ifndef DATEWINDOW_H
#define DATEWINDOW_H
// widgets used to set up arrive and departure selection UI
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <QDateEdit>


class DateWindow : public QWidget
{
    Q_OBJECT
public:
    DateWindow();

public slots:
    void captureDate();


public:
    QDateEdit* getArrival() const;
    QDateEdit* getDeparture() const;

private:
    //function to set up UI
    void calenderWindow();
    //various widgets used for the UI
    QGridLayout* _calenderLayout;
    QLabel *_bookDate;
    QLabel *_arrive;
    QLabel *_depart;
    QCalendarWidget *_arriveCal;
    QCalendarWidget *_departCal;
    QPushButton *_reserveButton;
    QDateEdit *_arrivalDate;
    QDateEdit *_departureDate;

};

#endif // DATEWINDOW_H

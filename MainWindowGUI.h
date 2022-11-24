//COS3711 ADVANCED PROGRAMMING
//ASSIGNMENT 2
//JOHNATHAN DAVID COOKSON
//8812125074088
//45051429
#ifndef MAINWINDOWGUI_H
#define MAINWINDOWGUI_H
// headers for proceeding UIs
#include "BookingWindow.h"
#include "datewindow.h"

class MainWindowGUI : public QWidget
{
    Q_OBJECT
public:
    //constructor
    MainWindowGUI();

public slots:
    //slot to booking window
    void addbooking();

    //slot to check the date retrieved from above window
    void date();

private:
    //function to set up main window UI
    void setupGUI();
    //layout
    QGridLayout * _layout;
    //labels
    QLabel *_logo1;
    QLabel *_logo2;
    //buttons
    QPushButton *_bookedButton;
    QPushButton *_closeButton;
    //proceeding UIs
    BookingWindow *_bookWindow;
    DateWindow *_dateWindow;
};

#endif // MAINWINDOWGUI_H

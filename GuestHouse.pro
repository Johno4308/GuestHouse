QT -= gui

QT += xml           #included to read write xml
QT += widgets       #included for UI

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        BookingWindow.cpp \
        MainWindowGUI.cpp \
        booking.cpp \
        bookinglist.cpp \
        bookinglistfromxml.cpp \
        bookinglisttoxml.cpp \
        datewindow.cpp \
        filewriter.cpp \
        main.cpp \
        person.cpp \
        sharing.cpp \
        single.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    BookingWindow.h \
    MainWindowGUI.h \
    booking.h \
    bookinglist.h \
    bookinglistfromxml.h \
    bookinglisttoxml.h \
    datewindow.h \
    filewriter.h \
    person.h \
    sharing.h \
    single.h

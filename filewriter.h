#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>

class FileWriter
{
public:
    FileWriter(QString fn);
    void write(QString s) const;
private:
    QString _fileName;
};

#endif // FILEWRITER_H

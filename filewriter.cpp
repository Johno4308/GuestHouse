#include "filewriter.h"
#include <QTextStream>
#include <QFile>

FileWriter::FileWriter(QString fn):
    _fileName(fn)
{

}

void FileWriter::write(QString s) const
{
    QFile file(_fileName);
    file.open(QIODevice::ReadWrite);
    QTextStream toFile(&file);
    toFile << s;
    file.close();
}

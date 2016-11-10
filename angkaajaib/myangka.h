#ifndef MYANGKA_H
#define MYANGKA_H
#include <QString>
#include <QDebug>
#include <QStringList>


class myAngka
{

public:
    myAngka();
    int isEven(QString str);
    int checkNumeric(QString str);
    long int getDigit(long int numOfDigit);
    long int getOneDigit(long int numOfDigit);
    QStringList getMagicNum(QString str);

};

#endif // MYANGKA_H

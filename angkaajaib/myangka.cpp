#include "myangka.h"
#include <QString>
#include <QRegExp>
#include <QStringList>
#include <QDebug>

myAngka::myAngka()
{



}

// Method for check even or odd

int myAngka::isEven(QString str){

    int even = str.toInt();

    if (even%2 == 0){

        return 1;
    }else{
        return 0;
    }

}

// Method for check only numeric input that can be proccess

int myAngka::checkNumeric(QString str){

    bool isNum;
    int result = str.toInt(&isNum);

    if (isNum){
       // use returned value
        return 1;

    }else{
        // report error
        return 0;
    }
}

// Method for get how many digit square number contained

long int myAngka::getDigit(long int numOfDigit){


    long int digits = 0;

    if (numOfDigit < 0) {
        digits = 1;

    }

    while (numOfDigit) {
        numOfDigit /= 10;
        digits++;
    }


    if(digits == 1){
        digits++;
        return digits;
    }else{
        return digits;
    }

}

// If the square number only have one digit

long int myAngka::getOneDigit(long int numOfDigit){


    int digits = 0;

    if (numOfDigit < 0) {
        digits = 1;

    }

    while (numOfDigit) {
        numOfDigit /= 10;
        digits++;
    }

    return digits;

}


// Core method, to get the result of angka ajaib

QStringList myAngka::getMagicNum(QString forDigit){

    long int bk;
    QString bil1, bil2;
    long int bak,bil3;
    QStringList finalResult;

    for(long int i = 0; getDigit(i*i) <= forDigit.toInt(); i++){ // i*i sama dengan 2 digit ga hasilnya

        if(getDigit(i*i) == forDigit.toInt()){

            bak = i; //2
            bk = i*i; //4

            int preDeli = forDigit.toInt();

            if(getOneDigit(bk) == 1){

                bil1 = "0";

                QString deliBil2 = "(\\d{"+QString::number(preDeli/2)+"})$";
                QRegExp rx2(deliBil2);
                rx2.indexIn(QString::number(bk));
                bil2 = rx2.capturedTexts()[0];

                bil3 = bil1.toLong()+bil2.toLong();

            }else{

                QString deliBil1 = "(^\\d{"+QString::number(preDeli/2)+"})";
                QRegExp rx(deliBil1);
                rx.indexIn(QString::number(bk));
                bil1 = rx.capturedTexts()[0];

                QString deliBil2 = "(\\d{"+QString::number(preDeli/2)+"})$";
                QRegExp rx2(deliBil2);
                rx2.indexIn(QString::number(bk));
                bil2 = rx2.capturedTexts()[0];

                bil3 = bil1.toLong()+bil2.toLong();

            }


            if(bil3 == bak){

                if(getOneDigit(bak) == 1){

                    finalResult.append("0"+QString::number(bak));
                }else{

                    finalResult.append(QString::number(bak));

                }

            }
        }
    }

    return finalResult;

}

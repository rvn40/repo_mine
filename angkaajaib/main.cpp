#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QFile>
#include "myangka.h"

// Read file input


QString read(QString Filename)
{
    QFile mFile(Filename);
    QStringList mTextList; QString mText;

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QString notif = "Could not open file for reading";
        return notif;
    }

    QTextStream in(&mFile);

    while (!in.atEnd()) {
        mTextList += in.readLine().split("/n");
    }

    if (mTextList.count() == 1){
        mText = mTextList[0];

    }else{
        mText = "more than one line.";
    }

    mFile.close();

    return mText;

}

// Write file output for the first time

void newWrite(QString Filename, QString value, int numberOfArray){

    QFile mFile(Filename);

    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Could not open file for writting";
        return;
    }

    QTextStream out(&mFile);

    if(numberOfArray == 2){

        out << value << ",dan ";
        mFile.flush();
        mFile.close();

    }else if(numberOfArray == 0){

        out << "There is no magic number founded ";
        mFile.flush();
        mFile.close();

    }else{

        out << value << ", ";
        mFile.flush();
        mFile.close();

    }


}

// Write file output for the X iteration time

void write(QString Filename, QString value, int numberOfArray){

    QFile mFile(Filename);

    if(!mFile.open(QFile::WriteOnly | QFile::Append))
    {
        qDebug() << "Could not open file for writting";
        return;
    }

    QTextStream out(&mFile);

    if(numberOfArray == 2){

        out << value << ",dan ";
        mFile.flush();
        mFile.close();

    }else if(numberOfArray == 1){

        out << value ;
        mFile.flush();
        mFile.close();

    }else{

        out << value << ", ";
        mFile.flush();
        mFile.close();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myAngka angka;

    QString forDigit, fileInputPath, fileOutputPath;
    int newFile = 0;

    fileInputPath = "C:/Documents/inputAngkaMagic.txt";

    forDigit= read(fileInputPath);

    if(forDigit == "" || forDigit == " "){

        qDebug() << "Input value can't be empty";

    }else if(angka.checkNumeric(forDigit) == 1 && angka.isEven(forDigit)){

        QStringList magicNumber = angka.getMagicNum(forDigit);
        fileOutputPath = "C:/Documents/outputAngkaMagic.txt";
        int magicNumberCount = magicNumber.count();

        if(forDigit <= "2"){
            QString zero = "00";
            if(newFile == 0){

                newWrite(fileOutputPath, zero, magicNumberCount);
                newFile++;

            }else{

                write(fileOutputPath, zero, magicNumberCount);
                newFile++;

            }
        }

        for(int i = 0; i < magicNumber.count() ; i++){

            if(newFile == 0){

                newWrite(fileOutputPath, magicNumber[i], magicNumberCount);
                newFile++;
                magicNumberCount--;

            }else{

                write(fileOutputPath, magicNumber[i], magicNumberCount);
                newFile++;
                magicNumberCount--;

            }
        }


    }else{

        qDebug() << "Opps, your input value must be numeric, even numeric, and can't more than one line.";

    }


    return a.exec();
}


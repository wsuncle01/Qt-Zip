#include "zip.h"
#include <fstream>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include "tree.h"


Zip::Zip()
{
//
}

void Zip::zipfile(QString OutPutPath)
{

//    QFile file("C:/Users/黄辙/Desktop/1111/test.bin");
//    if (!file.open(QIODevice::WriteOnly)) {
//        qDebug() << "Cannot open file for writing: "
//                 << qPrintable(file.errorString());
//        return;
//    }
//    QDataStream out(&file);
//    out.writeRawData(zDate,zDate.end()-zDate.begin());
//    file.close();
    ziptree.preOrder();
    QFile file(OutPutPath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Cannot open file for writing: "
                 << qPrintable(file.errorString());
        return;
    }
    QByteArray outfileData;
    outfileData=QString::fromStdString("").toUtf8();
    outfileData.append(ziptree.localFile);
    outfileData.append(ziptree.centralDirFile);
    outfileData.append(ziptree.EOCD);
    QDataStream out(&file);
    out.writeRawData(outfileData,outfileData.end()-outfileData.begin());
    file.close();
}



//void Zip::test()
//{
//    QFile file("C:/Users/黄辙/Desktop/1111/test.bin");
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
//        qDebug() << "Cannot open file for writing: "
//                  << qPrintable(file.errorString());
//        return;
//    }
//    int len=3;
//    const char* charArray = "\x00\x01\x99";
//    QByteArray byteArray = QByteArray::fromRawData(charArray, len);
//    QDataStream out(&file);
//    out.writeRawData(byteArray,byteArray.end()-byteArray.begin());
//    file.close();
//}

QByteArray Zip::getcrc32(QString data)
{
    QByteArray crcval;
    crcval=calcFileCRC(data);
    //qDebug()<<crcval;
//    QFile file("C:/Users/黄辙/Desktop/1111/test.bin");
//    if (!file.open(QIODevice::WriteOnly |QIODevice::Append)) {
//        qDebug() << "Cannot open file for writing: "
//                 << qPrintable(file.errorString());
//    }
//    QDataStream out(&file);
//    out.writeRawData(crcval,crcval.end()-crcval.begin());
//    file.close();
    return crcval;
}

QByteArray Zip::getlength(QString data)
{
    QByteArray length;
    length=fsize(data);
    //qDebug()<<length;
//    QFile file("C:/Users/黄辙/Desktop/1111/test.bin");
//    if (!file.open(QIODevice::WriteOnly |QIODevice::Append)) {
//        qDebug() << "Cannot open file for writing: "
//                 << qPrintable(file.errorString());
//    }
//    QDataStream out(&file);
//    out.writeRawData(length,length.end()-length.begin());
//    file.close();
    return length;
}

void Zip::addfile(QString path, QString data)
{
    QStringList filepath;
    filepath=path.split('/');
    ziptree.addFile(filepath,data);
}




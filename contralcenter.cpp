#include "contralcenter.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QByteArray>
#include <QFile>
#include <QMessageBox>


ContralCenter::ContralCenter()
{

}

ContralCenter::~ContralCenter()
{

}

void ContralCenter::setProFile(const QString &proFile)
{
    proFile_ = proFile;
    loadProFile();
}

bool ContralCenter::loadProFile()
{
    QFile* newFile = new QFile;
    newFile->setFileName(proFile_);
    bool exists = false;
    QJsonObject jsonRoot;
    if(newFile->exists())
    {
       exists = true;
       if(!newFile->open(QIODevice::ReadOnly | QIODevice::Text))
       {
           delete newFile;
           return false;
       }
       
       QString root = newFile->readAll();
       QJsonParseError jsonError;
       QJsonDocument document = QJsonDocument::fromJson(root.toUtf8(), &jsonError);
       
       if(jsonError.error != QJsonParseError::NoError)
       {
           newFile->close();
           delete newFile;
           return false;
       }
    }
    else
    {
        if(!newFile->open(QIODevice::WriteOnly | QIODevice::Text))
        {      
            delete newFile;
            return false;
        }

        QJsonArray jsonArray;
        jsonRoot["target"] = jsonArray;
        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonRoot);
        QByteArray data = jsonDoc.toJson();
        newFile->write(QString(data).toUtf8());
    }

    newFile->close();
    delete newFile;
    return true;
}

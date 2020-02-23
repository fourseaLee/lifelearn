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

void ContralCenter::addTarget(Target *target)
{
    map_name_target_[target->target] = target;
}

void ContralCenter::addTargetExtent(const QString &target, Extent *extent)
{
    map_name_target_[target]->extent = extent;
}

void ContralCenter::addTask(const QString &target, Task *task)
{
    map_name_target_[target]->vectTask.push_back(task);
}

void ContralCenter::addTaskExtent(const QString &target, const QString &task, Extent *extent)
{
   for(unsigned int i = 0; i < map_name_target_[target]->vectTask.size(); i++)
   {
       if(map_name_target_[target]->vectTask[i]->task == task)
       {
           map_name_target_[target]->vectTask[i]->extent = extent;
           return;
       }
   }
}

void ContralCenter::getTask(const QString &target, const QString &task_name, Task *&task)
{
    for(unsigned int i = 0; i < map_name_target_[target]->vectTask.size(); i++)
    {
        if(map_name_target_[target]->vectTask[i]->task == task_name)
        {
           task = map_name_target_[target]->vectTask[i];
           return;
        }
    }
}

void ContralCenter::getTargets(std::vector<QString> &vectTarget)
{
    std::map<QString, Target*>::const_iterator iter = map_name_target_.begin();
    while (iter != map_name_target_.end())
    {
        vectTarget.push_back(iter->first);
        iter++;
    }
}

void ContralCenter::getTasks(const QString &target, std::vector<QString> &vectTask)
{
    for(unsigned int i = 0; i < map_name_target_[target]->vectTask.size(); i++)
    {
        vectTask.push_back(map_name_target_[target]->vectTask[i]->task);
    }
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

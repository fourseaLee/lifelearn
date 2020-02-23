#ifndef CONTRALCENTER_H
#define CONTRALCENTER_H
#include <QString>
#include <vector>
#include <map>
#include "newfiledlg.h"
struct Extent
{
    QString import;
    QString urgency;
    QString priority;
};

struct Task
{
    QString task;
    QString taskDesc;

    QString quantization;
    QString quantizationDesc;
    int minTime;
    int maxTime;
    Extent *extent;
};

struct Target
{
    QString target;
    QString targetDesc;
    std::vector<Task*> vectTask;
    Extent *extent;
};

class ContralCenter
{
public:
    ContralCenter();
    ~ContralCenter();

    void setProFile(const QString& proFile);

public:
    void addTarget(Target* target);

    void addTargetExtent(const QString& target, Extent* extent);

    void addTask(const QString& target, Task*task);

    void addTaskExtent(const QString& target, const QString& task ,Extent* extent);

    void getTask(const QString& target, const QString& task_name, Task*& task);

    void getTargets(std::vector<QString>& vectTarget);

    void getTasks(const QString& target, std::vector<QString>& vectTask);

protected:
    bool loadProFile();


private:
    QString proFile_;
    std::map<QString, Target*> map_name_target_;
};

#endif // CONTRALCENTER_H

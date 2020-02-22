#ifndef CONTRALCENTER_H
#define CONTRALCENTER_H
#include <QString>
#include <vector>
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

protected:
    bool loadProFile();


private:
    QString proFile_;
    std::vector<Target*> task_;
};

#endif // CONTRALCENTER_H

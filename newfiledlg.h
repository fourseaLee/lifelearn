#ifndef NEWFILEDLG_H
#define NEWFILEDLG_H

#include <QDialog>

namespace Ui {
class NewFileDlg;
}

class NewFileDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NewFileDlg(QWidget *parent = nullptr);
    ~NewFileDlg();

    QString getNewFile();

private slots:
    void on_buttonBox_accepted();

    void on_fixPath_clicked();

private:
    Ui::NewFileDlg *ui;
    QString filePath_;
    QString fileName_;
};

#endif // NEWFILEDLG_H

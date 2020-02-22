#ifndef VIEWDLG_H
#define VIEWDLG_H

#include <QDialog>

namespace Ui {
class ViewDlg;
}

class ViewDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ViewDlg(QWidget *parent = nullptr);
    ~ViewDlg();

private:
    Ui::ViewDlg *ui;
};

#endif // VIEWDLG_H

#include "viewdlg.h"
#include "ui_viewdlg.h"

ViewDlg::ViewDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewDlg)
{
    ui->setupUi(this);
}

ViewDlg::~ViewDlg()
{
    delete ui;
}

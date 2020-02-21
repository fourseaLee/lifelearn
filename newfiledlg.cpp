#include "newfiledlg.h"
#include "ui_newfiledlg.h"
#include <QFileDialog>

NewFileDlg::NewFileDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFileDlg)
{
    ui->setupUi(this);
}

NewFileDlg::~NewFileDlg()
{
    delete ui;
}

QString NewFileDlg::getNewFile()
{

    return  filePath_ + tr("/")+ fileName_ + tr(".llpro");
}

void NewFileDlg::on_buttonBox_accepted()
{
    filePath_ = ui->lineEditPath->text();
    fileName_ = ui->lineEditName->text();
}

void NewFileDlg::on_fixPath_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(this, "选择路径", "/");
    ui->lineEditPath->setText(filePath);

}

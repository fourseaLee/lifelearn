#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_target_submit_clicked()
{
    QMessageBox::information(nullptr,tr("提示"),tr("提交成功"), QMessageBox::Yes, QMessageBox::Yes);
}

void MainWindow::on_pushButton_task_add_clicked()
{
    QMessageBox::information(nullptr,tr("提示"),tr("添加成功"), QMessageBox::Yes, QMessageBox::Yes);
}

void MainWindow::on_pushButton_quantization_submit_clicked()
{
    QMessageBox::information(nullptr,tr("提示"),tr("提交成功"), QMessageBox::Yes, QMessageBox::Yes);
}

void MainWindow::on_pushButton_advance_submit_clicked()
{
    QMessageBox::information(nullptr,tr("提示"),tr("提交成功"), QMessageBox::Yes, QMessageBox::Yes);
}

void MainWindow::on_pushButton_advance_setting_clicked()
{

}

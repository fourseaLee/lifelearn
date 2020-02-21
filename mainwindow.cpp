#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "newfiledlg.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QByteArray>

static NewFileDlg* s_newFileDlg = nullptr;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s_newFileDlg = new NewFileDlg();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_target_submit_clicked()
{
    QString target = ui->lineEdit_target->text();
    QString target_desc = ui->textEdit_target_desc->toPlainText();
    QMessageBox::information(nullptr, tr("提示"), tr("提交成功"), QMessageBox::Yes, QMessageBox::Yes);
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

void MainWindow::on_actionopen_triggered()
{
    QString proFile = QFileDialog::getOpenFileName(this, tr("打开计划文件"), "./", tr("life learn(*.llpro)"));
    QFile loadFile(proFile);
}

void MainWindow::on_actionnew_triggered()
{
    s_newFileDlg->exec();
    QString fileName = s_newFileDlg->getNewFile();

    QFile * newFile = new QFile;
    newFile->setFileName(fileName);
    if(newFile->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(nullptr,tr("打开文件失败"), fileName, QMessageBox::Yes, QMessageBox::Yes);
    }

    QJsonObject jsonRoot;
    QJsonArray jsonArray;
    jsonRoot[tr("target")] = jsonArray;
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonRoot);
    QByteArray data = jsonDoc.toJson();
    newFile->write(QString(data).toUtf8());
    newFile->close();
}

void MainWindow::on_action_target_task_dendrogram_triggered()
{

}

void MainWindow::on_action_quantization_list_triggered()
{

}

void MainWindow::on_action_advance_sequence_diagram_triggered()
{

}

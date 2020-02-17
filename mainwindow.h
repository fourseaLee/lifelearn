#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_target_submit_clicked();

    void on_pushButton_task_add_clicked();

    void on_pushButton_quantization_submit_clicked();

    void on_pushButton_advance_submit_clicked();

    void on_pushButton_advance_setting_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

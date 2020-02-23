#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ContralCenter;

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

    void on_actionopen_triggered();

    void on_actionnew_triggered();

    void on_action_target_task_dendrogram_triggered();

    void on_action_quantization_list_triggered();

    void on_action_advance_sequence_diagram_triggered();

    void on_tabWidget_currentChanged(int index);

protected:
    ContralCenter* contralCenter_;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

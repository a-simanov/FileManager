#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QString>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetLeftFolder();
    void SetRightFolder();

private slots:

    void on_left_list_widget_itemDoubleClicked(QListWidgetItem *item);

    void on_right_list_widget_itemDoubleClicked(QListWidgetItem *item);

    void on_btn_go_to_left_clicked();

    void on_btn_go_to_left_2_clicked();

private:
    Ui::MainWindow *ui;
    QString left_folder_;
    QString right_folder_;

    QList<QString> left_list_;
    QList<QString> right_list_;

    int left_index_;
    int right_index_;
};
#endif // MAINWINDOW_H

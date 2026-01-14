#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "createdirform.h"
#include "dialogrename.h"
#include "ui_dialogrename.h"


#include <QMainWindow>
#include <QProcess>
#include <QString>
#include <QListWidgetItem>
#include <QDir>

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
    void SetFolder(QString& folder, QStringList& list, QListWidget* widget, QLineEdit* le);
    void SetFolderByFlag();
    void ProcessDoubleClicked(int& idx, QString& folder, QStringList& list, QListWidget* widget, QLineEdit* le, QListWidgetItem *item);
    void ProcessItemClicked (QString& folder, QListWidgetItem *item, bool& r_flag, bool& l_flag, QStringList& list, int& idx);
    void createDir();

private slots:

    void on_left_list_widget_itemDoubleClicked(QListWidgetItem *item);

    void on_right_list_widget_itemDoubleClicked(QListWidgetItem *item);

    void on_btn_go_to_left_clicked();

    void on_btn_go_to_right_clicked();

    void on_btn_copy_clicked();

    void on_right_list_widget_itemClicked(QListWidgetItem *item);

    void on_left_list_widget_itemClicked(QListWidgetItem *item);

    void on_btn_create_folder_clicked();

    void on_btn_delete_clicked();

    void on_btn_replace_clicked();

    void copyDir (QDir destination_dir, QFileInfo file_info);

    void on_btn_rename_clicked();

    void renameObject();

private:
    Ui::MainWindow *ui;
    QString left_folder_;
    QString right_folder_;
    QString file_name_;

    QStringList left_list_;
    QStringList right_list_;

    int left_index_;
    int right_index_;
    bool is_right_folder = false;
    bool is_left_folder = false;

    CreateDirForm dir_form_;
    DialogRename new_name_;
};
#endif // MAINWINDOW_H

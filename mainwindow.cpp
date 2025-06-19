#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QDesktopServices>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qInfo() << "Приложение запущено";
    left_folder_ = "C:/PRGM";
    right_folder_ = "C:/Program Files";

    SetLeftFolder();
    SetRightFolder();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetLeftFolder() {
    QDir dir(left_folder_);
    ui->left_path_le->setText(left_folder_);
    left_list_ = dir.entryList();
    ui->left_list_widget->clear();
    ui->left_list_widget->addItems(left_list_);
}

void MainWindow::SetRightFolder() {
    QDir dir(right_folder_);
    ui->right_path_le->setText(right_folder_);
    right_list_ = dir.entryList();
    ui->right_list_widget->clear();
    ui->right_list_widget->addItems(right_list_);
}


void MainWindow::on_left_list_widget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << "Выбран элемент левого списка:" << item->listWidget()->currentRow();
    left_index_ = item->listWidget()->currentRow();
    QDir dir(left_folder_);
    QFileInfo file_info(dir,left_list_[left_index_]);
    if (file_info.isDir()) {
        left_folder_ = file_info.absoluteFilePath();
        SetLeftFolder();
    } else {
        QDesktopServices::openUrl(QUrl::fromLocalFile(file_info.absoluteFilePath()));
    }
}


void MainWindow::on_right_list_widget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << "Выбран элемент правого списка:" << item->listWidget()->currentRow();
    right_index_ = item->listWidget()->currentRow();
    QDir dir(right_folder_);
    QFileInfo file_info(dir.filePath(right_list_[right_index_]));
    if (file_info.isDir()) {
        right_folder_ = file_info.absoluteFilePath();
        SetRightFolder();
    } else {
        QDesktopServices::openUrl(QUrl::fromLocalFile(file_info.absoluteFilePath()));
    }
}


void MainWindow::on_btn_go_to_left_clicked()
{
    left_folder_ = ui->left_path_le->text();
    SetLeftFolder();
}


void MainWindow::on_btn_go_to_left_2_clicked()
{
    right_folder_ = ui->right_path_le->text();
    SetRightFolder();
}


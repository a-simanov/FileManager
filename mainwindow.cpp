#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDesktopServices>
#include <QDebug>
#include <QTreeView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qInfo() << "Приложение запущено";
    left_folder_ = "/home/artem/Project/Test/T1";
    right_folder_ = "/home/artem/Project/Test";

    SetLeftFolder();
    SetRightFolder();

    connect(&dir_form_, &CreateDirForm::sendDirName, this, &MainWindow::createDir);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetLeftFolder() {
    QDir dir(left_folder_);
    ui->left_path_le->setText(left_folder_);

    auto comp = [](const QString &str1, const QString &str2) {
        if(str1.contains(".") && !str2.contains(".")) {
            return str1 > str2;
        } else if (!str1.contains(".") && str2.contains(".")) {
            return str1 < str2;
        }
        return str1 < str2;

    };

    left_list_ = dir.entryList();
    std::sort(left_list_.begin(), left_list_.end(), comp);
    ui->left_list_widget->clear();
    ui->left_list_widget->addItems(left_list_);
}

void MainWindow::SetRightFolder() {
    QDir dir(right_folder_);
    ui->right_path_le->setText(right_folder_);

    auto comp = [](const QString &str1, const QString &str2) {
        if(str1.contains(".") && !str2.contains(".")) {
            return str1 > str2;
        } else if (!str1.contains(".") && str2.contains(".")) {
            return str1 < str2;
        }
        return str1 < str2;

    };

    right_list_ = dir.entryList();
    std::sort(right_list_.begin(), right_list_.end(), comp);

    ui->right_list_widget->clear();
    ui->right_list_widget->addItems(right_list_);
}


void MainWindow::on_left_list_widget_itemDoubleClicked(QListWidgetItem *item)
{
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


void MainWindow::on_btn_copy_clicked()
{
        QDir dir;
        QString file;
        QString destination;

        if (is_right_folder) {
            dir = right_folder_;
            file = dir.filePath(right_list_[right_index_]);
            destination = left_folder_;
        } else {
            dir = left_folder_;
            file = dir.filePath(left_list_[left_index_]);
            destination = right_folder_;
        }

        QFileInfo file_info(file);

        if (file_info.isFile()) {
            qDebug() << file;
            QFile::copy(file, destination + "/" + file_info.fileName());
        } else {            
            QDir destination_dir = (dir == left_folder_) ? right_folder_ : left_folder_;
            copyDir (destination_dir,file_info);

        }


        if (is_right_folder) {
            SetLeftFolder();
        } else {
            SetRightFolder();
        }
}


void MainWindow::on_right_list_widget_itemClicked(QListWidgetItem *item)
{
    right_index_ = item->listWidget()->currentRow();
    is_right_folder = true;
    is_left_folder = false;
}


void MainWindow::on_left_list_widget_itemClicked(QListWidgetItem *item)
{
    left_index_ = item->listWidget()->currentRow();
    is_right_folder = false;
    is_left_folder = true;
}

void MainWindow::createDir() {

    QString path;
    QDir dir;
    QString name = dir_form_.getDirName();

    if (is_right_folder) {
        path = right_folder_;
    } else {
        path = left_folder_;
    }

    path += "/" + name;


    dir.mkdir(path);

    if (is_right_folder) {
        SetRightFolder();
    } else {
        SetLeftFolder();
    }
}

void MainWindow::on_btn_create_folder_clicked()
{
    dir_form_.show();
}


void MainWindow::on_btn_delete_clicked()
{
    QDir dir;
    QFileInfo file_info;

    if (is_right_folder) {
        dir = right_folder_;
        file_info = QFileInfo(dir.filePath(right_list_[right_index_]));
    } else {
        dir = left_folder_;
        file_info = QFileInfo(dir.filePath(left_list_[left_index_]));
    }

    if(file_info.isFile()) {
        QString name(file_info.filePath());
        QFile(name).remove();
    } else {
        QString name(file_info.filePath());
        QDir(name).removeRecursively();
    }

    if (is_right_folder) {
        SetRightFolder();
    } else {
        SetLeftFolder();
    }
}


void MainWindow::on_btn_replace_clicked()
{
    QDir dir;
    QString file;
    QString destination;

    if (is_right_folder) {
        dir = right_folder_;
        file = dir.filePath(right_list_[right_index_]);
        destination = left_folder_;
    } else {
        dir = left_folder_;
        file = dir.filePath(left_list_[left_index_]);
        destination = right_folder_;
    }

    QFileInfo file_info(file);

    if (file_info.isFile()) {
        QFile::copy(file, destination + "/" + file_info.fileName());
        QFile(file).remove();
    }
    SetLeftFolder();
    SetRightFolder();
}

void MainWindow::copyDir (QDir destination_dir, QFileInfo file_info) {
    QDir source_dir{file_info.absoluteFilePath()};

    destination_dir.mkdir(file_info.fileName());

    QFileInfoList entries = source_dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    for (const QFileInfo& entry : entries) {
        if (entry.isDir()) {
            qDebug() << entry.fileName();
            QDir dest = destination_dir.filePath(file_info.fileName());
            qDebug() << dest;
            copyDir(dest, entry);
        } else {
            destination_dir = destination_dir.absoluteFilePath(file_info.fileName());
            QString dest = destination_dir.path();
            QFile::copy(entry.absoluteFilePath(), dest + "/" + entry.fileName());
        }
    }


}

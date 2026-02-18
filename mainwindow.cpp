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
    QDir current = QDir::currentPath();
    left_folder_ = current.absolutePath();
    right_folder_ = current.absolutePath();

    SetFolder(left_folder_, left_list_, ui->left_list_widget,ui->left_path_le);
    SetFolder(right_folder_, right_list_, ui->right_list_widget,ui->right_path_le);

    connect(&dir_form_, &CreateDirForm::sendDirName, this, &MainWindow::createDir);
    connect(&new_name_, &DialogRename::sendNewName, this, &MainWindow::renameObject);
}

MainWindow::~MainWindow()
{
    qInfo() << "Приложение завершено";
    delete ui;
}

void MainWindow::SetFolder(QString& folder, QStringList& list, QListWidget* widget, QLineEdit* le) {
    QDir dir(folder);
    le->setText(folder);
    dir.setSorting(QDir::Type | QDir::DirsFirst);
    list = dir.entryList(QDir::AllEntries | QDir::NoDot);

    widget->clear();
    widget->addItems(list);
}

void MainWindow::ProcessDoubleClicked(int& idx, QString& folder,
                                      QStringList& list, QListWidget* widget,
                                      QLineEdit* le, QListWidgetItem *item) {
    idx = item->listWidget()->currentRow();
    QDir dir(folder);
    QFileInfo file_info(dir,list[idx]);
    if (file_info.isDir()) {
        folder = file_info.absoluteFilePath();
        SetFolder(folder, list, widget, le);
    } else {
        QDesktopServices::openUrl(QUrl::fromLocalFile(file_info.absoluteFilePath()));
    }
}

void MainWindow::on_left_list_widget_itemDoubleClicked(QListWidgetItem *item)
{
    ProcessDoubleClicked(left_index_, left_folder_, left_list_, ui->left_list_widget,ui->left_path_le, item);
}


void MainWindow::on_right_list_widget_itemDoubleClicked(QListWidgetItem *item)
{
    ProcessDoubleClicked(right_index_, right_folder_, right_list_, ui->right_list_widget,ui->right_path_le, item);
}


void MainWindow::on_btn_go_to_left_clicked()
{
    left_folder_ = ui->left_path_le->text();
    SetFolder(left_folder_, left_list_, ui->left_list_widget,ui->left_path_le);
}


void MainWindow::on_btn_go_to_right_clicked()
{
    right_folder_ = ui->right_path_le->text();
    SetFolder(right_folder_, right_list_, ui->right_list_widget,ui->right_path_le);
}

void MainWindow::SetFolderByFlag() {
    if (is_right_folder) {
        SetFolder(right_folder_, right_list_, ui->right_list_widget,ui->right_path_le);
    } else {
        SetFolder(left_folder_, left_list_, ui->left_list_widget,ui->left_path_le);
    }
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
            SetFolder(left_folder_, left_list_, ui->left_list_widget,ui->left_path_le);
        } else {
            SetFolder(right_folder_, right_list_, ui->right_list_widget,ui->right_path_le);
        }
}

void MainWindow::ProcessItemClicked (QString& folder, QListWidgetItem *item, bool& r_flag, bool& l_flag, QStringList& list, int& idx) {
    QDir dir = folder;
    idx = item->listWidget()->currentRow();
    r_flag = true;
    l_flag = false;
    QFileInfo file_info = QFileInfo(dir.filePath(list[idx]));
    file_name_ = file_info.fileName();
    new_name_.ui->le_new_name->setText(file_name_);
}

void MainWindow::on_right_list_widget_itemClicked(QListWidgetItem *item)
{
    ProcessItemClicked(right_folder_, item, is_right_folder, is_left_folder, right_list_, right_index_);
}


void MainWindow::on_left_list_widget_itemClicked(QListWidgetItem *item)
{
    ProcessItemClicked(left_folder_, item, is_left_folder, is_right_folder, left_list_, left_index_);
}

void MainWindow::createDir(const QString& dir_name) {

    QString path;
    QDir dir;
    QString name = dir_name;

    if (is_right_folder) {
        path = right_folder_;
    } else {
        path = left_folder_;
    }

    path += "/" + name;
    dir.mkdir(path);

    SetFolderByFlag();
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

    SetFolderByFlag();
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
    } else {
        QDir destination_dir = (dir == left_folder_) ? right_folder_ : left_folder_;
        copyDir (destination_dir,file_info);
        QDir(file).removeRecursively();
    }

    SetFolder(left_folder_, left_list_, ui->left_list_widget,ui->left_path_le);
    SetFolder(right_folder_, right_list_, ui->right_list_widget,ui->right_path_le);
}

void MainWindow::copyDir (QDir destination_dir, QFileInfo file_info) {
    QDir source_dir{file_info.absoluteFilePath()};
    QString new_name;
    if (QDir(destination_dir.path() + "/" + file_info.fileName()).exists()) {
        destination_dir.mkdir(file_info.fileName() + "-copy");
        new_name = destination_dir.path() + "/" + file_info.fileName() + "-copy";
    } else {
        destination_dir.mkdir(file_info.fileName());
        new_name = destination_dir.path() + "/" + file_info.fileName();
    }

    QFileInfoList entries = source_dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    for (const QFileInfo& entry : entries) {
        if (entry.isDir()) {
            QDir dest(new_name);
            copyDir(dest, entry);
        } else {
            destination_dir = destination_dir.absoluteFilePath(file_info.fileName());
            QString dest = destination_dir.path();
            QFile::copy(entry.absoluteFilePath(), dest + "/" + entry.fileName());
        }
    }
}

void MainWindow::on_btn_rename_clicked()
{
    new_name_.show();
}

void MainWindow::renameObject(const QString& name) {
    QDir dir;
    QString file;

    if (is_right_folder) {
        dir = right_folder_;
        file = dir.filePath(right_list_[right_index_]);
    } else {
        dir = left_folder_;
        file = dir.filePath(left_list_[left_index_]);
    }

    QFileInfo file_info{file};
    QString new_name = file_info.path() + "/" + name;

    bool done= QFile::rename(file_info.absoluteFilePath(), new_name);

    qDebug() << done;

    SetFolderByFlag();
}


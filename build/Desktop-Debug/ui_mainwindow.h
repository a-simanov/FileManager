/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *right_path_le;
    QPushButton *btn_go_to_left_2;
    QListWidget *right_list_widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *left_path_le;
    QPushButton *btn_go_to_left;
    QListWidget *left_list_widget;
    QPushButton *btn_copy;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        right_path_le = new QLineEdit(centralwidget);
        right_path_le->setObjectName("right_path_le");

        horizontalLayout_2->addWidget(right_path_le);

        btn_go_to_left_2 = new QPushButton(centralwidget);
        btn_go_to_left_2->setObjectName("btn_go_to_left_2");

        horizontalLayout_2->addWidget(btn_go_to_left_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        right_list_widget = new QListWidget(centralwidget);
        right_list_widget->setObjectName("right_list_widget");

        verticalLayout_2->addWidget(right_list_widget);


        gridLayout->addLayout(verticalLayout_2, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        left_path_le = new QLineEdit(centralwidget);
        left_path_le->setObjectName("left_path_le");

        horizontalLayout->addWidget(left_path_le);

        btn_go_to_left = new QPushButton(centralwidget);
        btn_go_to_left->setObjectName("btn_go_to_left");

        horizontalLayout->addWidget(btn_go_to_left);


        verticalLayout->addLayout(horizontalLayout);

        left_list_widget = new QListWidget(centralwidget);
        left_list_widget->setObjectName("left_list_widget");

        verticalLayout->addWidget(left_list_widget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        btn_copy = new QPushButton(centralwidget);
        btn_copy->setObjectName("btn_copy");

        gridLayout->addWidget(btn_copy, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_go_to_left_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270", nullptr));
        btn_go_to_left->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270", nullptr));
        btn_copy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

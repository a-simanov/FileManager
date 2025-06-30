/********************************************************************************
** Form generated from reading UI file 'createdirform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDIRFORM_H
#define UI_CREATEDIRFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateDirForm
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *le_dir_name;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateDirForm)
    {
        if (CreateDirForm->objectName().isEmpty())
            CreateDirForm->setObjectName("CreateDirForm");
        CreateDirForm->resize(400, 300);
        verticalLayout = new QVBoxLayout(CreateDirForm);
        verticalLayout->setObjectName("verticalLayout");
        le_dir_name = new QLineEdit(CreateDirForm);
        le_dir_name->setObjectName("le_dir_name");

        verticalLayout->addWidget(le_dir_name);

        buttonBox = new QDialogButtonBox(CreateDirForm);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CreateDirForm);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CreateDirForm, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CreateDirForm, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CreateDirForm);
    } // setupUi

    void retranslateUi(QDialog *CreateDirForm)
    {
        CreateDirForm->setWindowTitle(QCoreApplication::translate("CreateDirForm", "Dialog", nullptr));
        le_dir_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateDirForm: public Ui_CreateDirForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDIRFORM_H

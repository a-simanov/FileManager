/********************************************************************************
** Form generated from reading UI file 'dialogrename.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRENAME_H
#define UI_DIALOGRENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogRename
{
public:
    QGridLayout *gridLayout;
    QLineEdit *le_new_name;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogRename)
    {
        if (DialogRename->objectName().isEmpty())
            DialogRename->setObjectName("DialogRename");
        DialogRename->resize(400, 300);
        gridLayout = new QGridLayout(DialogRename);
        gridLayout->setObjectName("gridLayout");
        le_new_name = new QLineEdit(DialogRename);
        le_new_name->setObjectName("le_new_name");

        gridLayout->addWidget(le_new_name, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogRename);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(DialogRename);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogRename, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogRename, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogRename);
    } // setupUi

    void retranslateUi(QDialog *DialogRename)
    {
        DialogRename->setWindowTitle(QCoreApplication::translate("DialogRename", "Dialog", nullptr));
        le_new_name->setText(QCoreApplication::translate("DialogRename", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\320\276\320\265 \320\270\320\274\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRename: public Ui_DialogRename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRENAME_H

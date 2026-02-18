#include "dialogrename.h"
#include "ui_dialogrename.h"

DialogRename::DialogRename(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogRename)
{
    ui->setupUi(this);
}

DialogRename::~DialogRename()
{
    delete ui;
}

void DialogRename::on_buttonBox_accepted()
{
    new_name_ = ui->le_new_name->text();
    ui->le_new_name->clear();
    emit sendNewName(new_name_);
}


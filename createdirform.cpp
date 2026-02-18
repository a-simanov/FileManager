#include "createdirform.h"
#include "ui_createdirform.h"

CreateDirForm::CreateDirForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateDirForm)
{
    ui->setupUi(this);
}

CreateDirForm::~CreateDirForm()
{
    delete ui;
}

void CreateDirForm::on_buttonBox_accepted()
{
    dir_name_ = ui->le_dir_name->text();
    ui->le_dir_name->clear();
    emit sendDirName(dir_name_);
}


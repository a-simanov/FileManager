#ifndef CREATEDIRFORM_H
#define CREATEDIRFORM_H

#include <QDialog>

namespace Ui {
class CreateDirForm;
}

class CreateDirForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDirForm(QWidget *parent = nullptr);
    ~CreateDirForm();

signals:
    void sendDirName(const QString& dir_name);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CreateDirForm *ui;
    QString dir_name_;

};

#endif // CREATEDIRFORM_H

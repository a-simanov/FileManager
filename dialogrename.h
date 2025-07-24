#ifndef DIALOGRENAME_H
#define DIALOGRENAME_H

#include <QDialog>

namespace Ui {
class DialogRename;
}

class DialogRename : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRename(QWidget *parent = nullptr);
    ~DialogRename();
    QString getNewName () {
        return new_name_;
    }
signals:
    void sendNewName();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogRename *ui;
    QString new_name_;
};

#endif // DIALOGRENAME_H

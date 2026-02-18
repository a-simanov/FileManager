#ifndef DIALOGRENAME_H
#define DIALOGRENAME_H

#include <QDialog>

namespace Ui {
class DialogRename;
}

class DialogRename : public QDialog
{
    Q_OBJECT

    friend class MainWindow;

public:
    explicit DialogRename(QWidget *parent = nullptr);
    ~DialogRename();
signals:
    void sendNewName(const QString& new_name);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogRename *ui;
    QString new_name_;
};

#endif // DIALOGRENAME_H

#ifndef LOGUSER_H
#define LOGUSER_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>


namespace Ui {
class logUser;
}

class logUser : public QDialog
{
    Q_OBJECT

public:
    explicit logUser(QWidget *parent = nullptr);
    ~logUser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::logUser *ui;
    QSqlDatabase mydb;
};

#endif // LOGUSER_H

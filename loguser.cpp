#include "loguser.h"
#include "ui_loguser.h"
#include "recipewindow.h"
#include "mainwindow.h"

logUser::logUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::logUser)
{
    ui->setupUi(this);


    ui->label_3->setText("");
    mydb=QSqlDatabase::addDatabase ("QSQLITE") ;
    mydb. setDatabaseName ("C:/Users/Raghav Singla/OneDrive/Desktop/SQLITE/sqlite-tools-win-x64-3450200/myrecipe.db") ;

    if(!mydb.open()){
        ui->label_3->setText("Failed to connect to Database");
    }
    else{
        ui->label_3->setText("Connected...");

    }
}

logUser::~logUser()
{
    delete ui;
}







void logUser::on_pushButton_clicked()
{
    QString  username , password;


    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the databse";

        return;
    }




    QSqlQuery qry;
    QString queryStr = "SELECT * FROM user WHERE username = '" + username + "' AND password = '" + password + "'";

    if (qry.exec(queryStr)){
        int count = 0;
        while (qry.next()){
            count++;
        }

        if (count == 1){
            ui->label_3->setText("User Logged in successfully");
            this->close();

            // Open the recipewindow window
            recipewindow *recipeWindowobject = new recipewindow(nullptr, username);
            recipeWindowobject->show();




        }
        // if (count > 1){
        //     ui->label_3->setText("Duplicate username and password");
        // }
        if (count < 1){
            ui->label_3->setText("username or passwor is not correct");
        }
    }
    else {
        qDebug() << "Error executing query: " << qry.lastError().text();
        ui->label_3->setText("Failed to add user");
    }


}


void logUser::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *mainwindowobject = new MainWindow();
    mainwindowobject->show();
}


void logUser::on_pushButton_3_clicked()
{
    this->close();
}


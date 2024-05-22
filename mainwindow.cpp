#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loguser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //===================  DATABASE INTEGRAATION ============================================


    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase ("QSQLITE") ;
    mydb. setDatabaseName ("C:/Users/Raghav Singla/OneDrive/Desktop/SQLITE/sqlite-tools-win-x64-3450200/myrecipe.db") ;

    if(!mydb.open()){
        ui->label_3->setText("Failed to connect to Database");
    }
    else{

        ui->label_3->setText("Conneted...");
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString name , username , password;

    name = ui->lineEdit->text();
    username = ui->lineEdit_2->text();
    password = ui->lineEdit_3->text();

    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the databse";

        return;
    }




    QSqlQuery qry;
    QString queryStr = "INSERT INTO user (name ,username, password) VALUES ('" + name + "', '" + username + "', '" + password + "')";
    if (qry.exec(queryStr)){
        ui->label_3->setText("User added successfully");
        this->close();
        loginuser = new logUser(this);
        loginuser -> show();


    }
    else {
        qDebug() << "Error executing query: " << qry.lastError().text();
        ui->label_3->setText("Failed to add user");
    }
}

// ========================================Login Window Open From Here==============================================


void MainWindow::on_pushButton_2_clicked()
{
    // Close the current MainWindow
    this->close();

    // Open the login window
    logUser *loginWindow = new logUser();
    loginWindow->show();
}


// =================================== Close Button =============================================================


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}


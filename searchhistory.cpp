    #include "searchhistory.h"
#include "ui_searchhistory.h"
#include "recipewindow.h"

// searchhistory.cpp
searchHistory::searchHistory(QWidget *parent, const QStringList& searchHistoryData, const QString& username) :
    QDialog(parent),
    ui(new Ui::searchHistory),
    username(username)
{
    ui->setupUi(this);

    // Set the username
    ui->label->setText("<html><head/><body><p><span style=\" font-size:20pt; font-weight:600; color:#111;\">Username: </span><span style=\" font-size:18pt; color:#111;\">" + username + "</span></p></body></html>");



    // Display search history data in the textEdit
    QString formattedText = "<html><head/><body style=\" font-size:14pt;\">";
    formattedText += searchHistoryData.join("<br/>"); // Use <br/> to create line breaks
    formattedText += "</body></html>";
    ui->textEdit->setText(formattedText);

}

searchHistory::~searchHistory()
{
    delete ui;
}


void searchHistory::on_pushButton_clicked()
{
    this->close();
    recipewindow * recipewindowobject = new recipewindow(nullptr, username);
    recipewindowobject->show();
}


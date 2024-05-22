#include "detailrecipe.h"
#include "ui_detailrecipe.h"
#include "recipewindow.h"

detailrecipe::detailrecipe(const QString& recipeName,  QWidget *parent)
    : QDialog(parent),
    ui(new Ui::detailrecipe)
{
    ui->setupUi(this);
    // setSteps(steps);
    setWindowTitle(recipeName);
}

detailrecipe::~detailrecipe()
{
    delete ui;
}

void detailrecipe::setRecipeName(const QString& recipeName) {
    QFont font("Arial", 22, QFont::Bold);
    ui->label->setFont(font);
    ui->label->setText("<html><head/><body><p><span style=\"text-decoration: underline; font-style: italic;\">" + recipeName + "</span></p></body></html>");

}
void detailrecipe::on_pushButton_clicked()
{
    this->close();
    recipewindow *recipewindowobject = new recipewindow();
    recipewindowobject->show();
}

// void detailrecipe::setSteps(const QString& steps) {
//     // qDebug() << "Setting steps to:" << steps;
//     // QFont font("Arial", 18);
//     // ui->textEdit->setFont(font);
//     qDebug()<<"Steps: "<<steps;

//     // QStringList stepsList = steps.split(", ");
//     // QString formattedSteps;


//     // for (int i = 0; i < stepsList.size(); ++i) {
//     //     formattedSteps += QString::number(i + 1) + ". " + stepsList[i] + "\n";
//     // }

//     // ui->textEdit->setText(formattedSteps);


//     // ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//     // ui->textEdit->setReadOnly(true);
// }

void detailrecipe::setInstructions(const QJsonArray& instructionsArray) {
    QString formattedInstructions;

    // Loop through the instructions array and format them
    for (int i = 0; i < instructionsArray.size(); ++i) {
        QString instruction = instructionsArray[i].toString();
        formattedInstructions += QString::number(i + 1) + ". " + instruction + "\n";
    }
        QFont font("Arial", 18);
        ui->textEdit->setFont(font);

    ui->textEdit->setText(formattedInstructions);

  ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
ui->textEdit->setReadOnly(true);
}





void detailrecipe::on_pushButton_2_clicked()
{
    this->close();
}

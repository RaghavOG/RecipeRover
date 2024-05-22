#include "aftersearch.h"
#include "ui_aftersearch.h"
#include "recipewindow.h"
#include "loguser.h"
#include"detailrecipe.h"




aftersearch::aftersearch(const QString& recipeName, const QJsonArray& instructionsArray, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aftersearch)
{
    ui->setupUi(this);
    this->recipeName = recipeName;
    // this->instructions = instructions;
    this->instructionsArray = instructionsArray;
}

aftersearch::~aftersearch()
{
    delete ui;
}

void aftersearch::setRecipeName(const QString& recipeName) {
    // qDebug() << "Setting recipe name to:" << recipeName;
    QFont font("Arial", 22, QFont::Bold); // Example font settings
    ui->label->setFont(font);
    ui->label->setText("<html><head/><body><p><span style=\"text-decoration: underline; font-style: italic;\">" + recipeName + "</span></p></body></html>");
}


void aftersearch::setIngredients(const QString& ingredients) {
    QStringList ingredientsList = ingredients.split(", ");
    QString formattedIngredients;

// Loop through the ingredients list and format them with serial numbering
    for (int i = 0; i < ingredientsList.size(); ++i) {
        formattedIngredients += QString::number(i + 1) + ". " + ingredientsList[i] + "\n";
    }

    ui->textEdit->setFontPointSize(18); // Set font size
    ui->textEdit->setText(formattedIngredients);

    // Enable vertical scroll bar if the text exceeds the visible area
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

// ========================================================================

// ===============================  back to recipe window===============================
void aftersearch::on_pushButton_clicked()
{
    this->close();
    recipewindow * recipewindowobject = new recipewindow();
    recipewindowobject->show();
}
// ===============================  back to Login window===============================

void aftersearch::on_pushButton_2_clicked()
{
    this->close();
    logUser *loginWindow = new logUser();
    loginWindow->show();
}

// ==================== close button ========================
void aftersearch::on_pushButton_3_clicked()
{
    this->close();
}

// void aftersearch::setInstructions(){

// }

// ======================= Detail Recipe Window =============
void aftersearch::on_pushButton_4_clicked()
{
    this->close();


    // detailrecipe *detailRecipeWindow = new detailrecipe(recipeName, steps);
    // detailRecipeWindow->setRecipeName(recipeName);
    // detailRecipeWindow->setSteps(steps);
    // detailRecipeWindow->show();
    // qDebug()<<steps;
    // QString instructions = ui->instructionsTextEdit->toPlainText();

    detailrecipe *detailRecipeWindow = new detailrecipe(recipeName);
    detailRecipeWindow->setRecipeName(recipeName);

    detailRecipeWindow->setInstructions(instructionsArray); // Pass the instructions array directly
    detailRecipeWindow->show();

}


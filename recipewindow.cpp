#include "recipewindow.h"
#include "ui_recipewindow.h"
#include "loguser.h"
#include "searchhistory.h"
#include "aftersearch.h"




#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QPixmap>
#include <QUrlQuery>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QByteArray>
#include <QProcess>


//        AIzaSyAbPB2HbI6rnMGUgMaY1kwLqa3IALP1kqI


recipewindow::recipewindow(QWidget *parent, const QString& username)
    : QDialog(parent)
    , ui(new Ui::recipewindow)
    ,  m_username(username)

{
    ui->setupUi(this);
    ui->label_4->setText("");
    connect(ui->pushButton_6, &QPushButton::clicked, this, &recipewindow::on_pushButton_6_clicked);
    //===================  DATABASE INTEGRAATION ============================================

    mydb=QSqlDatabase::addDatabase ("QSQLITE") ;
    mydb. setDatabaseName ("C:/Users/Raghav Singla/OneDrive/Desktop/SQLITE/sqlite-tools-win-x64-3450200/myrecipe.db") ;

    if(!mydb.open()){

         qDebug() << "Failed to connect to Database";
    }
    else{

        // ui->label_3->setText("Conneted...");
        qDebug() << "Conneted...(**RECIPE WINDOW**)";
    }
}


recipewindow::~recipewindow()
{
    delete ui;
}
// ===========================Close Button ====================================================
void recipewindow::on_pushButton_clicked()
{
    this->close();
}
// ================================Login Button===============================================

void recipewindow::on_pushButton_2_clicked()
{
    this->close();
    logUser *loginWindow = new logUser();
    loginWindow->show();
}

// ==========================================Search History Kholne wala thing======================

void recipewindow::setSearchHistory(const QStringList& searchHistory) {
    m_searchHistory = searchHistory;
}
// =============================================================

void recipewindow::on_pushButton_4_clicked()
{
    QString queryStr = "SELECT recipe_name FROM search_history "
                       "WHERE user_id = (SELECT id FROM user WHERE username = :username)";

    QSqlQuery qry;
    qry.prepare(queryStr);
    qry.bindValue(":username", m_username); // Bind the username

    if (qry.exec()) {
        // qDebug() << "Search history for user" << m_username << ":";

        QStringList searchHistoryData;
        while (qry.next()) {
            QString recipeName = qry.value(0).toString();
            searchHistoryData.append(recipeName);
        }

        // Open the searchHistory window and pass the search history data and username
        this->close();
        searchHistory *searchHistoryWindow = new searchHistory(this, searchHistoryData, m_username);
        searchHistoryWindow->show();
    } else {
        qDebug() << "Error executing query: " << qry.lastError().text();
    }
}
// /////////////////////////////////-------DROPDOWN------/////////////////////////////////////////////////
void recipewindow::on_comboBox_activated(int index)
{
    QString selectedText = ui->comboBox->itemText(index);
    qDebug() << "Selected item in dropdown: " << selectedText;
}

//const QString apiKey = "9hAGo2r3CcE+TfNwRj/y4Q==J3alfMXXRNTRANin";


// QString searchTerm = ui->lineEdit->text().trimmed().toLower();
// ------------------------------=============GPT API CODE HERE ========================-------------------------
// void recipewindow::on_pushButton_6_clicked() {
//     QString searchTerm = ui->lineEdit->text().trimmed().toLower();
//     if (searchTerm.isEmpty()) {
//         QMessageBox::warning(this, "Error", "Please enter a search term.");
//         return;
//     }
// // https://api.spoonacular.com/recipes/findByIngredients?apiKey=3d9fba0e32634b1f9619861c73d7cba3&ingredients=pasta

//     QUrl apiEndpoint("https://api.spoonacular.com/recipes/findByIngredients?");
//     QUrlQuery query;
//     query.addQueryItem("apiKey", "3d9fba0e32634b1f9619861c73d7cba3"); // Replace with your actual API key
//     query.addQueryItem("query", searchTerm);
//     apiEndpoint.setQuery(query);

//     QNetworkRequest request(apiEndpoint);
//     networkManager->get(request);
// }
// Connect the signal from networkManager to your slot
// =====================================================================================TRYYYYYYYYY=======================================




void recipewindow::on_pushButton_6_clicked() {
    if(ui->radioButton->isChecked()){
        qDebug()<<"breakfast";
    }
    if(ui->radioButton_2->isChecked()){
        qDebug()<<"Intermediate";
    }

    if(ui->radioButton_3->isChecked()){
        qDebug()<<"Advance";
    }

    if(ui->radioButton_6->isChecked()){
        qDebug()<<"Vegetarian";
    }

    if(ui->radioButton_4->isChecked()){
        qDebug()<<"Eggetarian";
    }

    if(ui->radioButton_6->isChecked()){
        qDebug()<<"Non - Vegetarian";
    }
    if(ui->checkBox->isChecked()){
        qDebug()<<"Gluten Free";
    }

    if(ui->checkBox_2->isChecked()){
        qDebug()<<"Dairy Free";
    }

    if(ui->checkBox_3->isChecked()){
        qDebug()<<"Nut Free";
    }


}
// ==============================================================================================
void recipewindow::on_pushButton_7_clicked() {
    QString searchTerm = ui->lineEdit->text().trimmed().toLower();
    if (!searchTerm.isEmpty()) {
        QString pythonScriptPath = "C:/Users/Raghav Singla/OneDrive/Desktop/QT_PYTHON_CODE/apiCall.py";

        QProcess process;
        QStringList arguments;
        arguments << pythonScriptPath << searchTerm;
        process.start("python", arguments);
        process.waitForFinished(-1);

        QString output = process.readAllStandardOutput();
        QString error = process.readAllStandardError();

        if (error.isEmpty()) {
            // Parse the output string to separate title, ingredients, and instructions
            QStringList recipeParts = output.split("\r\n");

            if (recipeParts.size() >= 4) {
                QString title = recipeParts[0].mid(7); // Remove "Title: " from the beginning
                QString ingredients = recipeParts[1].mid(12);
                QString servings = recipeParts[2].mid(10);                  // Remove "Ingredients: " from the beginning
                QString instructions = recipeParts[3].mid(14); // Remove "Instructions: " from the beginning

                // Now you have title, ingredients, and instructions separately
                // qDebug() << "Title:" << title;
                // qDebug() << "Ingredients:" << ingredients;
                // qDebug() << "Instructions:" << instructions;


                // =============

                QStringList instructionList = instructions.split(". ");
                QJsonArray instructionArray;
                for (const QString& instruction : instructionList) {
                    // Create a QJsonValue for the instruction and add it to the array
                    instructionArray.append(QJsonValue(instruction));
                }

                aftersearch *afterSearchWindow = new aftersearch(title, instructionArray);

                afterSearchWindow->setWindowTitle("Recipe Details");
                // Set the recipe name dynamically
                afterSearchWindow->setRecipeName(title); //yaha after me name set hora hai


                QStringList ingredientsList = ingredients.split("|");
                QString ingredientsString = ingredientsList.join(", ");
                afterSearchWindow->setIngredients(ingredientsString);
                afterSearchWindow->show();









                this->close();




            } else {
                qDebug() << "Error: Invalid recipe format";
            }
        } else {
            qDebug() << "Error:" << error;
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a search term.");
    }
}




// ==== ===============================After Search Wala thinggggggggggggggg============================================
void recipewindow::on_pushButton_5_clicked()
{
    QFile file("C:/Users/Raghav Singla/OneDrive/Desktop/QT_Try/Qt_app/recipe.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open JSON file";
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON data:" << jsonError.errorString();
        return;
    }

    if (jsonDoc.isObject()) {
        QJsonObject recipesObj = jsonDoc.object();
        QString searchTerm = ui->lineEdit->text().trimmed().toLower(); // Get the search term

        if (recipesObj.contains("recipes") && recipesObj["recipes"].isArray()) {
            QJsonArray recipesArray = recipesObj["recipes"].toArray();
            QJsonObject selectedRecipe;
            bool recipeFound = false;
            for (const auto& recipeValue : recipesArray) {
                QJsonObject recipeObj = recipeValue.toObject();
                QString recipeName = recipeObj["name"].toString().toLower();
                // qDebug() << "Recipe Name from JSON:" << recipeName;
                qDebug() << "Search Term:" << searchTerm;        // Convert recipe name to lowercase
                if (recipeName.contains(searchTerm)) {
                    selectedRecipe = recipeObj;
                    recipeFound = true;
                    break;
                }
            }

            if (recipeFound) {
                aftersearch *afterSearchWindow = new aftersearch(selectedRecipe["name"].toString(), selectedRecipe["instructions"].toArray());

                afterSearchWindow->setWindowTitle("Recipe Details");
                // Set the recipe name dynamically
                afterSearchWindow->setRecipeName(selectedRecipe["name"].toString()); //yaha after me name set hora hai

                QJsonArray ingredientsArray = selectedRecipe["ingredients"].toArray();
                QStringList ingredientsList;
                for (const auto& ingredientValue : ingredientsArray) {
                    ingredientsList.append(ingredientValue.toString());
                }
                QString ingredientsString = ingredientsList.join(", ");
                afterSearchWindow->setIngredients(ingredientsString);

                // QJsonArray instructionsArray = selectedRecipe["instructions"].toArray();
                // QStringList instructionsList;
                // for (const auto& instructionValue : instructionsArray) {
                //     instructionsList.append(instructionValue.toString());
                // }
                // QString instructionsString = instructionsList.join(", ");
                // afterSearchWindow->setInstructions(instructionsString);




                afterSearchWindow->show();









                this->close();
            } else {
                qDebug() << "Recipe not found";
            }
        } else {
            qDebug() << "No 'recipes' array found in JSON data";
        }
    } else {
        qDebug() << "JSON data is not in object format";
    }
}

// ===========================================push button 3 nhi hai hmare passs====================================
void recipewindow::on_pushButton_3_clicked()
{
    this->hide();
    searchHistory *searchhistoryobject = new searchHistory();
    searchhistoryobject->show();
}


// ===============================================================================
// void recipewindow::on_label_4_linkActivated(){
//     this->close();
//     aftersearch *afterSeachObject = new aftersearch();
//     afterSeachObject->show();
// }



// spoonacular
// api-ninja
// gemini
// bing ai
// dummyjson
//edamam
// rapid api
//









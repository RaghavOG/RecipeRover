#ifndef RECIPEWINDOW_H
#define RECIPEWINDOW_H

#include<QtNetwork/QNetworkReply>
#include <QtSql>
#include <QDialog>

namespace Ui {
class recipewindow;
}

class recipewindow : public QDialog
{
    Q_OBJECT

public:
    // Updated constructor to accept username parameter
    explicit recipewindow(QWidget *parent = nullptr, const QString& username = "");
    void setSearchHistory(const QStringList& searchHistory);
    ~recipewindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    // void on_label_4_linkActivated(const QString &link);

    void on_pushButton_4_clicked();

    // void on_searchButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_activated(int index);

    // void replyFinished(QNetworkReply *reply);
    // void makeRecipeRequest(const QString& requestUrl);
    // void handleRecipeResponse(QNetworkReply *reply);

    void on_searchFinished(QNetworkReply *reply);
    // void processJsonResponse(const QJsonObject &jsonObject);

    void on_pushButton_7_clicked();

private:
    Ui::recipewindow *ui;
    QSqlDatabase mydb;

    // Member variable to store the username
    QString m_username;
    QStringList m_searchHistory;
    // QNetworkAccessManager *networkManager;

};

#endif // RECIPEWINDOW_H

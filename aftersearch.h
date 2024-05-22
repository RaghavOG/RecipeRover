#ifndef AFTERSEARCH_H
#define AFTERSEARCH_H
#include <QJsonArray>
#include <QDialog>

namespace Ui {
class aftersearch;
}

class aftersearch : public QDialog
{
    Q_OBJECT

public:
    explicit aftersearch(const QString& recipeName = "", const QJsonArray& instructionsArray = QJsonArray(), QWidget *parent = nullptr);



    ~aftersearch();

    // Add member variables for recipe name and steps
    QString recipeName;
    // QString instructions;
    QJsonArray instructionsArray;

    void setRecipeName(const QString& recipeName); // Declaration for setting recipe name

    void setIngredients(const QString& ingredients); // Declaration for setting ingredients

    // void setInstructions(const QString& instructions);

    // void setSteps(const QString& steps);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::aftersearch *ui;

};

#endif // AFTERSEARCH_H

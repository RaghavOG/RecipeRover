    #ifndef DETAILRECIPE_H
    #define DETAILRECIPE_H

    #include <QDialog>

    namespace Ui {
    class detailrecipe;
    }

    class detailrecipe : public QDialog
    {
        Q_OBJECT

    public:
        explicit detailrecipe(const QString& recipeName,  QWidget *parent = nullptr);
        ~detailrecipe();

        // Declare the function to set the steps
        void setRecipeName(const QString& recipeName);
        // void setSteps(const QString& steps);
        void setInstructions(const QJsonArray& instructionsArray);


    private slots:
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();

    private:
        Ui::detailrecipe *ui;
    };

    #endif // DETAILRECIPE_H

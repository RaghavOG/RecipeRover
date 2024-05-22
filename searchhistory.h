#ifndef SEARCHHISTORY_H
#define SEARCHHISTORY_H

#include <QDialog>

namespace Ui {
class searchHistory;
}

class searchHistory : public QDialog
{
    Q_OBJECT

public:
    explicit searchHistory(QWidget *parent = nullptr,  const QStringList& searchHistoryData = QStringList(), const QString& username = "");
    ~searchHistory();

private slots:
    void on_pushButton_clicked();

private:
    Ui::searchHistory *ui;
    QString username;
};

#endif // SEARCHHISTORY_H

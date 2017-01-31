#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QListWidget>
#include <QListWidgetItem>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QVBoxLayout * vbl_1, *vbl_2, *vbl_3, *vbl_4;
    QHBoxLayout * hbl_1, *hbl_2, *hbl_3, *hbl_4;
    QTableWidget *m_tableWidget;
    QListWidget *m_listWidget;
    QLabel *label_1, *label_2;
    QPushButton *button_1, *button_2;
    QWidget *wgt;
    int column=3, row=5, k;
    int A[15];
    QStringList columnName, rowName;

public slots:
        void fillTable();
        void generateNumbers();
        void completeTable();
        void clearTable();
        void deleteNumber();
        void countNumbers();
};

#endif // WIDGET_H

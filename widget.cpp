#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    vbl_1 = new QVBoxLayout();
    vbl_2 = new QVBoxLayout();
    vbl_3 = new QVBoxLayout();
    vbl_4 = new QVBoxLayout();
    hbl_1 = new QHBoxLayout();
    hbl_2 = new QHBoxLayout();
    hbl_3 = new QHBoxLayout();
    hbl_4 = new QHBoxLayout();

    label_1 = new QLabel("");
    m_tableWidget = new QTableWidget();
        m_tableWidget->setColumnCount(column);
        m_tableWidget->setRowCount(row);
        m_tableWidget->setHorizontalHeaderLabels(columnName<<"Mark_1"<<"Mark_2"<<"Mark_3");
        m_tableWidget->setVerticalHeaderLabels(rowName<<"Item_1"<<"Item_2"<<"Item_3"<<"Item_4"<<"Item_5");
    button_1 = new QPushButton("Complete the table");
    button_2 = new QPushButton("Clear the table");

    vbl_1->addWidget(label_1);
    vbl_1->addWidget(m_tableWidget);
    hbl_1->addWidget(button_1);
    hbl_1->addWidget(button_2);
    vbl_1->addLayout(hbl_1);
    this->setLayout(vbl_1);

    connect(button_1, SIGNAL(clicked()), this, SLOT(completeTable()));
    connect(button_2, SIGNAL(clicked()), this, SLOT(clearTable()));
}

Widget::~Widget()
{

}
void Widget::completeTable()
{
    wgt = new  QWidget();
    QVBoxLayout *vbl1 = new QVBoxLayout();
    QHBoxLayout *hbl1 = new QHBoxLayout();
    QHBoxLayout *hbl2 = new QHBoxLayout();
    m_listWidget = new QListWidget();
    QPushButton *button = new QPushButton("Count numbers");
    QPushButton *button1 = new QPushButton("Generate numbers");
    QPushButton *button2 = new QPushButton("Delete number");
    QPushButton *button3 = new QPushButton("Fill table");
    QLabel *label = new QLabel("Generation numbers");
    hbl1->addWidget(label);
    hbl1->addWidget(button);
    vbl1->addLayout(hbl1);
    vbl1->addWidget(m_listWidget);
    hbl2->addWidget(button1);
    hbl2->addWidget(button2);
    hbl2->addWidget(button3);
    vbl1->addLayout(hbl2);
    wgt->setLayout(vbl1);
    wgt->show();

    connect(button, SIGNAL(clicked()), this, SLOT(countNumbers()));
    connect(button1, SIGNAL(clicked()), this, SLOT(generateNumbers()));
    connect(button2, SIGNAL(clicked()), this, SLOT(deleteNumber()));
    connect(button3, SIGNAL(clicked()), this, SLOT(fillTable()));
}

void Widget::clearTable()
{
        m_tableWidget->clear();
}

void Widget::generateNumbers()
{
    k = 0;

    for (int i=0; i<15; i++){
            A[i] = rand()%100+10;
            QListWidgetItem *lwi = new QListWidgetItem();
            lwi->setText(QString("%1").arg(A[i]));
            m_listWidget->insertItem(k, lwi);
            k++;
     }
}

void Widget::deleteNumber()
{
    m_listWidget->clear();
    k = 0;
}

void Widget::countNumbers()
{
       int q1 = m_listWidget->count();
       QMessageBox::information(this, "", QString("Count = %1").arg(q1));
}

void Widget::fillTable()
{
    int w1 = m_listWidget->count();
    int s = w1;
        for (int i=0; i<row; i++){
            for (int j=0; j<column; j++){
                QTableWidgetItem *twi = new QTableWidgetItem();
                twi->setText(QString("%1").arg(A[w1-s]));
                m_tableWidget->setItem(i, j, twi);
                if (A[w1-s] <= 30) m_tableWidget->item(i,j)->setBackground(QBrush(Qt::red));
                if ((A[w1-s] > 30)&&(A[w1-s] <= 60)) m_tableWidget->item(i,j)->setBackground(QBrush(Qt::green));
                if(A[w1-s] > 60) m_tableWidget->item(i,j)->setBackground(QBrush(Qt::blue));
                s--;
            }
        }
}

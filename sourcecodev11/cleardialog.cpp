#include "cleardialog.h"
#include "ui_cleardialog.h"
#include<fstream>
using namespace std;

ClearDialog::ClearDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClearDialog)
{
    ui->setupUi(this);

    QString q_title;
    string f_title="Clear";

    q_title = QString::fromStdString(f_title);

    QWidget::setWindowTitle (q_title);

}

ClearDialog::~ClearDialog()
{
    delete ui;
}

void ClearDialog::on_pushButton_2_clicked() //no button
{
    this->close();
}

void ClearDialog::on_pushButton_clicked() //yes button
{
    remove("StockDictionary.sdf");
    remove("StockLog.slf");
    remove("StockDictionaryO.sdf");

    ofstream newdic("StockDictionary.sdf");
    ofstream newstk("StockLog.slf");

    newdic<<"Stock Name,SYM1,STOCKEX,"<<endl;

    newdic.close();
    newstk.close();

    ofstream pexit("pyexit.tmp");
    pexit.close();

    QApplication::quit();

}

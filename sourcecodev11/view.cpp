#pragma once
#include "view.h"
#include "ui_view.h"

#include <fstream>
#include<iostream>

#include<string>


#include<qDebug>

using namespace std;

View::View(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);

    QString q_title;
    string f_title="StockLog View";

    q_title = QString::fromStdString(f_title);

    QWidget::setWindowTitle (q_title);

    QString q_lines;
    string f_lines;

    ui->textBrowser->clear();

    ifstream datain("StockLog2.slf");

    while(getline(datain, f_lines)) {

     q_lines = QString::fromStdString(f_lines);

     ui->textBrowser->append(q_lines);


    }
}

View::~View()
{
    delete ui;
}

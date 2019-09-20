#pragma once
#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include<iostream>

#include<Windows.h>

#include<string>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QFileDialog>
#include<qDebug>
#include<QAction>
#include<QObject>

#include<QHBoxLayout>

#include"displaygraph.h"

//remove this
//#include <shlobj.h>
//#include <shlwapi.h>
//#include <objbase.h>

//QPushButton* btn_edit; //remove this
//#include"findstocksymbol.h"
using namespace std;


extern bool findStockName(const string &StockSymbol, string &stockname, string &stockexchange, const int GoToBank);
//void graphwindow(const string symbolpass);
extern string stockpass;
bool findStockNameOther(const string sp);


string sympass;
string a;
QString filepath;

extern vector<string>symlist;

//SHELLEXECUTEINFO shellExInfo;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QString q_title;
    string f_title="Summary View";
    string stockex;
   // string sympass;

    q_title = QString::fromStdString(f_title);
    string stockname;
    bool findstate=false;
    bool totalflag=false;
    QWidget::setWindowTitle (q_title);



    //remove this



    /*
    shellExInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    shellExInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    shellExInfo.hwnd = NULL;
    shellExInfo.lpVerb = L"open";
    shellExInfo.lpFile = L"StockFetcher2.exe";
    shellExInfo.lpParameters = NULL;
    shellExInfo.lpDirectory = NULL;
    shellExInfo.nShow = SW_HIDE;
    shellExInfo.hInstApp = NULL;

    ShellExecuteEx(&shellExInfo);

    GetProcessId(shellExInfo.hProcess);

    TerminateProcess(shellExInfo.hProcess, 1);

    //
    */



    ifstream summarylog("summarylog.sld");
    string items;
    string owner;
    string dash="---------";
    QString qdash = QString::fromStdString(dash);
    QString qstr;

    int cntr=0;

    while(getline(summarylog, items, ',')) {
             // getline(summarylog, items, ',');
        totalflag=false;
        items.erase(std::remove(items.begin(), items.end(), '\n'), items.end());
        if(items=="NAME") {
           // items.erase(std::remove(items.begin(), items.end(), '\n'), items.end());
            getline(summarylog,owner, ',');
            qstr = QString::fromStdString(owner);
            ui->tableWidget->insertRow(cntr);
            ui->tableWidget->setItem(cntr,0, new QTableWidgetItem(qstr));

            for(int i=1; i<8; i++) {
                ui->tableWidget->setItem(cntr,i, new QTableWidgetItem(qdash));
            }

        }


        else if(items=="TOTAL") {

           // items.erase(std::remove(items.begin(), items.end(), '\n'), items.end());
            getline(summarylog, items, ',');
            ui->tableWidget->insertRow(cntr);
            qstr = QString::fromStdString(items);
            ui->tableWidget->setItem(cntr,0, new QTableWidgetItem(qstr));
            totalflag=true;

        }

        else  {


            ui->tableWidget->insertRow(cntr);
           // items.erase(std::remove(items.begin(), items.end(), '\n'), items.end());
            qstr = QString::fromStdString(items);

            if(!(findStockName(items, stockname, stockex, 0))) {
                ui->tableWidget->setItem(cntr,1, new QTableWidgetItem(qstr));


                cout<<"item being passed to findstate is: "<<items<<endl;

                findstate=findStockNameOther(items); //this was set to false before

                cout<<"findstate is: "<<findstate<<endl;

                if(findstate)sympass=items;



            } else {
                findstate=true;
                if(!items.empty())sympass=items;
            }

            for(int i=2; i<8; i++) {

                if(i==2 && (!(totalflag)) && (findstate) && (!(items.empty()))) {

                   // if(findstate) {


                        QWidget* pWidget = new QWidget();
                        QPushButton* btn_edit = new QPushButton();
                        btn_edit->setText(qstr);
                        QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                        pLayout->addWidget(btn_edit);
                       // pLayout->setAlignment(Qt::AlignCenter);
                        pLayout->setContentsMargins(0, 0, 0, 0);
                        pWidget->setLayout(pLayout);
                        pWidget->setLayout(pLayout);
                        ui->tableWidget->setCellWidget(cntr, 1, pWidget);


                       // connect(
                         //   sender, &Sender::valueChanged,
                         //   someFunction
                       // );


                      // connect(btn_edit, &QObject::SIGNAL(clicked()), graphwindow(sympass) );
                       connect(btn_edit, SIGNAL(clicked()), this, SLOT(setValue()));





                        //connect(btn_edit, &QAction::triggered, this, SLOT(setValue(int)));

                    //MainWindow::on_pushButton_7_clicked()

                   // }

//SLOT(finishedSlot(QNetworkReply *)

                }

              //  else {
                    getline(summarylog, items, ',');
                    qstr = QString::fromStdString(items);

                    ui->tableWidget->setItem(cntr,i, new QTableWidgetItem(qstr));
              //  }

            }
        }

        cntr++;

    }
}










   // QProcess *proc = new QProcess(this);
    //QProcess::startDetached("Summary.txt");



   // QFile file(path);


   // QTextStream in(&file);
   // ui->textBrowser->setText(in.readAll());












Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked() //choose location
{



    QString qpath2 = QFileDialog::getExistingDirectory();
   // a = qpath2.toStdString().c_str();
   // ui->lineEdit->setDisabled(true);
    ui->lineEdit->setText(qpath2);




}

void Dialog::on_pushButton_2_clicked()
{

    QString qpath3;

    qpath3 = ui->lineEdit->text();
    string lines;

    a=qpath3.toStdString().c_str();
    a=a+"/";

    ifstream summarytextin("Summary.sf");
   // ifstream summarytextinlog("StockLog2.slf");
    ofstream summarytextout(a+"/StockSummary.txt");
   // ofstream summarytextoutlog(a+"/StockLog.txt");

    ifstream summarylogin("summarylog.sld");
    ofstream summarylogout(a+"StockSummary.csv");


    while(getline(summarytextin,lines)) {
        summarytextout<<lines<<endl;

    }

    while(getline(summarylogin,lines)) {
        summarylogout<<lines<<endl;
    }



    summarytextout.close();
    summarytextin.close();
    summarylogout.close();
    summarylogin.close();


    ui->lineEdit->clear();

}



/*
QWidget* pWidget = new QWidget();
QPushButton* btn_edit = new QPushButton();
btn_edit->setText("Edit");
QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
pLayout->addWidget(btn_edit);
pLayout->setAlignment(Qt::AlignCenter);
pLayout->setContentsMargins(0, 0, 0, 0);
pWidget->setLayout(pLayout);
ui.table->setCellWidget(i, 3, pWidget);
*/


//void graphwindow(const string symbolpass) {

   // cout<<"we here now"<<endl;
//}


void Dialog::setValue(void) {

    cout<<"we here now"<<endl;
    cout<<"symbol is: "<<sympass<<endl;
    //QString gettext;
    string f_gettext;
    //gettext=btn_edit->text();
   // f_gettext=gettext.toStdString().c_str();
    //cout<<"get text value: "<<f_gettext<<endl;

    QPushButton* clickedButton = qobject_cast< QPushButton* >( sender() );
    if ( clickedButton )
    {
        const QString qgettext   = clickedButton->text();


        stockpass = qgettext.toStdString().c_str();
        cout<<"button pressed: "<<f_gettext<<endl;

/*
        Qt::WindowFlags flags = windowFlags();
        setWindowFlags(flags | Qt::WindowStaysOnTopHint);
        show();
*/


        displaygraph openstats;

        //openstats.setModal(true);

        openstats.QDialog::exec();



        //const QString clickedButtonName = clickedButton->objectName();
    }



}

bool findStockNameOther(const string sp) {

    cout<<"symlist size is: "<<symlist.size()<<endl;

    for(int i=0; i<symlist.size(); i++) {
        cout<<"symlist is: "<<symlist[i]<<endl;
        if(sp==symlist[i]) {

            return true;
        }
    }

    return false;

}

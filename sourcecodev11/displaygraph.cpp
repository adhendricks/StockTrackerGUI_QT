#pragma once
#include "displaygraph.h"
#include "ui_displaygraph.h"



#include<iostream>

#include<QObject>



#include<iostream>
#include<QtWebEngineCore>
#include<QWebEngineView>
#include <Windows.h>



#include<QObject>
#include<QEvent>

#include <QSizePolicy>

#include <QWebEngineSettings>

#include<QtCore>
#include<string>

using namespace std;




#include<QUrl>


//extern class StockBank;
//extern StockBank bank;

extern string stockpass;

using namespace std;

displaygraph::displaygraph(QWidget *parent) :

    QDialog(parent),
    m_view(new QWebEngineView(this)),
    ui(new Ui::displaygraph)
{

    ui->setupUi(this);


    //Qt::WindowFlags flags = windowFlags();
   // setWindowFlags(flags | Qt::Widget);
   // show();



    cout<<"WEB SYMBOL: "<<stockpass<<endl;
    //QString q_stockpass=QString::fromStdString(stockpass);

    QWebEnginePage *page = m_view->page();



    //CustomWebEngineView *m_view = new CustomWebEngineView(this);
    //QApplication::instance()->installEventFilter(this);


    //CustomWebEngineView *m_view = new CustomWebEngineView(this);
    //QCoreApplication::instance()->installEventFilter(this);

   // QCoreApplication::instance()->installEventFilter(this);

    ui->scrollArea->setWidget(m_view);

    cout<<"stock pass is: "<<stockpass<<endl;

    string furl = "https://ca.finance.yahoo.com/chart/" + stockpass;
    QString qurl = QString::fromStdString(furl);

     QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::ShowScrollBars, false);

     //page->load(QUrl(QStringLiteral("https://www.google.com/search?q=aapl&tbm=fin#scso=_INObXJHTAuvQjwSbmJWIBQ2:0,_M9ObXOTzIOrIjgS84pXADA2:0")));
     page->load(QUrl(qurl));






    //connect(filter, SIGNAL);

}

displaygraph::~displaygraph()
{
    delete ui;
}

#pragma once
#ifndef DISPLAYGRAPH_H
#define DISPLAYGRAPH_H





#include "displaygraph.h"


#include<iostream>

#include<QObject>




#include<iostream>
#include<QtWebEngineCore>
#include<QWebEngineView>
#include <Windows.h>




#include<QObject>


#include <QSizePolicy>

#include <QWebEngineSettings>


#include<string>
#include "ui_displaygraph.h"



#include <QDialog>

namespace Ui {
class displaygraph;
}

class displaygraph : public QDialog
{
    Q_OBJECT

public:
    explicit displaygraph(QWidget *parent = nullptr);
    ~displaygraph();

private:
    Ui::displaygraph *ui;
    QWebEngineView *m_view;

    QWebEnginePage *page = m_view->page();


};

#endif // DISPLAYGRAPH_H





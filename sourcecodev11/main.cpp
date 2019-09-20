#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <fstream>
#include<iostream>

extern void callPy(void);

extern int init_prog(void);
extern class Stock_Dictionary;
using namespace std;



int main(int argc, char *argv[])
{

  //  ofstream filefile("whereisthis.txt");
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/this.ico"));

    init_prog();
    MainWindow w;

    w.show();


    a.exec();

    ofstream pexit("pyexit.tmp");
    pexit.close();
    return 0;
}

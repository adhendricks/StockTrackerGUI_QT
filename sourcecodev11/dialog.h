#ifndef DIALOG_H
#define DIALOG_H
#include<string>
#include <QDialog>
using namespace std;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);


    ~Dialog();



public slots:

   // void graphwindow(const string symbolpass);

    void setValue(void);

    //void setWindowFlags(Qt::WindowFlags );



private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    //void graphwindow(const string symbolpass);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <algorithm>
#include "dialog.h"
#include "cleardialog.h"
#include "view.h"
#include "about.h"

#include<Windows.h>


#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>



#include<findstocksymbol.h>

#include"displaygraph.h"

//#include<winbase.h>



#define MAX 5

using namespace std;

int init_prog(void);
void callPy(void);
bool is_file_exist(const string filename);
extern bool findStockName(string &StockSymbol);
extern bool findStockNameOther(const string sp);



bool autoset=false;
bool stockerror=false;

string stockpass;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_7->setVisible(false);

    //setWindowIcon(QIcon(":/this.ico"));

    QString q_title;
    string f_title="StockTracker";

    q_title = QString::fromStdString(f_title);

    QWidget::setWindowTitle (q_title);

    ui->label_8->setVisible(false);
    ui->label_9->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);

    ui->lineEdit_4->clear();



}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////////Class declarations//////////////////////////////////////////////

class Stock; // Stores the information of stocks
class Owner; // Stores the information of the stock users such as names and stocks owned
class Stock_Dictionary; // Store the information of stock name and market
void Summary(vector<Owner>& s); // Function used to produce a summary page for stocks
void readPrice(string p[]);

// Stores the information of the stock users such as names and stocks owned
class Stock_Dictionary {
    friend class Owner;
    friend class Stock;
private:
    string Name; // Name of the Stock eg Apple
    string Symbol; // Symbol of the Stock eg AAPL
    string Stock_Exchange; // Stock exchange for stock eg. NASDAQ
public:
    Stock_Dictionary(string n = " ", string S = " ", string e=" "); //Constructor
    void SetStockName(string n); // Set Stock Name by string
    void SetStockSymbol(string s); // Set Stock Symbol by string
    void SetStockExchange(string e); //Set Stock Exchange by string
    void SetStockName(istream& in); // Set Stock Name by input
    void SetStockName(void);
    void SetStockSymbol(istream& in); // Set Stock Symbol by input
    void SetStockSymbol(void);
    void SetStockExchange(istream& in); //Set Stock Exchange by input
    void SetStockExchange(void);

    string GetStockExchange(void);
    string GetStockSymbol(void);

    void AddStock(string n , string S, string e ); //Add stock all at once
    bool SearchStockSymbol(string s); // Checks to see if the symbol is a match then returns a 1 if yes or 0 if no
    string GetStockName(void) const;
    void PrintData(ostream& out);
};

class Stock {
    friend class Owner;
private:
    string Name;
    string Symbol;
    bool Chose; // 0 - buy 1 - sell
    float InitialPrice;
    float CurrentPrice;
    int Shares;
    int TotalShares;
    float InitialValue;
    float TotalInitialValue;
    float CurrentValue;
    vector<Stock_Dictionary>*  Dictionary;
public:
    Stock(string n= " ", string i = " ", bool c=0,float p = 0.0, int a = 0);
    int SetStock(istream& in);
    int SetStock(string L);
    int SetStock(void);
    void SetName(istream& in);
    void SetName(void);
    int SetChose(istream& in);
    int SetChose(void);
    void SetSymbol(istream& in);
    void SetSymbol(void);
    void SetInitialPrice(istream& in);
    void SetInitialPrice(void);
    void SetShares(istream& in);
    void SetShares(void);
    void SetName(string s);
    void SetChose(bool s);
    void SetSymbol(string s);
    void SetInitialPrice(float s);
    void SetShares(int s);
    void setDictionary(vector<Stock_Dictionary> *g);
    void SetTotalShares(int shares);
    void SetTotalInitialValue(float Values);
    void CalculateInitValue(void);
    string getname(void) const;
    bool GetChose(void) const;
    string getsymbol(void) const;
    float getprice(void) const;
    int getshares(void) const;
    float GetInitialValue(void) const;
    int GetTotalShares(void) const;
    float GetTotalInitialValue(void)const;
    Stock& operator=(const Stock& rhs);

};


class Owner {
private:
    string Name;
    string Timestamp;
    vector<Stock> Stocks;
    vector<Stock_Dictionary>*  Dictionary;
public:
    Owner(string n =" ");
    void setDictionary(vector<Stock_Dictionary>& q);
    void addStock(istream & in);
    void addStock(void);
    void addStock(string L);
    void SetTimeStamp(istream& in);
    void SetTimeStamp(void);
    void SetTimeStamp(string s);
    string GetTimeStamp(void);
    void SetName(istream& in);
    void SetName(void);
    void SetName(string g);
    void printStock(ostream& out)const;
    void PrintStockSummary(void);
    string getname(void);
    vector<Stock> GetStock(void);
    void SetStock(vector<Stock> temp);
    void StockSummary(void);


};



class StockBank {
    private:
        bool BankFoundState;
        string BankSymbol;
    public:
        bool getBankFoundState(void);
        string getBankSymbol(void);
        void setBankFoundState(bool st);
        void setBankSymbol(string sy);

};

StockBank bank;


///////////////////////////////////////////////////////////////////////////

vector<Owner> OwnerV2;
vector<Owner> OwnerVT;

vector<Owner> Temp_Owner_V;

vector<string> symlist;

///////////////////////////////////global vars////////////////////////////
PROCESS_INFORMATION PROCESS_INFORMATION_GLOBAL;

vector<Owner> OwnerV;
Owner Temp_Owner;

Owner Temp_Owner_v2; //remove this

Owner Temp_Owner_v3; //remove this

Owner Temp_Owner_v4;


string Timestamp;

QString q_Owner_name;
string f_Owner_name;

QString q_Stock_Symbol;
string f_Stock_Symbol;

QString q_Stock_Name;
string f_Stock_Name;

QString q_Stock_Dictionary_Stock_Exchange;
string f_Stock_Dictionary_Stock_Exchange;

QString q_Stock_Shares;
string f_Stock_Shares;

QString q_Stock_InitialPrice;
string f_Stock_InitialPrice;

string f_autofill;

//QString q_Owner_name_check;
//string f_Owner_name_check;

//bool Owner_name_changestatus=0;

bool BuySell;

int stock_num=0;

vector<Stock_Dictionary>  TotalDictionary;

int loopcntr=0;


bool CheckFind=0; //written by line edit 2

int Owner_count = 0;
unsigned int countD=0;

bool FirstLineStatus=1;

bool memorycheck=1;

bool whilecheck=1;

bool quitcheck=0;


int OwnerStatus=0;
int FirstInstance=0;
int i_cnt=0;

int linecount=0;

//bool timestampcheck=0; //remove this

bool fileflag=0;

//bool readpriceflag=0;

bool symcheck=0;

SHELLEXECUTEINFO shellExInfo;
HANDLE h;

int sdcount=0;

string banksymbolpass;


///////////////////////////////////exec code//////////////////////////////
int init_prog(void) {

//Time Stamp Set Up;
    remove("statesym.tmp");
    remove("checksym.tmp");
    remove("pyexit.tmp");
    remove("pystate.tmp");
    remove("StockLog2.slf");
    callPy(); //init py at start



    ifstream sin("StockDictionaryO.sdf");
    string dicline;
    while(getline(sin,dicline)) {
        dicline.erase(std::remove(dicline.begin(), dicline.end(), '\n'), dicline.end());
        symlist.push_back(dicline);
    }

    sin.close();











   time_t T = time(NULL);
   struct tm tm;
   localtime_s(&tm, &T);
   Timestamp = to_string(tm.tm_year + 1900) + "/" + to_string(tm.tm_mon + 1) + "/" + to_string(tm.tm_mday);

   //Declare variables that are to be used in code

   vector<Stock_Dictionary> dictionary;
   Stock_Dictionary temp_Dictionary;

   if(is_file_exist("stock_current_price.tmp")){
       remove("stock_current_price.tmp");
   }


   bool run = 1;

  // unsigned int countD=0;
   char ch;
   string word,word1,word2, words;




   // Attach a pointer to the stock dictionary to every owner class
   Temp_Owner.setDictionary(dictionary);

   // Reads in the stock dictionary file to memory
   ifstream datain("StockDictionary.sdf", ios::in);
   if (datain) { // Check if the file exists
   while(getline(datain, words, ',')) {
       word=words;
       word.erase(std::remove(word.begin(), word.end(), '\n'), word.end()); //attention


       getline(datain, words, ',');
       word1=words;



       getline(datain, words, ',');
       word2=words;


       temp_Dictionary.AddStock(word, word1, word2);
       dictionary.push_back(temp_Dictionary);

       TotalDictionary.push_back(temp_Dictionary);
       countD++;
       }
   }




   datain.close();



   char ownercheck;
  // int ownercnt=0;
   ifstream datain2("StockLog.slf", ios::in);


    if(datain2) {


        while(whilecheck) {

                Owner NewTemp;

                NewTemp.SetName(datain2);

                OwnerVT.push_back(NewTemp);

                FirstLineStatus=1;

                Owner_count++;

            }
    }
   // cout<<"COUNTD: "<<countD<<endl;



  //  cout << std::left << std::setw(12)<<"Serge"<<std::left << std::setw(12)<<"test"<<endl;

   TotalDictionary.erase(TotalDictionary.begin()+ (countD-1)); //attention
   return 0;
}

///////////////////////Class definitions//////////////////////////////////////

Stock::Stock(string n, string i, bool c, float p, int a) {
    Name = n;
    Symbol = i;
    InitialPrice = p;
    Shares = a;
    Chose = c;
}



int Stock::SetStock(string L) {

    string buyorsell;
    string longline=L;

    buyorsell=L.substr(0,1); //gets 1st character
    if(buyorsell=="B") Chose=0;
    else if(buyorsell=="S") Chose=1;

    //cout<<"BUY OR SELL VALUE IS: "<<Chose<<endl;

    unsigned lastcommapos=L.find_last_of(',');

    unsigned firstcommapos=L.find_first_of(',');
     L = L.substr(firstcommapos+1,lastcommapos+1);
    //cout<<"LONG LINE IS:->"<<L<<"<-"<<endl;


    unsigned secondcommapos=L.find_first_of(',');
     L = L.substr(secondcommapos+1, lastcommapos+1);
    //cout<<"LONG LINE IS:->"<<L<<"<-"<<endl;

    unsigned thirdcommapos=L.find_first_of(',');
     L = L.substr(thirdcommapos+1, lastcommapos+1);
   // cout<<"LONG LINE IS:->"<<L<<"<-"<<endl;

    unsigned fourthcommapos=L.find_first_of(',');
     L=L.substr(fourthcommapos+1, lastcommapos+1);
    //cout<<"LONG LINE IS:->"<<L<<"<-"<<endl;

    unsigned lastcomma=lastcommapos+1;
    unsigned firstcomma=firstcommapos+1;
    unsigned secondcomma=firstcomma+secondcommapos+1;
    unsigned thirdcomma=thirdcommapos+secondcomma+1;
    unsigned fourthcomma=fourthcommapos+thirdcomma+1;


   // cout<<"second comma pos is: "<<secondcomma<<endl;
   // cout<<"third coma pos is: "<<thirdcomma<<endl;

    Symbol=longline.substr(firstcomma, secondcomma-firstcomma-1);
   // cout<<"symbol IS->"<<Symbol<<"<-"<<endl;

   // cout<<"long line is: "<<longline;
    Name=longline.substr(secondcomma, thirdcomma-secondcomma-1);
  //  cout<<"name IS->"<<Name<<"<-"<<endl;

    string s_Shares=longline.substr(thirdcomma, fourthcomma-thirdcomma-1);
    Shares=stoi(s_Shares);
   // cout<<"shares is: "<<Shares<<endl;

    string s_InitialPrice=longline.substr(fourthcomma, lastcomma-fourthcomma-1);
    InitialPrice=stof(s_InitialPrice);
    CalculateInitValue();

   // cout<<"initialprice is: "<<InitialPrice<<endl;
  //  cout<<"initiavaluue is: "<<InitialValue<<endl;






    //string s_InitialPrice=long






    // Name=longline.substr(secondcommapos+1, thirdcommapos);
   // cout<<"name IS->"<<Name<<"<-"<<endl;














    /*
    unsigned first = Name.find(' ');
    unsigned last = Name.find(',');

    Name=Name.substr(first+1, last-2); */


    /*
    string Name;
    string Symbol;
    bool Chose; // 0 - buy 1 - sell
    float InitialPrice;
    float CurrentPrice;
    int Shares;
    int TotalShares;
    float InitialValue;
    float TotalInitialValue;
    float CurrentValue;


        if (c == "BUY") Chose = 0;
        else if (c == "SELL") Chose = 1;


    */



    return 0;
}

int Stock::SetStock(istream& in) {

    int num=0;
    Stock_Dictionary s;
    bool match = 0;
    string temp;
    if (SetChose(in)) return 1;
    SetSymbol(in);
    if(&in == &cin){
        for (unsigned int i = 0; i < TotalDictionary.size(); i++) {
            if (TotalDictionary[i].SearchStockSymbol(Symbol)) {
                Name = TotalDictionary[i].GetStockName();
                num = i;
                match = 1;
                //in >> temp;
                break;
            }
        }
        if (!match) {
            SetName(in);
            s.SetStockExchange(in);
            s.Name = Name;
            s.Symbol = Symbol;
            TotalDictionary.push_back(s);
        }
    }
    else SetName(in);
    SetShares(in);
    SetInitialPrice(in);
    CalculateInitValue();
    return 0;
}

int Stock::SetStock(void) {



    loopcntr++;

    if(CheckFind) {
        Symbol=f_Stock_Symbol;
        for (unsigned int i = 0; i < TotalDictionary.size(); i++) {
            if (TotalDictionary[i].SearchStockSymbol(Symbol)) {
                Name = TotalDictionary[i].GetStockName(); //fix this
                f_autofill=Name; //fix this
                return 2;
            }
        }

    }
    else {

    int num=0;
    Stock_Dictionary s;
    bool match = 0;
    string temp;
    if (SetChose()) return 1;
    SetSymbol();

    for (unsigned int i = 0; i < TotalDictionary.size(); i++) {
        if (TotalDictionary[i].SearchStockSymbol(Symbol)) {

            Name = TotalDictionary[i].GetStockName();
            f_Stock_Name=Name;

            num = i;
            match = 1;
            break;

        }
    }

    if (!match) {
        SetName();
        s.SetStockExchange();
        s.Name = Name;
        s.Symbol = Symbol;
        TotalDictionary.push_back(s);
       // cout<<"pushed"<<endl;

    }

    SetName();
    SetShares();

    SetInitialPrice();
    CalculateInitValue();



    }
    return 0;
}


void Stock::SetName(istream& in) {
    if (&in == &cin) cout << "Enter the name of the Stock" << endl;
    cin.ignore(INT_MAX, '\n');
    getline(cin, Name);
}

void Stock::SetName(void) {
    Name=f_Stock_Name;
}
void Stock::SetSymbol(istream& in) {
    if (&in == &cin) cout << "What is the symbol for stock bought / sold?" << endl;
    in >> Symbol;
}

void Stock::SetSymbol(void) {

    Symbol=f_Stock_Symbol;

}



void Stock::SetInitialPrice(istream& in) {
    if (&in == &cin) cout << "What is the value it was purchased / sold for?" << endl;
    in >> InitialPrice;
}

void Stock::SetInitialPrice(void) {

    float n_initprice=stof(f_Stock_InitialPrice);
    InitialPrice=n_initprice;
  //  cout<<"init price entered: "<<InitialPrice;



    //may need attention
}

int Stock::SetChose(istream& in) {

    if (&in == &cin) {
      //  cout << "Choose 0 - buy 1 - sell" << endl;
        in >> Chose;
    }
    else {
        string c;
        in >> c;
        if (c == "BUY") Chose = 0;
        else if (c == "SELL") Chose = 1;
        else return 1;
    }
    return 0;
}

int Stock::SetChose(void) {


    Chose=BuySell;

    return 0;
}

void Stock::SetShares(istream& in) {
    if (&in == &cin) cout << "What is the number of shares bought / sold?" << endl;
    in >> Shares;
}

void Stock::SetShares(void) {
    int n_shares=stoi(f_Stock_Shares);
    Shares=n_shares;

}

void Stock::SetName(string s)
{
    Name = s;
}
void Stock::SetChose(bool s)
{
    Chose = s; // 0 - BUY 1 - SELL
}
void Stock::SetSymbol(string s)
{
    Symbol = s;
}
void Stock::SetInitialPrice(float s)
{
    InitialPrice = s;
}
void Stock::SetShares(int s)
{
    Shares = s;
}
void Stock::setDictionary(vector<Stock_Dictionary> *g)
{
    Dictionary = g;
}
void Stock::SetTotalShares(int shares)
{
    TotalShares = shares;
}
void Stock::SetTotalInitialValue(float Values)
{
    TotalInitialValue = Values;
}
void Stock::CalculateInitValue(void)
{
   // cout<<"INITIAL PRICE IS: "<<InitialPrice<<endl;
    InitialValue = InitialPrice * Shares;
}
string Stock::getname(void) const {
    return Name;
}
bool Stock::GetChose(void) const
{
    return Chose;
}
string Stock::getsymbol(void) const {
    return Symbol;
}


float Stock::getprice(void) const {
    return InitialPrice;
}
int Stock::getshares(void) const {
    return Shares;
}

float Stock::GetInitialValue(void) const
{
    return InitialValue;
}

int Stock::GetTotalShares(void) const
{
    return TotalShares;
}

float Stock::GetTotalInitialValue(void) const
{
    return TotalInitialValue;
}

Stock& Stock::operator=(const Stock& rhs) {
    if (this != &rhs) {
        Name = rhs.Name;
        Symbol = rhs.Symbol;
        InitialPrice = rhs.InitialPrice;
        Shares = rhs.Shares;
        Chose = rhs.Chose;
    }
    return *this;
}


Owner::Owner(string n)
{
    Name = n;
}

void Owner::setDictionary(vector<Stock_Dictionary> &q)
{

    Dictionary = &q;
}

void Owner::addStock(istream& in) {
    Stock a;
    bool Continue=1;
    Stocks.clear();
    while (Continue) {

        a.SetStock(in);
        Stocks.push_back(a);



    }
}


void Owner::addStock(void) {
    Stock a;
    SetName();
    Stocks.clear();
  //  a.setDictionary(Dictionary);
    a.SetStock();
    Stocks.push_back(a);

}

void Owner::addStock(string L) {
    Stock a;
    a.SetStock(L); //sets all the stock members
    Stocks.push_back(a); //stores in stock vector
   // Stocks.pop_back(); //remove this

}



void Owner::SetTimeStamp(istream & in)
{
    in >> Timestamp;
   // cout<<"time stamp is:"<<Timestamp;
}

void Owner::SetTimeStamp(string s)
{
    Timestamp = s;

}


string Owner::GetTimeStamp(void) {
    return Timestamp;

}


void Owner::SetName(istream& in) {

   string Line2;
   char NextChar;

    if(FirstLineStatus) {

        string Line2;
        getline(in, Name, ',');

        unsigned first = Name.find(' ');
        unsigned last = Name.find(',');

        Name=Name.substr(first+1, last-2);

       // cout<<"NAME IS:"<<Name<<endl;

        getline(in, Line2);

        Timestamp=Line2;

        FirstLineStatus=0;
    }

    while(!FirstLineStatus) {

        if(getline(in, Line2)) {

            //if(Owner_count==1) cout<<"LINE2 IS: "<<Line2<<endl; //remove this

            addStock(Line2); //submit stock vector element for each line of Owner object

            in>>NextChar;
            if(NextChar=='*') {
                FirstLineStatus=1;
            }

          } else {
            whilecheck=0;
            break;
        }

       }
}

void Owner::SetName(string g)
{
    Name = g;

}


void Owner::SetName(void) {
    Name=f_Owner_name;

}


void Owner::printStock(ostream & out) const
{

    string buy[] = { "BUY","SELL" };

    if(FirstInstance||(i_cnt==1)) {


        out <<endl<< "* " << Name << "," << Timestamp<< ",";

   }

    //cout<<"STOCK NAME IS"

    for (unsigned int i = 0; i < Stocks.size(); i++) {
        out <<endl<<buy[Stocks[i].Chose]<< ","<<Stocks[i].Symbol << "," << Stocks[i].Name << "," << Stocks[i].Shares << "," << Stocks[i].InitialPrice<<",";
       // string temps;
       // temps = Stocks[i].getname();

        //****cout<<endl<<"temps is---->"<<Stocks[i].getname()<<"<-----"<<endl;*** //attention


      //  temps.erase(std::remove(temps.begin(), temps.end(), '\n'), temps.end()); //attention

       // cout<<endl<<"temps is---->"<<temps<<"<-----"<<endl;

      //  Stocks[i].getsymbol().erase(std::remove(Stocks[i].getsymbol().begin(), Stocks[i].getsymbol().end(), '\n'), Stocks[i].getsymbol().end());

      //  out<< "symbol is--->"<<Stocks[i].getsymbol()<<"<----"<<endl;
       // out<<"stock name is --->"<<Stocks[i].getname()<<"<----"<<endl;

    }
}

void Owner::PrintStockSummary(void)
{
    float Total=0;
    string buy[] = { "BUY","SELL" };
    string sign[] = { " $","  -$" };

    ofstream summarydata("Summary.sf", ios::app);
    ofstream logdata("summarylog.sld", ios::app);

    string*price;
    price = new string [TotalDictionary.size()];
    if(!fileflag) { //need attention

     // cout<<"file created"<<endl; //remove this
     // cout<<"checkpoint 1"<<endl;

      readPrice(price);

     // TotalDictionary.erase(TotalDictionary.begin()+2); //attention

       // cout<<"price read"<<endl;

     // cout<<"DIC ELEMENTS ARE:"<<endl;
     // for(int i=0; i<TotalDictionary.size(); i++) {
         // cout<<TotalDictionary[i].GetStockSymbol()<<"<--"<<i<<endl;
    //  }




    //  cout<<"PRICE READ"<<endl;
   /*   for(int i=0; i<Stocks.size(); i++) {
          for(int j=0; j<TotalDictionary.size(); j++) {

            // cout<<"STOCK SYMBOL IS--->"<<Stocks[i].getsymbol()<<endl;
             // cout<<"PRICE and SYMBOL is---> "<<price[j]<<" "<<TotalDictionary[j].GetStockSymbol()<<endl;
              if(Stocks[i].getsymbol()==TotalDictionary[j].GetStockSymbol()) {
                  cout<<Stocks[i].getsymbol()<<" "<<price[j]<<endl;
              }
          }

      } */

    }

   // cout << std::setfill('-');
    summarydata << std::setfill('-');


   // cout << std::setw(45) << std::left<<"-"<<std::setw(35) << std::left <<Name << std::setw(20) << std::left<<"-" <<endl;
    summarydata <<endl<< std::setw(45) << std::left<<"-"<<std::setw(42) << std::left <<Name << std::setw(30) << std::left<<"-" <<endl<<endl;
    logdata<<"NAME,"<<Name<<","<<endl;



   // cout << std::setfill(' ');
    summarydata << std::setfill(' ');


   // summarydata<< "-----------------------------------"<< Name << "-----------------------------------"<< endl<<endl;
    for (unsigned int i = 0; i < Stocks.size(); i++) {

        //cout<<"checkpoint 2"<<endl;
       // summarydata << std::setfill('-');


       // cout <<std::setw(15) << std::left<<Stocks[i].Symbol << std::setw(27) << std::left << Stocks[i].Name << std::setw(15) << std::left << Stocks[i].TotalShares  << sign[Stocks[i].Chose] << std::setw(15) << std::left <<Stocks[i].TotalInitialValue;
        summarydata <<std::setw(15) << std::left<<Stocks[i].Symbol << std::setw(27) << std::left << Stocks[i].Name << std::setw(15) << std::left << Stocks[i].TotalShares  << sign[Stocks[i].Chose] << std::setw(15) << std::left <<Stocks[i].TotalInitialValue;
        logdata<<Stocks[i].Symbol<<", "<<Stocks[i].Name<<", "<<Stocks[i].TotalShares<<", "<<sign[Stocks[i].Chose]<<Stocks[i].TotalInitialValue<<", ";
        // cout <<Stocks[i].Symbol << " " << Stocks[i].Name << " " << Stocks[i].TotalShares  << sign[Stocks[i].Chose] <<  Stocks[i].TotalInitialValue;
      //  cout<<std::setw(30) << std::left<<Stocks[i].Symbol << std::setw(30) << std::left << Stocks[i].Name << std::setw(30) << std::left << Stocks[i].TotalShares  <<std::setw(30) << std::left <<sign[Stocks[i].Chose]  <<Stocks[i].TotalInitialValue;
       // summarydata <<std::setw(30) << std::left<<Stocks[i].Symbol << std::setw(30) << std::left << Stocks[i].Name << std::setw(30) << std::left << Stocks[i].TotalShares  <<std::setw(30) << std::left <<sign[Stocks[i].Chose]  <<Stocks[i].TotalInitialValue;


        //cout << std::left << std::setw(12)<<"Serge"<<std::left << std::setw(12)<<"test"<<endl;


        if(!fileflag) {


                 for(int j=0; j<TotalDictionary.size(); j++) {

                        //  cout<<"STOCK SYMBOL IS--->"<<Stocks[i].getsymbol()<<endl;
                        //  cout<<"CHECKING AGAINST DIC SYMBOL: "<<TotalDictionary[j].GetStockSymbol()<<endl;
                      //    cout<<"J IS"<<j<<endl;
                        //  cout<<"PRICE and SYMBOL is---> "<<price[j]<<" "<<TotalDictionary[j].GetStockSymbol()<<endl;
                    if(TotalDictionary[j].GetStockSymbol()==Stocks[i].getsymbol()) {


                            if(price[j]!="-1") {

                                float pval = stof(price[j]);

                                float assets=pval*Stocks[i].getshares();

                            //    cout <<"$" <<setprecision (2) << fixed <<std::setw(15) << std::left <<assets; //prints stock asset

                                summarydata <<"$" <<setprecision (2) << fixed <<std::setw(15) << std::left <<price[j]; //remove this
                                logdata<<"$" <<setprecision (2) << fixed <<price[j]<<","; //remove this

                                summarydata <<"$" <<setprecision (2) << fixed <<std::setw(15) << std::left <<assets;
                                logdata<<"$" <<setprecision (2) << fixed <<assets<<",";


                                float rval = 100*(assets-Stocks[i].TotalInitialValue)/Stocks[i].TotalInitialValue;

                                 //   cout<<"%"<<setprecision(2)<<fixed<<std::setw(15) << std::left<<rval<<endl;
                                    summarydata<<"%"<<setprecision(2)<<fixed<<std::setw(15) << std::left<<rval<<endl;
                                    logdata<<"%"<<setprecision(2)<<fixed<<rval<<","<<endl;



                            } else {
                               // cout<<endl;
                                summarydata<<endl;
                                logdata<<"N/A,N/A,N/A,"<<endl; //remove extra n/a
                            }


                          }

                      }





      //  readpriceflag=1;
        }
        else {

          //  cout<<endl;
            summarydata<<endl;
            logdata<<","<<endl;
        }

        if (!Stocks[i].Chose) Total += Stocks[i].TotalInitialValue;
        else Total -= Stocks[i].TotalInitialValue;


    }
    summarydata<<endl<<"Total Investment: ";
  //  cout << "Total Invested: ";
    logdata<<"TOTAL,"<<"Total Investment: ";
    if (Total < 0) {
        Total *= -1.0;
     //   cout << "-$" << Total << endl;
        summarydata << "-$" << Total << endl;
        logdata << "-$" << Total <<"," <<endl;

    }
    else {
        summarydata << " $" << Total << endl;
      //  cout << " $" << Total << endl;
        logdata<< " $" << Total <<"," <<endl;
    }

    if(fileflag) {
        summarydata<<"Refreshing stock prices . . . Please wait . . ."<<endl;
     //   cout<<"Refreshing stock prices . . . Please wait . . ."<<endl;
    }

    summarydata.close();
    logdata.close();
}


string Owner::getname(void)
{
    return Name;
}

vector<Stock> Owner::GetStock(void)
{
    return Stocks;
}

void Owner::SetStock(vector<Stock> temp)
{
    Stocks = temp;
}

void Owner::StockSummary(void)
{
    vector<int> count;
    for (unsigned int w = 0; w < Stocks.size(); w++) {
        if (Stocks[w].GetChose()) {
            Stocks[w].SetTotalShares((Stocks[w].getshares()*-1));
            Stocks[w].SetTotalInitialValue((Stocks[w].GetInitialValue() * -1 ));
        }
        else {
            Stocks[w].SetTotalShares(Stocks[w].getshares());
            Stocks[w].SetTotalInitialValue(Stocks[w].GetInitialValue());
        }

    }
    for (unsigned int i = 0; i < Stocks.size(); i++) {
        count.clear();
        for (unsigned int q = 0; q < Stocks.size(); q++) {
            if ((i != q)&&(Stocks[i].getname()==Stocks[q].getname())) {
                if (Stocks[q].GetChose()) {
                    Stocks[i].SetTotalShares(Stocks[i].GetTotalShares() - Stocks[q].getshares());
                    Stocks[i].SetTotalInitialValue(Stocks[i].GetTotalInitialValue() - Stocks[q].GetInitialValue());
                }
                else {
                    Stocks[i].SetTotalShares(Stocks[i].GetTotalShares() + Stocks[q].getshares());
                    Stocks[i].SetTotalInitialValue(Stocks[i].GetTotalInitialValue() + Stocks[q].GetInitialValue());
                }
                count.push_back(q);
            }
        }
        for (int j = 0; j < count.size(); j++) {
        Stocks.erase(Stocks.begin() + (count[j]-j));
        }
       // if(Stocks[i].GetTotalShares()<0) Stocks[i].SetTotalShares(0); //remove this new shares
    }
}




Stock_Dictionary::Stock_Dictionary(string n, string S, string e)
{
    Name = n;
    Symbol = S;
    Stock_Exchange = e;
}

void Stock_Dictionary::AddStock(string n, string S, string e)
{
    Name = n;
    Symbol = S;
    Stock_Exchange = e;
}

bool Stock_Dictionary::SearchStockSymbol(string s)
{
    if (Symbol == s) return 1;
    return 0;
}

string Stock_Dictionary::GetStockName(void) const
{
    return Name;
}

string Stock_Dictionary::GetStockSymbol(void) {
    return Symbol;
}

void Stock_Dictionary::SetStockExchange(istream & in)
{
    int num;
    if (&in == &cin) {
      //  cout << "What is the stock exchange for the stock?\n1 - TSE\n2 - NASDAQ\n3 - Other" << endl;
        in >> num;
        if (num == 1) Stock_Exchange = "TSE";
        else if (num == 2) Stock_Exchange = "NASDAQ";
        else if (num == 3) {
          //  cout << "Type the name of the stock exchange"<<endl;
            in >> Stock_Exchange;
        }
    }
    else in >> Stock_Exchange;

}

void Stock_Dictionary::SetStockExchange(void)
{

    if (stock_num == 1) {
        Stock_Exchange = "TSX";
      //  cout<<"STOCK NUM IS"<<stock_num<<endl;


    }

    else if (stock_num == 2){

            Stock_Exchange = "NASDAQ";

        }
    else if (stock_num == 3) { //other

        Stock_Exchange = f_Stock_Dictionary_Stock_Exchange;

    }
    else if (stock_num == 4) {
            Stock_Exchange = "NYSE";




}

}

string Stock_Dictionary::GetStockExchange(void) {
    return Stock_Exchange;
}


void Stock_Dictionary::SetStockName(string n)
{
    Name = n;
}

void Stock_Dictionary::SetStockName(istream & in)
{
    in >> Name;
}

void Stock_Dictionary::SetStockSymbol(string s)
{
    Symbol = s;
}

void Stock_Dictionary::SetStockSymbol(istream & in)
{
    in >> Symbol;
}

void Stock_Dictionary::SetStockExchange(string e)
{
    Stock_Exchange = e;
}

void Stock_Dictionary::PrintData(ostream & out)
{
    out << Name << "," << Symbol << "," << Stock_Exchange <<","<<endl;
}


void Summary(vector<Owner>& s)
{
    vector<Owner> summary;
    vector<Stock> TempStocks,TotalStocks;
    Owner T;
    bool match = 0;
    unsigned int count=0;
    // Retreive the names of all the stock owner
   // cout<<"OWNER V2 SIZE IS: "<<s.size();
    for (unsigned int i = 0; i < s.size(); i++) {
        for (unsigned int n = 0; n < summary.size(); n++) {
            if (s[i].getname() == summary[n].getname()) match = 1;
        }
        if (!match) {
            T.SetName(s[i].getname());
            summary.push_back(T);
            count++;

        }
        match = 0;
    }


//	Retreive the name of stocks owned by each stock owner and add to Owner class
    for (unsigned int v = 0; v < summary.size(); v++) {
        TotalStocks.clear();
        for (unsigned int b = 0; b < s.size(); b++) {
            if (s[b].getname() == summary[v].getname()) {
                TempStocks = s[b].GetStock();
                for (unsigned int s = 0; s < TempStocks.size(); s++) {
                    TotalStocks.push_back(TempStocks[s]);
                }

            }
        }
        summary[v].SetStock(TotalStocks);
        summary[v].StockSummary();
    }

    //ofstream pyflag("pystate.tmp");
    if(!fileflag) while(!is_file_exist("stock_current_price.tmp"));


    ofstream summarydata("Summary.sf");
    ofstream logdata("summarylog.sld");

   // cout<<"MEMORY CHECK STATUS IS: "<<memorycheck;
   if(memorycheck) {
      // if(!fileflag) while(!is_file_exist("stock_current_price.tmp")); //need attention

     //   cout <<endl<< "_________________________________________________Summary_______________________________________________" << endl;
        summarydata <<endl<< "_______________________________________________________Summary_______________________________________________________" << endl<<endl;

     //   cout << "A negative total means you are already seeing profits :) " << endl;
      //  cout << "Symbol               Stock   Shares    Net Stock Investment    Potential Stock Asset    Potential ROR" << endl;
        cout<<std::setw(15) << std::left <<"Symbol"<<std::setw(25) << std::left<<"Stock" <<" "<<std::setw(16) << std::left<<"Shares"<<std::setw(17) << std::left <<"NSI"<<std::setw(16) << std::left <<"Last Sale"<<std::setw(16) << std::left<<"NSW"<< std::setw(15) << std::left << "PROR"<<endl;
        summarydata<<std::setw(15) << std::left <<"Symbol"<<std::setw(25) << std::left<<"Stock" <<" "<<std::setw(16) << std::left<<"Shares"<<std::setw(17) << std::left <<"NSI"<<std::setw(16) << std::left <<"Last Sale"<<std::setw(16) << std::left<<"NSW"<< std::setw(15) << std::left << "PROR"<<endl;

       // summarydata <<endl<< "_____________________________________________Summary______________________________________________" << endl;
       // summarydata << "A negative total means you are already seeing profits :) " << endl;
        //summarydata << "Symbol                  Stock                Shares               NSI                PSA               PROR" << endl;


      //  std::left << std::setw(20)

   }
   summarydata.close();
   logdata.close();


  //  cout<<"SUMMARY SIZE IS: "<<summary.size()<<endl;
   for (unsigned int z = 0; z < summary.size(); z++) { //attention , change to z<summary.size()
        summary[z].PrintStockSummary();
    }

   /* int z=0;
    while(z<summary.size() && (!readpriceflag)) {
      summary[z].PrintStockSummary();
      z++;

    } */

}


void callPy(void) {	 //attention py

    //REMOVE THIs
    /* ghJob = CreateJobObject( NULL, NULL); // GLOBAL
    if( ghJob == NULL)
    {
        cout<<"could not create job obj"<<endl;
    }
    else
    {
        JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = { 0 };

        // Configure all child processes associated with the job to terminate when the
        jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
        if( 0 == SetInformationJobObject( ghJob, JobObjectExtendedLimitInformation, &jeli, sizeof(jeli)))
        {
            cout<<"could not set obj info"<<endl;
        }
    } */





    shellExInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    shellExInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    shellExInfo.hwnd = NULL;
    shellExInfo.lpVerb = L"open";
    shellExInfo.lpFile = L"StockFetcher8.exe";
    shellExInfo.lpParameters = NULL;
    shellExInfo.lpDirectory = NULL;
    shellExInfo.nShow = SW_HIDE;
    shellExInfo.hInstApp = NULL;

    ShellExecuteEx(&shellExInfo);

    DWORD process_id=GetProcessId(shellExInfo.hProcess);



    //remove this;

/*
    if(0 == AssignProcessToJobObject( ghJob, shellExInfo.hProcess))
            {
                cout<<"couldnt assign shit"<<endl;
            }
  */


    h = OpenProcess(PROCESS_TERMINATE, false, process_id);

   // AssignProcessToJobObject(ghJob, shellExInfo.hProcess);

   // JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = { 0 };
   // jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;

   // TerminateProcess(shellExInfo.hProcess, 1);






    /*  STARTUPINFO startInfo = {0};
   // PROCESS_INFORMATION processInfo = {0};
    BOOL bScucces = CreateProcess(TEXT("StockFetcher.exe"),NULL,NULL,NULL,FALSE,NULL,NULL,NULL,&startInfo,&PROCESS_INFORMATION_GLOBAL);
  //  PROCESS_INFORMATION_GLOBAL = processInfo;
  */
}


void readPrice(string p[]) { //need attention

    ifstream pricein("stock_current_price.tmp");
    //cout<<"we bout to read some shit"<<endl;
    int i=0;
    while(getline(pricein, p[i])) {
       // cout<<"PRICE---->"<<p[i]<<endl;

        //cout<<"I IS "<<i<<endl;
        if(i==TotalDictionary.size()-1) break; //remove this
        i++;

    }
   // cout<<"all read"<<endl;
    pricein.close();
   // cout<<"file closed"<<endl;
}


bool is_file_exist(const string filename){
    ifstream infile(filename);
    return infile.good();
}

////////////////////////GUI Functions///////////////////////////////////////////



void MainWindow::on_pushButton_clicked() //add new stock button
{



        q_Owner_name = ui->lineEdit->text();
       f_Owner_name = q_Owner_name.toStdString().c_str();

       q_Stock_Symbol = ui->lineEdit_2->text();
       f_Stock_Symbol = q_Stock_Symbol.toStdString().c_str();



       std::transform(f_Stock_Symbol.begin(), f_Stock_Symbol.end(),f_Stock_Symbol.begin(), ::toupper); //this transform f_Stock_Symbol to upper case string
       //attention



       q_Stock_Name = ui->lineEdit_3->text();
       f_Stock_Name = q_Stock_Name.toStdString().c_str();

     //  if(f_Stock_Name.empty()) cout<<"name is->"<<f_Stock_Name<<"<-"<<endl;

       q_Stock_Shares = ui->lineEdit_5->text();
       f_Stock_Shares = q_Stock_Shares.toStdString().c_str();

       q_Stock_InitialPrice = ui->lineEdit_6->text();
       f_Stock_InitialPrice = q_Stock_InitialPrice.toStdString().c_str();


       if(stock_num==3) {
           q_Stock_Dictionary_Stock_Exchange = ui->lineEdit_4->text();
           f_Stock_Dictionary_Stock_Exchange = q_Stock_Dictionary_Stock_Exchange.toStdString().c_str();


       }

      // cout<<"stoc_num is:->"<<stock_num<<endl;

       if(stock_num!=0 && !(f_Stock_Shares.empty()) && !(f_Stock_Name.empty()) && !(f_Stock_Symbol.empty()) && !(f_Owner_name.empty()) && !(stockerror)) {




           Temp_Owner.addStock();
           Temp_Owner.SetTimeStamp(Timestamp);
           OwnerV.push_back(Temp_Owner);
           OwnerVT.push_back(Temp_Owner);
           ui->label_8->setVisible(false);
           ui->lineEdit_3->setVisible(0);
           ui->label_3->setVisible(0);
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();

       }

       else {
           ui->label_8->setVisible(true);
       }

       // ui->pushButton_7->setVisible(false);

        cout<<"banksymbol is "<<banksymbolpass<<endl;

       std::transform(banksymbolpass.begin(), banksymbolpass.end(), banksymbolpass.begin(), ::toupper);
       if(symcheck) {

           sdcount++;
           symlist.push_back(banksymbolpass);

       }
       symcheck=false;
      // sdcount++;

}




void MainWindow::on_radioButton_clicked()
{
    BuySell=0; //buy
}

void MainWindow::on_radioButton_2_clicked()
{
    BuySell=1; //sell
}



void MainWindow::on_radioButton_3_clicked()
{

   // ui->lineEdit_4->setDisabled(true);
   // stock_num=4;



    string sn, se;

    if(autoset) {
        ui->lineEdit_4->setDisabled(true);
        stock_num=4;
        ui->label_9->setVisible(false);
        stockerror=false;

    }

    else {
        if(findStockName(bank.getBankSymbol(), sn, se, 2)) {
            ui->lineEdit_4->setDisabled(true);
            stock_num=4;
            ui->label_9->setVisible(false);
            stockerror=false;
        }

        else {
            cout<<"cant use this"<<endl;
            ui->label_9->setVisible(true);
            stockerror=true;

        }

    }








}



void MainWindow::on_radioButton_4_clicked()
{

    string sn, se;

    if(autoset) {
        ui->lineEdit_4->setDisabled(true);
        stock_num=2;
        ui->label_9->setVisible(false);
        stockerror=false;

    }

    else {
        if(findStockName(bank.getBankSymbol(), sn, se, 1)) {
            ui->lineEdit_4->setDisabled(true);
            stock_num=2;
            ui->label_9->setVisible(false);
            stockerror=false;
        }

        else {
            cout<<"cant use this"<<endl;
            ui->label_9->setVisible(true);
            stockerror=true;

        }

    }



}

void MainWindow::on_radioButton_5_clicked()
{
   // ui->lineEdit_4->setDisabled(true);
   // stock_num=1;


    string sn, se;

    if(autoset) {
        ui->lineEdit_4->setDisabled(true);
        stock_num=1;
        ui->label_9->setVisible(false);
        stockerror=false;

    }

    else {
        if(findStockName(bank.getBankSymbol(), sn, se, 3)) {
            ui->lineEdit_4->setDisabled(true);
            stock_num=1;
            ui->label_9->setVisible(false);
            stockerror=false;
        }

        else {
            cout<<"cant use this"<<endl;
            ui->label_9->setVisible(true);
            stockerror=true;

        }

    }







}



void MainWindow::on_radioButton_6_clicked()
{
    ui->lineEdit_4->setDisabled(false);
    f_Stock_Dictionary_Stock_Exchange="N/A";
    stock_num=3;

}

void MainWindow::on_lineEdit_2_editingFinished() //symbol entered
{



    if((!CheckFind)&&(!bank.getBankFoundState())) {
        ui->lineEdit_3->setDisabled(false);
       // ui->lineEdit_3->clear();
     }

    Stock a;
    CheckFind=1;

     q_Stock_Symbol = ui->lineEdit_2->text();
     string fsym =q_Stock_Symbol.toStdString().c_str();
     std::transform(fsym.begin(), fsym.end(), fsym.begin(), ::toupper);

     cout<<"stock_num is: "<<stock_num<<endl;

     if(stock_num==3) {



         QString qsym;

         if(!findStockNameOther(fsym)) {




             remove("statesym.tmp");
            // string fsym =q_Stock_Symbol.toStdString().c_str();
             ofstream fchk("checksym2.tmp"); //make another file for py to wait for eg checksym2
              //cout<<"fsym val is: "<<fsym<<endl;
             fchk<<fsym;
             fchk.close();

             rename("checksym2.tmp", "checksym.tmp");

             cout<<"waiting for statesym"<<endl;
             //Sleep(5000);
             Sleep(3000);
             while(is_file_exist("checksym.tmp"));
             cout<<"done waiting for statesym"<<endl;
             ifstream fchkin("statesym.tmp");

             string schk;



             fchkin>>schk;

              cout<<"state sym value is: "<<schk<<endl;

             if(schk!="-1") {
                 qsym = ui->lineEdit_2->text();
                // string fsym = qsym.toStdString().c_str();



                 //bank.setBankSymbol(fsym);

                 //std::transform(fsym.begin(), fsym.end(), fsym.begin(), ::toupper);
                 banksymbolpass=fsym;
                 stockpass=fsym;

                 qsym=QString::fromStdString(fsym);

                 ui->pushButton_7->setText(qsym);
                 ui->pushButton_7->setVisible(true);


                 cout<<"stockpass1 value is: "<<stockpass;


                // cout<<"setting bank symbol to: "<<bank.getBankSymbol()<<endl;

                 symcheck=1;

             }

             else{

                 ui->pushButton_7->setVisible(false);
                 symcheck=0;

             }
             fchkin.close();
             remove("checksym.tmp");

        }

         else {

             qsym = ui->lineEdit_2->text();

             string fsym2 = qsym.toStdString().c_str();

             std::transform(fsym2.begin(), fsym2.end(), fsym2.begin(), ::toupper);

             qsym=QString::fromStdString(fsym2);

             ui->pushButton_7->setText(qsym);
             ui->pushButton_7->setVisible(true);

             banksymbolpass=fsym;
             stockpass=fsym;

             symcheck=1;



         }

     }









     //QString autofill; //may need attention

     cout<<"f_stock_name is: "<<f_autofill<<endl;
    // autofill=QString::fromStdString(f_autofill); //may need attention
    // if(a.SetStock()==2) {
        // ui->lineEdit_3->setText(autofill); //may need attention
        // ui->lineEdit_3->setDisabled(true); //may need attention
    // }



/*


    if(bank.getBankFoundState()) {
        QString buttontext;
        buttontext=QString::fromStdString(bank.getBankSymbol());
        ui->pushButton_7->setVisible(true);
        ui->pushButton_7->setText(buttontext);
    }
 */


    ui->lineEdit_3->setVisible(1);
    ui->label_3->setVisible(1);



    CheckFind=0;

}



//std::string str = "Hello world";
//QString qstr = QString::fromStdString(str);


/*
if(!CheckFind) ui->lineEdit_3->setDisabled(false);

Stock a;
CheckFind=1;

q_Stock_Symbol = ui->lineEdit_2->text();
f_Stock_Symbol = q_Stock_Symbol.toStdString().c_str();

a.SetStock();
ui->lineEdit_3->clear();
if(a.SetStock()==2) ui->lineEdit_3->setDisabled(true);
CheckFind=0; */








void MainWindow::on_pushButton_2_clicked() //View stock button
{




   // cout<<"write to pystate"<<endl;



    //summary will be printed on one page
    //printstock log will be printed in another page (full detail log)

       // Summary(OwnerV2);
      //  memorycheck=0;



       // cout<<"last stock name recorded is: "<<f_Stock_Name<<"to the left";
        //Owner accounts Loaded from file
       // for (unsigned int i = 0; i <OwnerV2.size(); i++) {
        //    OwnerV2[i].printStock(cout);
       // }
       // cout<<"THIS SHUD PRINT OWNERV2"<<endl;


       // Owner accounts that was made new during session
      //  for (unsigned int i = Owner_count; i < OwnerV.size(); i++) {
         //   OwnerV[i].printStock(cout);
      //  }

        //Summary of all accounts


       // Summary(OwnerV);
       // memorycheck=1;


        //TRY TO IMPLEMENT COMBINED VECTORS

        //remove this


      //  for (unsigned int i = 0; i <OwnerVT.size(); i++) {
      //      OwnerVT[i].printStock(cout);
     //   }

       // quitcheck=1;
      //  for (unsigned int i = 0; i < OwnerVT.size(); i++) { //this feat disabled for now
       //       OwnerVT[i].printStock(cout);
      //    }
     //   quitcheck=0;




        //attention
        //this passes temp stock dictionary to py


       // readpriceflag=0;
        remove("stock_current_price.tmp"); //attention
        remove("StockDictionaryPass.sdf");
        ofstream dpass("StockDictionaryPass.sdf");
        string SN, SS, SE;

        for(int i=0; i<TotalDictionary.size(); i++) {
        //    cout<<"total dictionary value->"<<TotalDictionary[i].GetStockName()<<","<<TotalDictionary[i].GetStockSymbol()<<","<<TotalDictionary[i].GetStockExchange()<<","<<"<--"<<i<<endl;
            //if(TotalDictionary[i].GetStockExchange().empty())
            SN=TotalDictionary[i].GetStockName();
            SS=TotalDictionary[i].GetStockSymbol();
            SE=TotalDictionary[i].GetStockExchange();


            if(SN.empty()) SN="N/A";
            if(SS.empty()) SS="N/A";
            if(SE.empty()) SE="N/A";

            dpass<<SN<<","<<SS<<","<<SE<<","<<endl; //may need attention
        }

        dpass.close();
        //

        ofstream pyflag("pystate.tmp");
        pyflag.close();


    //    callPy(); //attention py

        ifstream stocklogin("StockLog.slf");
        string printline;
        while(getline(stocklogin, printline)) { //prints stock log
          //  cout<<printline<<endl;
        }
        stocklogin.close();


        fileflag=1;
        Summary(OwnerVT); //prints initial summary without updated prices

        fileflag=0;
        Summary(OwnerVT);
        fileflag=0;



        //opens view window
        Dialog viewlog;
        viewlog.setModal(true);
        viewlog.exec();

        //ShellExecute(0,"open", "notepad", "Summary.txt", NULL, SW_SHOW);

}

void MainWindow::on_pushButton_3_clicked() //Quit button
{

    //Save New Owners made during session
        ofstream dataout("StockLog.slf", ios::app);

        string *ref = new string[OwnerV.size()];



        for (unsigned int i = Owner_count; i < OwnerV.size(); i++) {
            ref[i]=OwnerV[i].getname();
         //   cout<<"I NUMBER IS: "<<i<<endl;

        }

       // int LastRepeatedInstance;
        int store_i=0;
        int j=1;

        OwnerStatus=0;
        FirstInstance=0;

      //  cout<<"Owner count is: "<<Owner_count<<endl;

        for (unsigned int i = 0; i < OwnerV.size(); i++) { //i should be Owner_count or 0

            if((i==store_i+1)&&FirstInstance==1) {
                FirstInstance=0;
                OwnerStatus=1;


            }

            if(OwnerV[i].getname()==ref[j]) {
                  store_i=i;
                  i_cnt++;

                 if(!OwnerStatus) FirstInstance++;

                 OwnerStatus=1;

            } else{

                FirstInstance=1;
                i_cnt=0;

            }

        if((i==store_i+1)&&(OwnerV[i].getname()!=ref[j])) FirstInstance=0;


            OwnerV[i].printStock(dataout);


          if((i==store_i+1)&&(OwnerV[i].getname()!=ref[j])) FirstInstance=1;
           j++;

        }
        dataout.close();

      //  cout<<"NO CRASH AT THIS POINT2----<"<<endl;


       // cout<<"WE JUST SAVED"<<endl;

       // cout<<countD<<"<--countD"<<endl;
       // cout<<TotalDictionary.size()<<"<--totaldic"<<endl;


      //  cout<<"NO CRASH AT THIS POINT2.5----<"<<endl;
     //   cout<<"DIC SIZE IS:"<<TotalDictionary.size()<<endl;
     //   cout<<"COUNTD is:"<<countD<<endl;

      //  cout<<TotalDictionary[countD-1].GetStockSymbol()<<"<-stock symbol of most recent element"<<endl;






        //Save New Dictionary Elements made during session
        ofstream dataoutD("StockDictionary.sdf", ios::app);



        for (unsigned int i = countD-1; i < TotalDictionary.size(); i++) { //attention change countD-1 to countD-2

           // cout<<"we just saved these dic elements"<<endl;

            TotalDictionary[i].PrintData(dataoutD);

           // cout<<TotalDictionary[i].GetStockName()<<","<<TotalDictionary[i].GetStockSymbol()<<","<<TotalDictionary[i].GetStockExchange()<<","<<"<--"<<i<<endl;
        }

     //   cout<<"NO CRASH AT THIS POINT3----<"<<endl;
        dataoutD.close();  //attention

        delete [] ref;

      //  CloseHandle(PROCESS_INFORMATION_GLOBAL.hProcess);
      //  CloseHandle(PROCESS_INFORMATION_GLOBAL.hThread);



        //function below saves the other-stock name dictionary

        cout<<"sd count is: "<<sdcount<<endl;
        cout<<"symlist size is: "<<symlist.size()<<endl;
        ofstream otherout("StockDictionaryO.sdf", ios::app);
        for(int i=sdcount-1; i<symlist.size(); i++) {

            cout<<"symlist item pushed: "<<symlist[i];
            otherout<<symlist[i]<<endl;

        }
        otherout.close();









        ofstream pexit("pyexit.tmp");
        pexit.close();

        TerminateProcess(h, 1);

        CloseHandle(h);

        QApplication::quit();




}



void MainWindow::on_lineEdit_editingFinished() //owner name field
{

}


void MainWindow::on_pushButton_4_clicked() //clear stock button
{

    ClearDialog clearlog;
    clearlog.setModal(true);
    clearlog.exec();


}

void MainWindow::on_Main_Menu_Return_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Add_Stock_Menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_3->setVisible(0);
    ui->label_3->setVisible(0);
}

void MainWindow::on_pushButton_5_clicked() //view stock history button
{



        //init stock log files for viewing

        ifstream datain_init("StockLog.slf");
        ofstream dataout_init("StockLog2.slf");

        string lines;
        while(getline(datain_init, lines)) {
            dataout_init<<lines<<endl;
        }

        datain_init.close();
        dataout_init.close();

        //fin init stock log files for viewing




        ofstream dataout("StockLog2.slf", ios::app);


        string *ref = new string[OwnerV.size()];


        for (unsigned int i = Owner_count; i < OwnerV.size(); i++) {
            ref[i]=OwnerV[i].getname();
         //   cout<<"I NUMBER IS: "<<i<<endl;

        }

       // int LastRepeatedInstance;
        int store_i=0;
        int j=1;

        OwnerStatus=0;
        FirstInstance=0;

      //  cout<<"Owner count is: "<<Owner_count<<endl;

        for (unsigned int i = 0; i < OwnerV.size(); i++) { //i should be Owner_count or 0

            if((i==store_i+1)&&FirstInstance==1) {
                FirstInstance=0;
                OwnerStatus=1;


            }

            if(OwnerV[i].getname()==ref[j]) {
                  store_i=i;
                  i_cnt++;

                 if(!OwnerStatus) FirstInstance++;

                 OwnerStatus=1;

            } else{

                FirstInstance=1;
                i_cnt=0;

            }

        if((i==store_i+1)&&(OwnerV[i].getname()!=ref[j])) FirstInstance=0;


            OwnerV[i].printStock(dataout);


          if((i==store_i+1)&&(OwnerV[i].getname()!=ref[j])) FirstInstance=1;
           j++;

        }

        dataout.close();

        delete [] ref;

        View viewlog2;
        viewlog2.setModal(true);
        viewlog2.exec();

}

void MainWindow::on_pushButton_6_clicked() //about
{
    About aboutlog;
    aboutlog.setModal(true);
    aboutlog.exec();
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1) //stock symbol changed
{
    QString buttontext;
    /*
    if(!CheckFind) {
        ui->lineEdit_3->setDisabled(false);
        ui->lineEdit_3->clear();
     }

    Stock a;
    CheckFind=1;
    */

    QString q_StockSymbol = ui->lineEdit_2->text();
   // q_Stock_Symbol = ui->lineEdit_2->text();
    string StockSymbol = q_StockSymbol.toStdString().c_str();
    std::transform(StockSymbol.begin(), StockSymbol.end(), StockSymbol.begin(), ::toupper); //attention


   // a.SetStock();
   // ui->lineEdit_3->clear();


    cout<<"stock symbol is: "<<StockSymbol<<endl;
    string foundStockName;

    bool symbolFound;
    string StockExchange;

    symbolFound=findStockName(StockSymbol, foundStockName, StockExchange, 0);
    bank.setBankFoundState(symbolFound);

    cout<<"stock symbol is: "<<StockSymbol<<endl;
    cout<<"stock name is: "<<foundStockName<<endl;
    //cout<<"bool value is: "<<findStockName(StockSymbol)<<endl;

    //QString autofill; //may need attention

  //  cout<<"f_stock_name is: "<<f_autofill<<endl;
  //  autofill=QString::fromStdString(f_autofill); //may need attention
 /*   if(a.SetStock()==2) {
        ui->lineEdit_3->setText(autofill); //may need attention
        ui->lineEdit_3->setDisabled(true); //may need attention
    }
    */

    if(symbolFound){
        autoset=true;
        ui->pushButton_7->setVisible(true);
        bank.setBankSymbol(StockSymbol);
       // bank.setBankFoundState(true);



        QString foundautofill;
        foundautofill=QString::fromStdString(foundStockName);
        ui->lineEdit_3->setText(foundautofill);
        ui->lineEdit_3->setDisabled(true);
        if(StockExchange=="NASDAQ") {
            ui->radioButton_4->click();

        }
        else if(StockExchange=="NYSE") {
            ui->radioButton_3->click();
        }

        else if(StockExchange=="TSX") {
            ui->radioButton_5->click();
        }




       buttontext=QString::fromStdString(bank.getBankSymbol());
       ui->pushButton_7->setVisible(true);
       ui->pushButton_7->setText(buttontext);






    }

    else {
        bank.setBankFoundState(false);
        ui->radioButton_6->click(); //other
        ui->pushButton_7->setVisible(false);
       // if((stock_num!=0 && !(f_Stock_Shares.empty()) && !(f_Stock_Name.empty()) && !(f_Stock_Symbol.empty()) && !(f_Owner_name.empty()) && !(stockerror))
        ui->lineEdit_3->clear();
        ui->lineEdit_3->setDisabled(false);
        autoset=false;
/*
        ofstream fchk("checksym.tmp");
        while(!is_file_exist("statesym.tmp"));
        ifstream fchkin("statesym.tmp");
        string schk;
        fchkin>>schk;
        if(schk!="-1") {
            QString qsym = ui->lineEdit_2->text();
            ui->pushButton_7->setText(qsym);
            ui->pushButton_7->setVisible(true);
        }
*/



    }

    ui->lineEdit_3->setVisible(1);
    ui->label_3->setVisible(1);



    CheckFind=0;
    autoset=false;
}

void StockBank::setBankSymbol(string sy) {
    BankSymbol=sy;

}

void StockBank::setBankFoundState(bool st) {
    BankFoundState=st;
}

bool StockBank::getBankFoundState(void) {
    return BankFoundState;
}

string StockBank::getBankSymbol(void) {
    return BankSymbol;

}




void MainWindow::on_pushButton_7_clicked() //stats button
{

    if(bank.getBankFoundState() || (symcheck)) {




      if(stock_num!=3)  stockpass=bank.getBankSymbol();

        displaygraph showpage;

        showpage.setModal(true);

        showpage.exec();

        showpage.show();

      //  symcheck=false;



    }




}






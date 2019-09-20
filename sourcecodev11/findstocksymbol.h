#pragma once
#include <iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include <algorithm>



/*this scans the NASQAD csv file and reports the stock symbol and its worth*/



using namespace std;



bool findStockName(const string &StockSymbol, string &stockname, string &stockexchange, const int GoToBank) //0 = all banks, 1 = nasdaq, 2= nyse, 3=tsx

{
	


ifstream datain("noc6.lf");
ofstream dataout("symbolfnd.txt");
string currentline;
string symbolcheck;

string testsymbol;


bool filestate=0;
testsymbol=StockSymbol;

if(GoToBank==0 || GoToBank==1) {
    getline(datain, currentline);

    if(currentline==testsymbol) {
        getline(datain, currentline);
        getline(datain, currentline);
        stockname=currentline;
        cout<<stockname<<endl;
        dataout<<stockname<<endl;
        filestate=1;

        dataout.close();
        datain.close();
        stockexchange="NASDAQ";
        return true;
    }

    while(datain.good()) {

        for(int i=0; i<16; i++) {

            getline(datain, currentline);
            if(currentline==testsymbol) {
                getline(datain, currentline);
                getline(datain, currentline);
                stockname=currentline;
                cout<<stockname<<endl;
                dataout<<stockname<<endl;
                filestate=1;
                dataout.close();
                datain.close();
                stockexchange="NASDAQ";
                return true;
            }

        //	cout<<"line was: "<<currentline<<endl;


        }


    }

    datain.close();

}


if(GoToBank==0 || GoToBank==2) {
    ifstream datain2("noc7.lf");


       getline(datain2, currentline);

       if(currentline==testsymbol) {
           getline(datain2, currentline);
           getline(datain2, currentline);
           stockname=currentline;
           cout<<stockname<<endl;
           dataout<<stockname<<endl;
           filestate=1;

           dataout.close();
           datain2.close();
           stockexchange="NYSE";
           return true;
       }

while(datain2.good()) {

   for(int i=0; i<16; i++) {

       getline(datain2, currentline);
       if(currentline==testsymbol) {
           getline(datain2, currentline);
           getline(datain2, currentline);
           stockname=currentline;
           cout<<stockname<<endl;
           dataout<<stockname<<endl;
           filestate=1;
           dataout.close();
           datain2.close();
           stockexchange="NYSE";
           return true;
       }

   //	cout<<"line was: "<<currentline<<endl;


   }


}

datain2.close();



}


if(GoToBank==0 || GoToBank==3) {
   ifstream datain3("noc9.lf");
    while(datain3.good()) {

        getline(datain3, currentline, ',');
        //cout<<currentline<<endl;
        if(currentline==testsymbol) {
        //	cout<<"shud work"<<endl;
            getline(datain3, currentline, ',');
            stockname=currentline;
            cout<<stockname<<endl;
            dataout<<stockname<<endl;
            filestate=1;
            dataout.close();
            datain3.close();
            stockexchange="TSX";
            return true;
        }


    }

}

	


return false;

}
/*
void openNASQAD(void) {
		
	STARTUPINFO startInfo = {0};
	PROCESS_INFORMATION processInfo = {0};
	BOOL bScucces = CreateProcessA(TEXT("geturl4.exe"),NULL,NULL,NULL,FALSE,NULL,NULL,NULL,&startInfo,&processInfo);
	}
	*/

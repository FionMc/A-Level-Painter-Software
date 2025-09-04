                                            //---------------------------------------------------------------------------
/******************************************************************************
Program: Installation
File: Installation.cpp
Functions: main
Description:Creates all files
Author: Fion McReynolds
Environment: Borland C++ Pro 6.0
Notes:
Revisions: 08/02/2024
******************************************************************************/
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<math.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

//CUSTOMER
char FileName2[80] = "CustomerFileSD";
typedef struct tag_cr{
        char title[10];
        char fnamecust[15];
        char lnamecust[15];
        char oneadcust[30];
        char twoadcust[30];
        char threeadcust[15];
        char pcodecust[9];
        char telnocust[12];
        char flag[2];
}CUSTOMER_RECORD;
int custref;
CUSTOMER_RECORD a_cust;

//INVOICE
char FileName5[80] = "InvoiceFileSD";
char invoiceref[10][3];
char custnum[10][3];
char quotenum[10][3];
char invoicedate[10][11];
char jobstartdate[10][11];
char jobenddate[10][11];
char paid[10][2];
int nii;
char nic[3];

//QUOTES
char FileName4[80] = "QuotesFileSD";
char quoteref[10][3];
char custno[10][3];
char quotedate[10][11];
char mainjobdesc[10][50];
char numofdays[10][3];
char labourq[10][5];
char mileage[10][4];
char vat[10][5];
char stockcost[10][5];
char totalcost[10][5];
int nqi;
char nqc[3];

//STAFF
char FileName1[80] = "StaffFileSD";
char staffref[10][3];
char fnamestaff[10][15];
char lnamestaff[10][15];
char oneadstaff[10][30];
char twoadstaff[10][30];
char threeadstaff[10][30];
char pcodestaff[10][9];
char telnostaff[10][12];
char emtel[10][12];
char ninum[10][15];
char username[10][15];
char password[10][15];
char loa[10][2];
int nsi;
char nsc[3];

//STOCK
char FileName3[80] = "StockFileSD";
char stockref[10][10];
char quantity[10][10];
char colour[10][15];
char volume[10][4];
char type[10][10];
char stockprice[10][8];
int nsti;
char nstc[3];

//LINKS
char FileName6[80] = "LinksFile";
char linksquoteref[10][3];
char linksstockref[10][3];
char linksquantity[10][4];
int nli;
char nlc[3];

//SCHEDULE
char FileName7[80]= "ScheduleFileSD";
char booking[3][370][14][3];
int staff;
int date;
int hour;

int Customer();
int Invoice();
int Staff();
int Quotes();
int Stock();
int Links();
int Schedule();
int ReWriteScheduleFile();

int main(int argc, char* argv[])
{
Customer();
Invoice();
Staff();
Quotes();
Stock();
Links();
Schedule();
return 0;
}
//CUSTOMER
int Customer()
{
getch();
ofstream fout(FileName2, ios::binary);
strcpy(a_cust.flag,"0");
for(custref=0;custref<10;custref++)
        {
        fout.write((char*)&a_cust,sizeof(a_cust));
        }//endfor
fout.close();
return 0;
}


//INVOICE
int Invoice()
{
int count;
nii=0;
itoa(nii,nic,10);
ofstream fout(FileName5, ios::binary);
fout.write((char*)&nic,sizeof(nic));
fout.close();
return 0;
}

//QUOTES
int Quotes()
{
int count;
nqi=0;
itoa(nqi,nqc,10);
ofstream fout(FileName4, ios::binary);
fout.write((char*)&nqc,sizeof(nqc));
fout.close();
return 0;
}

//STAFF
int Staff()
{
int count;
nsi=0;
itoa(nsi,nsc,10);
ofstream fout(FileName1, ios::binary);
fout.write((char*)&nsc,sizeof(nsc));
fout.close();
return 0;
}


//STOCK
int Stock()
{
int count;
nsti=0;
itoa(nsti,nstc,10);
ofstream fout(FileName3, ios::binary);
fout.write((char*)&nstc,sizeof(nstc));
fout.close();
return 0;
}

//LINKS
int Links()
{
int count;
nli=0;
itoa(nli,nlc,10);
ofstream fout(FileName6, ios::binary);
fout.write((char*)&nlc,sizeof(nlc));
fout.close();
return 0;
}

//SCHEDULE
int Schedule()
{
for(staff=0;staff<2;staff++)
        {
        for(date=0;date<366;date++)
                {
                for(hour=0;hour<13;hour++)
                        {
                        strcpy(booking[staff][date][hour],"*");
                        }//endfor - hour
                }//endfor - date
        }//endfor - staff
ReWriteScheduleFile();
return 0;
}

int ReWriteScheduleFile()
{
ofstream fout(FileName7, ios::binary);
for(staff=0;staff<2;staff++)
        {
        for(date=0;date<366;date++)
                {
                for(hour=0;hour<13;hour++)
                        {
                        fout.write((char*)&booking[staff][date][hour],1);
                        fout.write("\n",1);
                        }//endfor - hour
                }//endfor - date
        }//  endfor - staff
getch();
fout.close();
return 0;
}
//---------------------------------------------------------------------------


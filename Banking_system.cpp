#include <iostream>
#include<string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

class account
{
    char type;
    int acno, pass, pass2;
    char acname[20], actype[10];
    int acbalance, acloan, time;

public:
    account()
    {
        acno = 0;
        strcpy(acname, "UNASSIGNED");
        type = '\0';
        strcpy(actype, "NONE");
        acbalance = 0;
        acloan = 0;
        time = 0;
    }
    void create_ac();
    void modify_ac();
    void select_type()
    {
        if (type == 'S')
            strcpy(actype, "Saving");
        else if (type == 'C')
            strcpy(actype, "Current");
    }

    void show_ac()
    {
        cout << "\nAccount No. : " << acno;
        cout << "\nAccount Holder Name : " << acname;
        cout << "\nType of Account : " << actype;
        cout << "\nBalance amount : " << acbalance;
        cout << "\nLoan : " << acloan;
    }
    void deposit(int amt)
    {
        acbalance += amt;
    }
    void withdraw(int amt)
    {
        acbalance -= amt;
    }
    int getbal()
    {
        return acbalance;
    }
    char gettype()
    {
        return type;
    }
    int getacno()
    {
        return acno;
    }
    int getpass()
    {
        return pass;
    }
    float getloan()
    {
        return acloan;
    }
    int gettime()
    {
        return time;
    }
    void changeloan(int loan, int tim)
    {
        acloan = loan;
        time = tim;
    }

    void show_all()
    {
        cout << acno << "\t\t" << acname << "\t\t " << actype << " \t" << acbalance << " \t" << acloan << " \t" << time << " month(s)" << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
    }
};



void intro();
void write_ac();
void deposit_withdraw(int);
void transfer();
void tloan_ac();
void plona_ac();
void display_ac();
void display_all();
void modify_account();
void delete_ac();
void ploan_ac();
void finish();







void select(int opt)
{	
	switch(opt)
	{	case 1 : write_ac();
			 break;
		case 2 : deposit_withdraw(1);
			 break;
		case 3 : deposit_withdraw(2);
			 break;
		case 4 : transfer();
			 break;
		case 5 : tloan_ac();
			 break;
		case 6 : ploan_ac();
			 break;
		case 7 : display_ac();
			 break;
		case 8 : display_all();
			 break;
		case 9 : modify_account();
			 break;
		case 10 : delete_ac();
			  break;
		case 11 : finish();
			  exit(0);

		default : cout<<"\n\tInvalid Option !!!";
			  cout<<"\n\tEXITING....";
			  exit(0);
	}
}

int main()
{       int opt;
	intro();
	do
	{	
		cout<<"//=//=//=//=//=//=//=//=//=//=//=//=//=//=//";
		cout<<"\n//\t\tMAIN MENU\t\t  //";
		cout<<"\n//=//=//=//=//=//=//=//=//=//=//=//=//=//=//";
		cout<<"\n\n\t1>  NEW ACCOUNT";
		cout<<"\n\t2>  DEPOSIT MONEY";
		cout<<"\n\t3>  WITHDRAW MONEY";
		cout<<"\n\t4>  TRANSFER MONEY";
		cout<<"\n\t5>  TAKE LOAN";
		cout<<"\n\t6>  PAY LOAN";
		cout<<"\n\t7>  BALANCE ENQUIRY";
		cout<<"\n\t8>  ACCOUNT HOLDER LIST";
		cout<<"\n\t9>  MODIFY AN ACCOUNT";
		cout<<"\n\t10> CLOSE AN ACCOUNT";
		cout<<"\n\t11> EXIT";
		cout<<"\n\n\tSelect Option (1 to 11)";
		cout<<"\n\n\tEnter Your Choice : ";
		cin>>opt;
		select(opt);
	}while(opt!=11);
	finish();\

    return 0;
}
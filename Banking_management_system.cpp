//****************************************************************//
//			HEADER FILES USED IN PROJECT              //
//****************************************************************//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;
//****************************************************************//
//			CLASS USED IN PROJECT		          //
//****************************************************************//

class account
{
    char type;
    int acno, pass, pass2;
    string acname, actype;
    int acbalance, acloan, time;

public:
    account()
    {
        acno = 0;
        acname = "UNASSIGNED";
        type = '\0';
        actype = "NONE";
        acbalance = 0;
        acloan = 0;
        time = 0;
    }
    void create_ac();
    void modify_ac();
    void select_type()
    {
        if (type == 'S')
            actype = "Saving";
        else if (type == 'C')
            actype = "Current";
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
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    }
}; // CLASS ENDS HERE

//****************************************************************//
//  	GLOBAL DECLARATION of fstream Object, Class Object        //
//****************************************************************//

fstream file, tempfile;
account ac, trans_ac;

//****************************************************************//
//		GLOBAL FUNCTIONS USED IN PROJECT		  //
//****************************************************************//

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
void finish();

//****************************************************************//
//		FUNCTION TO WRITE RECORD IN FILE 		  //
//****************************************************************//

void write_ac()
{
    file.open("account.dat", ios::app);
    ac.create_ac();
    file.write((char *)&ac, sizeof(ac));
    file.close();
}
void account::create_ac()
{
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\t\t\tTO CREATE AN NEW ACCOUNT\t";
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\nEnter Account No. : ";
    cin >> acno;
    cout << "Enter the name of Account Holder : ";
    cin >> acname;
psk:
    cout << "Enter 4-Digit Pin : ";
    cin >> pass;
    cout << "Re-enter 4-Digit Pin : ";
    cin >> pass2;
    if (pass != pass2)
    {
        cout << "\nPassword not matching";
        cout << "\nEnter again : ";
        goto psk;
    }
    cout << "Enter type of Account ( C for Current/ S for Saving) : ";
    cin >> type;
    type = toupper(type);
    select_type();
    cout << "Enter the initial amount";
again:
    cout << " ( >=500 for Saving and >=1000 for Current) : ";
    cin >> acbalance;
    if (acbalance < 500 && type == 'S' || acbalance < 1000 && type == 'C')
    {
        cout << "\nInsufficient Balance!!!\nRenter initial amount";
        goto again;
    }
    cout << "\nAccount Created Successfully...";
}

//****************************************************************//
//		FUNCTION TO DEPOSIT OR WITHDRAW AMOUNT		  //
//****************************************************************//

void deposit_withdraw(int op)
{
    int num, amt, pswd, pos, bal, flag = 0, found = 1;
    file.open("account.dat", ios::out | ios::in);
    if (!file)
    {
        cout << "\nERROR!!! FILE COULD NOT BE OPENED";
        cout << "\n\nRESOLVE :- ";
        cout << "\nGo to Main Menu to create a file";
        return;
    }
    cout << "\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*";
    if (op == 1)
        cout << "\t\t\tTO DEPOSIT MONEY";
    else if (op == 2)
        cout << "\t\t\tTO WITHDRAW MONEY";
    cout << "\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*";
    cout << "\n\nEnter Account No. : ";
    cin >> num;
    while (file.read((char *)&ac, sizeof(ac)) && found == 1)
    {
        if (ac.getacno() == num)
        {
            found = 0;
            cout << "\nEnter Pass-Key : ";
            cin >> pswd;
            if (ac.getpass() != pswd)
            {
                flag = 1;
                cout << "\nWrong Password !!!";
                cout << "\nQuitting To Main Menu";
            }
            if (flag != 1)
            {
                ac.show_ac();
                if (op == 1)
                {
                    cout << "\n\nEnter Amount to be Deposited : ";
                    cin >> amt;
                    ac.deposit(amt);
                    cout << "\nAmount Deposited Successfully...";
                    cout << "\n\nNew Balance available : " << ac.getbal();
                }
                else if (op == 2)
                {
                    cout << "\n\nEnter Amount to be Withdraw : ";
                    cin >> amt;
                    bal = ac.getbal() - amt;
                    if (((bal <= 500 && ac.gettype() == 'S') || (bal <= 1000 && ac.gettype() == 'C')) && amt > bal)
                        cout << "\nInsufficient Balance !!!";
                    else
                    {
                        ac.withdraw(amt);
                        cout << "\nAmount Withdraw Successfully...";
                        cout << "\n\nNew Balance available : " << ac.getbal();
                    }
                }
                pos = -1 * sizeof(ac);
                file.seekp(pos, ios::cur);
                file.write((char *)&ac, sizeof(ac));
            }
        }
    }
    file.close();
    if (found == 1)
        cout << "\n\nRecord Not Found in File !!!";
}
//****************************************************************//
//		FUNCTION FOR TRANSFER OF MONEY			  //
//****************************************************************//

void transfer()
{
    int num, tnum, pos, pos2, tpos, pswd, amt, bal, flag = 0, found = 1, tfound = 1;
    file.open("account.dat", ios::in | ios::out | ios::binary);
    if (!file)
    {
        cout << "\nERROR!!! FILE COULD NOT BE OPENED";
        cout << "\n\nRESOLVE :- ";
        cout << "\nGo to Main Menu to create a file";
        return;
    }
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\t\t\t\tTO TRANSFER MONEY";
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\nEnter Account No. from transaction has to made : ";
    cin >> num;
    while (file.read((char *)&ac, sizeof(ac)) && found == 1)
    {
        pos2 = file.tellg();
        if (ac.getacno() == num)
        {
            found = 0;
            cout << "\nEnter Pass-Key : ";
            cin >> pswd;
            if (ac.getpass() != pswd)
            {
                flag = 1;
                cout << "\nWrong Password !!!";
                cout << "\nQuitting To Main Menu";
            }
            if (flag != 1)
            {
                ac.show_ac();
                cout << "\n\nEnter Amount to Transfer : ";
                cin >> amt;
                bal = ac.getbal() - amt;
                if (((bal <= 500 && ac.gettype() == 'S') || (bal <= 1000 && ac.gettype() == 'C')) && amt > bal)
                    cout << "\nInsufficient Balance !!!";
                else
                {
                    cout << "\nEnter Account No. in which Transfer is to be done : ";
                    cin >> tnum;
                    while (file.read((char *)&trans_ac, sizeof(trans_ac)) && tfound == 1)
                    {
                        tpos = file.tellg();
                        if (trans_ac.getacno() == tnum)
                        {
                            tfound = 0;
                            ac.withdraw(amt);
                            trans_ac.deposit(amt);
                            cout << "\nSuccessfully Transfered ...";
                            cout << "\nYour available balance : " << ac.getbal();
                            tpos = -1 * tpos;
                            file.seekp(tpos, ios::cur);
                            file.write((char *)&trans_ac, sizeof(trans_ac));
                        }
                    }
                }
                pos2 = -1 * pos2;
                file.seekp(pos2);
                file.write((char *)&ac, sizeof(ac));
            }
        }
    }
    file.close();
    if (found == 1)
        cout << "\nRecord not Found";
    if (tfound == 1 && amt < bal)
        cout << "\nAccount not found in which transaction had to made ";
}

//****************************************************************//
//		FUNCTION TO TAKE LOAN				  //
//****************************************************************//

void tloan_ac()
{
    float lamt, loan;
    int num, pswd, pos, time, flag = 0, found = 1;
    file.open("account.dat", ios::out | ios::in);
    if (!file)
    {
        cout << "\nERROR!!! FILE COULD NOT BE OPENED";
        cout << "\n\nRESOLVE :- ";
        cout << "\nGo to Main Menu to create a file";
        return;
    }
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\t\t\t\tTO TAKE LOAN";
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\nEnter Account No. : ";
    cin >> num;
    while (file.read((char *)&ac, sizeof(ac)) && found == 1)
    {
        if (ac.getacno() == num)
        {
            found = 0;
            cout << "\nEnter Pass-Key : ";
            cin >> pswd;
            if (ac.getpass() != pswd)
            {
                flag = 1;
                cout << "\nWrong Password !!!";
                cout << "\nQuitting To Main Menu";
            }
            if (flag != 1)
            {
                ac.show_ac();
                loan = ac.getloan();
                if (loan != 0)
                {
                    cout << "\n\nSORRY !!!\nCould not process your request";
                    cout << "\nIt Seems you already have a Loan on your Account";
                    cout << "\nPlease Pay previous Loan in order to take next Loan";
                }
                else
                {
                    cout << "\n\nEnter Amount of Loan : ";
                    cin >> lamt;
                    loan = lamt;
                    cout << "\nEnter time period for the Loan (in months): ";
                    cin >> time;
                    cout << "\nInterest on the loan will be 2% of original amount per month";
                    loan = lamt + lamt * 0.2 * time;
                    cout << "\nNet Payable amount after " << time << " months will be " << loan << endl;
                    ac.changeloan(loan, time);
                }
            }
            pos = -1 * sizeof(ac);
            file.seekp(pos, ios::cur);
            file.write((char *)&ac, sizeof(ac));
        }
    }
    file.close();
    if (found == 1)
        cout << "\n\nRecord Not Found in File !!!";
}

//****************************************************************//
//      	FUNCTION TO PAY LOAN				  //
//****************************************************************//

void ploan_ac()
{
    float lamt, loan;
    int num, pswd, pos, time, flag = 0, found = 1;
    file.open("account.dat", ios::out | ios::in);
    if (!file)
    {
        cout << "\nERROR!!! FILE COULD NOT BE OPENED";
        cout << "\n\nRESOLVE :- ";
        cout << "\nGo to Main Menu to create a file";
        return;
    }
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\t\t\t\tTO PAY LOAN";
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\nEnter Account No. : ";
    cin >> num;
    while (file.read((char *)&ac, sizeof(ac)) && found == 1)
    {
        if (ac.getacno() == num)
        {
            found = 0;
            cout << "\nEnter Pass-Key : ";
            cin >> pswd;
            if (ac.getpass() != pswd)
            {
                flag = 1;
                cout << "\nWrong Password !!!";
                cout << "\nQuitting To Main Menu";
            }
            if (flag != 1)
            {
                ac.show_ac();
                loan = ac.getloan();
                time = ac.gettime();
                if (loan == 0)
                {
                    cout << "\n\nYou dont have any Loan";
                }
                else
                {
                    cout << "\n\nYou have to pay : " << loan;
                    cout << "\nEnter your payment : ";
                    cin >> lamt;
                    if (lamt > loan)
                        cout << "\nSORRY!!!\nCannot Pay in Advance";
                    else
                    {
                        if (lamt == loan)
                        {
                            cout << "\nYour Loan is paid completely";
                            loan = 0;
                            time = 0;
                        }
                        else if (lamt < loan)
                        {
                            cout << "\nLoan to be Paid : " << loan - lamt;
                            cout << "\nTime remaining : " << time << " months";
                            loan = loan - lamt;
                        }
                    }
                    ac.changeloan(loan, time);
                }
            }
            pos = -1 * sizeof(ac);
            file.seekp(pos, ios::cur);
            file.write((char *)&ac, sizeof(ac));
        }
    }
    file.close();
    if (found == 1)
        cout << "\nRecord Not Found in File !!!";
}

//****************************************************************//
//		FUNCTION TO DISPLAY RECORD			  //
//****************************************************************//

void display_ac()
{
    int num, pswd, found = 1;
    file.open("account.dat", ios::in | ios::binary);
    if (!file)
    {
        cout << "\nERROR!!! FILE COULD NOT BE OPENED";
        cout << "\n\nRESOLVE :- ";
        cout << "\nGo to Main Menu to create a file";
        return;
    }
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\t\t\tTO DISPLAY DETAILS OF AN ACCOUNT";
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\nEnter Account No. : ";
    cin >> num;
    cout << "\n\nACCOUNT DETAILS\n";
    while (file.read((char *)&ac, sizeof(ac)) && found == 1)
    {
        if (ac.getacno() == num)
        {
            found = 0;
            cout << "\nEnter the Pass key : ";
            cin >> pswd;
            if (ac.getpass() != pswd)
            {
                cout << "\nWrong Password !!!";
                cout << "\nQuitting To Main Menu";
            }
            else
                ac.show_ac();
        }
    }
    file.close();
    if (found == 1)
        cout << "\n\nRecord Not Found in File !!!";
}

//****************************************************************//
//		FUNCTION TO DISPLAY ALL RECORDS			  //
//****************************************************************//

void display_all()
{
    file.open("account.dat", ios::in | ios::binary);
    if (!file)
    {
        cout << "\nERROR!!! FILE COULD NOT BE OPENED";
        cout << "\n\nRESOLVE :- ";
        cout << "\nGo to Main Menu to create a file";
        return;
    }
    cout << "\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=";
    cout << "\n\t\t\tACCOUNT HOLDER LIST";
    cout << "\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=";
    cout << "\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
    cout << "\nA/C No. \tName\t \tType\t\tBalance\t\tLoan\t\tTime Remaining";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    while (file.read((char *)&ac, sizeof(ac)))
    {
        ac.show_all();
    }
    file.close();
}

//****************************************************************//
//		FUNCTION TO MODIFY A RECORD IN FILE		  //
//****************************************************************//

void modify_account()
{
    int num, pswd, pos, flag = 0, found = 1;
    file.open("account.dat", ios::in | ios::out);
    if (!file)
    {
        cout << "\nERROR!!! FILE COULD NOT BE OPENED";
        cout << "\n\nRESOLVE :- ";
        cout << "\nGo to Main Menu to create a file";
        return;
    }
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\t\t\tTO MODIFY DETAILS OF AN ACCOUNT";
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\nEnter the Account No. whose details is to be modified : ";
    cin >> num;
    while (file.read((char *)&ac, sizeof(ac)) && found == 1)
    {
        if (ac.getacno() == num)
        {
            found = 0;
            cout << "\nEnter the Pass Key : ";
            cin >> pswd;
            if (ac.getpass() != pswd)
            {
                flag = 1;
                cout << "\nWrong Password !!!";
                cout << "\nQuitting To Main Menu";
                return;
            }
            if (flag != 1)
            {
                ac.show_ac();
                ac.modify_ac();
                pos = -1 * sizeof(ac);
                file.seekp(pos, ios::cur);
                file.write((char *)&ac, sizeof(ac));
                cout << "\n\nRecord Updated Successfully...";
            }
        }
    }
    file.close();
    if (found == 1)
        cout << "\nRecord Not Found in File !!!";
}
void account::modify_ac()
{
    int amt, psd, psd2;
    char tp = ' ';
    string nm = " ";
    cout << "\n\nEnter new details of account\n";
    cout << "\nModify Account Holder Name (Enter '.' to retain old one) : ";
    cin >> nm;
    cout << "\nModify Type of Account (Press '.' to retain old one) : ";
    cin >> tp;
    tp = toupper(tp);
    cout << "\nModify Balance amount (Press -1 to retain old one) : ";
    cin >> amt;
rep:
    cout << "\nEnter New 4-Digit Pin (Press -1 to retain old one) : ";
    cin >> psd;
    cout << "\nRenter 4-Digit Pin : ";
    cin >> psd2;
    if (psd != psd2)
    {
        cout << "\nPassword not matching !!!";
        cout << "\nEnter again : ";
        goto rep;
    }
    if ((nm == ".") != 0)
        acname = nm;
    if (tp != '.')
    {
        type = tp;
        select_type();
    }
    if (amt != -1)
        acbalance = amt;
    if (psd != -1)
        pass = psd;
}

//****************************************************************//
//		FUNCTION TO DELETE A RECORD FROM FILE		  //
//****************************************************************//

void delete_ac()
{
    int num, pswd, found = 1;
    char confirm = 'n';
    file.open("account.dat", ios::in | ios::binary | ios::app);
    tempfile.open("temp.dat", ios::out | ios::binary | ios::app);
    if (!file)
    {
        cout << "\nERROR!!! FILE COULD NOT BE OPENED";
        cout << "\n\nRESOLVE :- ";
        cout << "\nGo to Main Menu to create a file";
        return;
    }
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\tTO DELETE AN ACCOUNT";
    cout << "\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n\nEnter Account No. of the Customer whose Record is to be Deleted : ";
    cin >> num;
    while (file.read((char *)&ac, sizeof(ac)))
    {
        if (ac.getacno() == num)
        {
            found = 0;
            cout << "\nEnter the Pass Key : ";
            cin >> pswd;
            if (ac.getpass() != pswd)
            {
                cout << "\nWrong Password !!!";
                cout << "\nQuitting !!!";
                goto skip;
            }
            ac.show_ac();
            cout << "\n\nAre you sure, you want to Delete this Record? (y/n) : ";
            cin >> confirm;
        skip:
            if (ac.getpass() != pswd)
                confirm = 'n';
            if (confirm == 'n')
                tempfile.write((char *)&ac, sizeof(ac));
        }
        else
            tempfile.write((char *)&ac, sizeof(ac));
    }
    file.close();
    tempfile.close();
    if (confirm == 'n' && found == 0)
        cout << "\nDeletion Aborted Successfully";
    if (found == 1)
        cout << "\nRecord Not Found in File !!!";
    if (confirm == 'y' && found == 0)
        cout << "\nRecord Deleted Successfully...";
    remove("account.dat");
    rename("temp.dat", "account.dat");
}

//****************************************************************//
//		FUNCTION TO SELECT OPTIONS			  //
//****************************************************************//

void select(int opt)
{
    switch (opt)
    {
    case 1:
        write_ac();
        break;
    case 2:
        deposit_withdraw(1);
        break;
    case 3:
        deposit_withdraw(2);
        break;
    case 4:
        transfer();
        break;
    case 5:
        tloan_ac();
        break;
    case 6:
        ploan_ac();
        break;
    case 7:
        display_ac();
        break;
    case 8:
        display_all();
        break;
    case 9:
        modify_account();
        break;
    case 10:
        delete_ac();
        break;
    case 11:
        finish();
        exit(0);

    default:
        cout << "\n\tInvalid Option !!!";
        cout << "\n\tEXITING....";
        exit(0);
    }
}

//****************************************************************//
//			INTRODUCTORY FUNCTION			  //
//****************************************************************//

void intro()
{
    cout << "\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
    cout << "\n*\tBANKING TRANSACTION SYSTEM\t\t\t*";
    cout << "\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
}

//****************************************************************//
//			FINISHING FUNCTION			  //
//****************************************************************//

void finish()
{
    cout << "\n\n\tTHANKS FOR USING\n\n";
}

//****************************************************************//
//			MAIN FUNCTION OF PROGRAM		  //
//****************************************************************//

int main()
{
    int opt;
    intro();
    do
    {
        cout << "\n\n//=//=//=//=//=//=//=//=//=//=//=//=//=//=//";
        cout << "\n//\t\tMAIN MENU\t\t  //";
        cout << "\n//=//=//=//=//=//=//=//=//=//=//=//=//=//=//";
        cout << "\n\n\t 1>  NEW ACCOUNT";
        cout << "\n\t 2>  DEPOSIT MONEY";
        cout << "\n\t 3>  WITHDRAW MONEY";
        cout << "\n\t 4>  TRANSFER MONEY";
        cout << "\n\t 5>  TAKE LOAN";
        cout << "\n\t 6>  PAY LOAN";
        cout << "\n\t 7>  BALANCE ENQUIRY";
        cout << "\n\t 8>  ACCOUNT HOLDER LIST";
        cout << "\n\t 9>  MODIFY AN ACCOUNT";
        cout << "\n\t10> CLOSE AN ACCOUNT";
        cout << "\n\t11> EXIT";
        cout << "\n\n\tSelect Option (1 to 11)";
        cout << "\n\n\tEnter Your Choice : ";
        cin >> opt;
        select(opt);
    } while (opt != 11);
    finish();

    return 0;
}

//****************************************************************//
//                      END OF PROJECT                            //
//****************************************************************//
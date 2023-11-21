// emply id,name,salary, working hour, ITR file;

#include <iostream>
#include <string>

using namespace std;

class employee
{
private:
    int salary;
    int ITR;

public:
    string name;
    int id;
    int w_h;

    void set_id(int id)
    {
        this->id=id;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_w_h(int w_h)
    {
        this->w_h = w_h;
    }
    void set_salary(int salary)
    {
        this->salary = salary;
        if ((salary * 12) > 700000)
        {
            ITR = 0.10 * salary * 12;
        }
    }
    int get_id()
    {
        return this->id;
    }
    string get_name()
    {
        return this->name;
    }
    int get_w_h()
    {
        return this->w_h;
    }
    int get_salary()
    {
        int s = this->salary;
        return s;
    }
    int get_ITR()
    {
        int itr = this->ITR;
        return itr;
    }
    void print()
    {
        cout << "ID :" << id << "\t Name: " << name << "\t working hours: " << w_h << "\t Salary: " << salary << "\t ITR: " << ITR << endl;
    }
};

int main()
{
    int s,id,wh;
    string name;
    employee e[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter Id: ";
        cin >> id;
        e[i].set_id(id);
        cout << endl
             << "Enter name: ";
        cin >> name;
        e[i].set_name(name);
        cout << endl
             << "Enter working hours: ";
        cin >> wh;
        e[i].set_w_h(wh);
        cout << endl
             << "Enter the Salary: ";
        cin >> s;
        e[i].set_salary(s);
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "ID :" << e[i].get_id() << "\t Name: " <<e[i].get_name()<< "\t working hours: " << e[i].get_w_h() << "\t Salary: " << e[i].get_salary() << "\t ITR: " << e[i].get_ITR() << endl;
        e[i].print();
    }
    return 0;
}
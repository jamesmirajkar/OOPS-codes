//Write the code to display student name, Roll no and Grade of 5 student Write and Display the content of the array


#include<iostream>
#include<string>

using namespace std;

class student
{
private:
    char grade[2];
public:

    string name;
    int roll;

    void set(char g[2])
    {
        strcpy(grade,g);
    }
    void print()
    {
        cout<<"Name: "<<name<<endl<<"Roll no: "<<roll<<endl<<"Grade: "<<grade<<endl;
    }

};

int main()
{
    student s[5];
    char g[2];
    for(int i=0;i<5;i++)
    {
        cout<<"Enter the student name: ";
        cin>>s[i].name;
        cout<<endl<<"Enter Roll no: ";
        cin>>s[i].roll;
        cout<<endl<<"Enter Grade: ";
        cin>>g;
        s[i].set(g);
        cout<<endl<<endl;
    }


    for(int i=0;i<5;i++)
    {
        s[i].print();
    }
    return 0;
}
#include<iostream>

using namespace std;

class cd
{
public:
    cd()
    {
        cout<<"Contrutor"<<endl;
    }
    ~cd()
    {
        cout<<"Destrutor"<<endl;
    }

};
int main()
{
    cd c;

    return 0;
}
#include<iostream>
using namespace std;

class A
{
    
    public: 
    int x;
    int increment()
    {
        return ++this->x;
    }
    void get_data(int x)
    {
        this->x = x;
    }

};

int main()
{
    int x;
    A a;
    cin>>x;
    a.get_data(x);
    cout<<a.increment()<<endl;
    cout<<a.increment()<<endl;
    cout<<a.increment()<<endl;

    return 0;
}
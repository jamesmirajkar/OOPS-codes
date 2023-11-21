// write c++ function 
#include<iostream>

using namespace std;

class distance
{
    private:
        int meter;
        friend int add(distance);
    public:
        //distance::meter(10){}
};

int add(distance d)
{
    d.meter +=5;
    return d.meter;
}
int main()
{
    distance d;
    cout<<add(d);
    return 0;
}

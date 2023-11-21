#include<iostream>
using namespace std;
class car{
    public:
    static int a;
    static void method()
    {
        a = 100;
    }
    int x;

};
int main()
{
    car c1,c2;
    car::method();
    c1.x = 5;
    c2.x = 10;
    cout<<c2.a<<endl;
    return 0;
}
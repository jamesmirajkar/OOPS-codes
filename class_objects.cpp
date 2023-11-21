#include<iostream>
using namespace std;
class car
{
    private:
        int price;
    public:
        string name;
        car(int p):price(p){}
        int getprice()
        {
            return price;
        }
};
int main()
{
    car c1(100);
    c1.name = "lambo";
    cout<<c1.name<<endl;
    cout<<c1.getprice();
    return 0;
}
#include<iostream>
using namespace std;
class car
{
    private:
    int price;
    public:
    string name,color;
    void set_value(int x)
    {
        price = x;
    }
    int get_value()
    {
        return price;
    }
};
int main()
{
    car c1;
    c1.set_value(100);
    cout<<"price : "<<c1.get_value()<<endl;
    return 0;
}
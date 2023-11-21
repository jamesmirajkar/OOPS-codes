#include<iostream>
using namespace std;

class vech
{
    public:
    double fuelcapacity;
};
class bus:public vech
{
    public:
    int Seatcapacity;
};
int main()
{
    bus b;
    b.fuelcapacity = 10.00;
    b.Seatcapacity = 30;
    cout<<b.fuelcapacity<<" "<<b.Seatcapacity<<endl;
    return 0;
}

// we write object name as argument while calling function same way do it for anthor variable 

#include<iostream>
using namespace std;

class square
{
    public:
    double x;
    square(double x)
    {
        this->x = x;
    }
};

void calAverage(square s1)
{
    double sq = s1.x*s1.x;
    cout<<"Square: "<<sq;
}
int main()
{
    square s1(100.00);
    calAverage(s1);

    return 0;
}
#include<iostream>
using namespace std;
class car
{
    public:
    string name,model,color;
    car()
    {
        name = "lambo";
        model  = "Urus V8 turbo";
    }
    private:
    int price=2;//cr
};
int main()
{
    car c1;
    const car c;
    cin>>c1.color;
    cout<<c1.name<<"\t"<<c1.model<<"\t"<<c1.color<<"\t";
    return 0;
}
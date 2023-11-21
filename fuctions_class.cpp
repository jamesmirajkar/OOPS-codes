#include<iostream>
#include<string.h>
using namespace std;
class car{
    public:
    string name,color,model;
    void set_value(string x, string y, string z);
    
};
void car::set_value(string x, string y,string z)
{
    name = x;
    color = y;
    model = z;
}
int main()
{
    car c1;
    c1.set_value("lambo","black","Urus V8 turbo");
    cout<<c1.name<<c1.model<<c1.color;
    return 0;
}
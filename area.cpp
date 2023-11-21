#include <iostream>
using namespace std;
class room
{
private:
    int l, b;

public:
    void set_l(int l)
    {
        this->l = l;
    }
    void set_b(int b)
    {
        this->b = b;
    }
    int get_l()
    {
        int l = this->l;
        return l;
    }
    int get_b()
    {
        int b = this->b;
        return b;
    }
    int area()
    {
        return l*b;
    }
    int perimeter()
    {
        return 2*(l+b);
    }               
};

int main()
{
    room r;
    
    r.set_l(10);
    r.set_b(10);
    cout<<"Area: "<<r.area()<<endl;
    cout<<"Perimeter: "<<r.perimeter()<<endl;

    return 0;
}
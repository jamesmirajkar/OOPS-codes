#include <iostream>
using namespace std;

class shape
{
protected:
    float width, height;
public:
    void setheight(int x)
    {
        this->height = x;
    }
    void setwidth(int y)
    {
        this->width = y;
    }
};
class rectangle:public shape
{
public:
float getArea()
{
    return height*width;
}
};

int main()
{
    rectangle r;
    r.setheight(10);
    r.setwidth(20);
    cout<<"Area: "<<r.getArea()<<endl;
    return 0;
}
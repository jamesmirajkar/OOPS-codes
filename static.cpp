#include<iostream>
using namespace std;
class myclass
{
    public:
        int x;
        static int y;
        void setx(int x)
        {
            this->x = x;
        }
        int getx()
        {
            return x;
        }
};
int myclass::y = 20;
int main()
{
    myclass a;
    a.setx(10);
    cout<<a.getx()<<endl;
    cout<<a.y<<endl;
}
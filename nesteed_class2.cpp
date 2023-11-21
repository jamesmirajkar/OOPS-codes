//Write c++ program to demostrate as nested class public member inner class
#include<iostream>

using namespace std;

class A
{
    public:
    class B
    {
        public:
            void print()
            {
                cout<<"Nested class"<<endl;
            }
    };
    B n;
        void show()
        {
            n.print();
        }
};

int main()
{
    A enc;
    enc.show();

    return 0;
}
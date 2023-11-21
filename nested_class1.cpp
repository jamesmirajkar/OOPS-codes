// Write the c++ code to demostrate nested class as private member of inner class


#include<iostream>
using namespace std;

class A
{
    private:
    class B
    {
        public:
            void print()
            {
                cout<<"Nested class"<<endl;
            }
    };
    B n;
    public:
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
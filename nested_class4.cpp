////Define the nested class using scope visiblity

#include <iostream>
#include <string>
using namespace std;
class A
{
public:
    class B
    {
    public:
        void print_A()
        {
            cout << "Nested A" << endl;
        }
    };

    class C
    {
    public:
        void print_B()
        {
            cout << "Nested B" << endl;
        }
    };
};

int main()
{

    A::B b;
    A::C c;

    b.print_A();
    c.print_B();

    return 0;
}

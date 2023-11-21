// using inline function create class member addition , sub,mul and div

#include <iostream>
using namespace std;

class mathsUtility
{
public:
    float a, b;
    inline void add()
    {
        cout << "SUM: " << a + b<<endl;
    }
    inline void sub()
    {
        cout << "SUB: " << a - b<<endl;
    }
    inline void MUL()
    {
        cout << "MUL: " << a * b<<endl;
    }
    inline void DIV()
    {
        if (b != 0)
        {
            cout << "DIV: " << a / b<<endl;
        }
    }
};
int main()
{
    mathsUtility m;
    m.a = 10.00;
    m.b = 8.00;
    m.add();
    m.sub();
    m.MUL();
    m.DIV();
    return 0;
}
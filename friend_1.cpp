// write c++ prorgam to add two differnent

#include <iostream>
using namespace std;
class classB
class classA
{
private:
    int numA;
    friend int add(classA, classB);
public:
    classA :: numsA(15) {}
};
class classB
{

private:
    int numB;
    friend int add(classA, classB);
public:
    classB :: numsB(15) {}
};
int add(classA A, classB B)
{
    return (A.numA + B.numB);
}

int main()
{
    classA a;
    classB b;
    cout << "Sum: " << add(a, b);
    return 0;
}
// static number create in class is not instancsited when created of the class;
// if u delared the outside of class a static keyword is used to define elements of static storage class
// static memeber in c++ delared inside a class but outside class using scope resolution operator 

//Write c++ program to demostrate how static member can be accessed using help of static member function

#include<iostream>
using namespace std;

class A
{
    static int x;
    public: 
    static int increment()
    {
        return ++x;
    }

};
int A::x = 10;
int main()
{
    A a;
    cout<<a.increment();
    
    return 0;
}
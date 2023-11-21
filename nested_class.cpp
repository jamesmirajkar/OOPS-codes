// A nested class can be delacred as protecte, public and private, internal , internal protected and allowed to create inner class 
//your allowed to access the inner clas 
//innner class can access static memeber in outer class 


//Write c++ problem to demostrate how memeber class can access and class member of inner class(anclosing class)



#include<iostream>

using namespace std;
class A
{
    public:
    int b;


    class B
    {
        void print(A*a)
        {
            cout<<a->b;
        }
    };

};


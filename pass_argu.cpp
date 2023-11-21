// we write object name as argument while calling function same way do it for anthor variable 

#include<iostream>
using namespace std;

class student
{
    public:
    double marks;
    student(double m)
    {
        marks = m;
    }
};

void calAverage(student s1,student s2)
{
    double avg = (s1.marks + s2.marks)/2.00;
    cout<<"avg: "<<avg;
}
int main()
{
    student s1(100.00),s2(50.000);
    calAverage(s1,s2);

    return 0;
}
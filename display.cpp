#include<iostream>
using namespace std;


class integer
{
    private:
        int d;
    public:
    void set(int data)
    {
        this->d = data;
    }
    int get()
    {
        int data = this->d;
        return data;
    }
};
int main()
{
    integer i;
    i.set(10);
    cout<<i.get()<<endl;
    return 0;
}
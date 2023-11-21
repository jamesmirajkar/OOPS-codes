#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    a.push_back(10);
    cout<<a.capacity()<<endl;

    return 0;
}
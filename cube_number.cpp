#include <iostream>
using namespace std;


class cube
{
public:
    double x;
    double get_cube()
    {
        return x * x * x;
    }
};
int main()
{
    cube c;
    c.x = 10;
    cout << "Cube: " << c.get_cube() << endl;
    return 0;
}
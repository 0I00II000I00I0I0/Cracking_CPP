//捕获除零异常
#include <iostream>
using namespace std;

double Division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}

int main()
{
    int x = 9;
    int y = 0;
    double z = 0;

    try {
        z = Division(x, y);
        cout << z << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}

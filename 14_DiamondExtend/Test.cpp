#include "Vehicle.h"
#include <iostream>
using namespace  std;

int main()
{
    CFlyingCar flyingCar(100, 300);
    cout << flyingCar.m_nNumber << endl; //非虚继承下m_nNumber不明确
    cout << flyingCar.m_nMaxSpeed << endl; //非虚继承下m_nMaxSpeed不明确
    // cout << flyingCar.CTravelTool::m_nNumber << endl;
    // cout << flyingCar.CTravelTool::m_nMaxSpeed << endl;

    flyingCar.Start();
    flyingCar.CCar::Start();

    return 0;
}


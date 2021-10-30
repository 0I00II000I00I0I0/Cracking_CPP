#include "Vehicle.h"
#include <iostream>
using namespace std;

CTravelTool::CTravelTool(int nNumber, int nMaxSpeed) :m_nNumber(nNumber), m_nMaxSpeed(nMaxSpeed)
{
}
CTravelTool::~CTravelTool()
{
}

CCar::CCar(int nNumber, int nMaxSpeed) :CTravelTool(nNumber, nMaxSpeed)
{
}
CCar::~CCar()
{
}
void CCar::Start()
{
    cout << "car start" << endl;
}
void CCar::Stop()
{
    cout << "car stop" << endl;
}

CPlane::CPlane(int nNumber, int nMaxSpeed) : CTravelTool(nNumber, nMaxSpeed)
{
}
CPlane::~CPlane()
{
}
void CPlane::Start()
{
    cout << "plane start" << endl;
}
void CPlane::Stop()
{
    cout << "plane stop" << endl;
}

//CFlyingCar::CFlyingCar(int nNumber, int nMaxSpeed) :CCar(nNumber, nMaxSpeed), CPlane(nNumber, nMaxSpeed)
//{
//}
CFlyingCar::CFlyingCar(int nNumber, int nMaxSpeed) :CTravelTool(nNumber, nMaxSpeed), CCar(nNumber, nMaxSpeed), CPlane(nNumber, nMaxSpeed)
{
}
CFlyingCar::~CFlyingCar()
{
}
void CFlyingCar::Start()
{
    cout << "flyingCar start" << endl;
}
void CFlyingCar::Stop()
{
    cout << "flyingCar stop" << endl;
}

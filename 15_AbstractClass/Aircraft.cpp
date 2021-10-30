#include "Aircraft.h"

CAircraft::CAircraft()
{
}
CAircraft::~CAircraft()
{
}
void CAircraft::Refuel()
{
    cout << "通用燃油" << endl;
}
void FlyMode()
{
    cout << "停止起飞" << endl;
}

CHelicopter::CHelicopter()
{
}
CHelicopter::~CHelicopter()
{
}
void CHelicopter::FlyMode()
{
    cout << "山地打击" << endl;
}

CFighter::CFighter()
{
}
CFighter::~CFighter()
{
}
void CFighter::Refuel()
{
    cout << "航空煤油" << endl;
}
void CFighter::FlyMode()
{
    cout << "高空巡航" << endl;
}

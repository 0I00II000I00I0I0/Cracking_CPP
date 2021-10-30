#include <iostream>
#include "Aircraft.h"

class CPilot
{
public:
    CPilot();
    ~CPilot();
    void RefuelPlane(CAircraft* pAircraft);
    void DrivePlane(CAircraft* pAircraft);
};
CPilot::CPilot()
{
}
CPilot::~CPilot()
{
}
void CPilot::RefuelPlane(CAircraft* pAircraft)
{
    pAircraft->Refuel();
}
void CPilot::DrivePlane(CAircraft* pAircraft)
{
    pAircraft->FlyMode();
}

int main()
{
    CPilot pilot;
    CAircraft* Z20 = new CHelicopter;
    CAircraft* J20 = new CFighter;

    pilot.RefuelPlane(Z20);
    pilot.DrivePlane(Z20);
    pilot.RefuelPlane(J20);
    pilot.DrivePlane(J20);
    return 0;
}

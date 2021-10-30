#pragma once
#include <iostream>
using namespace std;

class CAircraft
{
public:
    CAircraft();
    ~CAircraft();
    virtual void Refuel();// 加燃油，虚函数
    virtual void FlyMode() = 0;// 飞行方式，纯虚函数
};

class CHelicopter :public CAircraft
{
public:
    CHelicopter();
    ~CHelicopter();
    void FlyMode();
};

class CFighter :public CAircraft
{
public:
    CFighter();
    ~CFighter();
    void Refuel();
    void FlyMode();
};

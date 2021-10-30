#pragma once
//出行工具
class CTravelTool
{
public:
    CTravelTool(int nNumber = 0, int nMaxSpeed = 0);
    ~CTravelTool();
public:
    int m_nNumber;
    int m_nMaxSpeed;
};
//汽车
class CCar :virtual public CTravelTool
{
public:
    CCar(int nNumber = 0, int nMaxSpeed = 0);
    ~CCar();
    void Start();
    void Stop();
};
//飞机
class CPlane :virtual public CTravelTool
{
public:
    CPlane(int nNumber = 0, int nMaxSpeed = 0);
    ~CPlane();
    void Start();
    void Stop();
};
//飞行汽车
class CFlyingCar :public CCar, public CPlane
{
public:
    CFlyingCar(int nNumber = 0, int nMaxSpeed = 0);
    ~CFlyingCar();
    void Start();
    void Stop();
};

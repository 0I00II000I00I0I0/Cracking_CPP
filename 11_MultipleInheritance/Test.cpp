#include "SofeBed.h"
#include <iostream>
using namespace std;

//直接定义可折叠沙发床的类
class CSoftBed
{
public:
    CSoftBed(double dbWeight = 0);
    ~CSoftBed();
    double GetWeight();
    CSoft GetSoft();
    CBed GetBed();
    void Function();

private:
    double m_dbWeigth;
    CSoft m_soft;
    CBed m_bed;
};

CSoftBed::CSoftBed(double dbWeight) :m_soft(0), m_bed(0), m_dbWeigth(dbWeight)
{
}
CSoftBed::~CSoftBed()
{
}
double CSoftBed::GetWeight()
{
    return m_dbWeigth;
}
CSoft CSoftBed::GetSoft()
{
    return m_soft;
}
CBed CSoftBed::GetBed()
{
    return m_bed;
}
void CSoftBed::Function()
{
    cout << "Sit and Lie" << endl;
}

int main()
{
    //使用多重继承
    CSoftbed softbed(1);
    //cout << softbed.m_dbWeigth << endl; //m_dbWeigth不明确
    cout << softbed.CSoft::m_dbWeigth << endl;
    cout << softbed.CBed::m_dbWeigth << endl;
    softbed.Function();
    softbed.CSoft::Function();
    softbed.CBed::Function();

    //直接使用类
    CSoftBed softBed(9);
    cout << softBed.GetWeight() << endl;
    cout << softBed.GetSoft().m_dbWeigth << endl;
    cout << softBed.GetBed().m_dbWeigth << endl;
    softBed.Function();
    softBed.GetSoft().Function();
    softBed.GetBed().Function();

    return 0;
}

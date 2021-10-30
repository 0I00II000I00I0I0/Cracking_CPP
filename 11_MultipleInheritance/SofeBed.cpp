#include "SofeBed.h"
#include <iostream>
using namespace std;

CSoft::CSoft(double dbWeight) :m_dbWeigth(dbWeight)
{
}
CSoft::~CSoft()
{
}
void CSoft::Function()
{
    cout << "Sit" << endl;
}

CBed::CBed(double dbWeight) :m_dbWeigth(dbWeight)
{
}
CBed::~CBed()
{
}
void CBed::Function()
{
    cout << "Lie" << endl;
}

CSoftbed::CSoftbed(double dbWeight) : CSoft(dbWeight), CBed(dbWeight)
{
}
CSoftbed::~CSoftbed()
{
}
void CSoftbed::Function()
{
    cout << "Sit and Lie" << endl;
}


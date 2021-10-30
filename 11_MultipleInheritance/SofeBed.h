#pragma once

//多重继承实现可折叠沙发床
class CSoft
{
public:
    CSoft(double dbWeight = 0);
    ~CSoft();
    void Function();
public:
    double m_dbWeigth;
};

class CBed
{
public:
    CBed(double dbWeight = 0);
    ~CBed();
    void Function();
public:
    double m_dbWeigth;
};

class CSoftbed :public CSoft, public CBed
{
public:
    CSoftbed(double dbWeight = 0);
    ~CSoftbed();
    void Function();
};

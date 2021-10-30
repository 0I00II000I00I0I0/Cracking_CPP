#pragma once

class CAnimal
{
public:
    CAnimal(int nAge = 0, int dbWeight = 0);
    ~CAnimal();
    void EatAndDrink();
    void Sleep();
    void ShowInfo();

protected:
    int m_nAge;
    int m_dbWeight;
};

class CDog :public CAnimal
{
public:
    CDog(int nAge = 0, int dbWeight = 0, char* szBelong = (char*)"canine");
    ~CDog();
    void SetBelong(char* szBelong);
    char* GetBelong();
    void Bark();
    void ShowInfo();

private:
    char m_szBelong[128];
};

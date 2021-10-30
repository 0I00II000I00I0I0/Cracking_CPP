//定义一个复数类，使用运算符重载实现复数的加法运算
#include <iostream>
using namespace std;

class CComplex
{
public:
    CComplex();
    CComplex(double real, double imag);
public:
    //声明运算符重载
    CComplex operator+(const CComplex& A) const;
    void Display() const;
    //重载输入运算符
    friend istream& operator>>(istream& in, CComplex& C);
    //重载输出运算符
    friend ostream& operator<<(ostream& out, CComplex& C);
private:
    double m_dbReal; //实部
    double m_dbImag; //虚部
};

CComplex::CComplex() : m_dbReal(0.0), m_dbImag(0.0) { }

CComplex::CComplex(double real, double imag) : m_dbReal(real), m_dbImag(imag) { }
//实现运算符重载
CComplex CComplex::operator+(const CComplex& A) const
{
    return CComplex(this->m_dbReal + A.m_dbReal, this->m_dbImag + A.m_dbImag);
}

void CComplex::Display() const
{
    cout << m_dbReal << " + " << m_dbImag << "i" << endl;
}

istream& operator>>(istream& in, CComplex& C)
{
    in >> C.m_dbReal >> C.m_dbImag;
    return in;
}

ostream& operator<<(ostream& out, CComplex& C)
{
    out << C.m_dbReal << " + " << C.m_dbImag << "i" << endl;
    return out;
}


int main()
{
    CComplex c1(1.1, 2.2);
    CComplex c2(2.2, 1.1);
    CComplex c3 = c1 + c2;
    c3.Display();

    cin >> c1 >> c2;
    c3 = c1 + c2;
    cout << c3 << endl;

    return 0;
}

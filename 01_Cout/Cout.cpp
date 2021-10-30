#include <iostream>
using namespace std;

int main()
{
    //1、以八进制输入输出整数 2、以十进制输入输出整数 3、以十六进制输入输出整数
    int nNum = 99;
    cout << "oct=" << oct << nNum << endl;
    cout << "dec=" << dec << nNum << endl;
    cout << "hex=" << hex << nNum << endl;
    cout.unsetf(ios::hex);

    //2、将浮点数分别以整型，单(双)精度浮点，科学表示法输出
    float fNum = 123.456f;
    cout << "dec=" << dec << fNum << endl;
    cout << "fixed=" << fixed << fNum << endl;
    cout << "scientific=" << scientific << fNum << endl;
    cout.unsetf(ios::scientific);

    cout.setf(ios::oct, ios::basefield);
    cout << "oct=" << nNum << endl;
    cout.setf(ios::dec, ios::basefield);
    cout << "dec=" << nNum << endl;
    cout.setf(ios::hex, ios::basefield);
    cout << "hex=" << nNum << endl;
    cout.unsetf(ios::hex);

    cout.setf(ios::oct);
    cout << "oct=" << fNum << endl;
    cout.unsetf(ios::oct);
    cout.setf(ios::fixed);
    cout << "fixed=" << fNum << endl;
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific);
    cout << "scientific=" << fNum << endl;
    cout.unsetf(ios::scientific);

    //3、用cout输出类似printf格式化浮点数为整形的方式
    double dbNum = 123.456f;
    printf("printf=%d\n", dbNum);
    cout.setf(ios::dec, ios::basefield);
    cout << "coutdec=" << *(int*)&dbNum << endl;

    //4、实现浮点数的指数格式和定点格式的输入输出，并制定精度
    cout.setf(ios::oct);
    cout.precision(2);
    cout << "fixed=" << fixed << fNum << endl;
    cout << "scientific=" << scientific << fNum << endl;

    //5、将Ascii码表分别以十进制，字符，十六进制，八进制输出
    int nCount = 0;
    for (int i = 32; i < 127; i++)
    {
        cout << char(i) << " ";
        nCount++;
        if (nCount % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;

    // 6、把字符串读入字符型数组变量中并且显示，要求空格也要全部读入
    char szBuff[256] = { 0 };
    cin.getline(szBuff, sizeof(szBuff));
    cout << "szBuf:\n" << szBuff << endl;

    return 0;
}


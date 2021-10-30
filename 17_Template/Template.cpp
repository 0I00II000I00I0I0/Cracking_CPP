#include <iostream>
using namespace std;

template<typename T> void Swap(T& NumberA, T& NumberB)
{
    T temp = NumberA;
    NumberA = NumberB;
    NumberB = temp;
}

template <typename T> class CArray
{
    int size; //数组元素的个数
    T* ptr; //指向动态分配的数组
public:
    CArray(int s = 0);  //s代表数组元素的个数
    CArray(CArray& a);
    ~CArray();
    T length();
    T& operator[](int i); //用以支持根据下标访问数组元素
    CArray& operator=(const CArray& a); //用于数组对象间的赋值
    void push_back(const T& v); //用于在数组尾部添加一个元素v 
};

template<typename T>
T CArray<T>::length()
{
    return size;
}

template<typename T>
T& CArray<T>::operator[](int i)
{
    return ptr[i];
}

template<class T>
CArray<T>::CArray(int s) :size(s)
{
    if (s == 0)
    {
        ptr = NULL;
    }
    else
    {
        ptr = new T[s];
    }
}

template<class T>
CArray<T>::CArray(CArray& a)
{
    if (!a.ptr)
    {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new T[a.size];
    memcpy(ptr, a.ptr, sizeof(T) * a.size);
    size = a.size;
}

template <class T>
CArray<T>::~CArray()
{
    if (ptr)
    {
        delete[] ptr;
    }
    size = 0;
}

template <class T>
CArray<T>& CArray<T>::operator=(const CArray& a)
{
    if (this == &a)
    {
        return *this;
    }
    if (a.ptr == NULL)
    {
        if (ptr)
        {
            delete[] ptr;
        }
        ptr = NULL;
        size = 0;
        return *this;
    }
    if (size < a.size)
    {
        if (ptr)
        {
            delete[] ptr;
        }
        ptr = new T[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(T) * a.size);
    size = a.size;
    return *this;
}

template <class T>
void CArray<T>::push_back(const T& v)
{
    if (ptr)
    {
        T* tmpPtr = new T[size + 1]; //重新分配空间
        memcpy(tmpPtr, ptr, sizeof(T) * size); //拷贝原数组内容
        delete[] ptr;
        ptr = tmpPtr;
    }
    else
    {
        ptr = new T[1];
    }
    ptr[size++] = v;
}

int main()
{
    //交换 int 变量的值
    int n1 = 8;
    int n2 = 9;
    Swap(n1, n2);
    cout << "n1=" << n1 << " n2=" << n2 << endl;

    //交换 float 变量的值
    float f1 = 8.8;
    float f2 = 9.9;
    Swap(f1, f2);
    cout << "f1=" << f1 << " f2=" << f2 << endl;

    CArray<int> a;
    for (int i = 0; i < 6; ++i)
    {
        a.push_back(i);
    }
    for (int i = 0; i < a.length(); ++i)
    {
        cout << a[i] << " ";
    }

    return 0;
}

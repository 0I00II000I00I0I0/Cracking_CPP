#include "Animal.h"
/*
多态：
1、不同继承关系中的类对象，去调用同一函数，产生不同的行为。
2、具体来说，有一对继承关系的两个类，这两个类里面都有一个函数且名字、参数、返回值相同，通过调用这个函数来实现不同类对象完成不同的事件。
构成多态条件：
1、调用函数的对象必须是指针或者引用。
2、被调用的函数必须是虚函数，且完成了虚函数的重写。

将析构函数定义为虚函数的原因：
因为基类指针可能指向派生类，当delete的时候，如果不定为虚函数，系统会直接调用基类的析构函数，这个时候派生类就有一部分没有被释放，就会造成可怕的内存泄漏问题。
若定义为虚函数构成多态，那么就会先调用派生类的析构函数，然后派生类的析构函数会自动调用基类的析构函数。
*/
int main()
{
    CAnimal* pAnimal = new CAnimal(5, 9);
    pAnimal->ShowInfo();
    pAnimal->EatAndDrink();
    pAnimal->Sleep();

    CDog* pDog = new CDog(6, 8, (char*)"canine");
    pDog->ShowInfo();
    pDog->EatAndDrink();
    pDog->Sleep();

    pAnimal = pDog;
    pAnimal->ShowInfo();
    pAnimal->EatAndDrink();
    pAnimal->Sleep();

    CDog* dog = (CDog*)(new CAnimal);//错误的定义
    dog->Bark();

    return 0;
}

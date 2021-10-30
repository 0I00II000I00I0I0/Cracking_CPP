/*
1、public（公有的）：可以通过对象访问
2、private（私有的）：在类的外部不能通过对象访问
3、protected（受保护的）：基类中的 protected 成员可以在派生类中使用
在类的内部（定义类的代码内部）
无论成员被声明为 public、protected 还是 private，都是可以互相访问的，没有访问权限的限制。
在类的外部（定义类的代码之外）
只能通过对象访问成员，并且通过对象只能访问 public 属性的成员，不能访问 private、protected 属性的成员。

1) public继承方式
基类中所有 public 成员在派生类中为 public 属性；
基类中所有 protected 成员在派生类中为 protected 属性；
基类中所有 private 成员在派生类中不能使用。
2) protected继承方式
基类中的所有 public 成员在派生类中为 protected 属性；
基类中的所有 protected 成员在派生类中为 protected 属性；
基类中的所有 private 成员在派生类中不能使用。
3) private继承方式
基类中的所有 public 成员在派生类中均为 private 属性；
基类中的所有 protected 成员在派生类中均为 private 属性；
基类中的所有 private 成员在派生类中不能使用。
*/

#include <iostream>
using namespace std;
#include "Animal.h"
#include "Shape.h"

int main()
{
    CAnimal animal;
    animal.ShowInfo();
    animal.EatAndDrink();
    animal.Sleep();

    CDog DogA;
    DogA.ShowInfo();
    DogA.CAnimal::ShowInfo();
    CDog DogB(3, 6, (char*)"canine");
    DogB.ShowInfo();
    DogB.EatAndDrink();
    DogB.Sleep();
    DogB.Bark();

    CPoint point(1, 1);
    point.ShowPoint();
    C3DPoint point3(3, 3, 3);
    point3.ShowPoint();

    CLine line(point, CPoint(7, 9));
    cout << "linelength:" << line.GetLength() << endl;
    CRectangle rectangle(CPoint(0, 0), CPoint(9, 9));
    cout << "lengthline and widthline:" << rectangle.GetLengthLine() << " " << rectangle.GetWidthLine() << endl;
    cout << "areaofrectangle:" << rectangle.AreaOfRectangle() << endl;

    return 0;
}

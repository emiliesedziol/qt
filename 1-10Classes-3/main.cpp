#include <iostream>
#include "rectangle.h"
#include "para.h"
#include "square.h"

using namespace std;

int main()
{
    Rectangle r;
    Rectangle r1(2,6);
    Para p (30, 30, 30);
    Square s (40);

    cout << "The area of the rectangle is " << r.getArea() << endl;

    cout << endl;

    cout << "The area of the rectangle is " << r1.getArea() << endl;
    cout << endl;

    cout << "The volume is " << p.getVolume() << endl;
    cout << endl;

    cout << "The area of the square is " << s.getArea() << endl;
    cout << endl;
    cout << "End!" << endl;
    return 0;
}

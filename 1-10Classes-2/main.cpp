#include <iostream>

using namespace std;

class Rectangle {

 public:
    // define a public constructor
    Rectangle();
    Rectangle(int w, int l);

    void setWidth( int width ) {
        this->width = width;
    }
    // or the set can be defined outside the class
    void setLength( int length );

    int getArea() {
        return width * length;
    }

public:
    int width;
    int length;
};
Rectangle::Rectangle() {
    clog << "default constructor call " << endl;
    this->length = 5;
    this->width = 10;
}
/*
Rectangle::Rectangle(int w, int l){
    clog << "custom constructor called" << endl;
    this->width = w;
    this->length = l;
}
*/
Rectangle::Rectangle(int w, int l):width(w), length(l) {
    clog << "custom constructor called" << endl;
}
// functions inside classes are methods
void Rectangle::setLength(int length) {
    this->length = length;
}

//para class
class Para
{
public:
    Para(int w, int l, int h):r(w,l),height(h)
    {
        cout<< "Para constructor called" << endl;
    }

    int getVolume()
    {
        return r.getArea() * height;
    }

 private:
    Rectangle r;
    int height;
}

int main()
{
    Rectangle r;
    Rectangle r1(2,6);
    Para p (30, 30, 30);
/*    r.setWidth(10);
    r.setLength(20);
    the set is no longer needed because of the constructor
    */
    cout << "The area of the rectangle is " << r.getArea() << endl;

    cout << endl;

    cout << "The area of the rectangle is " << r1.getArea() << endl;
    cout << endl;

    cout << "The volume is " << p.getVolume() << endl;
    cout << endl;
    cout << "End!" << endl;
    return 0;
}

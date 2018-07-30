#include <iostream>
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle() {
    clog << "default constructor call " << endl;
    this->length = 5;
    this->width = 10;
}

Rectangle::Rectangle(int w, int l):width(w), length(l) {
    clog << "custom constructor called" << endl;
}
void Rectangle::setWidth(int width)
{
    this->width = width;
}
void Rectangle::setLength(int length) {
    this->length = length;
}

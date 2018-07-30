#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {

 public:
    // define a public constructor
    Rectangle();
    Rectangle(int w, int l);

    void setWidth( int width );

    void setLength( int length );

    int getArea() {
        return width * length;
    }

public:
    int width;
    int length;
};

#endif // RECTANGLE_H

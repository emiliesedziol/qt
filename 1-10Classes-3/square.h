#ifndef SQUARE_H
#define SQUARE_
#include "rectangle.h"


// Square extends Rectangle
class Square : public Rectangle
{
public:
    Square( int side ) : Rectangle(side, side)
    {

    }

};

#endif // SQUARE_H

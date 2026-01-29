#ifndef SHAPE_H
#define SHAPE_H

#include "Vector2D.h"

class Shape
{
protected:
    Vector2D center;
    float area;

public:
    Shape() : center(0, 0)
    {
    }

    Shape(const Vector2D& center) : center(center)
    {
    }

    const float getArea() const { return this->area; };
    const Vector2D getCenter() const { return this->center; };
};


#endif

#include "Point.hpp"

#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(const float x, const float y) : x(x), y(y)
{}

Point::Point(const Point &other) : x(other.x), y(other.y)
{}

Point &Point::operator=(const Point &other)
{
 // Nothing to assign here, as x and y are const members
	return *this;
}

Point::~Point()
{}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}



#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate barycentric coordinates
    Fixed detT = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());
    Fixed alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / detT;
    Fixed beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / detT;
    Fixed gamma = Fixed(1) - alpha - beta;

    // Check if the point is inside the triangle
    return (alpha >= 0 && beta >= 0 && gamma >= 0);
}

int main( void ) {
	// Create points for the triangle vertices and the point to check
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);
    Point pointToCheck(2, 2);

    // Check if the point is inside the triangle
    if (bsp(a, b, c, pointToCheck))
    {
        std::cout << "Point is inside the triangle." << std::endl;
    }
    else
    {
        std::cout << "Point is outside the triangle." << std::endl;
    }

    return 0;
}

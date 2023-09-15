
#include "Fixed.hpp"

Fixed::Fixed() :rawBits(0) //initialization list, prefarable.
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed	&Fixed::operator=(const Fixed &copy2)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(copy2.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

void Fixed::setRawBits( int const raw )
{
	this->rawBits = raw;
}

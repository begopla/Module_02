
#include "Fixed.hpp"

Fixed::Fixed() :rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	this->setRawBits(copy.getRawBits());
	std::cout << "Copy constructor called" << std::endl;
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
	return (rawBits);
}

void Fixed::setRawBits( int const raw )
{
	this->rawBits = raw;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = (x << fractBits);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(num * (1 << fractBits));
}

float Fixed::toFloat( void ) const
{
	return ((float)(rawBits) / (1 << fractBits));
}

int Fixed::toInt( void ) const
{
	return (rawBits >> fractBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}


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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//Overloaded Operators

Fixed	&Fixed::operator=(const Fixed &copy2)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(copy2.getRawBits());
	return (*this);
}
//Overload Comparison Operators -ex02

bool	Fixed::operator>(Fixed num)const
{
	return (this->toFloat() > num.toFloat());
}

bool	Fixed::operator<(Fixed num)const
{
	return (this->toFloat() < num.toFloat());
}

bool	Fixed::operator>=(Fixed num)const
{
	return (this->toFloat() >= num.toFloat());
}

bool	Fixed::operator<=(Fixed num)const
{
	return (this->toFloat() <= num.toFloat());
}

bool	Fixed::operator==(Fixed num)const
{
	return (this->toFloat() == num.toFloat());
}

bool	Fixed::operator!=(Fixed num)const
{
	return (this->toFloat() != num.toFloat());
}

// Overloaded Arithmetic Operators -ex02

float	Fixed::operator+(Fixed num)const
{
	return (this->toFloat() + num.toFloat());
}

float	Fixed::operator-(Fixed num)const
{
	return (this->toFloat() - num.toFloat());
}

float	Fixed::operator*(Fixed num)const
{
	return (this->toFloat() * num.toFloat());
}

float	Fixed::operator/(Fixed num)const
{
	return (this->toFloat() / num.toFloat());
}

// Overloaded pre-increment Operators -ex02
	//modify the object's value and then return the updated object
Fixed	Fixed::operator++()
{
	rawBits++;
	return(*this);
}

Fixed	Fixed::operator--()
{
	rawBits--;
	return(*this);
}

// Overloaded post-increment Operators -ex02
	// modify the object's value, but it should return a copy of the object's original value
		//before the increment.
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++rawBits;
	return(tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--rawBits;
	return(tmp);
}

//Public Methods
float Fixed::toFloat( void ) const
{
	return ((float)(rawBits) / (1 << fractBits));
}

int Fixed::toInt( void ) const
{
	return (rawBits >> fractBits);
}

Fixed &Fixed::min(Fixed &firstNum, Fixed &secondNum)
{
	if (firstNum.toFloat() <= secondNum.toFloat())
		return(firstNum);
	else
		return (secondNum);
}
const Fixed &Fixed::min(Fixed const &firstNum, Fixed const &secondNum)
{
	if (firstNum.toFloat() <= secondNum.toFloat())
		return(firstNum);
	else
		return (secondNum);
}
Fixed &Fixed::max(Fixed &firstNum, Fixed &secondNum)
{
	if (firstNum.toFloat() >= secondNum.toFloat())
		return(firstNum);
	else
		return (secondNum);
}
const Fixed &Fixed::max(Fixed const &firstNum, Fixed const &secondNum)
{
	if (firstNum.toFloat() >= secondNum.toFloat())
		return(firstNum);
	else
		return (secondNum);
}

//Getter and setters
int Fixed::getRawBits( void ) const
{
	return (rawBits);
}

void Fixed::setRawBits( int const raw )
{
	this->rawBits = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

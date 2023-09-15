#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int				rawBits;
		static const	int	fractBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int x);
		Fixed(const float num);
		~Fixed();
		Fixed	&operator=(const Fixed &copy2);
		//Comparison operators
		bool	operator>(Fixed num)const;
		bool	operator<(Fixed num)const;
		bool	operator>=(Fixed num)const;
		bool	operator<=(Fixed num)const;
		bool	operator==(Fixed num)const;
		bool	operator!=(Fixed num)const;
		// Overloaded Arithmetic Operators
		float	operator+(Fixed num)const;
		float	operator-(Fixed num)const;
		float	operator*(Fixed num)const;
		float	operator/(Fixed num)const;
		//Overloaded pre-increment Operators
		Fixed	operator++();
		Fixed	operator--();
		//Overloaded post-increment Operators
		Fixed	operator++(int);
		Fixed	operator--(int);
		//Public methods
		float toFloat( void ) const;
		int toInt( void ) const;
		static	Fixed &min(Fixed &firstNum, Fixed &secondNum);
		static	const Fixed &min(Fixed const &firstNum, Fixed const &secondNum);
		static	Fixed &max(Fixed &firstNum, Fixed &secondNum);
		static	const Fixed &max(Fixed const &firstNum, Fixed const &secondNum);
		//Getters and setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif

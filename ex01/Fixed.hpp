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
		Fixed	&operator=(const Fixed &copy2);
		//from here ex01
		Fixed(const int x);
		Fixed(const float num);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		//from here ex01
		float toFloat( void ) const;
		int toInt( void ) const;
	};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif

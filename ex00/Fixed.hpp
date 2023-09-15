#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// CANONIC FORM
// Class containing at least:
// 1) Constructor default
// 2) Copy constructor
// 3) '=' Operator overload
// 4) Destructor (virtual!)

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &copy2);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int				rawBits;
		static const	int	fractBits = 8;
	};



#endif

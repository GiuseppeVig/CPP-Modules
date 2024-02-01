#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int                 fixedPoint;
	static const int    bits = 8;
public:
	Fixed(const int value);
	Fixed(const float number);
	Fixed(void);
	Fixed(const Fixed &point);
	Fixed &operator=(const Fixed& point);
	~Fixed();
	int     getRawBits(void) const;
	void    setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator<<(std::ostream& out, const Fixed& point);

#endif
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
	bool operator>(const Fixed& point);
	bool operator<(const Fixed& point);
	bool operator>=(const Fixed& point);
	bool operator<=(const Fixed& point);
	bool operator!=(const Fixed& point);
	bool operator==(const Fixed& point);
	Fixed operator*(const Fixed& point);
	Fixed operator+(const Fixed& point);
	Fixed operator-(const Fixed& point);
	Fixed operator/(const Fixed& point);
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	~Fixed();
	int     getRawBits(void) const;
	void    setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed min(Fixed &f1, Fixed &f2);
	static const Fixed& min(const Fixed &f1, const Fixed &f2);
	static Fixed max(Fixed &f1, Fixed &f2);
	static const Fixed& max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream& out, const Fixed& point);

#endif
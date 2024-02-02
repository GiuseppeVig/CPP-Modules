#include "Fixed.hpp"

Fixed::Fixed(void)
{
	fixedPoint = 0;
}

Fixed::Fixed(const int value)
{
	fixedPoint = value << bits;
}

Fixed::Fixed(const float number)
{
	fixedPoint = roundf(number * (1 << bits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &point)
{
	this->setRawBits(point.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& point)
{
	if (this != &point)
		this->fixedPoint = point.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed& point) 
{
	return (this->fixedPoint > point.fixedPoint);
}

bool	Fixed::operator<(const Fixed& point) 
{
	return (this->fixedPoint < point.fixedPoint);
}

bool	Fixed::operator>=(const Fixed& point) 
{
	return (this->fixedPoint >= point.fixedPoint);
}

bool	Fixed::operator<=(const Fixed& point) 
{
	return (this->fixedPoint <= point.fixedPoint);
}

bool	Fixed::operator!=(const Fixed& point) 
{
	return (this->fixedPoint != point.fixedPoint);
}

bool	Fixed::operator==(const Fixed& point) 
{
	return (this->fixedPoint == point.fixedPoint);
}

Fixed Fixed::operator*(const Fixed& point)
{
	return Fixed(this->toFloat() * point.toFloat());
}

Fixed Fixed::operator/(const Fixed& point)
{
	return Fixed(this->toFloat() / point.toFloat());
}

Fixed Fixed::operator+(const Fixed& point)
{
	return Fixed(this->toFloat() + point.toFloat());
}

Fixed Fixed::operator-(const Fixed& point)
{
	return Fixed(this->toFloat() - point.toFloat());
}

Fixed &Fixed::operator++()
{
	this->fixedPoint += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->fixedPoint -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

std::ostream& operator<<(std::ostream& out, const Fixed& point)
{
	out<<point.toFloat()<<std::endl;
	return out;
}

int Fixed::getRawBits(void) const
{
	return fixedPoint;
}

void    Fixed::setRawBits(int const raw)
{
	fixedPoint = raw;
}

float   Fixed::toFloat(void) const
{
	return (float)fixedPoint/(float)(1 << bits);
}

int     Fixed::toInt(void) const
{
	return fixedPoint >> bits;
}

Fixed Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.fixedPoint < f2.fixedPoint)
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.fixedPoint < f2.fixedPoint)
		return f1;
	return f2;
}

Fixed Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.fixedPoint > f2.fixedPoint)
		return f1;
	return f2;
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
		if (f1.fixedPoint > f2.fixedPoint)
		return f1;
	return f2;
}

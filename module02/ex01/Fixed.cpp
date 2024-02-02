#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout<<"Default constructor called"<<std::endl;
	fixedPoint = 0;
}

Fixed::Fixed(const int value)
{
	std::cout<<"Int constructor called"<<std::endl;
	fixedPoint = value << bits;
}

Fixed::Fixed(const float number)
{
	std::cout<<"Float constructor called"<<std::endl;
	fixedPoint = roundf(number * (1 << bits));
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &point)
{
	std::cout<<"Copy constructor called"<<std::endl;
	this->setRawBits(point.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& point)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &point)
		this->fixedPoint = point.getRawBits();
	return (*this);
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

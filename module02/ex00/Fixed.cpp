#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout<<"Default constructor called"<<std::endl;
	fixedPoint = 0;
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

Fixed &Fixed::operator=(const Fixed& point)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &point)
		this->fixedPoint = point.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return fixedPoint;
}

void    Fixed::setRawBits(int const raw)
{
	fixedPoint = raw;
}
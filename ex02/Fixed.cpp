/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:01 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/11 17:29:31 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointVal(0){}

Fixed::Fixed(const int intNum)
{
	this->_fixedPointVal = intNum<<_fractBitNum;
}

Fixed::Fixed(const float& floatNum)
{
	this->_fixedPointVal = floatNum * (1<<_fractBitNum);// times the destination bit = 1 * (2^8) or 256
}

Fixed::Fixed(const Fixed& other)
{
	*this = other; // same as : _fixedPointVal(other._fixedPointVal)
}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_fixedPointVal = other._fixedPointVal;
	return *this;
}

bool Fixed::operator>(const Fixed& other)
{
	return this->_fixedPointVal > other._fixedPointVal;
}

bool Fixed::operator<(const Fixed& other)
{
	return this->_fixedPointVal < other._fixedPointVal;
}

bool Fixed::operator>=(const Fixed& other)
{
	return this->_fixedPointVal >= other._fixedPointVal;
}

bool Fixed::operator<=(const Fixed& other)
{
	return this->_fixedPointVal <= other._fixedPointVal;
}

bool Fixed::operator==(const Fixed& other)
{
	return this->_fixedPointVal == other._fixedPointVal;
}

bool Fixed::operator!=(const Fixed& other)
{
	return this->_fixedPointVal != other._fixedPointVal;
}

Fixed Fixed::operator+(const Fixed& other)
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other)
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other)
{
	return Fixed(this->toFloat() / other.toFloat());
}

/**
 * pre-increment operator, 
 * increase the value of _fixedPointVal and 
 * then return the incremented object.
*/
Fixed& Fixed::operator++()
{
	_fixedPointVal++;
	return *this;
}

/**
 * post-increment operator,
 * save the current state of the object, 
 * increase the value of _fixedPointVal,
 * then return the saved state.
*/
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return temp;
}

/**
 * pre-decrement operator, 
 * increase the value of _fixedPointVal and 
 * then return the incremented object.
*/
Fixed& Fixed::operator--()
{
	_fixedPointVal--;
	return *this;
}

/**
 * post-decrement operator,
 * save the current state of the object, 
 * increase the value of _fixedPointVal,
 * then return the saved state.
*/
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return temp;
}

/**
 * The ternary operator ? : is a shorthand for an if-else statement 
 * that returns one of two values based on a condition. 
 * here it is used to return the smaller of the two Fixed objects.
*/
Fixed& Fixed::min(Fixed& fixedPoint1, Fixed& fixedPoint2)
{
	return (fixedPoint1.getRawBits() < fixedPoint2.getRawBits()) ? fixedPoint1 : fixedPoint2;
}

const Fixed& Fixed::min(const Fixed& fixedPoint1, const Fixed& fixedPoint2)
{
	return (fixedPoint1.getRawBits() < fixedPoint2.getRawBits()) ? fixedPoint1 : fixedPoint2;
}

Fixed& Fixed::max(Fixed& fixedPoint1, Fixed& fixedPoint2)
{
	return (fixedPoint1.getRawBits() > fixedPoint2.getRawBits()) ? fixedPoint1 : fixedPoint2;
}

const Fixed& Fixed::max(const Fixed& fixedPoint1, const Fixed& fixedPoint2)
{
	return (fixedPoint1.getRawBits() > fixedPoint2.getRawBits()) ? fixedPoint1 : fixedPoint2;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointVal;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointVal = raw;
}

float Fixed::toFloat(void) const // bits fixedpointvalue to float
{
	return (float)this->_fixedPointVal / (1<<_fractBitNum);
}

int Fixed::toInt(void) const // bits fixedpointvalue to int
{
	return (int)this->_fixedPointVal >>_fractBitNum;
}

std::ostream & operator<<(std::ostream & stream, const Fixed& other)
{
	return (stream << other.toFloat());
}
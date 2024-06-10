/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:01 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/10 18:07:08 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointVal(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _fixedPointVal(other._fixedPointVal)
{
	std::cout << "copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointVal = other._fixedPointVal;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "deconstructor called" << std::endl;
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
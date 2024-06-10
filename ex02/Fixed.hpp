/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:04 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/10 22:55:56 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedPointVal;
		static const int _fractBitNum = 8;
	
	public:
		Fixed(void);
		Fixed(const int intNum);
		Fixed(const float& floatNum);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		Fixed& operator>(const Fixed& other);
		Fixed& operator<(const Fixed& other);
		Fixed& operator>=(const Fixed& other);
		Fixed& operator<=(const Fixed& other);
		Fixed& operator==(const Fixed& other);
		Fixed& operator!=(const Fixed& other);
		Fixed& operator+(const Fixed& other);
		Fixed& operator-(const Fixed& other);
		Fixed& operator*(const Fixed& other);
		Fixed& operator/(const Fixed& other);
		Fixed& operator++(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream & operator<<(std::ostream & stream, const Fixed& other);

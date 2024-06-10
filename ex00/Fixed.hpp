/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:04 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/10 12:32:53 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once //look this one up

#include <iostream>

class Fixed
{
	private:
		int _fixedPointVal;
		static const int _fractBitNum = 8;
	
	public:
		//default constructor
		Fixed(int _fixedPointVal);
		//copy constructor
		Fixed(const Fixed& other);
		//copy assignment operator overload
		Fixed& operator = (const Fixed& other);
		//deconstructor
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

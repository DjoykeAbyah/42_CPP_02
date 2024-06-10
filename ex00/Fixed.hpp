/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:04 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/10 17:49:39 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int _fixedPointVal;
		static const int _fractBitNum = 8;
	
	public:
		Fixed(void);//default constructor
		Fixed(const Fixed& other); //copy constructor
		Fixed& operator=(const Fixed& other); //copy assignment operator overload
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:23 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/15 07:02:36 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

// ================== [ public ] constructor / destructor =================== //

// default constructor
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _bits = 0;
}

// converting constructor
Fixed::Fixed(const int i)
{
    std::cout << "Converting constructor called" << std::endl;
    _bits = i;
}

// copy constructor
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    _bits = fixed.getRawBits();
}

// destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// ========================== [ public ] operator =========================== //

// assignment operator
void    Fixed::operator=(const int i)
{
    std::cout << "assignment operator called" << std::endl;
    _bits = i;
}

// copy assignment operator
void    Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _bits = fixed.getRawBits();
}

// ======================= [ public ] setter / getter ======================= //

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _bits = raw;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _bits;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:23 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/15 06:55:41 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

// ======================= [ private ] setter / getter ====================== //

void    Fixed::_setValueFromInt(const int i)
{
    _bits = i<<_frac;
}

void    Fixed::_setValueFromFloat(const float f)
{
    _bits = roundf(f * (1<<_frac));
}

void    Fixed::_setMask()
{
    for (int i = 0; i < _frac; i++) {
        _mask |= 1<<i;
    }
}

int     Fixed::_getValueToInt() const
{
    return _bits>>_frac;
}

float   Fixed::_getValueToFloat() const
{
    return (float)_bits / (1<<_frac);
}

// ================== [ public ] constructor / destructor =================== //

// default constructor
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _bits = 0;
    _setMask();
}

// converting constructor
Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    _setValueFromInt(i);
    _setMask();
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _setValueFromFloat(f);
    _setMask();
}

// copy constructor
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    _bits = fixed.getRawBits();
    _setMask();
}

// destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// ========================== [ public ] operator =========================== //

int     Fixed::toInt(void) const
{
    return _getValueToInt();
}

float   Fixed::toFloat(void) const
{
    return _getValueToFloat();
}

bool    Fixed::isInt(void) const
{
    if ((_bits & _mask) == 0)
        return true;
    return false;
}

// ========================== [ public ] operator =========================== //

// assignment operator
void    Fixed::operator=(const int i)
{
    std::cout << "assignment operator called" << std::endl;
    _setValueFromInt(i);
}

void    Fixed::operator=(const float f)
{
    std::cout << "assignment operator called" << std::endl;
    _setValueFromFloat(f);
}

// copy assignment operator
void    Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _bits = fixed.getRawBits();
}

// stream operator
std::ostream    &operator<<(std::ostream &os, const Fixed &fixed)
{
    if (fixed.isInt())
        os << fixed.toInt();
    else
        os << fixed.toFloat();
    
    return os;
}

// ======================= [ public ] setter / getter ======================= //

void    Fixed::setRawBits(int const raw)
{
     _bits = raw;
}

int     Fixed::getRawBits(void) const
{
    return _bits;
}

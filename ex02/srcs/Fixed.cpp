/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:23 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/16 20:04:01 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

// ======================= [ private ] setter / getter ====================== //

// --------------------------- set/get int value ---------------------------- //

void    Fixed::_setValueFromInt(const int value)
{
    _rawBits = value << _fracLen;
}

int     Fixed::_getValueToInt() const
{
    return _rawBits >> _fracLen;
}

// -------------------------- set/get float value --------------------------- //

void    Fixed::_setValueFromFloat(const float value)
{
    _rawBits = roundf(value * (1 << _fracLen));
}

float   Fixed::_getValueToFloat() const
{
    return (float)_rawBits / (1 << _fracLen);
}

// ================== [ public ] constructor / destructor =================== //

// -------------------------- default contsructor --------------------------- //

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

// ------------------------- conberting contsructor ------------------------- //

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    _setValueFromInt(value);
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    _setValueFromFloat(value);
}

// ---------------------------- copy contsructor ---------------------------- //

Fixed::Fixed(const Fixed &fixed)
{
    // std::cout << "Copy constructor called" << std::endl;
    _rawBits = fixed.getRawBits();
}

// ------------------------------- destructor ------------------------------- //

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

// =========================== [ public ] method ============================ //

// ---------------------------- toInt / toFloat ----------------------------- //

int     Fixed::toInt(void) const
{
    return _getValueToInt();
}

float   Fixed::toFloat(void) const
{
    return _getValueToFloat();
}

// ------------------------------- max / min -------------------------------- //

Fixed        &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 <= fixed2)
        return fixed1;
    else
        return fixed2;
}

const Fixed  &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1 <= fixed2)
        return fixed1;
    else
        return fixed2;
}

Fixed        &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 >= fixed2)
        return fixed1;
    else
        return fixed2;
}

const Fixed  &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1 >= fixed2)
        return fixed1;
    else
        return fixed2;
}

// ========================== [ public ] operator =========================== //

// -------------------------- assignment operator --------------------------- //

Fixed   &Fixed::operator=(const int value)
{
    // std::cout << "assignment operator called" << std::endl;
    _setValueFromInt(value);
    return *this;
}

Fixed   &Fixed::operator=(const float value)
{
    // std::cout << "assignment operator called" << std::endl;
    _setValueFromFloat(value);
    return *this;
}

// ------------------------ copy assignment operator ------------------------ //

Fixed   &Fixed::operator=(const Fixed &fixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        _rawBits = fixed.getRawBits();
    }
    return *this;
}

// --------------------------  comparison operator -------------------------- //

// comparison operator ">"
bool    Fixed::operator>(const Fixed &fixed) const
{
    return this->getRawBits() > fixed.getRawBits();
}

// comparison operator "<"
bool    Fixed::operator<(const Fixed &fixed) const
{
    return this->getRawBits() < fixed.getRawBits();
}

// comparison operator ">="
bool    Fixed::operator>=(const Fixed &fixed) const
{
    return this->getRawBits() >= fixed.getRawBits();
}

// comparison operator "<="
bool    Fixed::operator<=(const Fixed &fixed) const
{
    return this->getRawBits() <= fixed.getRawBits();
}

// comparison operator "=="
bool    Fixed::operator==(const Fixed &fixed) const
{
    return this->getRawBits() == fixed.getRawBits();
}

// comparison operator "!="
bool    Fixed::operator!=(const Fixed &fixed) const
{
    return this->getRawBits() != fixed.getRawBits();
}

// --------------------------  arithmetic operator -------------------------- //

// arithmetic operator "+"
Fixed   Fixed::operator+(const Fixed &fixed) const
{
    Fixed   result;
    result.setRawBits(this->getRawBits() + fixed.getRawBits());
    return result;
}

// arithmetic operator "-"
Fixed   Fixed::operator-(const Fixed &fixed) const
{
    Fixed   result;
    result.setRawBits(this->getRawBits() - fixed.getRawBits());
    return result;
}

// arithmetic operator "*"
Fixed   Fixed::operator*(const Fixed &fixed) const
{
    Fixed   result;
    long long rawBits;
    rawBits
        = ((long long)this->getRawBits() * fixed.getRawBits()) >> _fracLen;
    result.setRawBits((int)rawBits);
    return result;
}

// arithmetic operator "/"
Fixed   Fixed::operator/(const Fixed &fixed) const
{
    Fixed   result;
    if (fixed.getRawBits() == 0) {
        throw std::runtime_error("ZeroDivisionError: division by zero");
    }
    long long rawBits
        = ((long long)this->getRawBits() << _fracLen) / fixed.getRawBits();
    result.setRawBits((int)rawBits);
    return result;
}

// ---------------------  increment/decrement operator ---------------------- //

// pre-increment operator
Fixed   &Fixed::operator++(void)
{
    ++this->_rawBits;
    return *this;
}

// post-increment operator
Fixed   Fixed::operator++(int)
{
    Fixed   result = *this;
    this->_rawBits++;
    return result;
}

// pre-decrement operator
Fixed   &Fixed::operator--(void)
{
    --this->_rawBits;
    return *this;
}

// post-decrement operator
Fixed   Fixed::operator--(int)
{
    Fixed   result = *this;
    this->_rawBits--;
    return result;
}

// ========================== [ global ] operator =========================== //

// ---------------------------- stream operator ----------------------------- //

std::ostream    &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

// ======================= [ public ] setter / getter ======================= //

// ---------------------------- set/get rawBits ----------------------------- //

void    Fixed::setRawBits(int const rawBits)
{
    // std::cout << "setRawBits member function called" << std::endl;
    _rawBits = rawBits;
}

int     Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

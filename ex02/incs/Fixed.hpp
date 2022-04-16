/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:30 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/16 16:15:00 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

// ================================ library ================================= //

#include <iostream>
#include <cmath>

// ================================= class ================================== //

class Fixed
{
    private:
        // [ variable ]
        static const int    _fracLen = 8;
        int                 _rawBits;

        // [ setter / getter ]
        void    _setValueFromInt(const int value);
        void    _setValueFromFloat(const float value);
        int     _getValueToInt(void) const;
        float   _getValueToFloat(void) const;

    public:
        // [ constructor / destructor ]
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        ~Fixed();

        // [ method ]
        // type converter
        int     toInt(void) const;
        float   toFloat(void) const;
        // min/max finder
        static Fixed        &min(Fixed &fixed1, Fixed &fixed2);
        static const Fixed  &min(const Fixed &fixed1, const Fixed &fixed2);
        static Fixed        &max(Fixed &fixed1, Fixed &fixed2);
        static const Fixed  &max(const Fixed &fixed1, const Fixed &fixed2);

        // [ operator ]
        // assignment operator
        Fixed   &operator=(const int value);
        Fixed   &operator=(const float value);
        Fixed   &operator=(const Fixed &fixed);
        // comparison operator
        bool    operator>(const Fixed &fixed) const;
        bool    operator<(const Fixed &fixed) const;
        bool    operator>=(const Fixed &fixed) const;
        bool    operator<=(const Fixed &fixed) const;
        bool    operator==(const Fixed &fixed) const;
        bool    operator!=(const Fixed &fixed) const;
        // arithmeric operator
        Fixed   operator+(const Fixed &fixed) const;
        Fixed   operator-(const Fixed &fixed) const;
        Fixed   operator*(const Fixed &fixed) const;
        Fixed   operator/(const Fixed &fixed) const;
        // increment/decrement operator
        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);

        // [ setter / getter ]
        void    setRawBits(int const rawBits);
        int     getRawBits(void) const;
};

// [ stream operator ]
std::ostream    &operator<<(std::ostream &os, const Fixed &fixed);

#endif
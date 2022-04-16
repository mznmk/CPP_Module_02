/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:30 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/16 13:30:27 by mmizuno          ###   ########.fr       */
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
        int     _getValueToInt(void) const;
        void    _setValueFromFloat(const float value);
        float   _getValueToFloat(void) const;

    public:
        // [ constructor / destructor ]
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        ~Fixed();

        // [ method ]
        int     toInt(void) const;
        float   toFloat(void) const;

        // [ operator ]
        Fixed   &operator=(const int value);
        Fixed   &operator=(const float value);
        Fixed   &operator=(const Fixed &fixed);

        // [ setter / getter ]
        void    setRawBits(int const rawBits);
        int     getRawBits(void) const;
};

// [ stream operator ]
std::ostream    &operator<<(std::ostream &os, const Fixed &fixed);

#endif
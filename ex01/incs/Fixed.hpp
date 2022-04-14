/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:30 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/15 06:56:00 by mmizuno          ###   ########.fr       */
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
        int                 _bits;
        static const int    _frac = 8;
        int                 _mask;

        // [ method ]
        void    _setValueFromInt(const int i);
        void    _setValueFromFloat(const float f);
        void    _setMask(void);
        int     _getValueToInt(void) const;
        float   _getValueToFloat(void) const;

    public:
        // [ constructor / destructor ]
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        Fixed(const Fixed &fixed);
        ~Fixed();

        // [ method ]
        int     toInt(void) const;
        float   toFloat(void) const;
        bool    isInt(void) const;

        // [ operator ]
        void    operator=(const int i);
        void    operator=(const float f);
        void    operator=(const Fixed &fixed);

        // [ getter / setter ]
        void    setRawBits(int const raw);
        int     getRawBits(void) const;
};

// [ stream operator ]
std::ostream    &operator<<(std::ostream &os, const Fixed &fixed);

#endif
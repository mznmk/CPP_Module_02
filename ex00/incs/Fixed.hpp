/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:30 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/15 03:30:40 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

// ================================ library ================================= //

#include <iostream>

// ================================= class ================================== //

class Fixed
{
    private:
        // [ variable ]
        int                 _value;
        static const int    fracBits = 8;

    public:
        // [ constructor / destructor ]
        Fixed();
        Fixed(const int i);
        Fixed(const Fixed &f);
        ~Fixed();

        // [ operator ]
        void    operator=(const int i);
        void    operator=(const Fixed &fixed);
        operator const int();

        // [ method ]

        // [ getter / setter ]
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
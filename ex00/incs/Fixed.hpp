/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:30 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/15 07:02:40 by mmizuno          ###   ########.fr       */
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
        int                 _bits;
        static const int    _frac = 8;

    public:
        // [ constructor / destructor ]
        Fixed();
        Fixed(const int i);
        Fixed(const Fixed &fixed);
        ~Fixed();

        // [ operator ]
        void    operator=(const int i);
        void    operator=(const Fixed &fixed);
 
        // [ getter / setter ]
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
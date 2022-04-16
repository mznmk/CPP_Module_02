/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:30 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/16 11:46:15 by mmizuno          ###   ########.fr       */
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
        static const int    _fracLen = 8;
        int                 _rawBits;

    public:
        // [ constructor / destructor ]
        Fixed();
        Fixed(const Fixed &fixed);
        ~Fixed();

        // [ operator ]
        Fixed   &operator=(const Fixed &fixed);
 
        // [ getter / setter ]
        int     getRawBits(void) const;
        void    setRawBits(int const rawBits);
};

#endif
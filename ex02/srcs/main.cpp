/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:16 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/16 20:12:37 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"
#include <iostream>

int main(void)
{
    // --------------------- [ test: default (static) ] --------------------- //

    std::cout << "---------- [ test: default (static) ] ----------" << std::endl;

    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "---------- -------------------------- ----------" << std::endl;

    // -------------------- [ test: default (dynamic) ] --------------------- //

    std::cout << "---------- [ test: default (dynamic) ] ----------" << std::endl;

    Fixed       *c = new Fixed;
    Fixed const *d = new Fixed( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << *c << std::endl;
    std::cout << ++(*c) << std::endl;
    std::cout << *c << std::endl;
    std::cout << (*c)++ << std::endl;
    std::cout << *c << std::endl;

    std::cout << *d << std::endl;

    std::cout << Fixed::max( *c, *d ) << std::endl;

    delete c;
    delete d;

    std::cout << "---------- --------------------------- ----------" << std::endl;

    // ------------------------ [ test: additional ] ------------------------ //

    std::cout << "---------- [ test: additional ] ----------" << std::endl;

    Fixed       e, f;
    Fixed const g(-42), h(24), i(4.2f), j(2.4f), k(2.4f);

    std::cout << "Fixed       e, f"                                     << std::endl;
    std::cout << "Fixed const g(-42), h(24), i(4.2f), j(2.4f), k(2.4f)" << std::endl;
    
    std::cout << "< min / max finder >" << std::endl;
    e = -4; f = 2;
    std::cout << "e=-4    f=2     : max(e, f)       : " << Fixed::max(e, f) << std::endl;
    std::cout << "e=-4    f=2     : min(e, f)       : " << Fixed::min(e, f) << std::endl;
    e = -0.4f; f = 0.2f;
    std::cout << "e=-0.4  f=0.2   : max(e, f)       : " << Fixed::max(e, f) << std::endl;
    std::cout << "e=-0.4  f=0.2   : min(e, f)       : " << Fixed::min(e, f) << std::endl;
    std::cout << "g=-42   h=24    : const max(g, h) : " << Fixed::max(g, h) << std::endl;
    std::cout << "g=-42   h=24    : const min(g, h) : " << Fixed::min(g, h) << std::endl;
    std::cout << "i=4.2   j=2.4   : const max(i, j) : " << Fixed::max(i, j) << std::endl;
    std::cout << "i=4.2   j=2.4   : const min(i, j) : " << Fixed::min(i, j) << std::endl;

    std::cout << "< comparison operator >" << std::endl;
    std::cout << "g=-42   h=24    : g > h           : " << (g > h ? "True" : "False") << std::endl;
    std::cout << "i=4.2   j=2.4   : i > j           : " << (i > j ? "True" : "False") << std::endl;
    std::cout << "g=-42   h=24    : g < h           : " << (g < h ? "True" : "False") << std::endl;
    std::cout << "i=4.2   j=2.4   : i < j           : " << (i < j ? "True" : "False") << std::endl;
    std::cout << "i=4.2   j=2.4   : i >= j          : " << (i >= j ? "True" : "False") << std::endl;
    std::cout << "j=2.4   k=2.4   : j >= k          : " << (j >= k ? "True" : "False") << std::endl;
    std::cout << "i=4.2   j=2.4   : i <= j          : " << (i <= j ? "True" : "False") << std::endl;
    std::cout << "j=2.4   k=2.4   : j <= k          : " << (j <= k ? "True" : "False") << std::endl;
    std::cout << "i=4.2   j=2.4   : i == j          : " << (i == j ? "True" : "False") << std::endl;
    std::cout << "j=2.4   k=2.4   : j == k          : " << (j == k ? "True" : "False") << std::endl;
    std::cout << "i=4.2   j=2.4   : i != j          : " << (i != j ? "True" : "False") << std::endl;
    std::cout << "j=2.4   k=2.4   : j != k          : " << (j != k ? "True" : "False") << std::endl;

    std::cout << "< arithmetic operator >" << std::endl;
    std::cout << "g=-42   h=24    : g + h           : " << (g + h) << std::endl;
    std::cout << "g=-42   h=24    : g - h           : " << (g - h) << std::endl;
    std::cout << "g=-42   h=24    : g * h           : " << (g * h) << std::endl;
    std::cout << "g=-42   h=24    : g / h           : " << (g / h) << std::endl;
    e = 1<<12; f = 1<<10;
    std::cout << "e=1<<12 f=1<<10 : e * f           : " << (e * f) << std::endl;
    std::cout << "e=1<<12 f=1<<10 : e / f           : " << (e / f) << std::endl;
    e = 42; f = 0;
    std::cout << "e=42    f=0     : e / f           : ";
    try { e / f; } catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
    
    std::cout << "< increment/ decrement operator >" << std::endl;
    e = -4; f = 2;
    std::cout << "e=-4   f=2    : e + ++f         : " << (e + (++f)) << std::endl;
    e = -4; f = 2;
    std::cout << "e=-4   f=2    : e + f++         : " << (e + (f++)) << std::endl;
    e = -0.4f; f = 0.2f;
    std::cout << "e=-0.4 f=0.2  : e + --f         : " << (e + (--f)) << std::endl;
    e = -0.4f; f = 0.2f;
    std::cout << "e=-0.4 f=0.2  : e + f--         : " << (e + (f--)) << std::endl;

    std::cout << "---------- -------------------- ----------" << std::endl;

    // [ return ]
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:16 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/16 20:31:50 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"
#include <iostream>
#include <stdio.h>

int main(void)
{
    // --------------------- [ test: default (static) ] --------------------- //

    std::cout << "---------- [ test: default (static) ] ----------" << std::endl;

    Fixed       a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "---------- -------------------------- ----------" << std::endl;

    // -------------------- [ test: default (dynamic) ] --------------------- //

    std::cout << "---------- [ test: default (dynamic) ] ----------" << std::endl;

    Fixed       *e = new Fixed;
    Fixed const *f = new Fixed(10);
    Fixed const *g = new Fixed(42.42f);
    Fixed const *h = new Fixed(*f);

    *e = Fixed(1234.4321f);

    std::cout << "e is " << *e << std::endl;
    std::cout << "f is " << *f << std::endl;
    std::cout << "g is " << *g << std::endl;
    std::cout << "h is " << *h << std::endl;

    std::cout << "e is " << (*e).toInt() << " as integer" << std::endl;
    std::cout << "f is " << (*f).toInt() << " as integer" << std::endl;
    std::cout << "g is " << (*g).toInt() << " as integer" << std::endl;
    std::cout << "h is " << (*h).toInt() << " as integer" << std::endl;

    delete e;
    delete f;
    delete g;
    delete h;

    std::cout << "---------- --------------------------- ----------" << std::endl;

    // ------------------------ [ test: additional ] ------------------------ //

    std::cout << "---------- [ test: additional ] ----------" << std::endl;

    Fixed i;
    Fixed j;

    i = -42;
    j = -42.42f;

    std::cout << i << std::endl;
    std::cout << j << std::endl;

    std::cout << i.toInt() << std::endl;
    std::cout << j.toInt() << std::endl;

    std::cout << "---------- -------------------- ----------" << std::endl;

    // [ return ]
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:16 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/16 20:33:30 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"
#include <iostream>
#include <stdio.h>

int main(void)
{
    // --------------------- [ test: default (static) ] --------------------- //

    std::cout << "---------- [ test: default (static) ] ----------" << std::endl;

    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;
 
    std::cout << a.getRawBits() << std::endl;
    printf("pointer: %p\n", &a);
    std::cout << b.getRawBits() << std::endl;
    printf("pointer: %p\n", &b);
    std::cout << c.getRawBits() << std::endl;
    printf("pointer: %p\n", &c);

    std::cout << "---------- -------------------------- ----------" << std::endl;

    // -------------------- [ test: default (dynamic) ] --------------------- //

    std::cout << "---------- [ test: default (dynamic) ] ----------" << std::endl;

    Fixed *d = new Fixed;
    Fixed *e = new Fixed(*d);
    Fixed *f = new Fixed;

    *f = *e;

    std::cout << d->getRawBits() << std::endl;
    printf("pointer: %p\n", &d);
    std::cout << e->getRawBits() << std::endl;
    printf("pointer: %p\n", &e);
    std::cout << f->getRawBits() << std::endl;
    printf("pointer: %p\n", &f);

    delete d;
    delete e;
    delete f;

    std::cout << "---------- --------------------------- ----------" << std::endl;

    // [ return ]
    return 0;
}
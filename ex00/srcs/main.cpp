/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:16 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/15 03:22:40 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"
#include <iostream>
#include <stdio.h>

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;
 
    std::cout << a.getRawBits() << std::endl;
    // printf("pointer: %p\n", &a);
    std::cout << b.getRawBits() << std::endl;
    // printf("pointer: %p\n", &b);
    std::cout << c.getRawBits() << std::endl;
    // printf("pointer: %p\n", &c);

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;

    return 0;
}
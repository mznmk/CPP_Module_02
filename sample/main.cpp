#include "MyString.hpp"
#include <stdio.h>
#include <iostream>

int main()
{
    // [ test MyString ]
    MyString a = "a";
    std::cout << "string : " << a << std::endl;
    printf("pointer: %p\n", &a);
    printf("length : %ld\n", a.length());

    MyString b;
    b = "bb";
    std::cout << "string : " << b << std::endl;
    printf("pointer: %p\n", &b);
    printf("length : %ld\n", b.length());

    MyString c = "ccc";
    std::cout << "string : " << c << std::endl;
    printf("pointer: %p\n", &c);
    printf("length : %ld\n", c.length());

    MyString d;
    d = "dddd";
    std::cout << "string : " << d << std::endl;
    printf("pointer: %p\n", &d);
    printf("length : %ld\n", d.length());

    d = c;
    std::cout << "string : " << d << std::endl;
    printf("pointer: %p\n", &d);
    printf("length : %ld\n", d.length());

    // [ return ]
    return (0);
}
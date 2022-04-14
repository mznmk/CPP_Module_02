#ifndef MYSTRING_HPP
# define MYSTRING_HPP

#include <cstring>

class MyString
{
    private:
        // [ variable ]
        char    *_s;
        size_t  _len;

        // [ method ]
        void _create(const char *s);
        void _destroy();

    public:
        // [ constructor / destructor ]
        // constructor
        MyString();
        // converting constructor
        MyString(const char *s);
        // copy constructor
        MyString(const MyString &s);
        // destructor
        ~MyString();

        // [ operator ]
        // assignment operator
        void operator=(const char *s);
        // copy assignment operator
        void operator=(const MyString &s);
        // conversion function
        operator const char*();

        // [ method ]
        size_t length();
};

#endif

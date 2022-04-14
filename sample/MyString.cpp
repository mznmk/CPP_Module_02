#include "MyString.hpp"

void    MyString::_create(const char *s) {
    _len = std::strlen(s);
    _s = new char[_len + 1];
    std::strcpy(_s, s);
}

void    MyString::_destroy() {
    if (_s) {
        delete[] _s;
        _s = NULL;
    }
}

// ======================== constructor / destructor ======================== //

// default constructor
MyString::MyString() {
    _s = NULL;
}

// converting constructor
MyString::MyString(const char *s) {
    _create(s);
}

// copy constructor
MyString::MyString(const MyString &s) {
    _create(s._s);
}

// destructor
MyString::~MyString() {
    _destroy();
}

// ================================ operator ================================ //

// assignment operator
void    MyString::operator=(const char *s) {
    _destroy();
    _create(s);
}
// copy assignment operator
void    MyString::operator=(const MyString &s) {
    _destroy();
    _create(s._s);
}
// conversion function
MyString::operator const char*() {
    return (_s);
}

// ================================= method ================================= //

size_t  MyString::length() {
    return (_len);
}

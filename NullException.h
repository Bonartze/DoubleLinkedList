//
// Created by ivan on 11.06.23.
//

#ifndef UNTITLED58_NULLEXCEPTION_H
#define UNTITLED58_NULLEXCEPTION_H

#include <exception>
#include <cstring>

class NullException : public std::exception {
private:
    char *str;
public:
    NullException() = default;

    NullException(char *st) : str(st) {}

    virtual const char *what() const noexcept override;

    ~NullException() = default;
};


#endif //UNTITLED58_NULLEXCEPTION_H

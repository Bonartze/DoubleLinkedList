//
// Created by ivan on 11.06.23.
//

#include "NullException.h"

const char *NullException::what() const noexcept {
    return str;
}
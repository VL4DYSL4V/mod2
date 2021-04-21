//
// Created by владислав on 21.04.2021.
//

#ifndef INDEXOUTOFBOUNDSEXCEPTION_H
#define INDEXOUTOFBOUNDSEXCEPTION_H

#include "exception"
#include "string"
#include <iostream>

class IndexOutOfBoundsException : public std::exception{

private:
    std::string message = "Invalid index";

public:
    IndexOutOfBoundsException();
    IndexOutOfBoundsException(std::string message);
    IndexOutOfBoundsException(IndexOutOfBoundsException const &e) noexcept;

    void printMessage();

};


#endif //LIST_INDEXOUTOFBOUNDSEXCEPTION_H

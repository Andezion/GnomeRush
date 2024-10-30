#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H

#include "../include/Book.h"
#include "../include/Renter.h"

class Rent
{
public:
    Rent(Book, Renter, std::string ptime);

    std::string timeBegin{};
    std::string timeEnd{};
};

#endif //LIBRARY_RENT_H

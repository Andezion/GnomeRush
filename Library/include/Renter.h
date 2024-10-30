#ifndef LIBRARY_RENTER_H
#define LIBRARY_RENTER_H

#include <iostream>
#include <string>

class Renter
{
public:
    std::string firstName{};
    std::string lastName{};

    int personalID{};
    int type{};

    std::string getInfo();
    std::string getID();

    void setRenterType(int input);

    Renter(std::string name, std::string surname, int id, int RenterType);
};

#endif //LIBRARY_RENTER_H

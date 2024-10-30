#include "../include/Renter.h"

Renter::Renter(std::string name, std::string surname, int id, int RenterType)
{
    firstName = name;
    lastName = surname;

    personalID = id;

    type = RenterType;
}

std::string Renter::getID()
{
    return firstName + " " + lastName;
}

std::string Renter::getInfo()
{
    return std::to_string(personalID);
}

void Renter::setRenterType(int input)
{
    type = input;
}


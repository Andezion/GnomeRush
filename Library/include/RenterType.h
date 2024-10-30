#ifndef LIBRARY_RENTERTYPE_H
#define LIBRARY_RENTERTYPE_H

#include <string>
#include <iostream>

class RenterType
{
public:
    int type{};

    void setRenterType(int input);

    virtual int getMaxBooks() const = 0;
    virtual int getMaxPeriod() const = 0;
    virtual std::string getInfo() const = 0;
};

class Student : public RenterType
{
public:
    int MaxBooks = 10;
    int MaxPeriod = 25;
    std::string Info = "Student";

    int getMaxBooks() const override
    {
        return MaxBooks;
    }

    int getMaxPeriod() const override
    {
        return MaxPeriod;
    }

    std::string getInfo() const override
    {
        return Info;
    }
};

class Master : public RenterType
{
public:
    int MaxBooks = 20;
    int MaxPeriod = 50;
    std::string Info = "Master";

    int getMaxBooks() const override
    {
        return MaxBooks;
    }

    int getMaxPeriod() const override
    {
        return MaxPeriod;
    }

    std::string getInfo() const override
    {
        return Info;
    }
};

class Doktor : public RenterType
{
public:
    int MaxBooks = 30;
    int MaxPeriod = 100;
    std::string Info = "Doktor";

    int getMaxBooks() const override
    {
        return MaxBooks;
    }

    int getMaxPeriod() const override
    {
        return MaxPeriod;
    }

    std::string getInfo() const override
    {
        return Info;
    }
};

#endif //LIBRARY_RENTERTYPE_H

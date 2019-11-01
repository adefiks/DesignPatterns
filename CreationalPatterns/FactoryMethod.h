#include <iostream>
#include <memory>
#include <string>

class Cars
{
public:
    virtual std::string typ() = 0;
};

class Ford : public Cars
{
public:
    Ford()
    {
        std::cout << "Ford created" << std::endl;
    }
    std::string typ()
    {
        return "Ford";
    }
};

class Opel : public Cars
{
public:
    Opel()
    {
        std::cout << "Opel created" << std::endl;
    }
    std::string typ()
    {
        return "Opel";
    }
};

template <class T>
class Creator
{
public:
    virtual std::unique_ptr<T> Create(std::string typ) = 0;
};

class FactoryCars : public Creator<Cars>
{
public:
    std::unique_ptr<Cars> Create(std::string typ) override
    {
        if (typ == "Ford")
        {
            return std::make_unique<Ford>();
        }
        else if (typ == "Opel")
        {
            return std::make_unique<Opel>();
        }
        else
        {
            std::cout << "there is no car like this" << std::endl;
        }
    }
};
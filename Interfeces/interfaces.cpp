#include <iostream>

class interfaceCar
{
    virtual void runEngine() = 0;
    virtual void runHeater() = 0;
};

class Ferrari : public interfaceCar
{
public:
    Ferrari() { std::cout << "Ferrari entity created" << std::endl; }
    ~Ferrari() {}
    void runEngine() override
    {
        std::cout << "Ferrari start engine " << std::endl;
    }

    void runHeater() override
    {
        std::cout << "Ferrari run heater" << std::endl;
    }

    static void askTheCarName();
};

void Ferrari::askTheCarName()
{
    std::cout << "Ferrari" << std::endl;
}

int main()
{
    Ferrari::askTheCarName();
    Ferrari myFerrari;

    return 0;
}
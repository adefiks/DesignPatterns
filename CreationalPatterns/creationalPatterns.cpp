#include <iostream>
#include "Singletone.h"
#include "FactoryMethod.h"

typedef SingletoneTemplate<TestClass> TestClassTemplate; // Global declaration for template singletone

int main()
{
    std::cout << "Design Patterns" << std::endl
              << std::endl;

    std::cout << "==================" << std::endl;
    std::cout << "=== Singletone ===" << std::endl;
    std::cout << "==================" << std::endl;

    //Singletone *newSingletone = new Singletone(); // Can't do this (constructor is private)

    Singletone *newSingletone = Singletone::getIntance();
    Singletone *nextSingletone = Singletone::getIntance();

    TestClassTemplate::getInstance()->wypiszTekst();
    TestClassTemplate::getInstance()->variable = 123;
    TestClassTemplate::getInstance()->counter = 12;
    std::cout << std::endl;

    std::cout << "======================" << std::endl;
    std::cout << "=== Factory Method ===" << std::endl;
    std::cout << "======================" << std::endl;

    auto factory = std::make_unique<FactoryCars>();
    std::unique_ptr<Cars> car11 = factory->Create("Opel");
    std::unique_ptr<Cars> car22 = factory->Create("Ford");

    return 0;
}
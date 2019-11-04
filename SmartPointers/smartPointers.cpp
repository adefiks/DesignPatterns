#include <iostream>
#include <memory>

namespace myNamspace
{

} // namespace myNamspace

class testClass
{
public:
    testClass(int xpos, int ypos) : x(xpos), y(ypos)
    {
        std::cout << "Entity class Created!" << std::endl;
    }
    ~testClass()
    {
        std::cout << "Entity class Destroyed" << std::endl;
    }
    int x, y;
};

int main()
{
    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "= Uniqe Pointer ==" << std::endl;
    std::cout << "==================" << std::endl;
    {
        std::unique_ptr<testClass> testClassUniqe(new testClass(2, 3));
        std::unique_ptr<testClass> tryToCopy(new testClass(2, 2));
        auto fromC14 = std::make_unique<testClass>(2, 2); // new way to create smart pointer from C++ 14

        // tryToCopy = testClassUniqe; // can't do this operation
        auto passClass = std::move(testClassUniqe); // !!! move semantic !!!

        std::cout << passClass->x << std::endl;
    }

    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "= Shared Pionter =" << std::endl;
    std::cout << "==================" << std::endl;
    {
        auto firstSharedPointer = std::make_shared<testClass>(2, 4);
        {
            auto secondSharedPointer = firstSharedPointer;
            secondSharedPointer->x = 234;
            std::cout << "instance counter: " << firstSharedPointer.use_count() << std::endl;
        }
        std::cout << "instance counter: " << firstSharedPointer.use_count() << std::endl;

        std::cout << std::endl;
        std::cout << "==================" << std::endl;
        std::cout << "== Weak Pointer ==" << std::endl;
        std::cout << "==================" << std::endl;

        std::weak_ptr<testClass> weakPointer = firstSharedPointer;
        std::cout << "instance counter: " << firstSharedPointer.use_count() << std::endl;
    }
    return 0;
}
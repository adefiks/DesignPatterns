#include <iostream>

// Singleton Class
class Singletone
{
private:
    static Singletone *instance;
    Singletone()
    {
        std::cout << "singletone created" << std::endl;
    }
    Singletone(Singletone const &) = delete;            // copy constructor
    Singletone &operator=(Singletone const &) = delete; // move constructor

public:
    static Singletone *getIntance()
    {
        if (!instance)
        {
            instance = new Singletone();
        }
        else
        {
            std::cout << "Singleton already exist" << std::endl;
        }
        return instance;
    }

    ~Singletone() {}
};

Singletone *Singletone::instance = 0;

// Singletone template
template <class T>
class SingletoneTemplate
{
private:
    static T *instance;

    SingletoneTemplate() {}
    SingletoneTemplate(SingletoneTemplate const &) = delete;
    SingletoneTemplate &operator=(SingletoneTemplate const &) = delete;

public:
    static T *getInstance()
    {
        if (!instance)
        {
            instance = new T();
        }
        return instance;
    }
    ~SingletoneTemplate() {}
};

template <class T>
T *SingletoneTemplate<T>::instance = 0;

// Class for Testing Singletone
class TestClass
{
private:
    int x, y;

public:
    TestClass(/* args */)
    {
        std::cout << "Test Class" << std::endl;
    }
    ~TestClass() {}

    void wypiszTekst()
    {
        std::cout << "Print in Test Class" << std::endl;
    }
    int variable = 0;
    static int counter;
};

int TestClass::counter = 0;
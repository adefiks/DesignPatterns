#include <iostream>
#include <thread>
#include <atomic>
#include <string>

std::atomic<int> safeVariable{8};

void bodyForFirstThread(std::string name)
{

    std::cout << "Go 1: " << name << std::endl;
}

void bodyForSecondThread(std::string name)
{

    std::cout << "Go 2: " << name << std::endl;
}

int main()
{

    std::thread threadFirst(bodyForFirstThread, "First Thread");

    std::thread threadSecond(bodyForSecondThread, "Second Thread");

    auto lambdaFunction = []() { std::cout << "Third Thread" << std::endl; };

    std::thread threadThird(lambdaFunction);

    threadFirst.join();
    threadSecond.join();
    threadThird.join();

    return 0;
}
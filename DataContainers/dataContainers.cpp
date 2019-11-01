#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <map>

template <class T>
void printContainers(T container)
{
    for (auto element : container)
        std::cout << " " << element;
    std::cout << std::endl;
}

int main()
{
    std::cout << "==================" << std::endl;
    std::cout << "==== Vectors =====" << std::endl;
    std::cout << "==================" << std::endl;

    std::vector<int> testVector = {1, 2, 3, 2, 2, 1};
    testVector.push_back(12);

    printContainers(testVector);

    std::sort(testVector.begin(), testVector.end());

    printContainers(testVector);

    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "====== array =====" << std::endl;
    std::cout << "==================" << std::endl;

    std::array<int, 12> testArray = {1, 2};
    testArray.at(10) = 23;

    try
    {
        testArray.at(12);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    printContainers(testArray);

    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "====== list ======" << std::endl;
    std::cout << "==================" << std::endl;

    std::list<int> testList = {4, 2, 3, 0, 7, 8}; // 20 times faster then vector
    testList.push_back(12);

    // testList[5]; Can't go to n element (is not-contiguous)

    printContainers(testList);

    testList.sort();

    printContainers(testList);

    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "====== set =======" << std::endl;
    std::cout << "==================" << std::endl;

    std::set<std::string> testSet = {"first", "second"};

    testSet.insert("third");
    testSet.insert("first"); // can't insert, it needs to be uniqe
    printContainers(testSet);

    std::cout << std::endl;
    std::cout << "==================" << std::endl;
    std::cout << "====== map =======" << std::endl;
    std::cout << "==================" << std::endl;

    std::map<std::string, int> testMap = {{"second", 13}, {"third", 2}};
    testMap.insert(std::make_pair("zero", 1));
    testMap.insert(std::make_pair("first", 12));
    for (auto elements : testMap)
    {
        std::cout << " " << elements.first;
    }

    return 0;
}
// heap mem and stack are on the RAM memory
// try to alocate on stack when it is posible

#include <iostream>
#include <memory>

class testClass
{
public:
    testClass(int xpos, int ypos) : x(xpos), y(ypos)
    {
        std::cout << "Entity of test class created" << std::endl;
    }

    ~testClass()
    {
        std::cout << "Entity of test class destroyed" << std::endl;
    }

private:
    int x, y;
};

int main()
{

    // alocate on stack (stos)
    {
        int variable = 12;
        int tableStack[12] = {0};
        testClass classStack(2, 3);
    } // memory free

    // alocate on heap mem (sterta)
    {
        int *variableHeap = new int(7);
        int *table = new int[12];
        auto classHeap = std::make_unique<testClass>(2, 2); // auto delete out of scope no need to delete
        auto classHeapnew = new testClass(2, 2);            // watch FOR deleting this entity !!!

        delete variableHeap;
        delete[] table;
        delete classHeapnew;
    } // memory free (needs to delete)

    return 0;
}

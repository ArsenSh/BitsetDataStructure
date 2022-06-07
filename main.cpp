#include <iostream>
#include "Header.h"

int main()
{
    Bitset<9> bit1(-1114);
    Bitset<9> bit2(5);
    Bitset<9> bit3;
    std::cout << "Your initial values below\n" << std::endl;
    std::cout << "Bit1: " << bit1 << std::endl;
    std::cout << "Bit2: " << bit2 << std::endl;
    std::cout << "Bit3: " << bit3 << std::endl;
    
    bit1.choosing_operation();
    bit2.choosing_operation();
    bit3.choosing_operation();
    
    std::cout << "Results" << "\n\t\tbit1: " << bit1 << "\n\t\tbit2: " << bit2 << "\n\t\tbit3: " << bit3 << std::endl;
    
    return 0;
}

#include <iostream>
#include "Header.h"

int main()
{
    Bitset<8> bit1(100);
    Bitset<8> bit2(bit1);
    Bitset<8> bit3;
    Bitset<8> bit4;
    bit4 = bit1;
    
    std::cout << "Your initial values below\n" << std::endl;
    std::cout << "Bit1: " << bit1 << std::endl;
    std::cout << "Bit2: " << bit2 << std::endl;
    std::cout << "Bit3: " << bit3 << std::endl;
    std::cout << "Bit4: " << bit4 << std::endl;
    
    bit1.choosing_operation();
    bit2.choosing_operation();
    bit3 ^= bit4;
    
    std::cout << "Results" << "\nbit1: " << bit1 << "\nbit2: " << bit2  << "\nbit3: " << bit3 << "\nbit4: " << bit4 <<  std::endl;
    
    return 0;
}

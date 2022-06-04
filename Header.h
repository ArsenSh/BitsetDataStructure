#ifndef Header_h
#define Header_h
#include <iostream>
#include <bitset>
#include <limits>
#include <cstdlib>
#include <fstream>
#include <cmath>

template <long long N>

class Bitset
{
public:
    Bitset ();
    Bitset (int value);
    Bitset (const Bitset& oth);
    ~Bitset ();
    
private:
    long long bitsSize = N;
    std::bitset<N> bits;

public:
    //Bitset& resizng();
    Bitset <N> & operator = (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                bits[i] = oth.bits[i];
            }
            return *this;
        }
        Bitset <N> & operator = (Bitset <N>&& oth)
        {
            
            return *this;
        }
        Bitset <N> & operator ~ ()
        {
            for(int i = 0; i < bitsSize; i++)
            {
                if(bits[i] == true)
                {
                    bits[i] = false;
                }
                else
                {
                    bits[i] = true;
                }
            }
            return *this;
        }
        
        Bitset <N> & operator &= (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                bits[i] = bits[i] & oth.bits[i];
            }
            return *this;
        }
        Bitset <N> & operator |= (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                bits[i] = bits[i] | oth.bits[i];
            }
            return *this;
        }
        Bitset <N>& operator ^= (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                bits[i] = bits[i] ^ oth.bits[i];
            }
            return *this;
        }
        
        Bitset<N>& operator <<= (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                bits[i] <<= oth.bits[i];
            }
            return *this;
        }
        Bitset<N>& operator >>= (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                bits[i] >>= oth.bits[i];
            }
            return *this;
        }
        Bitset<N>& operator << (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                bits[i] << oth.bits[i];
            }
            return *this;
        }
        Bitset<N>& operator >> (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                bits[i] >> oth.bits[i];
            }
            return *this;
        }
        bool operator == (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; i++)
            {
                if(this -> bits[i] != oth.bits[i])
                {
                    return false;
                }
            }
            return true;
        }
        bool operator != (const Bitset <N>& oth)
        {
            int amount = 0;
            
            for(int i = 0; i < bitsSize; i++)
            {
                if(this -> bits[i] == oth.bits[i])
                {
                    ++amount;
                }
            }
            if(amount == (int)bitsSize)
            {
                return false;
            }
            return true;
        }
        
        friend std::ostream& operator << (std::ostream& COUT, const Bitset& oth)
        {
            for(int i = N - 1; i >= 0; --i)
            {
                COUT << oth.bits[i] << " ";
            }
            COUT << '\n';
            return COUT;
        }
        void operator [](long long pos);
};



#include "implementation.hpp"
#endif 

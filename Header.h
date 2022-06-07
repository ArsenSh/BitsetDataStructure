#ifndef Header_h
#define Header_h
#include <iostream>
#include <limits>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <string>


template <unsigned long long N>
class Bitset
{
public:
    Bitset ();
    Bitset (int value);
    Bitset (const Bitset& oth);
    ~Bitset ();
    
private:
    unsigned long long* bits = new unsigned long long[N];
    int bitsSize = (int)(N);

public:
        Bitset& set();                                          
        Bitset& set(std::size_t position, bool value = true);
        Bitset& reset();
        Bitset& to_String();
        Bitset& to_Long();
        Bitset& choosing_operation();
        Bitset& setting_by_given_val();
        Bitset& checking_none_all_any();
        Bitset& toggle_value();
        Bitset& choose(int index);
        Bitset& count();

        bool any();
        bool none();
        bool all();
    
        int getSize() const;
    
        Bitset <N> & operator = (const Bitset <N>& oth)
        {
            bitsSize = oth.bitsSize;
            bits = new unsigned long long[bitsSize];
            for(auto i = 0; i < bitsSize; i++)
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
            for(int i = 0; i < bitsSize; ++i)
            {
                bits[i] = bits[i] & oth.bits[i];
            }
            return *this;
        }
        Bitset <N> & operator |= (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; ++i)
            {
                bits[i] = bits[i] | oth.bits[i];
            }
            return *this;
        }
        Bitset <N>& operator ^= (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; ++i)
            {
                bits[i] = bits[i] ^ oth.bits[i];
            }
            return *this;
        }
        
    Bitset<N>& operator <<= (const Bitset <N>& oth)
    {
        int index = 0;
        int num = 0;
        
        for(int i = oth.bitsSize - 1; i >= 0; --i)
        {
            if(oth.bits[i] == 1)
            {
                num += pow(2,index);
            }
            ++index;
        }
        
        std::string tmp = "";
        
        for(int i = 0; i < bitsSize; ++i)
        {
            tmp = tmp + std::to_string(bits[i]);
        }
        
        tmp.erase(0,num);
        for(int i = 0; i < num; ++i)
        {
            tmp = tmp + '0';
        }
        for(int i = 0; i < bitsSize; ++i)
        {
            if(tmp[i] == '1'){bits[i] = 1;}
            else{bits[i] = 0;}
        }
        return *this;
    }
        
        Bitset<N>& operator >>= (const Bitset <N>& oth)
        {
            int index = 0;
            int num = 0;
            
            for(int i = oth.bitsSize - 1; i >= 0; --i)
            {
                if(oth.bits[i] == 1)
                {
                    num += pow(2,index);
                }
                ++index;
            }
            
            std::string tmp = "";
            
            for(int i = 0; i < bitsSize; ++i)
            {
                tmp = tmp + std::to_string(bits[i]);
            }
            tmp.erase(tmp.size() - num);
            for(int i = 0; i < num; ++i)
            {
                tmp = '0' + tmp;
            }
            for(int i = 0; i < bitsSize; ++i)
            {
                if(tmp[i] == '1'){bits[i] = 1;}
                else{bits[i] = 0;}
            }
            return *this;
        }
        Bitset<N>& operator << (const Bitset <N>& oth)
        {
            int index = 0;
            int num = 0;
            
            for(int i = oth.bitsSize - 1; i >= 0; --i)
            {
                if(oth.bits[i] == 1)
                {
                    num += pow(2,index);
                }
                ++index;
            }
            
            std::string tmp = "";
            
            for(int i = 0; i < bitsSize; ++i)
            {
                tmp = tmp + std::to_string(bits[i]);
            }
            
            tmp.erase(0,num);
            for(int i = 0; i < num; ++i)
            {
                tmp = tmp + '0';
            }
            for(int i = 0; i < bitsSize; ++i)
            {
                if(tmp[i] == '1'){bits[i] = 1;}
                else{bits[i] = 0;}
            }
            return *this;
        }
        Bitset<N>& operator >> (const Bitset <N>& oth)
        {
            int index = 0;
            int num = 0;
            
            for(int i = oth.bitsSize - 1; i >= 0; --i)
            {
                if(oth.bits[i] == 1)
                {
                    num += pow(2,index);
                }
                ++index;
            }
            
            std::string tmp = "";
            
            for(int i = 0; i < bitsSize; ++i)
            {
                tmp = tmp + std::to_string(bits[i]);
            }
            tmp.erase(tmp.size() - num);
            for(int i = 0; i < num; ++i)
            {
                tmp = '0' + tmp;
            }
            for(int i = 0; i < bitsSize; ++i)
            {
                if(tmp[i] == '1'){bits[i] = 1;}
                else{bits[i] = 0;}
            }
            return *this;
        }
        bool operator == (const Bitset <N>& oth)
        {
            for(int i = 0; i < bitsSize; ++i)
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
            
            for(int i = 0; i < bitsSize; ++i)
            {
                if(this -> bits[i] == oth.bits[i])
                {
                    ++amount;
                }
            }
            if(amount == (int)(bitsSize))
            {
                return false;
            }
            return true;
        }
        
        friend std::ostream& operator << (std::ostream& COUT, const Bitset& oth)
        {
            for(int i = 0; i < oth.bitsSize; ++i)
            {
                COUT << oth.bits[i] << " ";
            }
            COUT << '\n';
            return COUT;
        }
        bool operator [](unsigned int pos);
};



#include "implementation.hpp"
#endif 

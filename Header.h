#ifndef Header_h
#define Header_h
#include <iostream>
#include <limits>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <string>

template <unsigned long long N>
class Bitset;

template <unsigned long long N>
std::ostream& operator << (std::ostream& COUT, const Bitset<N>& oth);

template <unsigned long long N>
class Bitset
{
public:
        Bitset ();
        Bitset (long long value);
        Bitset (const Bitset& oth);
        Bitset (Bitset<N>&& oth);
        ~Bitset ();
    
private:
        unsigned long long* bits;
        int bitsSize = static_cast<int>(N);

public:
        Bitset& set();
        Bitset& setting_by_given_val(long long value);
        Bitset& reset();
        Bitset& count();
        Bitset& flip();
        Bitset& to_String();
        Bitset& to_Long();
        Bitset& checking_none_all_any();
        Bitset& choosing_operation();
        Bitset& choose(int index);
        Bitset& choosing_second();
    
        bool any();
        bool none();
        bool all();
        int getSize() const;
    
        template<unsigned long long U>
        friend std::ostream& operator << (std::ostream& COUT, const Bitset<U>& oth);
        Bitset<N>& operator = (const Bitset<N>& oth);
        Bitset<N>& operator = (Bitset <N>&& oth);
        Bitset<N>& operator ~ ();
        Bitset<N>& operator &= (const Bitset <N>& oth);
        Bitset<N>& operator |= (const Bitset <N>& oth);
        Bitset<N>& operator ^= (const Bitset <N>& oth);
        Bitset<N>& operator <<= (const Bitset <N>& oth);
        Bitset<N>& operator >>= (const Bitset <N>& oth);
        Bitset<N>& operator << (const Bitset <N>& oth);
        Bitset<N>& operator >> (const Bitset <N>& oth);
        bool operator == (const Bitset <N>& oth);
        bool operator != (const Bitset <N>& oth);
        bool operator [] (unsigned int pos);
    
};

#include "implementation.hpp"
#endif // Header_h

template <unsigned long long N>

Bitset<N>::Bitset()
{
    if((N / 9 + 1) == 1)
    {
        delete [] bits;
        bits = new unsigned long long [sizeof(long)];
        bitsSize = sizeof(long);
    }
    else
    {
        delete [] bits;
        bits = new unsigned long long [sizeof(long) * (N / 9 + 1)];
        bitsSize = sizeof(long) * (N / 9 + 1);
    }
    for(int i = 0; i < bitsSize; ++i)
    {
        bits[i] = 0;
    }
}

template <unsigned long long N>

Bitset<N>::Bitset(int value)
{
    if((N / 9 + 1) == 1)
    {
        delete [] bits;
        bits = new unsigned long long [sizeof(long)];
        bitsSize = sizeof(long);
    }
    else
    {
        delete [] bits;
        bits = new unsigned long long [sizeof(long) * (N / 9 + 1)];
        bitsSize = sizeof(long) * (N / 9 + 1);
    }
    for(int i = 0; i < bitsSize; ++i)
    {
        bits[i] = 0;
    }

    if(value >= pow(2,bitsSize))
    {
        int amount = 0, x = value;
        while(x > 0)
        {
            ++amount;
            x /= 2;
        }
        delete [] bits;
        bits = new unsigned long long [sizeof(long) * (amount / 9 + 1)];
        bitsSize = sizeof(long) * (amount / 9 + 1);
        for(int i = 0; i < bitsSize; ++i)
        {
            bits[i] = 0;
        }
    }
    
    if(value == 0)
    {
        for(int i = 0; i < bitsSize; ++i)
        {
            bits[bitsSize - 1 - i] = 0;
        }
    }
    
    if(value > 0)
    {
        std::string str = "";
        while(value > 0)
        {
            str = std::to_string(value % 2) + str;
            value /= 2;
        }
        for(int i = (int)(str.size() - 1); i >= 0; --i)
        {
            if(str[i] == '1')
            {
                bits[bitsSize - 1 - (str.size() - 1 - i)] = 1;
            }
            else{bits[bitsSize - 1 - (str.size() - 1 - i)] = 0;}
        }
    }
    
    if(value < 0)
    {
        if((-1)*value >= pow(2,bitsSize))
        {
            int amount = 0, x = (-1)*value;
            while(x > 0)
            {
                ++amount;
                x /= 2;
            }
            delete [] bits;
            bits = new unsigned long long [sizeof(long) * (amount / 9 + 1)];
            bitsSize = sizeof(long) * (amount / 9 + 1);
        }
        for(int i = 0; i < bitsSize; ++i)
        {
            bits[i] = 1;
        }
        
        std::string str = "";
        value = -1*value;
        while(value > 0)
        {
            str = std::to_string(value % 2) + str;
            value /= 2;
        }
        
        for(int i = 0; i < str.length(); ++i)
        {
            if(str[str.length() - 1 - i] == '0')
            {
                bits[bitsSize - 1 - i] = 1;
            }
            else
            {
                bits[bitsSize - 1 - i] = 0;
            }
        }
        
        if(bits[bitsSize - 1] == 0)
        {
            bits[bitsSize - 1] = 1;
        }
        else
        {
            for(int i = bitsSize - 2; i >= 0; --i)
            {
                if(bits[i] == 0)
                {
                    bits[i] = 1;
                    for(int j = i + 1; j <= bitsSize; ++j)
                    {
                        bits[j] = 0;
                    }
                    break;
                }
            }
        }
    }
}


template <unsigned long long N>
Bitset<N>& Bitset<N>::choosing_operation()
{
    std::cout << "============================================================" << std::endl;
    std::cout << "\t\t\t\t\t\tMAIN MANU\t\t\t" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << std::endl << "Which operation do you choose ?" << std::endl << std::endl;
    std::cout << "\t[1]  Set bits true \t\n" << "\t[2]  Set bits in a given value \t\n" << "\t[3]  Reset(set bits to false) \t\n" << "\t[4]  Return the number of bits set to true \t\n" << "\t[5]  Toggle the value of bits \t\n" << "\t[6]  Return the number of bits that bitset holds \t\n" << "\t[7]  Returning string representation of the data \t\n" << "\t[8]  Returning long integer representation of the data \t\n" << "\t[9]  Checking all, any or none of the bit is true \t\n" << "\t[10] EXIT all program \t\n" << "\t[11] Exit operations \t\n" << std::endl;
    int index = 0;
    std::cout << "============================== Choose by index: ";
    std::cin >> index;
    std::cout << std::endl;
    Bitset<N>::choose(index);
    return *this;
}

template <unsigned long long N>

Bitset<N>& Bitset<N>::choose(int index)
{
    
    switch(index)
    {
        case 1:
            Bitset<N>::set();
            choosing_operation();
            break;
        case 2:
            Bitset<N>::setting_by_given_val();
            choosing_operation();
            break;
        case 3:
            Bitset<N>::reset();
            choosing_operation();
            break;
        case 4:
            Bitset<N>::count();
            choosing_operation();
            break;
        case 5:
            Bitset<N>::toggle_value();
            choosing_operation();
            break;
        case 6:
            Bitset<N>::getSize();
            choosing_operation();
            break;
        case 7:
            Bitset<N>::to_String();
            choosing_operation();
            break;
        case 8:
            Bitset<N>::to_Long();
            choosing_operation();
            break;
        case 9:
            Bitset<N>::checking_none_all_any();
            choosing_operation();
            break;
        case 10:
            exit(0);
        case 11:
            break;
        default:
            std::cout << "No operation, you have entered a wrong index, try again: ";
            int tryagain = 0;
            std::cin >> tryagain;
            choose(tryagain);
    }
    return *this;
}


template <unsigned long long N>
Bitset<N>::Bitset (const Bitset& oth)
{
    bitsSize = oth.bitsSize;
    bits = new unsigned long long[bitsSize];
    
        for(auto i = 0; i < bitsSize; i++)
        {
            bits[i] = oth.bits[i];
        }
}

template <unsigned long long N>
Bitset<N>::~Bitset<N>()
{
    delete [] bits;
    bits = nullptr;
}

template <unsigned long long N>
bool Bitset<N>::operator[](unsigned int pos)
{
    return bits[bitsSize - 1 - pos];
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::set()
{
    std::cout << "Setted: ";
    for(int i = 0; i < bitsSize; ++i)
    {
        bits[i] = true;
        std::cout << bits[i] << " ";
    }
    std::cout << std::endl << std::endl;
    return *this;
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::set(std::size_t place, bool val)
{
    bits[bitsSize - 1 - place] = val;
    std::cout << "Setted: ";
    for(int i = 0; i < bitsSize; ++i)
    {
        std::cout << bits[i] << " ";
    }
    std::cout << std::endl << std::endl;
    return *this;
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::reset()
{
    std::cout << "Resetted: ";
    for(int i = 0; i < bitsSize; ++i)
    {
        bits[i] = false;
        std::cout << bits[i] << " ";
    }
    std::cout << std::endl << std::endl;
    return *this;
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::count()
{
    int amount = 0;
    for(int i = 0; i < bitsSize; i++)
    {
        if(bits[i] == true)
        {
            ++amount;
        }
    }
    std::cout << "The number of bits that are true is: " << amount << std::endl << std::endl;;
    return *this;
}

template <unsigned long long N>
int Bitset<N>::getSize() const
{
    std::cout << "Size is: " << bitsSize << std::endl << std::endl;
    return bitsSize;
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::to_Long()
{
    if(Bitset<N>::all()){std::cout << "Number inside long: " << -1 << std::endl << std::endl;}
    else if(Bitset<N>::none()){std::cout << "Number inside long: " << 0 << std::endl << std::endl;}
    else
    {
        if(bits[0] == 0)
        {
            long num = 0;
            int index = 0;
            for(int i = bitsSize - 1; i >= 0; --i)
            {
                if(bits[i] == 1)
                {
                    num += pow(2,index);
                }
                ++index;
            }
            std::cout << "Number inside long: " << num << std::endl << std::endl;
        }
        else
        {
            long num = 0;
            std::string tmp = "";
            
            for(int i = 0; i < bitsSize; ++i)
            {
                tmp = tmp + std::to_string(bits[i]);
            }
            for(int i = 0; i < tmp.size(); ++i)
            {
                if(tmp[i] == '1'){tmp[i] = '0';}
                else{tmp[i] = '1';}
            }
            if(tmp[tmp.size() - 1] == 0){tmp[tmp.size() - 1] = 1;}
            else
            {
                for(int i = (int)(tmp.size() - 2); i >= 0; --i)
                {
                    if(tmp[i] == '0')
                    {
                        tmp[i] = '1';
                        for(int j = i + 1; j <= tmp.size(); ++j)
                        {
                            tmp[j] = '0';
                        }
                        break;
                    }
                }
                int index = 0;
                for(int i = (int)(tmp.size() - 1); i >= 0; --i)
                {
                    if(tmp[i] == '1')
                    {
                        num += pow(2,index);
                    }
                    ++index;
                }
            }
            std::cout << "Number inside long: " << (-1)*num << std::endl << std::endl;
        }
        
    }
return *this;
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::to_String()
{
    std::string val = "";
    for(int i = 0; i < bitsSize; ++i)
    {
        if(bits[bitsSize -1 - i] == false)
        {
            val = '0' + val;
        }
        else
        {
            val = '1' + val;
        }
    }
    std::cout << "String: " << val << std::endl << std::endl;
    return *this;
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::toggle_value()
{
    int index = 0;
    std::cout << "Enter the position or index that you want to set value: ";
    std::cin >> index;
    std::cout << "Now enter the val 1 or 0: ";
    bool val = false;
    std::cin >> val;
    bits[bitsSize - 1 - index] = val;
    
    std::cout << "Value is toggled: ";
    
    for(int i = 0; i < bitsSize; ++i)
    {
        std::cout << bits[i] << " ";
    }
    std::cout << std::endl << std::endl;
    return *this;
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::setting_by_given_val()
{
     int value = 0;
     std::cout << "Enter a value: ";
     std::cin >> value;

    
    if(value >= pow(2,bitsSize))
    {
        int amount = 0, x = value;
        while(x > 0)
        {
            ++amount;
            x /= 2;
        }
        delete [] bits;
        bits = new unsigned long long [sizeof(long) * (amount / 9 + 1)];
        bitsSize = sizeof(long) * (amount / 9 + 1);
        for(int i = 0; i < bitsSize; ++i)
        {
            bits[i] = 0;
        }
    }
    
    if(value == 0)
    {
        for(int i = 0; i < bitsSize; ++i)
        {
            bits[bitsSize - 1 - i] = 0;
        }
    }
    
    if(value > 0)
    {
        for(int i = 0; i < bitsSize; ++i)
        {
            bits[i] = 0;
        }
        std::string str = "";
        while(value > 0)
        {
            str = std::to_string(value % 2) + str;
            value /= 2;
        }
        for(int i = (int)(str.size() - 1); i >= 0; --i)
        {
            if(str[i] == '1')
            {
                bits[bitsSize - 1 - (str.size() - 1 - i)] = 1;
            }
            else{bits[bitsSize - 1 - (str.size() - 1 - i)] = 0;}
        }
    }
    
    if(value < 0)
    {
        if((-1)*value >= pow(2,bitsSize))
        {
            int amount = 0, x = (-1)*value;
            while(x > 0)
            {
                ++amount;
                x /= 2;
            }
            delete [] bits;
            bits = new unsigned long long [sizeof(long) * (amount / 9 + 1)];
            bitsSize = sizeof(long) * (amount / 9 + 1);
        }
        for(int i = 0; i < bitsSize; ++i)
        {
            bits[i] = 1;
        }
        
        std::string str = "";
        value = -1*value;
        while(value > 0)
        {
            str = std::to_string(value % 2) + str;
            value /= 2;
        }
        
        for(int i = 0; i < str.length(); ++i)
        {
            if(str[str.length() - 1 - i] == '0')
            {
                bits[bitsSize - 1 - i] = 1;
            }
            else
            {
                bits[bitsSize - 1 - i] = 0;
            }
        }
        
        if(bits[bitsSize - 1] == 0)
        {
            bits[bitsSize - 1] = 1;
        }
        else
        {
            for(int i = bitsSize - 2; i >= 0; --i)
            {
                if(bits[i] == 0)
                {
                    bits[i] = 1;
                    for(int j = i + 1; j <= bitsSize; ++j)
                    {
                        bits[j] = 0;
                    }
                    break;
                }
            }
        }
    }
    std::cout << "Your bit is: ";
    for(int i = 0; i < bitsSize; ++i)
    {
        std::cout << bits[i] << " ";
    }
    std::cout << std::endl << std::endl;
    return *this;
}

template<unsigned long long N>
bool Bitset<N>::all()
{
    for(int i = 0; i < bitsSize; ++i)
    {
        if(bits[i] == false)
        {
            return false;
        }
    }
    return true;
}

template<unsigned long long N>
bool Bitset<N>::any()
{
    for(int i = 0; i < bitsSize; ++i)
    {
        if(bits[i] == true)
        {
            return true;
        }
    }
    return false;
}

template<unsigned long long N>
bool Bitset<N>::none()
{
    for(int i = 0; i < bitsSize; ++i)
    {
        if(bits[i] == true)
        {
            return false;
        }
    }
    return true;
}

template <unsigned long long N>
Bitset<N>& Bitset<N>::checking_none_all_any()
{
    if(Bitset<N>::all())
    {
        std::cout << "All bits are true" << std::endl << std::endl;
    }
    else if(Bitset<N>::any())
    {
        std::cout << "There exists at least one bit, which is true" << std::endl << std::endl;
    }
    else if(Bitset<N>::none())
    {
        std::cout << "None of bits is true" << std::endl << std::endl;
    }
    return *this;
}

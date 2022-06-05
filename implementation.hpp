template <unsigned long long N>

Bitset<N>::Bitset(): bits()
{
    if((N / 65 + 1) == 2)
    {
        delete [] bits;
        bits = new unsigned long long[sizeof(long) * 16];
        bitsSize = sizeof(long) * 16;
    }
    else if((N / 65 + 1) == 1)
    {
        delete [] bits;
        bits = new unsigned long long [sizeof(long) * 8];
        bitsSize = sizeof(long) * 8;
    }
    else
    {
        delete [] bits;
        bits = new unsigned long long [sizeof(long) * 8 * (N / 65 + 1)];
        bitsSize = sizeof(long) * 8 * (N / 65 + 1);
    }

    for(int i = 0; i < bitsSize; ++i)
    {
        bits[i] = 0;
        std::cout << bits[i] << " ";
    }
    std::cout << std::endl;
    
}

template <unsigned long long N>

Bitset<N>::Bitset(int value)
{
    if(value >= pow(2,bitsSize))
    {
        int amount = 0, x = value;
        while(x > 0)
        {
            ++amount;
            x /= 2;
        }
        std::cout << "amount: " << amount << std::endl;
        delete [] bits;
        bits = new unsigned long long [sizeof(long) * 8 * (N / 65 + 1)];
        std::cout << "bitsSize: " << sizeof(long) * 8 * (N / 65 + 1) << std::endl;
    }
    if(value == 0)
    {
        for(int i = 0; i < bitsSize; ++i)
        {
            bits[i] = 0;
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
        std::cout << "str: " << str << std::endl;
        for(int i = 0; i < str.length(); ++i)
        {
            if(str[i] == '0')
            {
                bits[i] = 0;
            }
            else
            {
                bits[i] = 1;
            }
        }
    }
    if(value < 0)
    {
        if((-1)*value >= pow(2,bitsSize))
        {
            int amount = 0;
            
            while(value > 0)
            {
                ++amount;
                value /= 2;
            }
            delete [] bits;
            bits = new unsigned long long [sizeof(long) * 8 * (amount / 65 + 1)];
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
        int index = 0;
        int num = 0;
        for(int i = (int)(str.length() - 1); i >= 0; --i)
        {
            if(str[i] == '1'){num += pow(2,index);}
            ++index;
        }
        for(int i = 0; i < str.length(); ++i)
        {
            if(str[str.length() - 1 - i] == '0')
            {
                bits[i] = 1;
            }
            else
            {
                bits[i] = 0;
            }
        }
        int ind = 0;
        if(bits[ind] == 0)
        {
            bits[ind] = 1;
        }
        else
        {
            for(int i = 1; i <= bitsSize - 1; ++i)
            {
                if(bits[i] == 0)
                {
                    bits[i] = 1;
                    for(int j = i - 1; j >= 0; --j)
                    {
                        bits[j] = 0;
                    }
                    break;
                }
            }
        }
    }
    std::cout << "bits: " << *bits << std::endl;
}

template <unsigned long long N>
Bitset<N>::Bitset (const Bitset& oth)
{
    for(int i = 0; i < bitsSize; ++i)
    {
        oth.bits[i] = this->bits[i];
    }
}

template <unsigned long long N>
Bitset<N>::~Bitset<N>()
{
    delete [] bits;
    bits = nullptr;
}

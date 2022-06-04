template <long long N>

Bitset<N>::Bitset(): bits()
{
    for(int i = 0; i < bitsSize; ++i)
    {
        bits[i] = 0;
    }
}

template <long long N>

Bitset<N>::Bitset(int value)
{
    if(value >= pow(2,N))
    {
        Bitset<N>* ptr = new Bitset<2*N>;
        *ptr = this -> Bitset<N>;
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
            str = str + std::to_string(value % 2);
            value /= 2;
        }
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
        if((-1)*value >= pow(2,N))
        {
        
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
    //std::cout << "bits: " << bits << std::endl;
}

template <long long N>
Bitset<N>::Bitset (const Bitset& oth)
{
    for(int i = 0; i < bitsSize; ++i)
    {
        oth.bits[i] = this->bits[i];
    }
}

//template <long long N>
//Bitset<N>& Bitset<N>::resizng()
//{
//    Bitset<N> newbits = new Bitset<N>;
//    return *this;
//}

template <long long N>
Bitset<N>::~Bitset<N>(){}

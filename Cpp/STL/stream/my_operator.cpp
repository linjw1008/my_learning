#include <iostream>
#include <sstream>

typedef struct
{
    int den;
    int num;
} Fraction;

template<class charT, class traits>
inline
std::basic_ostream<charT, traits>&
operator << (std::basic_ostream<charT, traits>& strm, const Fraction& f)
{
    std::basic_ostringstream<charT, traits> s;
    s.copyfmt(strm);
    s.width(0);

    s << f.num << '/' << f.den;

    strm << s.str();

    return strm;
}

template<class charT, class traits>
inline
std::basic_istream<charT, traits>&
operator >> (std::basic_istream<charT, traits>& strm, Fraction& f)
{
    int num, den;

    strm >> num;

    //读取/号
    if (strm.peek() == '/')
    {
        strm.ignore();
        strm >> den;
    }
    else
    {
        den = 1;
    }

    //若分母为0，设置错误位
    if (den == 0)
    {
        strm.setstate(std::ios::failbit);
        return strm;
    }

    //检查是否有错误，若有错误，则不为f赋值
    if (strm)
    {
        f = {num, den};    
    }

    return strm;
}

int main()
{
    Fraction f = {1, 2};

    std::cin >> f;
    std::cout << f << std::endl;
}
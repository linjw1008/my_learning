#include <iostream>
#include <iomanip>

int main()
{
    //设置字段宽度、填充值、向左对齐
    std::cout << std::setw(8) << std::setfill('-') << -3.14 << " " 
    << std::left << std::setw(8) << 42 << std::endl;

    //设置向右对齐
    std::cout << std::setw(8) << std::right << 1223 << std::endl;

    //读入时运用字段宽度
    char buffer[11];
    std::cin >> std::setw(11) >> buffer;

    std::cout << buffer << std::endl;
}
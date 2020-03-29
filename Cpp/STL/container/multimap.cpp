#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    multimap<string, string> stocks;
    multimap<string, string> stocks1;

    //插入元素
    stocks.insert(make_pair("one", "A"));
    stocks.insert(make_pair("one", "a"));
    stocks.insert(make_pair("two", "2"));
    stocks.insert(make_pair("two", "B"));
    stocks.insert(make_pair("two", "b"));
    stocks.insert(make_pair("three", "3"));
    stocks.insert(make_pair("four", "4"));
    stocks.insert(make_pair("five", "5"));
    stocks.insert(make_pair("five", "E"));
    
    stocks1.insert(make_pair("one", "A"));
    stocks1.insert(make_pair("one", "a"));
    stocks1.insert(make_pair("two", "2"));
    stocks1.insert(make_pair("two", "B"));
    stocks1.insert(make_pair("two", "b"));
    stocks1.insert(make_pair("three", "3"));
    stocks1.insert(make_pair("four", "4"));
    stocks1.insert(make_pair("five", "5"));
    stocks1.insert(make_pair("five", "e"));

    if (stocks == stocks1) cout << "stocks == stocks1" << endl;

    //析构函数
    //stocks.~multimap();

    //打印stocks
    for (multimap<string, string>::iterator it = stocks.begin(); it != stocks.end(); ++it)
    {
        cout << it->first << "\t " << it->second << endl;
    }    
    cout << endl;

    //打印所有key为one的元素
    for (auto it = stocks.lower_bound("one"); it != stocks.upper_bound("one"); ++it)
    {
        cout << it->first << "\t " << it->second << endl;        
    }
    cout << endl;
    
    //打印所有key为two的元素
    auto range = stocks.equal_range("two");
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->first << "\t " << it->second << endl;        
    }
    cout << endl;
}
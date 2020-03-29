#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    map<string, float> stocks;
    
    //插入元素
    stocks["A"] = 100.0;
    stocks.insert(pair<string, float>("B", 120.0));
    stocks.insert(make_pair("C", 39.4));
    stocks.insert(map<string, float>::value_type("D", 354.44));

    //遍历输出
    for (map<string, float>::iterator it = stocks.begin(); it != stocks.end(); ++it)
    {
        copy(&(it->second), &(it->second) + 1, ostream_iterator<float>(cout, " "));
    }
    cout << endl;

    //修改值
    for (auto it = stocks.begin(); it != stocks.end(); ++it)
    {
        it->second = it->second * 2;
    }
    
    //遍历输出
    for (map<string, float>::iterator it = stocks.begin(); it != stocks.end(); ++it)
    {
        copy(&(it->second), &(it->second) + 1, ostream_iterator<float>(cout, " "));
    }
    cout << endl;

    //遍历删除key小于等于B的元素
    for (auto it = stocks.begin(); it != stocks.end();)
    {
        if (it->first <= "B")
        {
            stocks.erase(it++);
        }
        else
        {
            ++it;
        }
    }
    
    //遍历输出
    for (map<string, float>::iterator it = stocks.begin(); it != stocks.end(); ++it)
    {
        copy(&(it->second), &(it->second) + 1, ostream_iterator<float>(cout, " "));
    }
    cout << endl;
}
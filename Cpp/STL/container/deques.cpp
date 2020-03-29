#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    deque<string> coll;

    //赋值
    coll.assign(3, string("string"));
    //头部插入
    coll.push_back("last string");
    //末尾插入
    coll.push_front("first string");

    //利用输出流迭代器打印
    copy(coll.begin(), coll.end(), ostream_iterator<string>(cout, "\n"));
    cout << endl;

    //移除头部
    coll.pop_front();
    //移除尾部
    coll.pop_back();

    //修改元素
    for (int i = 1; i < coll.size(); ++i)
    {
        coll[i] = "another " + coll[i];
    }

    //更改大小
    //不支持reverse
    coll.resize(4, "resized string");
    copy(coll.begin(), coll.end(), ostream_iterator<string>(cout, "\n"));
}


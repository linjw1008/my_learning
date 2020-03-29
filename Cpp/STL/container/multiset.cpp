#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    typedef multiset<int, greater<int>> IntSet;

    IntSet coll1;

    //插入元素
    coll1.insert(4);
    coll1.insert(3);
    coll1.insert(2);
    coll1.insert(1);
    coll1.insert(5);
    coll1.insert(6);
    //插入5第二次，允许重复
    coll1.insert(5);
    
    //遍历输出元素
    //此处只能用!=判断是否到达末端，因为没有定义<符号
    for (IntSet::iterator p = coll1.begin(); p != coll1.end(); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;

    //元素插入
    IntSet::iterator it = coll1.insert(4);
        cout << "4 inserted as element ";
    cout << distance(coll1.begin(), it) + 1 << endl;
    
    //初始化另一个变量，赋值时元素类型一样即可，判断准则可以不同
    multiset<int> coll2(coll1.begin(), coll1.end());

    //打印元素
    copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //删除3之前的所有元素，无返回值
    coll2.erase(coll2.begin(), coll2.find(3));

    //删除所有等于5的元素，返回删除个数
    cout << coll2.erase(5) << " element(s) removed" << endl;

    //打印元素
    copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
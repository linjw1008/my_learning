//vector

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename T>
void printElem(T t)
{
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
}

int main()
{
    //两种定义方式，第二个模板参数有默认值
    vector<int> v1;
    vector<int, allocator<int>> v2(10);

    cout << "The cap of v2 is: " << v2.capacity() << endl;
    cout << "The size of v2 is: " << v2.size() << endl;
    //容量只可以变大，不可以缩小
    v2.reserve(5);
    cout << "The cap of v2 is: " << v2.capacity() << endl;

    v1.reserve(20);
    cout << "The cap of v1 is: " << v1.capacity() << endl;
    //swap会交换双方的空间，
    swap(v1, v2);
    cout << "The cap of v1 is: " << v1.capacity() << endl;
    cout << "The cap of v2 is: " << v2.capacity() << endl;

    //构造、析构、拷贝
    vector<int> v3(v1);
    vector<int> v4(10);
    vector<int> v5(100, 6);
    vector<int> v6(v5.begin(), v5.end());
    cout << "The size of v5 is: " << v5.size() << endl;
    cout << "The size of v6 is: " << v6.size() << endl;
    int v7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v8(v7, v7 + sizeof(v7)/sizeof(v7[0]));
    cout << "The size of v8 is: " << v8.size() << endl;
    printElem(v8);
    //销毁所有元素并释放内存
//    v8.~vector();
    cout << "The size of v8 is: " << v8.size() << endl;
    printElem(v8);
    cout << "The max size of v8 is: " << v8.max_size() << endl;

    //赋值，会覆盖容器原有的值
    printElem(v1);
    v1 = v5;
    printElem(v1);
    v1.assign(10, 5);
    printElem(v1);
    v1.assign(v5.begin(), v5.begin() + 6);
    printElem(v1);

    //存取
    //不检查下标
    cout << "The first elem of v8 is: " << v8[0] << endl;
    cout << "The first elem of v8 is: " << v8.front() << endl;
    cout << "The last elem of v8 is: " << v8.back() << endl;

    //迭代器
    cout << "Travel v8 from back to front: ";
    for (vector<int>::reverse_iterator it = v8.rbegin(); it != v8.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //安插、移除元素
    cout << "v8: push 100 back" << endl;
    v8.push_back(100);   
    printElem(v8);
    cout << "v8: insert 99 at pos 5" << endl;   
    v8.insert(v8.begin() + 5, 99);   
    printElem(v8);
    cout << "v8: insert three 99 at pos 5" << endl;
    v8.insert(v8.begin() + 5, 3, 99);   
    printElem(v8);
    cout << "v8: insert v8 at end" << endl;    
    v8.insert(v8.end(), v8.begin(), v8.end());   
    printElem(v8);
    cout << "v8: pop back" << endl;
    v8.pop_back();   
    printElem(v8);
    //改变大小，若参数超过原有大小，用第二个参数进行填充
    cout << "v8: resize v8 to 40" << endl;
    v8.resize(40, 1);   
    cout << "The cap of v8 is: " << v8.capacity() << endl;
    printElem(v8);
    cout << "v8: erese v8 at pos 5" << endl;
    v8.erase(v8.begin() + 5);
    printElem(v8);
    
    

    //清空所有元素
    cout << "v8: clear" << endl;
    v8.clear();   
    printElem(v8);
    cout << "The size of v8 is: " << v8.size() << endl;
    cout << "The cap of v8 is: " << v8.capacity() << endl;
    

    vector<string>  sentence;
    sentence.reserve(5);
    sentence.push_back("Hello,");
    sentence.push_back("how");
    sentence.push_back("are");
    sentence.push_back("you");
    sentence.push_back("?");

    //流迭代器用法
    copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << "max_size(): " << sentence.max_size() << endl;
    cout << "size(): " << sentence.size() << endl;
    cout << "capacity(): " << sentence.capacity() << endl;
    //swap
    swap(*sentence.begin(), *(sentence.end() - 1));
    copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));
    swap(sentence[0], sentence[sentence.size() - 1]);
    copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");
    copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    sentence.back() = "!";
    copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << "max_size(): " << sentence.max_size() << endl;
    cout << "size(): " << sentence.size() << endl;
    cout << "capacity(): " << sentence.capacity() << endl;


    return 0;
}
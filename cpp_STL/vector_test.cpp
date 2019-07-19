#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vector_int;
    int i;

    cout << "Vector size = " << vector_int.size() << endl;
    cout << "Vector capacity = " << vector_int.capacity() << endl;
	
    for(int i = 0; i < 5; i++)
    {
        vector_int.push_back(i);
        cout << "Push " << i << " to vector_int." << endl;
    }

    cout << "Vector size = " << vector_int.size() << endl;
    cout << "Vector capacity = " << vector_int.capacity() << endl;

    //访问值
    for(int i = 0; i < 5; i++)
    {
        cout << "Value of vector_int[" << i << "] = " << vector_int[i] << endl;
    }

    //使用迭代器访问值
    vector<int>::iterator v = vector_int.begin();
    while(v != vector_int.end())
    {
        cout << "Value of v = " << *v << endl;
        v++;
    }

    //pop值
    for(int i = 4; i >= 0; i--)
    {
        cout << "Pop the value " << vector_int[i] << endl;
        vector_int.pop_back();
    }

    cout << "Vector size = " <<vector_int.size() << endl;
    cout << "Vector capacity = " << vector_int.capacity() << endl;

    system("pause");

    return 0;
}
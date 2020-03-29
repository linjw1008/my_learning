//利用迭代器特性，实现distance()操作

#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

template <class iterator>
typename iterator_traits<iterator>::difference_type
distance1(iterator pos1, iterator pos2)
{
    return distance1(pos1, pos2, iterator_traits<iterator>::iterator_category());
}

template <class Raiterator>
typename iterator_traits<Raiterator>::difference_type
distance1(Raiterator pos1, Raiterator pos2, random_access_iterator_tag)
{
    return pos2 - pos1;
}


//input迭代器，对forward迭代器、双向迭代器都有效，
template <class Initerator>
typename iterator_traits<Initerator>::difference_type
distance1(Initerator pos1, Initerator pos2, input_iterator_tag)
{
    typename iterator_traits<Initerator>::difference_type d;
    for (d = 0; pos1 != pos2; ++pos1, ++d);

    return d;
}

int main()
{
    vector<int> v1(10, 11);

    cout << distance1<vector<int>::iterator>(v1.begin(), v1.end()) << endl;
}

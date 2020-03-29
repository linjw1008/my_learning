#include <iterator>
#include <iostream>
#include <set>

using namespace std;

//从output iterator 派生出一个自定义的迭代器
template <class Container>
class asso_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
{
protected:
    Container& container;
public:
    explicit asso_insert_iterator(Container& c) : container(c) {}

    asso_insert_iterator<Container>&
    operator= (const typename Container::value_type& value)
    {
        container.insert(value);
        return *this;
    }

    asso_insert_iterator<Container>& operator*()
    {
        return *this;
    }

    //++i
    asso_insert_iterator<Container>& operator++()
    {
        return *this;
    }

    //i++
    asso_insert_iterator<Container>& operator++(int)
    {
        return *this;
    }

};

template <class Container>
inline asso_insert_iterator<Container> asso_inserter(Container& c)
{
    return asso_insert_iterator<Container>(c);
}

int main()
{
    set<int> coll;

    asso_insert_iterator<set<int>> iter(coll);

    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;

    for (auto c : coll)
    {
        cout << c << " ";
    }
    cout << endl;

    asso_inserter(coll) = 44;
    asso_inserter(coll) = 55;

    for (auto c : coll)
    {
        cout << c << " ";
    }
    cout << endl;

    int tmp[] = {7, 8, 9, 10};
    copy(&tmp[0], tmp + (sizeof(tmp)/sizeof(tmp[0])), asso_inserter(coll));

    for (auto c : coll)
    {
        cout << c << " ";
    }
    cout << endl;
}
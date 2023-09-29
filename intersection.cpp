#include<iostream>
#include<list>
using std::cout;
using std::endl;
using std::list;
list<int> intersection(list<int> &l1,list<int> &l2)
{
    list<int>::iterator iter1=l1.begin();
    list<int>::iterator iter2=l2.begin();
    list<int> inter;
    while (iter1!=l1.end() && iter2!=l2.end())
    {
        if (*iter1==*iter2)
        {
            inter.push_back(*iter1);
            iter1++;
            iter2++;
        }
        else if (*iter1<*iter2)
        {
            iter1++;
        }
        else
        {
            iter2++;
        }
    }
    return inter;
}
int main()
{
    list<int> l1={1,2,3,4,5};
    list<int> l2={1,3,5};
    list<int> l3;
    l3=intersection(l1,l2);
    for (list<int>::iterator iter= l3.begin(); iter != l3.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    system("pause");
    return 0;
}
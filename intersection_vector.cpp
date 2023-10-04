#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
vector<int> intersection(vector<int> &v1,vector<int> &v2)
{
    vector<int>::iterator iter1=v1.begin();
    vector<int>::iterator iter2=v2.begin();
    vector<int> v3;
    while (iter1!=v1.end()&&iter2!=v2.end())
    {
        if (*iter1==*iter2)
        {
            v3.push_back(*iter1);
            iter1++;
            iter2++;
        }
    }
    return v3;
}
int main()
{
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={1,2,3};
    vector<int> v3=intersection(v1,v2);
    for (vector<int>::iterator iter=v3.begin(); iter != v3.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    system("pause");
    return 0;
}
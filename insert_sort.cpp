#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::move;
using std::vector;
void insert_sort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int temp=move(a[i]);
        int j;
        for (j = i; j>0 && temp<a[j-1]; j--)
        {
            a[j]=move(a[j-1]);
        }
        a[j]=move(temp);
    }
}
int main()
{
    vector<int> v1={34,8,64,51,32,21};
    insert_sort(v1);
    for (vector<int>::iterator iter = v1.begin(); iter!=v1.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    system("pause");
    return 0;
}
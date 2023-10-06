#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::move;
using std::vector;
void  insert_sort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int temp=move(a[i]);
        int j;
        for (j = i; j >0 && temp<a[j-1]; j--)
        {
            a[j]=move(a[j-1]);
        }
        a[j]=temp;
    }
}
void  shell_sort(vector<int> &a)
{
    for (int gap = a.size()/2; gap>0; gap/=2)
    {
        for (int i = gap; i < a.size(); i++)
        {
            int temp=move(a[i]);
            int j;
            for (j=i;j>0 && temp<a[j-1]; j--)
            {
                a[j]=move(a[j-1]);
            }
            a[j]=move(temp);
        }
        
    }
    
}
int main()
{
    vector<int> v1={3,1,2,5,4};
    vector<int> v2={99,32,31,30,22,21,20,23,11,6};
    insert_sort(v1);
    for (vector<int>::iterator iter = v1.begin(); iter < v1.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    cout<<"------------------\n";
    shell_sort(v2);
    for ( vector<int>::iterator iter = v2.begin(); iter != v2.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    
    system("pause");
    return 0;

}
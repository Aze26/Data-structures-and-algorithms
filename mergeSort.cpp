#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::move;
using std::vector;
void mergeRecursive(vector<int> &v,vector<int> &temp,int left,int right)
{
    if (right-left<1)
    {
        return;
    }
    int mid=left+(right-left)/2;
    mergeRecursive(v,temp,left,mid);
    mergeRecursive(v,temp,mid+1,right);
    int i=left;
    int j=mid+1;
    int k=left;
    while (i<=mid&&j<=right)
    {
        if (v[i]<v[j])
        {
            temp[k++]=v[i++];
        }
        else
        {
            temp[k++]=v[j++];
        }
    }
    while (i<=mid)
    {
        temp[k++]=v[i++];
    }
    while (j<=right)
    {
        temp[k++]=v[j++];
    }
    for (int i=left;i<=right;++i)
    {
        v[i]=temp[i];
    }
}
void mergeSort(vector<int> &v)
{
    int n=v.size();
    vector<int> temp;
    temp.resize(n);
    mergeRecursive(v,temp,0,n-1);
}
int main()
{
    vector<int> v1={5,4,3,2,1};
    mergeSort(v1);
    for (auto i = v1.begin(); i !=v1.end(); ++i)
    {
        cout<<*i<<endl;
    }
    system("pause");
    return 0;
}
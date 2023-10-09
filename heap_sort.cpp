#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::move;
using std::vector;
int leftChild(int n)
{
    return 2*n+1;
}
int rightChild(int n)
{
    return 2*n+2;
}
void swap(int &x,int &y)
{
    int temp;
    temp=move(x);
    x=move(y);
    y=move(temp);
}
int max(int &x,int &y)
{
    return x>y?x:y;
}
void percolateDown(vector<int> &v,int i,int n)
{
    if (i<0||i>=n||n<=1)
    {
        return;
    }
    int max_val;
    while (leftChild(i)<n)
    {
        if (leftChild(i)==n-1)
        {
            max_val=v[leftChild(i)];
        }
        else
        {
            max_val=max(v[leftChild(i)],v[rightChild(i)]);
        }
        if (v[i]<max_val)
        {
            if (max_val==v[leftChild(i)])
            {
                swap(v[i],v[leftChild(i)]);
                i=leftChild(i);
            }
            else
            {
                swap(v[i],v[rightChild(i)]);
                i=rightChild(i);
            }
        }
        else
        {
            break;
        }
    }
}
void heapSort(vector<int> &v)
{
    int n=v.size();
    int i;
    for ( i = (n-1)/2; i>=0; --i)
    {
        percolateDown(v,i,n);
    }
    int val;
    for ( i = 0; i < n; i++)
    {
        val=v[0];
        v[0]=v[n-1-i];
        percolateDown(v,0,n-1-i);
        v[n-1-i]=val;
    }
}
int main()
{
    vector<int> v1={5,4,3,2,1};
    heapSort(v1);
    for (vector<int>::iterator i = v1.begin(); i!=v1.end(); i++)
    {
        cout<<*i<<endl;
    }
    system("pause");
    return 0;
}
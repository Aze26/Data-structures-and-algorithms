#include<iostream>
using namespace std;
int find_target(int *array,int target,int len)
{
    int left=0;
    int right=len-1;
    while (left<=right)
    {
        int mid=(left+right)/2;
        if (array[mid]>target)
        {
            right=right-1;
        }
        else if (array[mid]<target)
        {
            left=left+1;
        }
        else
            return mid;
    }
    return -1;
}
int main()
{
    int array[5]={1,2,3,4,5};
    cout<<find_target(array,3,5);
    system("pause");
    return 0;
}
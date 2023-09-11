#include<iostream>
using namespace std;
int search_arr(int *array,int target,int len)
{
    int left=0;
    int right=len-1;
    while (left<=right)
    {
        int mid=(left+right)/2;
        if (array[mid]<target)
        {
            left=mid+1;
        }
        else if (array[mid]>target)
        {
            right=mid-1;
        }
        else
            return mid;
    }
    return right+1;
}
int main()
{
    int array[4]={1,3,5,6};
    cout<<search_arr(array,7,4);
    system("pause");
    return 0;
}

#include<iostream>
using namespace std;
int *sortSquare(int *array,int len)
{
    int left=0;
    int right=len-1;
    int *ans=new int [len];
    for (int index = len-1; index >= 0; index--)
    {
        int ls=array[left]*array[left];
        int rs=array[right]*array[right];
        if (ls>rs)
        {
            ans[index]=ls;
            left++;
        }
        else
        {
            ans[index]=rs;
            right--;
        }
    }
    return ans;
}
int main()
{
    int array[5]={-2,-1,3,4,6};
    int *pa=sortSquare(array,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<pa[i]<<endl;
    }
    system("pause");
    return 0;
}
#include<iostream>
using namespace std;
void bubble_sort(int *arr,int size)
{
    int temp;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int array[5]={2,1,3,5,4};
    bubble_sort(array,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i]<<endl;
    }
    system("pause");
    return 0;
}
#include<iostream>
using namespace std; 
void quickSort(int a[], int low ,int high)
{
	if(low<high)  //判断是否满足排序条件，递归的终止条件
	{
		int i = low, j = high;   //把待排序数组元素的第一个和最后一个下标分别赋值给i,j，使用i,j进行排序；
		int x = a[low];    //将待排序数组的第一个元素作为哨兵，将数组划分为大于哨兵以及小于哨兵的两部分                                   
		while(i<j)  
		{
            while (i<j && a[j]>=x)
            {
                j--;
            }
            if (i<j)
            {
                a[i]=a[j];
                i++;
            }
            while (i<j && a[i]<=x)
            {
                i++;
            }
            if (i<j)
            {
                a[j]=a[i];
                j--;
            }
		} 
	    a[i] = x;   
		quickSort(a, low ,i-1);  
		quickSort(a, i+1 ,high);
	}
}
 
int main()
{  
    int a[5]={2,1,4,3,5};
    quickSort(a,0,4);  
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<endl;
    }
    system("pause"); 
} 
 
 
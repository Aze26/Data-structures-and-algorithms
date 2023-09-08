#include<iostream>
using namespace std;
int remove_num(int *arary,int val,int len)
{
    int slow=0;
    for (int fast = 0; fast < len; fast++)
    {
        if (arary[fast]!=val)
        {
            arary[slow]=arary[fast];
            slow++;
        }
    }
    return slow;
}
int main()
{
    int array[5]={1,2,3,3,5};
    int s=remove_num(array,3,5);
    cout<<s;
    cout<<"\n-------------------------------\n";
    for (int i = 0; i < s; i++)
    {
        cout<<"array["<<i<<"]:"<<array[i]<<endl;
    }
    system("pause");
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int> &v)
{
    int n=v.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
            }
        }
    }
}
int main()
{
    vector<int> v2={10,9,8,7,6};
    bubbleSort(v2);
    for (int i = 0; i < 5; i++)
    {
        cout<<v2[i]<<endl;
    }
    system("pause");
    return 0;
}
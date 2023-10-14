#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::move;
using std::swap;
using std::vector;
void selectSort(vector<int> &nums)
{
    int n=nums.size();
    for (int i = 0; i < n-1; i++)
    {
        int k=i;
        for (int j = i+1; j < n; j++)
        {
            if (nums[j]<nums[k])
            {
                k=j;
            }
        }
        swap(nums[i],nums[k]);
    }
}
int main()
{
    vector<int> v1={6,5,4,3,2,1};
    selectSort(v1);
    for (auto i = v1.begin(); i !=v1.end(); i++)
    {
        cout<<*i<<endl;
    }
    
    system("pause");
    return 0;
}
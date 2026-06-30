#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
int secondLargestElement(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        int mini = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=mini && nums[i]<maxi) mini = nums[i];
        }
        if(mini == INT_MIN) mini = -1;
        return mini;
    }

int main()
{
    vector<int> a = {8, 8, 7, 6, 5
    };
    cout<<secondLargestElement(a)<<endl;

    return 0;
}
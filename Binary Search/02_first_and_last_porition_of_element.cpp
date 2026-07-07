#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int maxi = -1;
        int mini = -1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target){
                mini = mid;
                e = mid -1;
            }
            else if(nums[mid]>target) e = mid-1;
            else s = mid+1;
        }
        s=0;
        e=nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target){
                maxi = mid;
                s = mid + 1;
            }
            else if(nums[mid]>target) e = mid-1;
            else s = mid+1;
        }
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};
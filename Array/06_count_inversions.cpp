#include<iostream>
#include<vector>
using namespace std;


long long merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long invCount = 0;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                invCount += (mid - left + 1);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left++]);
        }

        while(right <= high) {
            temp.push_back(nums[right++]);
        }

        for(int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return invCount;
    }

    long long mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) return 0;

        int mid = low + (high - low) / 2;

        long long invCount = 0;
        invCount += mergeSort(nums, low, mid);
        invCount += mergeSort(nums, mid + 1, high);
        invCount += merge(nums, low, mid, high);

        return invCount;
    }

    long long numberOfInversions(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
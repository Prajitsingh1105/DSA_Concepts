#include <iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n = nums.size();
        int sum1 = n * (n+1) /2;
        return sum1-sum;
    }
int main()
{
	vector<int> a = {0,1,2,3,5};
	cout<<missingNumber(a);
	return 0;
}
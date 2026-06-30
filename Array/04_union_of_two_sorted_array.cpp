#include <iostream>
#include<vector>
using namespace std;
vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ans;
	int i = 0;
	int j = 0;
	while(i<nums1.size() && j<nums2.size()) {
		if(nums1[i]<nums2[j]) {
			ans.push_back(nums1[i]);
			//cout<<nums1[i]<<" ";
			i++;
		}
		else if(nums1[i]==nums2[j]){
		    ans.push_back(nums1[i]);
		    i++;
		    j++;
		}
		else {
			ans.push_back(nums2[j]);
			//cout<<nums2[j]<<" ";
			j++;
		}

	}
	while(j<nums2.size()) {
		ans.push_back(nums2[j]);
		j++;
	}
	while(i<nums1.size()) {
		ans.push_back(nums1[i]);
		i++;
	}
	return ans;
}
int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	vector<int> b = {1, 2, 7};
	vector<int> ans = unionArray(a,b);
	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
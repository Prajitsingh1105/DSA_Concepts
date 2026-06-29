#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int i = 0;
    int j = 1;
    int maxi = 0;
    while(i<prices.size() && j<prices.size()){
        if(prices[i]>prices[j]){
            i++;
            j = i+1;
        }
        else{
            int diff = prices[j]-prices[i];
            cout<<"Diff: "<<diff<<endl;
            maxi = max(maxi,diff);
            cout<<maxi<<endl;
            j++;
        }
    }
    return maxi;
}

int main() {
    vector<int> prices = {7,6,4,3,1};
    int ans = maxProfit(prices);
    cout<<"Ans: "<<ans<<endl;
}

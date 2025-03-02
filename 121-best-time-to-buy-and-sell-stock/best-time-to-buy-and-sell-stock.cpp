class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, mini=prices[0];

        for(int i=0;i<prices.size();i++) {
            mini=min(mini,prices[i]);

            int val=prices[i]-mini;
            profit=max(profit,val);
        }
        return profit;
    }
};
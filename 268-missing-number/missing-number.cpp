class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int s1=(n*(n+1))/2;
        int s2=0;
        for(auto it:nums) s2+=it;
        int ans=s1-s2;
        return ans;
    }
};
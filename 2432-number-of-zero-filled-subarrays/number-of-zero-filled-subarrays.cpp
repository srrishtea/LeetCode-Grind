class Solution {
    int n;
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        n=nums.size();
        long long cnt=0;
        long long ans=0;
        for (int num:nums) {
            if (num==0) {
                cnt++;
                ans+=cnt;
            } else {
                cnt=0;
            }
        }

        return ans;
    }
};
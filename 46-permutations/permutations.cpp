class Solution {
    void f(int cur, vector<int>&nums,vector<vector<int>>&ans) {
        int n=nums.size();
        if(cur==n) {
            ans.push_back(nums);
            return;
        }

        for(int i=cur;i<n;i++) {
            swap(nums[cur],nums[i]);
            f(cur+1,nums,ans);
            swap(nums[cur],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        f(0,nums,ans);
        return ans;

    }
};
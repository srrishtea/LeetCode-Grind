class Solution {
public:
    bool possible(int val, vector<int>&nums, int t) {
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=ceil((double)nums[i]/(double)val);
        }

        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;

        while(low<=high) {
            int mid=(low+high)/2;
            if(possible(mid,nums,threshold)) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
            
        }

        return ans;
        

    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0, ps=0, i=0;
        unordered_map<int,int>mp;
        mp[0]=1;

        while(i<n) {
            ps+=nums[i];
            if(mp.find(ps-k) != mp.end()) {
                cnt+=mp[ps-k];
            }
            mp[ps]++;
            i++;
        
        }

        return cnt;
    }
};
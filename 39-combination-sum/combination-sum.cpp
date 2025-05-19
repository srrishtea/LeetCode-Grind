class Solution {
private:
    void f(int ind, int target, vector<vector<int>>&ans, vector<int>&ds ,vector<int>& can) {
        if(ind>=can.size()) {
            if(target==0) ans.push_back(ds);
            return;
            
        }

        if(can[ind]<=target) {
            ds.push_back(can[ind]);
            f(ind,target-can[ind],ans,ds,can);
            ds.pop_back();
        }
        f(ind+1,target,ans,ds,can);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,ans,ds,candidates);
        return ans;
    }
};
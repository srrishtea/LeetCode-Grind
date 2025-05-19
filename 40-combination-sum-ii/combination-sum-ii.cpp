class Solution {
private:
    void f(int ind, int target, vector<vector<int>>& ans, vector<int>& ds,
           vector<int>& can) {

       
            if (target == 0) {
                ans.push_back(ds);
                return; 
                }
        

        for (int i = ind; i < can.size(); i++) {
            if (i > ind && can[i] == can[i - 1])
                continue;
            if (can[i] > target)
                break;
            ds.push_back(can[i]);
            f(i + 1, target - can[i], ans, ds, can);
            ds.pop_back();
        }

        //f(ind + 1, target, ans, ds, can);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        f(0, target, ans, ds, candidates);
        return ans;
    }
};
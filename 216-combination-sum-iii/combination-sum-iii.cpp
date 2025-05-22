class Solution {
private:
    void f(int num, int sum, vector<int>&cur, vector<vector<int>>&ans, int k, int n) {
        if (cur.size() > k || sum > n) return;
        if(cur.size()==k) {
            if(sum==n) ans.push_back(cur);
            return;
        }
        if(num>9) return;

        cur.push_back(num);
        f(num+1, sum+num,cur,ans,k,n);
        cur.pop_back();
        f(num+1, sum,cur,ans,k,n);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>cur;
        f(1,0,cur,ans,k,n);
        return ans;
    }
};
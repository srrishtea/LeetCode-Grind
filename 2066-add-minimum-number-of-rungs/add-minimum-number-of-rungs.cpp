class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int prev = 0, res = 0;
        for(int i = 0, n = rungs.size(); i < n; ++i){
            res += (rungs[i] - prev - 1) / dist;
            prev = rungs[i];
        }
        return res;
    }
};
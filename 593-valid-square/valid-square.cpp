class Solution {
public:
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dists = {
            dist(p1, p2), dist(p1, p3), dist(p1, p4),
            dist(p2, p3), dist(p2, p4), dist(p3, p4)
        };
        
        sort(dists.begin(), dists.end());
        
        return dists[0] > 0 && dists[0] == dists[1] && dists[0] == dists[2] && dists[0] == dists[3] &&
               dists[4] == dists[5] && dists[4] == 2 * dists[0];
    }
};

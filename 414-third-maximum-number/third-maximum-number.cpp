class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq;
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                pq.push(num);
                seen.insert(num);
            }
        }

        if (pq.size() < 3) return pq.top();  
        for (int i = 0; i < 2; ++i) pq.pop();  
        return pq.top();
    }
};

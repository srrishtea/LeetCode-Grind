class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }

        int ans = 0;
        
        // Iterate through the set
        for (auto it : st) {
            // If `it-1` is not in the set, then `it` is the start of a sequence
            if (st.find(it - 1) == st.end()) {
                int currentNum = it;
                int cnt = 1;
                
                // Count the length of the sequence starting from `it`
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    cnt++;
                }

                // Update the answer with the longest sequence length found
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};

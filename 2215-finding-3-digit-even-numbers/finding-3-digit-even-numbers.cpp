class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        for(int i = 100; i <= 999; i++) {
            if(i % 2 == 0) st.insert(i);
        }
        vector<int> ans;
        for(auto it : st) {
            vector<int> copy = digits;
            
            int a = it % 10;
            auto t = find(copy.begin(), copy.end(), a);
            if(t != copy.end()) {
                copy.erase(t);
            } else {
                continue;
            }

            int b = (it / 10) % 10;
            t = find(copy.begin(), copy.end(), b);
            if(t != copy.end()) {
                copy.erase(t);
            } else {
                continue;
            }

            int c = (it / 100) % 10;
            t = find(copy.begin(), copy.end(), c);
            if(t != copy.end()) {
                copy.erase(t);
            } else {
                continue;
            }

            ans.push_back(it);
        }
        return ans;
    }
};

class Solution {
private:
    bool ispalin(string s) {
        if(s.size() == 1) return true;
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }

    void f(int ind, string& s, vector<string>& cur, vector<vector<string>>& ans) {
        if(ind == s.size()) {
            ans.push_back(cur);
            return;
        }

        for(int i = ind; i < s.size(); i++) {
            string temp = s.substr(ind, i - ind + 1);
            if(ispalin(temp)) {
                cur.push_back(temp);
                f(i + 1, s, cur, ans);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        f(0, s, cur, ans);
        return ans;
    }
};

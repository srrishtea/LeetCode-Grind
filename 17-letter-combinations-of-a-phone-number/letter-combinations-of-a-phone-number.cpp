class Solution {
private:
    unordered_map<char, string> mpp = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    void f(int ind, string &cur, string&digits, vector<string>& ans) {
        if(ind==digits.size()) {
            ans.push_back(cur);
            return;
        }
        for(char ch:mpp[digits[ind]]) {
            cur.push_back(ch);
            f(ind+1,cur,digits,ans);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>ans;
        string cur="";
        f(0,cur,digits,ans);
        return ans;

    }
};
class Solution {
public:
    int n;
    string reverseWords(string s) {
        n = s.length();
        if (n == 0 || n == 1) return s;
        int i = n - 1;
        string ans;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;
            
            int j = i;
            while (j >= 0 && s[j] != ' ') j--;

            if (!ans.empty()) ans += ' ';
            ans += s.substr(j + 1, i - j);

            i = j - 1;
        }

        return ans;
    }
};

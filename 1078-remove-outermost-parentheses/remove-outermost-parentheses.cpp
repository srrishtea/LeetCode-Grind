class Solution {
public:
    int n;
    string removeOuterParentheses(string s) {
        n = s.length();
        string ans;

        if (n == 0)
            return "";
        int i = 0;
        stack<int> st;

        while (i < n) {
            if (s[i] == '(') {
                st.push(i);
                i++;
            } else {
                int j;
                if (!st.empty()) {
                    j = st.top();
                    st.pop();
                }

                if (st.empty()) {
                    ans += s.substr(j + 1, i - j - 1);
                }
                i++;
            }
        }

        return ans;
    }
};
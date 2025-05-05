class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        int prev = 0, i = 0;
        while (i < n) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if (num <= prev) return false;
                prev = num;
            } else {
                i++;
            }
        }
        return true;
    }
};

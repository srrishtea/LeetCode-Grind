class Solution {
public:
    int myAtoi(string str) {
        return convert(str, 0);
    }

private:
    const int MAX_INT = INT_MAX;
    const int MIN_INT = INT_MIN;

    int convert(const string& str, int pos) {
        int len = str.size();
        while (pos < len && str[pos] == ' ') {
            pos++;
        }

        if (pos == len) return 0;

        int sign = 1;
        if (str[pos] == '+' || str[pos] == '-') {
            if (str[pos] == '-') sign = -1;
            pos++;
        }

        long num = extractNumber(str, pos, 0);
        num *= sign;

        if (num < MIN_INT) return MIN_INT;
        if (num > MAX_INT) return MAX_INT;
        return static_cast<int>(num);
    }

    long extractNumber(const string& str, int pos, long value) {
        if (pos >= str.size() || !isdigit(str[pos])) {
            return value;
        }

        value = value * 10 + (str[pos] - '0');
        if (value > static_cast<long>(MAX_INT) + 1) return value;

        return extractNumber(str, pos + 1, value);
    }
};

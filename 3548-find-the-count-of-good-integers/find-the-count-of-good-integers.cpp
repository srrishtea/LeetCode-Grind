class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> uniquePalindromes;
        int halfBase = pow(10, (n - 1) / 2);
        int isOdd = n & 1;

        for (int i = halfBase; i < halfBase * 10; i++) {
            string num = to_string(i);
            num += string(num.rbegin() + isOdd, num.rend());
            long long palindrome = stoll(num);
            if (palindrome % k == 0) {
                sort(num.begin(), num.end());
                uniquePalindromes.emplace(num);
            }
        }

        vector<long long> fact(n + 1, 1);
        long long result = 0;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        for (const string &num : uniquePalindromes) {
            vector<int> digitCount(10);
            for (char c : num) {
                digitCount[c - '0']++;
            }

            long long perm = (n - digitCount[0]) * fact[n - 1];
            for (int count : digitCount) {
                perm /= fact[count];
            }
            result += perm;
        }

        return result;
    }
};

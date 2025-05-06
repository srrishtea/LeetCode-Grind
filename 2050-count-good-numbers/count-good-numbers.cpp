class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long x, long long y) {
        long long res = 1;
        x = x % mod;
        while (y > 0) {
            if (y % 2 == 1) res = (res * x) % mod;
            x = (x * x) % mod;
            y = y / 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};

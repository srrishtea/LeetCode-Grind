#define ll long long

class Solution {
public:
    ll maximumStrength(vector<int>& nums, ll k) {
        ll n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1e13));

        dp[0][0] = nums[0] * k;

        for (ll i = 1; i < n; i++) {
            dp[i][0] = max({nums[i] * k, dp[i - 1][0] + nums[i] * k});
        }

        for (ll j = 1; j < k; j++) {
            ll newK = k - j;
            ll sign = (newK % 2 != 0) ? 1 : -1;
            for (ll i = j; i < n; i++) {
                dp[i][j] =
                    nums[i] * newK * sign + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }

        ll maxStr = -1e13;

        for (ll i = 0; i < n; i++) {
            maxStr = max(maxStr, dp[i][k - 1]);
        }

        return maxStr;
    }
};
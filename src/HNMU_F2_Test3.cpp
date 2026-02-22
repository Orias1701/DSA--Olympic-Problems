#include <bits/stdc++.h>
using namespace std;
const long long MOD = 123456789;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long S;
    cin >> n >> S;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    // ==================== n ≤ 40 ====================
    if (n <= 40) {
        int n1 = n / 2;
        int n2 = n - n1;

        vector<long long> left, right;
        left.reserve(1LL << n1);    // 2^n1
        right.reserve(1LL << n2);   // 2^n2

        // for (int mask = 0; mask < n1*2; ++mask) {
        //     long long sum = 0;
        //     for (int i = 0; i < n1; ++i)
        //         if (mask & (i*2)) sum += a[i];
        //     left.push_back(sum);
        // }

        for (int mask = 0; mask < (1 << n1); ++mask) {
            long long sum = 0;
            for (int i = 0; i < n1; ++i)
                if (mask & (1 << i)) sum += a[i];
            left.push_back(sum);
        }

        for (int mask = 0; mask < (1 << n2); ++mask) {
            long long sum = 0;
            for (int i = 0; i < n2; ++i)
                if (mask & (1 << i)) sum += a[n1 + i];
            right.push_back(sum);
        }

        sort(right.begin(), right.end());

        long long ans = 0;
        for (auto x : left) {
            long long need = S - x;
            auto range = equal_range(right.begin(), right.end(), need);
            ans = (ans + (range.second - range.first)) % MOD;
        }

        cout << ans % MOD;
    }
    // ==================== n > 40 ====================
    else {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int x = 1; x <= n; x++) {
            for (int s = n; s >= x; s--)
            dp[s] = (dp[s] + dp[s-x]) % MOD;
        }
        cout << dp[n];
    }


    // else {
    //     unordered_map<long long, long long> dp;
    //     dp.reserve(1000000);
    //     dp[0] = 1;

    //     for (int i = 0; i < n; ++i) {
    //         unordered_map<long long, long long> add;
    //         add.reserve(200000);

    //         for (auto &[sum, cnt] : dp) {
    //             long long new_sum = sum + a[i];
    //             if (new_sum <= S)
    //                 add[new_sum] = (add[new_sum] + cnt) % MOD;
    //         }

    //         for (auto &[s, c] : add)
    //             dp[s] = (dp[s] + c) % MOD;
    //     }

    //     cout << (dp.count(S) ? dp[S] : 0);
    // }

    return 0;
}

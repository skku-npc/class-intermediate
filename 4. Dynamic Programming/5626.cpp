#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> v;
long long dp1[5010];
long long dp2[5010];
const int MOD = 1e9 + 7;

long long solve() {
    if (v.front() > 0 || v.back() > 0)
        return 0;
    v.front() = v.back() = 0;
    dp1[0] = 1;
    for (int i = 1; i < n; i++) {
        memset(dp2, 0, sizeof(dp2));
        if (v[i] == -1) {
            dp2[0] = (dp1[0] + dp1[1]) % MOD;
            for (int j = 1; j < 5005; j++)
                dp2[j] = (dp1[j - 1] + dp1[j] + dp1[j + 1]) % MOD;
        } else if (v[i] > 0) {
            dp2[v[i]] = (dp1[v[i] - 1] + dp1[v[i]] + dp1[v[i] + 1]) % MOD;
        } else {
            dp2[0] = (dp1[0] + dp1[1]) % MOD;
        }
        swap(dp1, dp2);
    }
    return dp1[0];
}

int main() {
    scanf("%d\n", &n);
    v.resize(n);
    for (auto &i : v)
        scanf("%d", &i);
    printf("%lld\n", solve());
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
int a[10005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    int sum = a[0];

    while (r < n) {
        if (sum == m) ans++;
        if (sum > m) {
            sum -= a[l++];
        } else {
            sum += a[++r];
        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
int arr[10005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int l = 0, r = 1;
    while (r <= n) {
        if (arr[r] - arr[l] == m) ans++;
        if (arr[r] - arr[l] <= m) {
            r++;
        } else {
            l++;
        }
    }

    cout << ans << endl;
}
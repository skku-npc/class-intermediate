#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 0; i <= 1000; i++) {
        if (cnt[i] == 0) continue;
        if (cnt[i + 1] > 0) {
            int x = i + 2;
            while (x <= 1000 && cnt[x] == 0) x++;
            if (x > 1000) {
                while (cnt[i + 1] > 0) {
                    cout << i + 1 << ' ';
                    cnt[i + 1]--;
                }
                while (cnt[i] > 0) {
                    cout << i << ' ';
                    cnt[i]--;
                }
            } else {
                while (cnt[i] > 0) {
                    cout << i << ' ';
                    cnt[i]--;
                }
                cout << x << ' ';
                cnt[x]--;
            }
        } else {
            while (cnt[i] > 0) {
                cout << i << ' ';
                cnt[i]--;
            }
        }
    }
    cout << endl;
}
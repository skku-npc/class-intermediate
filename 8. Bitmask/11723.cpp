#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int bitset = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        int x;
        cin >> s;

        if (s == "add") {
            cin >> x;
            bitset |= (1 << x);
        } else if (s == "remove") {
            cin >> x;
            bitset &= ~(1 << x);
        } else if (s == "check") {
            cin >> x;
            cout << ((bitset >> x) & 1) << '\n';
        } else if (s == "toggle") {
            cin >> x;
            bitset ^= (1 << x);
        } else if (s == "all") {
            bitset = (1 << 21) - 1;
        } else if (s == "empty") {
            bitset = 0;
        }
    }
}
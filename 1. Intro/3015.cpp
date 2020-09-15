#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
vector<int> height;
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    height.resize(n);
    for (auto &i : height) cin >> i;
    for (auto h : height) {
        int cnt = 1;
        while (!s.empty() && s.top().first <= h) {
            ans += s.top().second;
            if (s.top().first == h) {
                cnt += s.top().second;
            }
            s.pop();
        }
        if (!s.empty()) ans++;
        s.emplace(h, cnt);
    }
    cout << ans << endl;
}

// 백준 3015번: 오아시스 재결합
// https://www.acmicpc.net/problem/3015

///// 풀이: 스택 /////
// ...

#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        v.resize(n);
        for (auto &i : v) {
            cin >> i.first >> i.second;
        }
        sort(v.begin(), v.end());
        int ans = 1;
        int min_rank = v[0].second;
        for (int i = 1; i < n; i++) {
            if (v[i].second < min_rank) {
                min_rank = v[i].second;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}

// 백준 1946번: 신입 사원
// https://www.acmicpc.net/problem/1946

///// 풀이: 그리디 알고리즘 /////
// 서류심사(v[i].first)를 기준으로 정렬 후,
// 0 <= j < i인 모든 j에 대해 v[i].first > v[j].first이므로
// v[i].second < v[j].second이 성립하는지 확인한다. (성립 시 ans++)
// 이를 각 i에 대해 O(1)에 연산하기 위해 v[j].second의 최솟값을
// min_rank로 저장해둔다.

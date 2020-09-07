#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    v.resize(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        ans += v[i] * (n - i);
    }
    cout << ans << endl;
}

// 백준 11399번: ATM
// https://www.acmicpc.net/problem/11399

///// 풀이: 그리디 알고리즘 /////
// 시간의 합을 구하면, 식은 다음과 같다.
// SUM = (p_0 * n) + (p_1 * (n-1)) + (p_2 * (n-2)) +
//       ... + (p_(n-2) * 2) + (p_(n-1) * 1)
// 즉, p_0이 작을 수록, 그 다음 p_1이 작을 수록, p_2이 작을 수록...
// SUM의 값이 최소가 됨을 유추할 수 있다. (증명 생략)
// 따라서, p를 오름차순으로 정렬하고 위 식을 계산하면 된다.

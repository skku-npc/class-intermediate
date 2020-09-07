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
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i] * (i + 1));
    }
    cout << ans << endl;
}

// 백준 2217: 로프
// https://www.acmicpc.net/problem/2217

///// 풀이: 그리디 알고리즘 /////
// k개의 로프를 사용하는 상황을 가정하자.
// 각 로프의 최대 중량을 a_0, a_1, ... a_(k-1)이라 하면
// 이 때 로프 전체의 최대 중량은 min(a) * k이다.
// 따라서, 각 k에 대해 min(a)가 최대가 될 수 있는 상황만 고려하면 된다.
// 즉, 주어진 로프의 최대 중량을 내림차순으로 정렬하고 앞의 k개만 택한다.
// 이를 k = 1부터 k = n까지 순회하며 가능한 최대 중량을 찾는다.

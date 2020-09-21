#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    v.resize(n);
    for (auto &i : v) cin >> i;
    reverse(v.begin(), v.end());
    for (auto i : v) {
        ans += k / i;
        k %= i;
    }
    cout << ans << endl;
}

/* 풀이: 그리디 알고리즘
 *
 * 문제를 꼼꼼하게 읽어보면 다음 접근을 얻을 수 있다.
 * i < j 일 때 A[i] * d = A[j]이므로, (d는 자연수) A[j]원을 A[i]원짜리 동전 대신
 * A[j]원 짜리 동전으로 내면 d - 1개의 동전을 절약할 수 있다.
 *
 * 이 발상을 확장시키면, 가장 큰 동전부터 낼 수 있는 대로 내는 것이 정답이라는
 * 발상을 얻을 수 있다.
 *
 * 즉, A가 오름차순 이므로 뒤에서부터 순회하며(내림차순) k원 중 낼 수 있는대로
 * 최대한 내며 동전 개수를 세면 정답을 얻을 수 있다.
 */
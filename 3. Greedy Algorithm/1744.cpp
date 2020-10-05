#include <bits/stdc++.h>
using namespace std;

int n, x;
long long ans;
vector<int> pos, neg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            ans++;
        } else {
            (x > 0 ? pos : neg).push_back(x);
        }
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    for (size_t i = 1; i < pos.size(); i += 2) {
        ans += pos[i - 1] * pos[i];
    }
    for (size_t i = 1; i < neg.size(); i += 2) {
        ans += neg[i - 1] * neg[i];
    }
    if (pos.size() & 1) ans += pos.back();
    if (neg.size() & 1) ans += neg.back();
    cout << ans << endl;
}

/* 풀이: 그리디 알고리즘
 *
 * (당연히 안될 것 같긴 하지만) 먼저 완전 탐색을 생각해보자. 모든 수를 묶음에
 * 속하도록 하는 경우를 고려하자. 조금 생각해보면 오차가 있긴 하지만 대략 O(N!)
 * 꼴의 경우의 수가 존재함을 유추할 수 있다. 하지만 묶음에 속하지 않는 수들도
 * 있을 수 있기에, 이를 고려하면 이보다 훨씬 많은 경우의 수가 존재할 것이다. 즉
 * 완전 탐색으로의 접근은 불가능하다.
 *
 * 다음과 같은 발상이 가능하다.
 * 1. 양수는 양수끼리, 음수는 음수끼리 묶는 것이 합이 최대가 나오는 경우다.
 * 2. 부호가 같은 두 수에 대해 절댓값이 큰 수끼리 곱할 수록 합이 최대로 나온다.
 *
 * 이에 추가로 고려해야 하는 사항이, 1이 포함된 경우다.
 * 1과 양수 x에 대해, (1 * x) < (1 + x) 이므로 1은 묶지 않아야 합이 최대로
 * 나온다.
 *
 * 위 발상들을 적절하게 구현으로 옮기면 AC를 받을 수 있다.
 */
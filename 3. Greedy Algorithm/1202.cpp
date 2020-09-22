#include <bits/stdc++.h>
using namespace std;

int n, k;
long long ans;
vector<pair<int, int>> gem;
multiset<int> bag;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    gem.resize(n);
    for (auto &i : gem) {
        cin >> i.second >> i.first;
        i.first = -i.first;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        bag.insert(x);
    }
    sort(gem.begin(), gem.end());
    for (auto i : gem) {
        auto it = bag.lower_bound(i.second);
        if (it != bag.end()) {
            ans -= (long long)i.first;  // 가격이 음수로 저장되어있음
            bag.erase(it);
        }
    }
    cout << ans << endl;
}

/* 풀이: 그리디 알고리즘
 *
 * 완전 탐색을 고려해보자. 가방을 줄 세워 고정해두고, 보석을 줄 세울 수 있는
 * 모든 경우로 줄 세운 뒤, 각각 매칭되는 가방에 보석을 넣어보는 접근을 떠올릴 수
 * 있다. 보석을 줄 세우는 경우는 O(N!)으로, 연산이 불가능하다.
 *
 * 대신 다음과 같은 발상이 가능하다.
 * 1. 가능한 비싼 보석을 담는 것이 유리하다.
 * 2. 가능한 보석을 가장 작은 무게의 가방에 담는 것이 유리하다.
 *
 * 위 발상에 따라 보석을 정렬하고, 각 보석을 가방에 담는 코드를 구현하면 AC를
 * 받을 수 있다.
 *
 * (위 코드에서 보석은 가격이 높은 순서로, 무게가 작은 순서로 정렬했다.)
 */
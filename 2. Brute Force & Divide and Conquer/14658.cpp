#include <bits/stdc++.h>
using namespace std;

int n, m, l, k;
int ans;
vector<pair<int, int>> star;
vector<int> v_x, v_y;

bool in_range(int x, int y, pair<int, int> i) {
    return x <= i.first && i.first <= x + l && y <= i.second &&
           i.second <= y + l;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> l >> k;
    star.resize(k);
    for (auto &i : star) {
        cin >> i.first >> i.second;
        v_x.push_back(i.first);
        v_y.push_back(i.second);
    }
    for (auto x : v_x) {
        for (auto y : v_y) {
            int cnt = 0;
            for (auto i : star) {
                if (in_range(x, y, i)) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << k - ans << endl;
}

/////// 풀이: 완전 탐색 ///////
// 트램펄린의 좌측 상단 꼭짓점의 좌표만 고려하면 된다. 이를 (0 ~ N, 0 ~ M)의
// 모든 값에 대해 연산하면 O(NMK)으로 당연히 TLE를 받는다. 대신 별똥별이 떨어진
// 위치들의 x, y 좌표만 대입하면 O(K^3)으로 무난하게 AC를 받을 수 있다.
// (출력 값이 튕겨낸 별똥별이 아니라 "튕겨내지 못한" 별똥별의 개수임을 유의하자)
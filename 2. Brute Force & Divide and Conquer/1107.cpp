#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
bool is_broken[10];

bool check(int x) {
    if (x == 0 && is_broken[0]) {
        return false;
    }
    while (x > 0) {
        if (is_broken[x % 10]) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int n_digit(int x) {
    if (x == 0) return 1;
    int ret = 0;
    while (x > 0) {
        ret++;
        x /= 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        is_broken[x] = true;
    }
    ans = abs(n - 100);
    for (int i = 0; i <= 1000000; i++) {
        if (check(i)) {
            ans = min(ans, abs(n - i) + n_digit(i));
        }
    }
    cout << ans << endl;
}

/////// 풀이: 완전 탐색 ///////
// 버튼으로 이동 가능한 모든 채널을 고려하면 된다.
// 주의할 점은 0을 처리하는 것과 초기 채널인 100을 고려하는 것이다.
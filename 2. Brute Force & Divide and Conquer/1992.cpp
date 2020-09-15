#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
string ans;
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

bool same(int y, int x, int len) {
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (v[i][j] != v[y][x]) return false;
        }
    }
    return true;
}

void f(int y, int x, int len) {
    if (same(y, x, len)) {
        cout << v[y][x];
    } else {
        cout << '(';
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i] * len / 2;
            int nx = x + dx[i] * len / 2;
            f(ny, nx, len / 2);
        }
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    v.resize(n);
    for (auto &i : v) cin >> i;
    f(0, 0, n);
    cout << endl;
}

/////// 풀이: 분할 정복 ///////
// 2630번과 유사한 문제다.
// 다만 2630번과 같이 중복된 연산을 없애기는 어려워 쉬운 방식으로 코드를 짰다.
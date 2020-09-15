#include <bits/stdc++.h>
using namespace std;

const int INVALID = -1;
const int WHITE = 0;
const int BLUE = 1;

int n;
int ans[2];
int paper[130][130];
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

int f(int y, int x, int len) {
    if (len == 1) return paper[y][x];
    int ret = paper[y][x];
    int cnt[2] = {0, 0};
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * len / 2;
        int nx = x + dx[i] * len / 2;
        int color = f(ny, nx, len / 2);
        if (color != INVALID) {
            cnt[color]++;
        }
        if (ret != color) {
            ret = INVALID;
        }
    }
    if (ret == INVALID) {
        ans[0] += cnt[0];
        ans[1] += cnt[1];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    int color = f(0, 0, n);
    if (color != INVALID) {
        ans[color]++;
    }
    cout << ans[0] << '\n' << ans[1] << endl;
}

/////// 풀이: 분할 정복 ///////
// 색종이를 쪼개며 재귀 형태로 구현하면 된다.
// 구현하는 방법이 다양하지만, 위 코드는 최대한 중복된 연산이 없도록 하였다.
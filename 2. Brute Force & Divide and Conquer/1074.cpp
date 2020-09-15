#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int cnt;
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

void f(int y, int x, int len) {
    if (len == 1) {
        if (y == r && x == c) {
            cout << cnt << endl;
            exit(0);
        } else {
            cnt++;
        }
    } else {
        if (y + len < r || x + len < c) {
            cnt += len * len;
        } else {
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i] * len / 2;
                int nx = x + dx[i] * len / 2;
                f(ny, nx, len / 2);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> r >> c;
    f(0, 0, pow(2, n));
}

/////// 풀이: 분할 정복 ///////
// 더 빠른 답이 있지만 여기서는 분할 정복으로 설계한 코드를 보여준다.
// 정사각형을 네 조각으로 쪼개 재귀 형태로 탐색하고, 탐색이 필요 없는 경우 (해당
// 영역에 (r, c)가 존재하지 않는 경우) 탐색을 건너뛴다.
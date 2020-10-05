#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
vector<string> a, b;

void flip(int y, int x) {
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            b[i][j] = (b[i][j] == '0' ? '1' : '0');
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                if (i < n - 2 && j < m - 2) {
                    flip(i, j);
                    ans++;
                } else {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << ans << endl;
}

/* 풀이: 그리디 알고리즘
 *
 * 단계적으로 접근하자.
 * (설명에 앞서, 행렬을 변환하는 연산을 flip이라 하자.)
 *
 * 완전 탐색을 생각해보면, flip이 가능한 위치의 개수는 O(NM)개 이고, 각각 flip을
 * 적용한/적용하지 않은 두 가지 경우가 있으므로 총 경우의 수는 O(2^NM)이다.
 * NM <= 2500이므로 이는 불가능한 접근법이다.
 *
 * 관찰을 해보면, 다음과 같은 발상을 얻을 수 있다.
 * 행렬을 오른쪽 아래로 순회하며 flip을 진행하면, 가장 왼쪽 위칸은 지금 적용하는
 * flip이 마지막 flip이 된다. 즉, 행렬 A에서의 이 칸의 값(0 또는 1)이 B와
 * 다르다면 flip을 수행하면 된다. 이를 반복하며 greedy한 풀이를 얻을 수 있다.
 * (귀류법으로 증명 가능)
 *
 * A를 B로 바꿀 수 없는 경우는 가장 오른쪽 가장자리와 아래쪽 가장자리의 flip을
 * 직접 적용할 수 없는, 즉 (y > n - 3 || x > m - 3)인 칸이 다른 모든 칸의 순회
 * 후 A와 B의 값이 다른 경우이다.
 */
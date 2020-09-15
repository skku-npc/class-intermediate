#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int y[20];  // 각 y좌표에 대한 x좌표를 저장한다.

bool check(int x) {
    // 해당 x좌표에 queen을 놓는 것이 가능한지 확인한다.
    for (int i = 1; i < x; i++) {
        if (y[x] == y[i] || x - i == abs(y[x] - y[i])) {
            return false;
        }
    }
    return true;
}

void f(int x) {
    if (x > n) {
        ans++;
    } else {
        for (int i = 1; i <= n; i++) {
            y[x] = i;
            if (check(x)) f(x + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    f(1);
    cout << ans << endl;
}

/////// 풀이: 백트래킹 ///////
// 매우 유명한 백트래킹 문제다.
// x좌표를 1부터 n까지 따라가며 y좌표를 하나식 대입해본다.
// 가능하면 탐색을 계속하고, 아니라면 다른 y좌표를 시도한다.
#include <bits/stdc++.h>
using namespace std;

int n;
int ans_max = INT_MIN;
int ans_min = INT_MAX;
int a[15];
int n_oper[4];

void f(int res, int idx) {
    if (idx == n) {
        ans_max = max(ans_max, res);
        ans_min = min(ans_min, res);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (n_oper[i] > 0) {
            int res_new;
            switch (i) {
                case 0:
                    res_new = res + a[idx];
                    break;
                case 1:
                    res_new = res - a[idx];
                    break;
                case 2:
                    res_new = res * a[idx];
                    break;
                case 3:
                    res_new = res / a[idx];
                    break;
            }
            n_oper[i]--;
            f(res_new, idx + 1);
            n_oper[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> n_oper[i];
    }
    f(a[0], 1);
    cout << ans_max << '\n' << ans_min << endl;
}

// 백준 14888번: 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888

///// 풀이: 완전 탐색 /////
// 가능한 모든 경우를 고려한다.
// 즉, 각 수 사이에 +, -, *, /를 가능한 대로 넣어본다.
// 다만 코드 구현이 조금 까다로울 수 있는데, 최대한 구현 과정을
// 고민해보며 풀어볼 것을 권장한다. 이 과정에서 구현 실력을 크게
// 높일 수 있다.

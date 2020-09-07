#include <bits/stdc++.h>
using namespace std;

int n;
long long p[105] = {
    0, 1, 1, 1, 2,
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 5; i <= 100; i++) {
        p[i] = p[i - 5] + p[i - 1];
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << p[n] << '\n';
    }
}

// 백준 9461번: 파도반 수열
// https://www.acmicpc.net/problem/9461

///// 풀이: 다이내믹 프로그래밍 /////
// p_i = p_(i-5) + p_(i-1)임을 이용하여 전처리를 하고,
// 각 쿼리에 대해 답을 O(1)에 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
int a[10005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    int sum = a[0];

    while (r < n) {
        if (sum == m) ans++;
        if (sum > m) {
            sum -= a[l++];
        } else {
            sum += a[++r];
        }
    }

    cout << ans << endl;
}

// 백준 2003번: 수들의 합 2
// https://www.acmicpc.net/problem/2003

///// 풀이: 투 포인터 /////
// 왼쪽 인덱스, 오른쪽 인덱스를 각각 l, r로 설정하고
// l부터 r까지 A의 합(이하 A[l ~ r]로 표현)을 구한다.
// 이 때 모든 A[l ~ r]을 구하는 것이 아니라,
// l과 r을 조건에 따라 한 칸씩 전진시키며 구한다.

// 추가 설명
//
// vv
// 1  2  3  4  2  5  3  1  1  2
// (sum = 1)
//
// v  v
// 1  2  3  4  2  5  3  1  1  2
// (sum = 3)
//
// v     v
// 1  2  3  4  2  5  3  1  1  2
// (sum = 6)
//
//    v  v
// 1  2  3  4  2  5  3  1  1  2
// (sum = 5) => ans++
//
//    v     v
// 1  2  3  4  2  5  3  1  1  2
// (sum = 9)
//
//       v  v
// 1  2  3  4  2  5  3  1  1  2
// (sum = 7)
//
// 위와 같이 반복한다.

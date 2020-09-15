#include <bits/stdc++.h>
using namespace std;

int n, s;
int ans;
int arr[25];

void f(int idx, int sum) {
    if (idx == n) {
        if (sum == s) ans++;
    } else {
        f(idx + 1, sum);
        f(idx + 1, sum + arr[idx]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    f(0, 0);
    if (s == 0) ans--;
    cout << ans << endl;
}

/////// 풀이: 백트래킹 ///////
// 가능한 모든 부분 수열의 수는 2^N <= 2^20 = 10^6이므로 연산 가능하다.
// 백트래킹을 이용하면 효율적으로 부분수열을 구할 수 있다.
// 위 코드는 크기가 0인 부분수열도 포함하므로 예외 처리가 필요하다.
#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    // 최댓값이 9876543210이므로, int 대신 long long을 사용한다.
    queue<long long> q;
    for (int i = 0; i <= 9; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        long long x = q.front();
        q.pop();
        if (cnt++ == n) {
            cout << x << endl;
            return 0;
        }
        for (int i = 0; i < x % 10; i++) {
            q.push(x * 10 + i);
        }
    }
    cout << -1 << endl;
}

/////// 풀이: 완전 탐색 ///////
// 0번째 숫자부터 n번째 숫자부터 직접 하나씩 구한다.
// 이 때, 십의 자리보다 일의 자리 숫자가 작아야함을 이용해 완전 탐색을 진행한다.
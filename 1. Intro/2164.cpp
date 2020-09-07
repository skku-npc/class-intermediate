#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << endl;
}

// 백준 2164번: 카드2
// https://www.acmicpc.net/problem/2164

///// 풀이: 큐 /////
// 주어진 문제 그대로 구현한다. (시뮬레이션)

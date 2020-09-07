#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    v.resize(n);
    for (auto &i : v) {
        // first: 끝나는 시간, second: 시작 시간
        cin >> i.second >> i.first;
    }

    sort(v.begin(), v.end());

    int last_end = 0;
    for (auto i : v) {
        if (last_end <= i.second) {
            last_end = i.first;
            ans++;
        }
    }

    cout << ans << endl;
}

// 백준 1931번: 회의실배정
// https://www.acmicpc.net/problem/1931

///// 풀이: 그리디 알고리즘 /////
// 끝나는 시간이 빠른 순으로 회의를 정렬한다.
// 마지막으로 끝난 시간 이후 시작한 회의를 찾는다.
// 증명 생략.

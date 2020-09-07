#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    int num = 0, temp = 0;
    for (auto c : s) {
        if (c == '+') {
            temp += num;
            num = 0;
        } else if (c == '-') {
            v.push_back(temp + num);
            temp = num = 0;
        } else {
            num = num * 10 + (c - '0');
        }
    }
    v.push_back(temp + num);
    cout << v[0] - accumulate(v.begin() + 1, v.end(), 0) << endl;
}

// 백준 1541번: 잃어버린 괄호
// https://www.acmicpc.net/problem/1541

///// 풀이: 그리디 알고리즘 /////
// (a+b)-(c+d)-(e+f)-... 형식으로 괄호를 만든다.
// 즉, - 를 기준으로 식을 분리하고, 각 부분(위 식에서 (b + c)와 (d + e))을 v에
// 넣는다.

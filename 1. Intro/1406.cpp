#include <bits/stdc++.h>
using namespace std;

string s;
int m;
char order, c;
stack<char> st1, st2;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    for (auto i : s) st1.push(i);
    cin >> m;
    while (m--) {
        cin >> order;
        switch (order) {
            case 'L':
                if (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
                break;
            case 'D':
                if (!st2.empty()) {
                    st1.push(st2.top());
                    st2.pop();
                }
                break;
            case 'B':
                if (!st1.empty()) {
                    st1.pop();
                }
                break;
            case 'P':
                cin >> c;
                st1.push(c);
                break;
        }
    }
    while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
    }
    while (!st2.empty()) {
        cout << st2.top();
        st2.pop();
    }
    cout << endl;
}

// 백준 1406번: 에디터
// https://www.acmicpc.net/problem/1406

///// 풀이: 스택 /////
// 두 스택을 이용한다.
// 하나는 커서의 왼쪽, 다른 하나는 커서의 오른쪽 글자를 담는다.
// 예를 들어 문장 abcdef가 있고 커서가 d와 e 사이에 있으면
// st1에는 아래부터 a, b, c, d 순으로 담겨있고
// st2에는 아래부터 f, e 순으로 담겨있는 식이다.
// 이를 이용하여 문제에 주어진 쿼리대로 push와 pop을 수행한다.

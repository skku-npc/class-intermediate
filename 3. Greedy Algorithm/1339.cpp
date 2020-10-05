#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
vector<string> v;
map<char, int> cnt;
map<char, int> num;
vector<pair<int, char>> tnc;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    v.resize(n);
    for (auto &i : v) cin >> i;

    for (auto str : v) {
        int len = str.length();
        for (int i = 0; i < len; i++) {
            cnt[str[i]] += pow(10, len - i - 1);
        }
    }

    for (auto i : cnt) {
        tnc.emplace_back(i.second, i.first);
    }

    sort(tnc.rbegin(), tnc.rend());

    int temp = 9;
    for (auto i : tnc) {
        num[i.second] = temp--;
    }

    for (auto i : cnt) {
        ans += num[i.first] * i.second;
    }
    cout << ans << endl;
}

/* 풀이: 그리디 알고리즘
 *
 * 완전 탐색(백트래킹)을 이용해도 풀리는 문제이지만, 조금 더 좋은 풀이인
 * 그리디로 접근해보겠다.
 *
 * 우선 다음 식이 성립함을 짚고 넘어가자.
 * GCF = (100 * G) + (10 * C) + (1 * F)
 * ACDEB = (10000 * A) + (1000 * C) + (100 * D) + (10 * E) + (1 * B)
 *
 * 따라서 총합은 다음과 같다.
 * A -> 10000
 * C -> 1010
 * D -> 100
 * G -> 100
 * E -> 10
 * B -> 1
 * F -> 1
 *
 * 여기서 직관적으로 얻을 수 있는 greedy한 접근법은, 왼쪽의 count된 값이 큰 수
 * 순서로 9, 8, 7...의 숫자를 할당하는 것이다. 이는 충분히 직관적이기에 증명은
 * 생략한다. (귀류법으로 증명 가능)
 *
 * 따라서 처음 입력 받을 때 map 등의 자료구조를 이용하여 count값을 적절하게 세면
 * 위와 같이 우선순위를 할당할 수 있고, 이에 따라 9, 8, 7...의 숫자를 할당하면
 * 된다.
 */
#include <bits/stdc++.h>
using namespace std;

int n, h;
int arr[10];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h;
        int idx = h;
        for (int j = 0; j < idx; j++) {
            if (arr[j] != 0) idx++;
        }
        while (arr[idx] != 0) idx++;
        arr[idx] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

/* 풀이: 그리디 알고리즘
 *
 * 먼저 완전 탐색을 생각해보자. 가능한 줄의 종류는 O(N!), 각각의 경우 키 큰
 * 사람의 수를 확인하는 데에는 O(N^2)으로, 총 O(N! * N^2)의 연산이 필요하다.
 * 최적화를 어느정도 하면 가능할지도 모르지만, 일반적으로는 어려울 것이라 보고
 * 완전 탐색으로 풀리지 않는 문제로 본다.
 *
 * 대신, 다음과 같은 발상을 얻을 수 있다.
 * 입력으로 주어지는 i번째 사람을 바로 줄에 배치하는 경우를 생각해보자.
 * [0 ~ i-1]번째 사람은 i번째 사람보다 키가 작으므로 줄에는 i번째 사람보다 키가
 * 큰 사람이 없다. 즉, 입력으로 주어지는 배열을 A라고 하면 i번째 사람은 왼쪽에
 * 빈 칸이 A[i]개 만큼 있는 칸에 배치하면 된다.
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int cnt_height[300];
int ans_time = INT_MAX;
int ans_height;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> b;
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        cnt_height[x]++;  // 각 좌표의 높이를 저장하는 것보다,
                          // 높이 h가 몇 번 나왔는지 세는 것이 효율적이다.
    }

    // 같은 시간의 경우 땅의 높이가 가장 높은 경우를 찾아야하므로, 0부터
    // 오름차순으로 찾는 것보다는 256부터 내림차순으로 찾는 것이 더 효율적이다.
    for (int height = 256; height >= 0; height--) {
        int time = 0;
        int block = 0;
        for (int i = 0; i < height; i++) {
            time += cnt_height[i] * (height - i);
            block += cnt_height[i] * (i - height);
        }
        for (int i = height + 1; i <= 256; i++) {
            time += cnt_height[i] * (i - height) * 2;
            block += cnt_height[i] * (i - height);
        }
        if (block + b < 0) continue;
        if (time < ans_time) {
            ans_time = time;
            ans_height = height;
        }
        // 오름차순으로 높이를 구하면(0 ~ 256),
        // ans_height를 update하는 코드를 추가해야한다.
    }

    cout << ans_time << ' ' << ans_height << endl;
}

/////// 풀이: 완전 탐색 ///////
// 땅의 높이가 256블록을 초과할 수 없다고 주어져 있으므로, 0블록부터 256블록까지
// 모든 블록을 시도해본다. 각 높이마다 문제에 주어진 대로 값을 계산한다. 나머지
// 구현은 위 코드를 참고하면 된다.
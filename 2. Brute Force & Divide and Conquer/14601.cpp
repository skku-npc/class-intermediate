#include <bits/stdc++.h>
using namespace std;

int res[133][133];  // 타일 칠해진 결과를 저장
int color = 1;      // 끼울 타일

void f(int x, int y, int p2, pair<int, int> hole) {
    if (p2 == 0) return;  // 기저 조건

    int now_color = color++;

    //분할과정
    int nxt_p2 = p2 - 1;
    int nxt_sz = 1 << nxt_p2;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int nx = x + i * nxt_sz;
            int ny = y + j * nxt_sz;
            if (nx <= hole.first && hole.first < nx + nxt_sz &&
                ny <= hole.second && hole.second < ny + nxt_sz) {
                f(nx, ny, nxt_p2, hole);
            } else {
                int mid_x = x + nxt_sz - 1 + i;
                int mid_y = y + nxt_sz - 1 + j;
                f(nx, ny, nxt_p2, make_pair(mid_x, mid_y));
                res[mid_x][mid_y] = now_color;
            }
        }
    }
}

int main() {
    pair<int, int> p;
    int k;
    cin >> k >> p.second >> p.first;
    p.first--, p.second--;  // 0-based index
    f(0, 0, k, p);
    for (int i = (1 << k) - 1; i >= 0; --i) {
        for (int j = 0; j < (1 << k); ++j) {
            cout << (res[i][j] ? res[i][j] : -1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
/*
이 문제는 이산수학에서 유명한 수학적 귀납법 문제이다.
명제: 한 칸을 채우면 안되는(x칸이라 하겠다) 2^n X 2^n grid는 ㄱ자 타일로 채울 수 있다.

증명
basis step
n = 1일때 : 자명하게 채울 수 있다.

inductive step
n=k일때 가능하다고 가정한 상황에서 n = k+1일때 가능함을 보여야 한다.
우린 2^(k+1) X 2^(k+1) 크기의 grid를 2^k X 2^k 크기의 grid 4개로 나눌 수 있다.
4개중 한개에는 x칸이 포함되어 있다. 이 부분은 귀납적 가정에 의해 채울 수 있다.
나머지 3개의 부분은, grid의 정 가운데에 ㄱ자 블록을 둠으로써, 한 칸이 x칸인 2^k X 2^k grid를 만들 수 있다.
이제 재귀적으로 모두 채울 수 있다.

 추가 설명

 ㅁ ㅁ ㅁ ㄹ
 ㅁ ㅌ ㅁ ㅁ
 ㅁ ㅌ ㅌ ㅁ
 ㅁ ㅁ ㅁ ㅁ
 위 그림에서 ㄹ의 위치가 타일을 채우면 안되는 칸 이다.
 2X2 4개로 쪼개면 우상단은 귀납적 가정에 의해 채울 수 있고
 ㅌ처럼 ㄱ자 블록을 놓으면 좌상단, 우하단, 좌하단 모두 귀납적 가정을 만족하게 된다.
//////////
 이러한 수학적 귀납법 과정을 모두 코드로 옮기면 된다.
*/

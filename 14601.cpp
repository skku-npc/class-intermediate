#include <bits/stdc++.h>
using namespace std;

int res[133][133]; // 타일 칠해진 결과를 저장
int color = 1;//끼울 타일
void f(int x, int y, int p2, pair<int,int> hole)
{
    if (p2 == 0) return;//기저 조건

    int now_color = color;
    ++color;
    //분할과정
    int nxt_p2 = p2 - 1;
    int nxt_sz = 1<<nxt_p2;
    for (int i=0;i<2;++i)
    {
        for (int j = 0; j < 2; ++j)
        {

            int nx = x + i * nxt_sz;
            int ny = y + j * nxt_sz;
            if (nx <= hole.first && hole.first < nx + nxt_sz &&
                ny <= hole.second && hole.second < ny + nxt_sz)
            {
                f(nx, ny, nxt_p2, hole);
            }
            else
            {
                int mid_x = x + nxt_sz - 1 + i;
                int mid_y = y + nxt_sz - 1 + j;
                f(nx, ny, nxt_p2, make_pair(mid_x, mid_y));
                res[mid_x][mid_y] = now_color;
            }
        }
    }
}
signed main()
{
    pair<int, int> p;
    int k; cin>>k>>p.second>>p.first;
    p.first--, p.second--; //저는 0-based index를 사용하기 때문에 1 빼줬습니다.
    f(0,0,k, p);
    for(int i=(1<<k)-1; i>=0; --i)
    {
        for (int j = 0; j < (1 << k); ++j)
        {
            cout << (res[i][j]?res[i][j]:-1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}

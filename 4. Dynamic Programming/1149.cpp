#include <cstdio>
using namespace std;
int min(int a, int b){return a<b?a:b;}
int d[1001][3];
signed main()
{
    int n; scanf("%d", &n);
    int r, g, b;
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d%d", &r, &g, &b);
        d[i][0] = min(d[i-1][1],d[i-1][2]) + r;
        d[i][1] = min(d[i-1][0],d[i-1][2]) + g;
        d[i][2] = min(d[i-1][1],d[i-1][0]) + b;
    }
    printf("%d\n", min(min(d[n][0], d[n][1]), d[n][2]));
}
/*
 d[i][0]=1~i까지 색칠완료 했으며 i번째를 r로 색칠했을 때 최소 비용
 d[i][1]= ~~, i번째를 g로 색칠
 d[i][2]= ~~, i번째를 b로 색칠
 dp에 색 정보를 넣어서, 연속으로 같은 색을 칠하는 것을 방지할 수 있다.
 */

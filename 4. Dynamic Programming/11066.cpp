#include <cstdio>
#include <cstring>
using namespace std;
int min(int a, int b){return a>b?b:a;}
int n, a[501], dp[501][501], pf[501];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        memset(dp, 0x3F, sizeof dp);
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
            pf[i] = pf[i-1] + a[i];
        }
        for (int i=n;i>=1;--i)
        {
            dp[i][i] = 0;
            for (int j=i + 1;j<=n;++j)
            {
                for (int k=i;k<j;++k)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + pf[j] - pf[i-1]);
                }

            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
/*
 dp[i][j] = 자료 [i, j]를 합치는데 필요한 비용,
 i~k까지 합치고, k+1~j까지 합치고, 이 둘을 합치는 전략으로 dp를 작성할 수 있다.
 dp[i][j] = min(dp[i][k]+dp[k+1][j] + sum(i~j) )

 여기엔 없지만 knuth's optimization 에 대해 알아보자.
 */

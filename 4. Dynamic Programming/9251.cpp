#include <cstdio>
using namespace std;
int max(int a, int b){return a > b ? a : b;}
int dp[1001][1001];
char s[1002], t[1002];
int main()
{
    scanf("%s %s", s+1, t+1);
    int ans = 0;
    for (int i=1;s[i];++i)
    {
        for (int j=1; t[j];++j)
        {
            dp[i][j] = max(dp[i-1][j-1]+(s[i]==t[j]), max(dp[i-1][j], dp[i][j-1]));
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
 dp[i][j]를 s의 i번째 문자까지, t의 j번째 문자 까지 봤을 때 lcs라고 정의합니다.
 이때 크게 2가지의 경우로 나눌 수 있습니다.
 1) 우리가 고려하고 있는 문자를 건너뛰는 common subsequence를 구할 때 -> dp[i-1][j], dp[i][j-1]
 2) 우리가 고려하고 있는 문자를 common subsequence에 포함 할 때 (s[i] == t[j]일때만 가능) -> dp[i-1][j-1] + (s[i]==t[j])
 */

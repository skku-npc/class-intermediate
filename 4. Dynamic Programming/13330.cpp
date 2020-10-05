#include <cstdio>
#include <cstring>
using namespace std;
int min(int a, int b){return a>b?b:a;}
int n, a, b;
char s[10'001];
int d[10'001];
int f[10'000][10'000];
int main()
{
    memset(d, 0x3F, sizeof d);
    scanf("%d%d%d%s", &n, &a, &b, s);
    for (int i= n-1; i>=0; --i)
        for (int j = i+1;j<n;++j)
        {
            if (s[i] == s[j]) f[i][j] = f[i+1][j-1] + 2;
            else f[i][j] = 0;
        }
    d[0]=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<i;++j)
        {
            if (f[j][i] * b >= (i - j + 1) * a)
                d[i+1] = min(d[i+1], d[j] + 1);
        }
    printf("%d\n", d[n]>1e9?0:d[n]);
    return 0;
}
/*
 문자열 w를 "펠린드롬 비율이 theta 이상인" 문자열들로 쪼개는 문제 입니다.
 예를 들어 s=aabcaa 같은 경우 총 4개의 문자 s[0], s[1], s[4], s[5]가 대칭을 이룸으로, 4/6 의 비율을 가집니다.
 f[i][j]를 w[i~j]에서 대칭을 이루는 문자의 총 개수 라고 정의합니다.
 또한 d[i]를 w[0~i]를 구성할 수 있는 최소 theta펠린드롬 개수라고 정의합니다.
 d[i] = min(d[j] + 1) (f[j][i]*l>=(i-j+1)*k 를 만족하는 모든 j에 대해)
 //

 f[i][j]를 전처리 하지 말고, d를 구함과 동시에 구하면 메모리를 아낄 수 있습니다.
 */

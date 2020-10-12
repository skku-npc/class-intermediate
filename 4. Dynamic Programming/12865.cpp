#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int dp[100005];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		for (int j = k - w; j >= 0; j--) {
			dp[j + w] = max(dp[j + w], dp[j] + v);
		}
	}
	for (int i = 0; i <= k; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
/*
 dp[i][j] = 1~i 물건들을 고려했고, 무게가 j일 때 최대 가치
 새로운 물건이 입력으로 들어 왔을 때,
 1) 그 물건을 배낭에 넣는다. (j + w<=k 일때만 가능), (dp[i][j+w] = dp[i-1][j] + v)
 2) 넣지 않는다. (dp[i][j] = dp[i-1][j])
 이렇게 2가지로 나눌 수 있다.
 그래서 dp[i][j + w] = max(dp[i-1][j + w], dp[i-1][j] + v) 이다.

 //
 dp[i][j]를 구할 때, 항상 dp[i-1] 만을 사용함으로 dp[2][100'001]로 구하는게 가능하다.
 dp[i%2], dp[(i-1)%2]로 인덱스를 계산하면 편리하게 구현 할 수 있다.
 정수는 n%2 == n&1이다.
 //
 이 문제는 사실 1차원 dp만으로도 해결 될 수 있는데,
 이는 for문을 감소하게 돌리면 i번째 물건이 2번 이상 담기는 일이 절때 일어나지 않기 때문에 가능하다.
 (dp[j] = dp[j-w]+v)
 */

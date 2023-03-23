#include<bits/stdc++.h>

using namespace std;

const int NN = 1010;

bool flag[NN][NN];
int sum[NN][NN], dp[NN][NN][101];

int main() {
	freopen("in.txt", "r", stdin);
	
	int m, n, H, K; scanf("%d %d %d %d", &m, &n, &H, &K);
	for(int i = 1; i <= m; i++) {
		for(int j = 1, x; j <= n; j++) {
			scanf("%d", &x), flag[i][j] = x >= H;
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + flag[i][j];
		}
	}
	
	int mx = -1, x1, y1, x2, y2;
	for(int i = 1; i <= m; i++) {
		if(flag[i][1]) dp[i][1][0] = 1;
		else dp[i][1][1] = 1;
	}
	for(int j = 1; j <= n; j++) {
		if(flag[1][j]) dp[1][j][0] = 1;
		else dp[1][j][1] = 1;
	}
	
	for(int i = 1; i <= m; i++) {//m
		for(int j = 1; j <= n; j++) {//n
			for(int k = 0; k <= K; k++) {//k
				dp[i][j][k] = min({dp[i][j][k], i, j});
				int len = dp[i][j][k];
				int num = sum[i + 1][j + 1] - sum[i + 1][j - len] - sum[i - len][j + 1] + sum[i - len][j - len];
				num -= sum[i][j] - sum[i][j - len] - sum[i - len][j] + sum[i - len][j - len];
				
				if(num <= K) dp[i + 1][j + 1][num] = max(dp[i + 1][j + 1][num], k + 1);
				if(len > mx) {
					mx = len;
					x1 = i - mx + 1, y1 = j - mx + 1;
					x2 = i, y2 = j;
				}
			}
		}
	}
	if(~mx) printf("%d %d %d %d\n", x1, y1, x2, y2);
	else puts("There is no answer about this input.");
}

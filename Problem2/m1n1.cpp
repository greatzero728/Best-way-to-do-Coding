#include<bits/stdc++.h>

using namespace std;

const int NN = 10101;

bool flag[NN][NN];
int dp[NN][NN];

int main() {
	freopen("in.txt", "r", stdin);
	
	int m, n, h; scanf("%d %d %d", &m, &n, &h);
	for(int i = 1; i <= m; i++) {
		for(int j = 1, x; j <= n; j++) {
			scanf("%d", &x), flag[i][j] = x >= h;
		}
	}
	
	int mx = 0, x1 = 1, y1 = 1, x2 = min({m, n, 2}), y2 = x2;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(flag[i][j - 1] && flag[i - 1][j]) {
				int mn = min(dp[i][j - 1], dp[i - 1][j]);
				if(mn) {
					if(flag[i - mn - 1][j - mn - 2] && flag[i - mn - 2][j - mn - 1]) {
						dp[i][j] = mn + 1;
					}
					else dp[i][j] = mn;
				}
				else {
					if(flag[i - 1][j - 2] && flag[i - 1][j - 1] && flag[i - 2][j - 1]) {
						dp[i][j] = 1;
					}
					else dp[i][j] = 0;
				}
				
				if(dp[i][j] > mx) {
					mx = dp[i][j];
					x1 = i - mx - 1, y1 = j - mx - 1;
					x2 = i, y2 = j;
				}
			}
			else dp[i][j] = 0;
		}
	}
	printf("%d %d %d %d\n", x1, y1, x2, y2);
}

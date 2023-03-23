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
			scanf("%d", &x);
			flag[i][j] = x >= h;
		}
	}
	
	int mx = -1, x1, y1, x2, y2;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(flag[i][j]) {
				int mn = min(dp[i][j - 1], dp[i - 1][j]);
				if(flag[i - mn][j - mn]) dp[i][j] = mn + 1;
				else dp[i][j] = mn;
				
				if(dp[i][j] > mx) {
					mx = dp[i][j];
					x1 = i - mx + 1, y1 = j - mx + 1;
					x2 = i, y2 = j;
				}
			}
			else dp[i][j] = 0;
		}
	}
	if(~mx) printf("%d %d %d %d\n", x1, y1, x2, y2);
	else puts("There is no answer about this input.");
}

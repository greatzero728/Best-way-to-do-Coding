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
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + flag[i][j];
		}
	}
	
	int mx = 0, x1, y1, x2, y2;
	for(int is = 1; is <= m; is++) {//m
		for(int js = 1; js <= n; js++) {//n
			for(int len = n; len > mx; len--) {//n
				int it = is + len - 1, jt = js + len - 1;
				if(it > m || jt > n) continue;
				
				int all_size = len * len - 4;
				int real_size = dp[it][jt] - dp[it][js - 1] - dp[is - 1][jt] + dp[is - 1][js - 1];
				real_size -= flag[is][js] + flag[is][jt] + flag[it][js] + flag[it][jt];
				
				if(real_size == all_size) {
					mx = len;
					x1 = is, y1 = js;
					x2 = it, y2 = jt;
				}
			}
		}
	}
	if(~mx) printf("%d %d %d %d\n", x1, y1, x2, y2);
	else puts("There is no answer about this input.");
}

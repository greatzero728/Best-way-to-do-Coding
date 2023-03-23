#include<bits/stdc++.h>

using namespace std;

const int NN = 10101;

int dp[NN][NN];

int main() {
	freopen("in.txt", "r", stdin);
	
	int m, n, h; scanf("%d %d %d", &m, &n, &h);
	for(int i = 1; i <= m; i++) {
		for(int j = 1, x; j <= n; j++) {
			scanf("%d", &x);
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + (x >= h);
		}
	}
	
	
	int mx = -1, x1, y1, x2, y2;
	for(int is = 1; is <= m; is++) {//m
		for(int it = is; it <= m; it++) {//m
			for(int js = 1; js <= n; js++) {//n
				for(int jt = js; jt <= n; jt++) {//n
					if(it - is != jt - js) continue;
					if(it - is <= mx) continue;
					
					int all_size = (it - is + 1) * (jt - js + 1);
					int real_size = dp[it][jt] - dp[it][js - 1] - dp[is - 1][jt] + dp[is - 1][js - 1];
					
					if(real_size == all_size) {
						mx = it - is;
						x1 = is, y1 = js;
						x2 = it, y2 = jt;
					}
				}
			}
		}
	}
	if(~mx) printf("%d %d %d %d\n", x1, y1, x2, y2);
	else puts("There is no answer about this input.");
}

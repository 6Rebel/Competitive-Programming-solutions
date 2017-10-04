//ALOVEG

#include <bits/stdc++.h>

using namespace std;

bool inside(int a, int b, int c) { return a<=b && b<=c; }

const int mn = 1005;

char ag[mn][mn];
long long d[mn][mn];
int n, m, sr, sc, er, ec;
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

bool valid(int i, int j) {
	return (inside(0, i, n-1) && inside(0, j, m-1));
}

long long love() {
	int r1, c1, r2, c2, i, dir;
	queue< int > Q;
	memset(d, 1000000, sizeof(d));
	d[sr][sc] = -1;
	Q.push(sr); Q.push(sc);
	while(!Q.empty()) {
		r1 = Q.front(); Q.pop();
		c1 = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			r2 = r1 + dr[i];
			c2 = c1 + dc[i];
			while(valid(r2, c2) && ag[r2][c2] != '*') {
				if(d[r2][c2] > d[r1][c1] + 1) {
					d[r2][c2] = d[r1][c1] + 1;
					if(r2==er && c2==ec) return d[r2][c2];
					Q.push(r2); Q.push(c2);
				}
				r2 += dr[i];
				c2 += dc[i];
			}
		}
	}
	return d[er][ec]>=1000000 ? -1 : d[er][ec];
}

int main() {
    
	int i, j, cnt = 0;
	cin>>n>>m;
	for(i = 0; i < n; i++) {
		scanf("%s", ag[i]);
		for(j = 0; j < m ; j++) {
			if(ag[i][j]=='V')
				sr = i, sc = j;
			else if(ag[i][j] == 'H')
			    er = i, ec = j;
		}
	}
	long long aloveg = love();
	printf("%lld", aloveg);
	return 0;
}


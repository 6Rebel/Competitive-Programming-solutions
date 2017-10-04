#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e6+5;

int readLine(char *s){
	int i=0;
	char ch;
	while((ch = getchar()) != '\n'){
		s[i++] = ch;
	}
	s[i] = '\0';
	return i;
}

int LCS(int *x, int *y, char *a, char *g, int n, int m){
	
	int i, j, k;
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			if(a[i-1] == g[j-1]){
				y[j] = x[j-1] + 1;
			}else{
				y[j] = y[j-1] > x[j] ? y[j-1] : x[j];
			} 
		}
		int *t;
		t = x;
		x = y;
		y = t;
	}
	return x[m];
}

int main()
{
    
    char a[50001], g[50001];
    int x[50001], y[50001];
    int n, m;
    n = readLine(a);
    m = readLine(g);
    
    int ag = LCS(x, y, a, g, n, m);
    printf("%d", ag);
    
    return 0;
}



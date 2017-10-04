#include<bits/stdc++.h>

using namespace std;

#define ALOVEG ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll unsigned long long

const int mn = 1e6+5;
vector<ll> a[mn],sub[mn];
ll g[mn],c[mn];
ll qu[mn],d=0;
ll power(ll a, ll g){ll ag = 1; while(g){if(g&1)ag = (ag*a); a=a*a; g>>=1;} return ag;}

void dfs(int u, bool seen[]){
	seen[u] =  1;
	for(int i=0;i<a[u].size();i++){
		int v = a[u][i];
		if(seen[v])continue;
		dfs(v,seen);
		for(int j=0;j<sub[v].size();j++)
			sub[u].push_back(sub[v][j]);
	}
}

int main(){
	
	ALOVEG
	
	int n,q;
	cin>>n>>q;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;	
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	for(int i=0;i<n;i++)
		sub[i].push_back(i);
	bool seen[n+1]={0};
	dfs(0,seen);
	
	long long p[n+1];
	for(int i=0;i<n;i++){
		p[i] = power(2, (int)(ceil(log2(sub[i].size()))));
	}	
	
	for(int i=0;i<n;i++)
		cin>>g[i];	
	for(int i=0;i<q;i++){
		cin>>qu[i];
		qu[i] %= p[0];
		d = max(d, qu[i]);
	}
	vector<ll> ag[d+1];
	for(int i=0;i<n;i++){
		ag[0].push_back(g[i]);
	}
	for(int i=1;i<=d;i++){
		if(i&1){
			for(int j=0;j<n;j++){
				if(i >= p[j]){
					c[j] = ag[i%p[j]][j];
					continue;
				}
				c[j] = 0;
				for(int k=0;k<sub[j].size();k++)
					c[j] ^= g[sub[j][k]];
				ag[i].push_back(c[j]);
			}
		}else{
			for(int j=0;j<n;j++){
				if(i >= p[j]){
					g[j] = ag[i%p[j]][j];
					continue;
				}
				g[j] = 0;
				for(int k=0;k<sub[j].size();k++)
					g[j] ^= c[sub[j][k]];
				ag[i].push_back(g[j]);
			}
		}
	}
	
	for(int i=0;i<q;i++){
		cout<<ag[qu[i]][0]<<"\n";
	}
	return 0;
}

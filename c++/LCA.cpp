#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int maxl = 22;
vector<int> adj[maxn];
int p[maxn],subtree[maxn],pos[maxn],cnt[maxn],depth[maxn];
int par[maxn][maxl];
bool seen[maxn];
int n,m,l;
void sieve(){p[0]=p[1]=1;for(int i=2;i*i<maxn;i++)if(!p[i])for(int j=i<<1;j<maxn;j+=i)p[j]=1;}

void dfs(int u){
	seen[u] = 1;
	subtree[u] = 1;
	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(!seen[v]){
			cnt[v] = cnt[u];
			if(p[v]==0)cnt[v] += 1;
			depth[v] = depth[u] + 1;
			dfs(v);
			subtree[u] += subtree[v]; par[v][0] = u;
		}
	}
}

void jump(int &u,int height){
	for(int i=l;i>=0;i--){
		if(height >= (1<<i)){
			u = par[u][i];
			height -= (1<<i);
		}
	}
}

int lca(int u, int v){
	if(depth[u]>depth[v])
		jump(u,depth[u]-depth[v]);
	else
		jump(v,depth[v]-depth[u]);
	if(u==v)	return (u);
	for(int i=l;i>=0;i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i]; v = par[v][i];
		}
	}
	return par[u][0];
}
	
void init(){
	scanf("%d",&n);
	int a,g;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&g);
		adj[a].push_back(g);
		adj[g].push_back(a);
	}
	depth[1]=0;cnt[1] = 0;
	dfs(1);
	l = (int)(log(n) / log(2)) + 1;
	for(int j=1;j<=l;j++){
		for(int i=1;i<=n;i++)
			par[i][j] = par[par[i][j-1]][j-1];
	}
}
void solve(){
	int q,a,g;scanf("%d",&q);
	while(q--){
		scanf("%d%d",&a,&g);
		int ag = lca(a,g);
		int aloveg = cnt[a] + cnt[g] - cnt[ag] - cnt[par[ag][0]];
		printf("%d\n",aloveg);
	}
}

int main(){
    //ios_base::sync_with_stdio(0);cin.tie(NULL);
	sieve();
	init();
	solve();
	return 0;
}

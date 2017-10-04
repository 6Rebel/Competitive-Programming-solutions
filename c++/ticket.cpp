#include<bits/stdc++.h>

using namespace std;

#define ll long long int
const int maxn = 3e5+5;
const int maxl = 22;
vector<int> adj[maxn];
ll p[maxn],subtree[maxn],pos[maxn],cnt[maxn],depth[maxn],tk[maxn],ff[maxn];
ll par[maxn][maxl]; map<pair<int,int>, ll> fre;
bool seen[maxn];
int n,m,l;

void dfs(int u){
	seen[u] = 1;
	subtree[u] = 1;
	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(!seen[v]){
			cnt[v] = cnt[u]; ff[v] = ff[u];
			if(p[v]==0){
				cnt[v] += tk[v];
				ff[v] += fre[make_pair(min(u, v), max(u, v))];
			}
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	    scanf("%lld",&tk[i]);
	int a,g; ll fr;
	for(int i=1;i<n;i++){
		scanf("%d%d%lld",&a,&g,&fr);
		adj[a].push_back(g);
		adj[g].push_back(a);
		if(g < a) swap(a, g);
		fre[make_pair(a, g)] = fr;
	}
	depth[1]=0;cnt[1] = tk[1]; ff[1] = 0;
	dfs(1);
	l = (int)(log(n) / log(2)) + 1;
	for(int j=1;j<=l;j++){
		for(int i=1;i<=n;i++)
			par[i][j] = par[par[i][j-1]][j-1];
	}
}
void solve(){
	int a,g;
	while(m--){
		scanf("%d%d",&a,&g);
		int ag = lca(a,g);
		ll aloveg = cnt[a] + cnt[g] - cnt[ag] - cnt[par[ag][0]];
		ll glovea = ff[a] + ff[g] - ff[ag] - ff[par[ag][0]];
		printf("%lld\n",aloveg-glovea);
	}
}

int main(){
    //ios_base::sync_with_stdio(0);cin.tie(NULL);
	init();
	solve();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 10010;
const ll mod = 1e9+7;
ll arr[mn], size[mn];

void init(int n){
	for(int i=0;i<=n;i++){
		arr[i] = i;
		size[i] = 1;
	}
}

ll root(ll a){
	while(a != arr[a]){
		arr[a] = arr[arr[a]];
		a = arr[a];
	}	
	return a;
}

void join(ll a, ll g){
	if(size[a] < size[g])
		swap(a, g);
	size[a] += size[g];
	size[g] = 0;
	//cout<<size[a]<<" "<<size[g]<<"\n";
	arr[g] = a;
}

int main()
{
    Aloveg

    int n, q, m;
    cin>>n>>q>>m;
    init(n+1);
    ll a, g;
    while(q--){
    	cin>>a>>g;
    	a = root(a);
    	g = root(g);
    	if(a != g)
    		join(a, g);
	}
	ll ag =1;
	for(int i=1;i<=n;i++){
		if(size[i]==0)continue;
		ag = (ag%mod * size[i]%mod)%mod;
	}
	cout<<ag;
    
    return 0;
}



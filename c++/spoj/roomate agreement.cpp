#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e6+5;

int main()
{
    Aloveg

    int t;cin>>t;
    while(t--){
    	map<ll,ll> g;
		int n; cin>>n;
		int a[n+1];a[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i] += a[i-1];
			g[a[i]] += 1;
		}
		ll ag = (g[0]*(g[0]-1))/2, c;
		g[0] = 0;
		for(auto i : g){
			c = i.second;
			ag += (c*(c-1))/2;
		}
		cout<<ag<<"\n";
    }
    return 0;
}



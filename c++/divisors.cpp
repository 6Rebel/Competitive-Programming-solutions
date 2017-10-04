#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e6+5;
const ll mod = 1e9+7;

ll power(ll a, ll g){
	ll ag = 1;
	while(g){
		if(g%2==1)
			ag = (ag%mod * a%mod)%mod;
		a = (a%mod * a%mod);
		g >>= 1;
	}
	return ag;
}

int main()
{
    Aloveg

    ll n; cin>>n;
    ll a[n+1], sum = 0, pro = 1;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i] == 0)continue;
    	sum = (sum%mod + a[i]%mod)%mod;
    	pro = (pro%mod * a[i]%mod)%mod;
	}
	if(n <= 2) pro = 0;
	ll ag = 1;
	for(int i=0;i<n;i++){
	    if(a[i] == 0)
	        continue;
		ll g = (a[i]%mod * (a[i]+1)%mod * power(2, mod-2)%mod )%mod;
		ll s = (sum - a[i] + mod)%mod;
		ll p = (pro%mod * power(a[i], mod-2)%mod + mod)%mod;
		ll ga = (g + ((s + p)*g)  + 1);
		ag = (ag%mod * ga%mod)%mod;
		cout<<g<<" "<<s<<" "<<p<<" "<<ga<<"\n";
	}
    cout<<ag;
    
    return 0;
}



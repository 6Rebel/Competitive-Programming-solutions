#include<bits/stdc++.h>
 
using namespace std;
 
#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pri(x) printf("%d",x)
#define pll(x) printf("%lld",x)
#define sstr(s) scanf("%s",s)
#define nl printf("\n")
#define ll long long int
#define pii pair<int,int>
#define pLL pair<ll,ll>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define FOR(i,x,y) for(int i=x;i<y;i++)
#define mod 1000000007
 
ll DP[65][2][65];
vector<int> v;
bool p[65];
 
ll func(int idx, int tight, int sum) {
    if(idx==v.size()) {
	if(!p[sum]) return 1;
	return 0;
    }
    if(DP[idx][tight][sum] != -1) {
	return DP[idx][tight][sum];
    }
    ll ans = 0;
    if(tight==1) {
	for(int i=0;i<=v[idx];i++) {
	    if(i<v[idx]) {
		ans += func(idx+1,0,sum+(i==1));
	    }
	    else {
		ans += func(idx+1,1,sum+(i==1));
	    }
	}
    }
    else {
	for(int i=0;i<=1;i++) {
	    ans += func(idx+1,0,sum+(i==1));
	}
    }
    return DP[idx][tight][sum] = ans;
}
 
ll solve(ll x) {
    memset(DP,-1,sizeof(DP));
    v.clear();
    while(x) {
	v.pb(x%2);
	x = x/2;
    }
    reverse(v.begin(),v.end());
    return func(0,1,0);
}
 
int main()
{
    p[0] = p[1] = 1;
    for(int i=2;i<=64;i++) {
	if(!p[i]) {
	    for(int j=i+i;j<=64;j+=i) {
		p[j] = 1;
	    }
	}
    }
    int q; si(q);
    while(q--) {
	ll l,r; sll(l); sll(r);
	cout<<solve(r)-solve(l-1)<<endl;
    }
    return 0;
}

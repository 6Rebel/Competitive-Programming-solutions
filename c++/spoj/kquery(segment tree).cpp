#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(a) a.begin(),a.end()
const int maxn = 2e6+5;
ll a[maxn];
vector <ll> ag[4*maxn];

void build(ll n,ll s,ll e){
	if(s==e)
	{
		ag[n].push_back(a[s]);
	}else{
		ll m = (s+e)>>1;
		ll l = n<<1;
		build(l,s,m);
		build(l+1,m+1,e);
		merge(all(ag[l]),all(ag[l+1]),back_inserter(ag[n]));
	}
}
ll query(ll n,ll s,ll e,ll l,ll r,ll k){
	if(l>e or s>r)
		return 0;
	if(s>=l and e<=r){
		ll q = ag[n].end() - upper_bound(all(ag[n]),k) ;
		return q;
	}
	ll m = (s+e)>>1;
	ll left = n<<1;
	ll q1 = query(left,s,m,l,r,k);
	ll q2 = query(left+1,m+1,e,l,r,k);
	return q1 + q2;
}

int main(){
	ll n;cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	ll q;cin>>q;
	ll l,r,k;
	ll ag = 0;
	while(q--){
		cin>>l>>r>>k;
		l ^= ag;
		r ^= ag;
		k ^= ag;
		ag = query(1,1,n,l,r,k);
		//cout<<(r-l+1)<<" "<<aloveg<<endl;
		cout<<ag<<endl;
	}
	return 0;
}

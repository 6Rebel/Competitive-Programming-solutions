#include<bits/stdc++.h>
#define inf 1e18
#define ll long long
using namespace std;
ll a,b,n,l;
ll gcd(ll x,ll y)
{
	if(y==0)return x;
	else return gcd(y,x%y);
}
bool f(ll x)
{
	ll val= x/a + x/b - x/l;
	if(val>=n)return 1;
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cin>>n;
		ll low=min(a,b),high=inf;
		ll ans;
		l=(a*b)/gcd(a,b);
		while(low<=high)
		{
			ll mid=(low+high)/2;
			if(f(mid))
			{
				ans=mid;
				high=mid-1;
			}
			else
				low=mid+1;
		}
		cout<<ans<<"\n";
	}
}

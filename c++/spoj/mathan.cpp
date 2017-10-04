#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e6+5;

int main()
{
    Aloveg

    ll n; ll p, q, r;
    cin>>n>>p>>q>>r;
    ll a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n);
    ll ag = 0;
    if(p <= 0){
    	ag += (p*a[0]);
	}else{
		ag += (p*a[n-1]);
	}
	if(q <= 0){
    	ag += (q*a[0]);
	}else{
		ag += (q*a[n-1]);
	}
	if(r <= 0){
    	ag += (r*a[0]);
	}else{
		ag += (r*a[n-1]);
	}
	cout<<ag;
    
    return 0;
}



#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ALOVEG ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll solve(ll a[], int n){
	stack<ll> s;
	ll ag = 0, top, ga = 0;
	int i = 0;
	while(i < n){
		if(s.empty() or a[s.top()] <= a[i])
			s.push(i++);
		else{
			top = s.top(); s.pop();
			ga = a[top]*(s.empty() ? i : i - s.top() - 1);
			ag = max(ag, ga);
		}
	}
	while(!s.empty()){
		top = s.top(); s.pop();
		ga = a[top]*(s.empty() ? i : i - s.top()-1);
		ag = max(ag, ga);
	}
	return ag;
}
int main(){

	// ALOVEG

	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		ll a[n+1]; for(int i=0;i<n;i++)cin>>a[i];
		ll ag = solve(a, n);
		cout<<ag<<"\n";
	}
	return 0;
}


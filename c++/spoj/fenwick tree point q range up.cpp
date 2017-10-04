#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e4+5;
ll a[mn], n, l, r, q, m, g;

void update(int x, int val){
	while(x <= n){
		a[x] += val;
		x += (x&-x);
	}
}
ll query(int x){
	ll ag = 0;
	while(x > 0){
		ag += a[x];
		x -= (x&-x);
	}
	return ag;
}

int main()
{
    Aloveg

    int t;cin>>t;
    while(t--){
		memset(a, 0, sizeof a);
		cin>>n>>m;
		while(m--){
			cin>>l>>r>>g;
			l += 1; r += 1;
			update(l, g);
			update(r+1, -g);
		}
		cin>>q;
		while(q--){
			cin>>g; g += 1;
			cout<<query(g)<<"\n";
		}
    }
    return 0;
}



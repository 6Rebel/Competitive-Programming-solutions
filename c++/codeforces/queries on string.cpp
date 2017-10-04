#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e6+5;

int main()
{
    Aloveg

	string a,g; cin>>a;
    int t, l, r, k, n;cin>>t;
    while(t--){
		cin>>l>>r>>k;
		l-=1; r-=1;
		n = r-l+1;
		k %= n; g = "";
		for(int i=r-k+1; i<=r; i++)
			g += a[i];
		for(int i=l; i<=r-k; i++)
			g += a[i];
		for(int i=l; i<=r; i++)
			a[i] = g[i-l];
    }
    cout<<a;
    
    return 0;
}



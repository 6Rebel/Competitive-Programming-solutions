#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 3e6+5; 
map<ll,int> g;
 
int main()
{
    Aloveg

    int t;cin>>t;
    while(t--){
    	//input
		int n, k; cin>>n>>k; k += 2;
		ll a[n+1]; for(int i=0;i<n;i++)cin>>a[i];
		
		ll b, e; set<ll> ag; g.clear();
		ll aloveg = -1000; 
		
		//preprocess
		for(int i=0;i<min(n,k);i++){
			ag.insert(a[i]);
			g[a[i]] += 1;
		} 
		b = *ag.begin(); e = *ag.rbegin();
		aloveg = max(aloveg, abs(e - b));
		
		// two pointer
		for(int i=k,j=0;i<n;i++,j++){
			g[a[i]] += 1; g[a[j]] -= 1;
			if(g[a[j]] == 0)
				ag.erase(a[j]);
			ag.insert(a[i]);
			b = *ag.begin(); e = *ag.rbegin();
			aloveg = max(aloveg, abs(e - b));
		}
		cout<<aloveg<<"\n";
    }
    return 0;
}



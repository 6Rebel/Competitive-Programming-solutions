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
		int n; cin>>n;
		map<string, string> a;
		map<string, int> g;
		string u, v, start;
		for(int i=0;i<n;i++){
			cin>>u>>v;
			a[u] = v;
			g[u] += 1; g[v] += 1;
			if(g[u] == 1)
				start = u;
		}
		for(int i=0;i<n;i++){
			cout<<start<<"-"<<a[start]<<" ";
			start = a[start];
		}
		cout<<"\n";
    }
    return 0;
}



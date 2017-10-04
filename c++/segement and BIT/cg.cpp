#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e3+5;

int main()
{
    Aloveg

    int t;cin>>t;
    while(t--){
		int p, k, l;
		cin>>p>>k>>l;
		int a[l+1];
		for(int i=0;i<l;i++)
			cin>>a[i];
		sort(a, a+l);
		ll ag = 0;
		int j = 0, c = 1;
		for(int i=l-1; i>=0; i--){
			ag += (c*a[i]);
			j += 1;
			if(j == k){
				j = 0;
				c += 1;
			}
		}
		cout<<ag<<"\n";
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e6+5;

int main()
{
    Aloveg

	int n;
	cin>>n;
	n *= 2;
	int a[n+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a, a+n);
	int aloveg = 100000000, ag, ga;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ag = 0;ga=0;
			for(int k=0;k<n;k++){
				if(k==i or k==j)continue;
				ag += (ga ? -a[k] : a[k]);
				ga ^= 1;
			}
			cout<<ag<<" ";
			aloveg = min(aloveg, ag);
		}
	}
	cout<<aloveg;
    return 0;
}



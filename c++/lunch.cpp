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
		int a[n+1];
		for(int i=0;i<n;i++)
			cin>>a[i];
		if(n == 1)
			cout<<"2 1 4 3 6 5\n";
		else if(n==2){
			if(a[0]==a[1])
				cout<<"-1\n";
			else if(abs(a[0]-a[1])>1)
				cout<<"2 1 4 3 6 5\n";
			else
				cout<<"2 4 6 1 3 5\n";
		}
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e6+5;

int main()
{
    Aloveg

    ll n; cin>>n;
    if(n==1){
    	cout<<"1 1\n1";
	}else{
		cout<<(n-1)*5<<" "<<2<<"\n1 5";
	}
    
    return 0;
}



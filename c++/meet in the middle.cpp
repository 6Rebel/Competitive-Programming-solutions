#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

bool com(ll a,ll g){
    return a>g;
}
ll X[5000005],Y[5000005];
 
void cs(ll a[], ll x[], int n, int c)
{
	for (long long i=0; i<(1<<n); i++)
	{
		ll s = 0;
		for (long long j=0; j<n; j++)
	    	if (i & (1<<j))
    	    	s += a[j+c];
		// cout<<s<<" ";
		x[i] = s;
	}
}
 
ll aloveg(ll a[], int n, ll S)
{
 
	cs(a, X, n/2, 0);
	cs(a, Y, n-n/2, n/2);
	long  size_X = 1<<(n/2);
	long  size_Y = 1<<(n-n/2);
	//sort(X, X+size_X);
	sort(Y, Y+size_Y,com);
	ll max = 0,i=0;
 
	while( i<size_X ) 
	{
    
		if (X[i] >= S)
		{  
    		max += size_Y;
    		i+=1;
    		continue;
		}
		long long j=0;
		while(j<size_Y){
    		//cout<<Y[j]+X[i]<<" ";
			if ((Y[j]+X[i]) >= S )
    			max++;
			else
    			break;
			j++;
    	}
		i++;
	}
	return max;
}

ll power(ll a,ll g){
    ll ag = 1;
    while(g){
        if(g&1)
            ag = (ag*a*1ll);
        g >>=1;
        a = (a*a);
    }
    return ag;
}
 
int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	unsigned long long int ag;
	cin>>n;
	ll a[n],k;
	int i=0;
	while(i<n){
    	cin>>ag;
    	a[i] = ag;
    	i++;
	}
	cin>>ag;k=ag;
	ll ans = aloveg(a,n,k);
	//ans = ans;
	cout<<ans;
	return 0;
}  


#include<bits/stdc++.h>
#define ll long long
#define mod 1e9+7
using namespace std;
ll dp[10004][102];
int main()
{
	int t;
	cin>>t;
	assert(t>=1 && t<=1e5);
	for(int i=1;i<=100;i++)dp[0][i]=1;
	for(int k=1;k<=100;k++)
	{
	    for(int i=1;i<=10000;i++)
    	{   
		    for(int j=1;j<=min(i,k);j++)
		    {
			    dp[i][k]+=dp[i-j][k];dp[i][k]%=(ll)mod;
		    }
	    }
	}
	while(t--)
	{
		int x,k;
		cin>>x>>k;
		assert(x>=1 && x<=1e4);
		assert(k>=1 && k<=1e2);
		cout<<dp[x][k]<<"\n";
	}
	return 0;
}

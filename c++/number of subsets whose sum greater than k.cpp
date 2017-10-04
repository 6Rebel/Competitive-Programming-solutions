#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
long long int n,k,ans;
 
void findsol(long long int a[],long long int index,long long int sum)
{
    //printf("%lld %lld\n",index,sum);
    if(sum>=k)
    {
        ans+=pow(2,n-index);
        return;
    }
    if(index==n)
    	return;
    long long int i;
    for(i=index;i<n;i++)
    	findsol(a,i+1,sum+a[i]);
}
 
int main()
{
    long long int i,j;
    scanf("%lld",&n);
    long long int a[n];
    for(i=0;i<n;i++)
    	scanf("%lld",&a[i]);
    scanf("%lld",&k);
    sort(a,a+n);
    ans=0;
    findsol(a,0,0);
    printf("%lld\n",ans);
    return 0;
}

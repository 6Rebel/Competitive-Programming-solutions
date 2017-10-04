#include<bits/stdc++.h>

using namespace std;

//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define bitcount    __builtin_popcountll
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define MOD 1000000007
#define MAX 100005

int prime[100007];

void sieve()
{
    for(int i=2;i*i<=100005;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=100005;j+=i)
                prime[j] = 1;
        }
    }
}

int a[1005][1005];
ll dp[1005][1005];
int mark[1005][1005];
int q=0,n,m;
pair<int,int>ans[100005];

void dfs(int i,int j,int k)
{
    if(a[i][j]==0||i>n||j>m||mark[i][j]||q)
        return;
    mark[i][j]=1;
    ans[k]=mp(i,j);
    if(i==n&&j==m)
    {
        q=k;
        return;
    }
    
    dfs(i+1,j+1,k+1);
    dfs(i+1,j,k+1);
    dfs(i,j+1,k+1);
}

int main()
{
    sd(n);
    sd(m);
    sieve();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(prime[a[i][j]]==0)
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    
    dp[1][1]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
                continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1])%MOD;
            
            if(a[i][j]==0)
                dp[i][j]=0;
        }
        
    }
    cout<<dp[n][m]<<"\n";
    dfs(1,1,1);
    
    for(int i=1;i<=q;i++)
        cout<<ans[i].F<<" "<<ans[i].S<<"\n";
    return 0;
}

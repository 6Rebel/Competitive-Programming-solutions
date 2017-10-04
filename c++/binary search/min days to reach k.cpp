#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e5+5;
ll a[mn],g[mn];
 
int main()
{
    Aloveg
    
    int n; ll h;
    cin>>n>>h;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll temp = h;
    for(int i=1;i<=n;i++){
        temp -= i;
        g[i] = g[i-1]+a[i];
        if(temp <= g[i]){
            cout<<i;
            return 0;
        }
    }
    ll l,r,m,i,c,ag=2e9;
    for(int i=1;i<=n;i++){
        l=0 , r=(2e9)/n + 1;
        while(l <= r){
            m = (l + r)>>1;
            c = m*n+i;
            if(m*g[n]+g[i] >= h-c*(c+1)/2)
                r = m-1;
            else
                l = m+1;
        }
        ag = min(ag, l*n+i);
    }
    cout<<ag;
    
    return 0;
}

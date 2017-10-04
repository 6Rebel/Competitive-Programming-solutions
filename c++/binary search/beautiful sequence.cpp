#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e5+5;
ll a[mn],g[mn],n;
 
ll solve(){
    g[0] = 0;
    int hi,lo,mid,k=0;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            lo = 0; hi = k;
            while(lo < hi){
                mid = (lo+hi)/2 + 1;
                if(g[mid] <= a[i])
                    lo = mid;
                else
                    hi = mid-1;
            }
            if(lo==k) k++;
            g[++lo] = a[i];
        }
    }
    return k;
}
 
int main()
{
    Aloveg
    
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i]; a[i] -= i;
        }
        ll ag = solve();
        cout<<n-ag<<"\n";
    }
    return 0;
}


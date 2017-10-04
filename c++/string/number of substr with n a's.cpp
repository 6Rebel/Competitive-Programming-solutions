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
        ll r=0, k=0, rr, kk, ag=0, ga=0;
        cin>>rr>>kk;
        string s; cin>>s;
        ll a[mn] , g[mn];
        for(int i=0;i<mn;i++){
            a[i] = g[i] = 0;
        }a[0]=g[0]=1;
        for(auto i : s){
            if(i == 'R')
                r += 1;
            else
                k += 1;
            if(r >= rr)
                ag += a[r - rr];
            a[r] += 1;
            if(k >= kk)
                ga += g[k - kk];
            g[k] += 1;
        }
        cout<<ag<<" "<<ga<<"\n";
    }
    return 0;
}

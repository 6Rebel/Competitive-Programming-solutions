#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e5+5;
 
int main()
{
    Aloveg
    
    int n; cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n);
    int ag = 0;
    for(int i=0;i<n-2;i++)
        ag = max(abs(a[i]-a[i+2]), ag);
    cout<<ag;
    return 0;
}

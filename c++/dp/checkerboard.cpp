#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 2e3+5;
string s[mn];
int a[mn][mn] , g[mn][mn], n, m, ag = 0;
 
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i != 0){
                if(s[i][j] == s[i-1][j])
                    a[i][j] = 1;
                else
                    a[i][j] = a[i-1][j] + 1; 
            }
            else
                a[i][j] = 1;
        }
    }
    for(int i=31;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] >= 32){
                if(j != 0){
                    if(s[i][j] == s[i][j-1])
                        g[i][j] = 1;
                    else
                        g[i][j] = g[i][j-1] + 1;
                }else
                    g[i][j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] >= 32 and s[i][j] == '_')
                ag += 1;
}
 
int main()
{
    Aloveg
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    solve();
    cout<<ag;
    
    return 0;
}


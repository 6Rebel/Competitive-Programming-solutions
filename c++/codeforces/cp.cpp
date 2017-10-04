#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e5+5;

int main()
{
    Aloveg
    
    int t;cin>>t;
    while(t--){
        int n, m, ag = 0, aag=0;
        cin>>n>>m;
        char a[n+1][n+1], g[n+1][n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j] == 'P'){
                    //cout<<j-1<<" g "<<max(j-m,0)<<"\n";
                    for(int k=max(j-m,0); k<j; k++){
                        if(a[i][k] == 'T'){
                            a[i][k] = 'g';
                            a[i][j] = 'a';
                            ag += 1;
                            break;
                        }
                    }
                }
                if(a[i][j] == 'P'){
                    //cout<<j+1<<" a "<<min(m+j,n-1)<<"\n";
                    for(int k=min(m+j,n-1); k>j; k--){
                        if(a[i][k] == 'T'){
                            a[i][k] = 'g';
                            a[i][j] = 'a';
                            ag += 1;
                            break;
                        }
                    }
                }
            }
        }
        
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }*/
        cout<<ag<<"\n";
    }
    return 0;
}


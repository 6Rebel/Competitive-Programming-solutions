#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+9;
long long solve(int a,int g){
    long long ag[a+1]={0};
    ag[0] = 1;
    for(int i=g;i<=a;i++){
        for(int j=i;j<=a;j++)
            ag[j] = (ag[j] + ag[j-i])%mod;
    }
    return ag[a];
}
 
int main(){
    int t ; cin>>t;
    while(t--){
        int a,g;
        cin>>a>>g;
        cout<<solve(a,g)<<"\n";
    }
    return 0;
}

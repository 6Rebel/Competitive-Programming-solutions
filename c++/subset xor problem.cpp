/*  Success may not come to me immediately,
 *  but it will come definitely....
 */
#include <bits/stdc++.h>
//=====================================================================
using namespace std;
//=====================================================================
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//=====================================================================
#define li      int64_t
#define ld      double_t
#define ulli    uint64_t
//=====================================================================
#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define repi(i,v)   for(i=v.begin();i!=v.end();i++)
#define repir(i,v)  for(i=v.rbegin();i!=v.rend();i++)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))
#define nl          cout<<'\n'
//=====================================================================
typedef vector<li>       vli;
typedef vector<string>   vstr;
typedef pair<li,li>      pli;
typedef pair<li,pli >    ppli;
typedef pair<li,ppli >   pppli;
typedef vector<pli >     vpli;
typedef vector<ppli >    vppli;
typedef vector<pppli >   vpppli;
//=====================================================================
#define pb  push_back
#define pob pop_back
#define pf  push_front
#define pof pop_front
#define all(v)  v.begin(),v.end()
#define itr iterator
#define rtr reverse_iterator
#define sz  size()
#define lb  lower_bound
#define ub  upper_bound
#define bs  binary_search
#define mp  make_pair
#define F   first
#define S   second
//=====================================================================
#define mod (li)(1e9+7)
#define inf (li)(1e18)
#define MX1 (li)(1e5+5)
#define MX2 (li)(1e6+5)
#define pi  acos(-1)
//=====================================================================
li power(li a,li b){li ans=1;while(b){if(b&1){ans=(ans*a)%mod;}
a=(a*a)%mod;b>>=1;}return ans;}
//=====================================================================
li mmi(li n){return power(n,mod-2);}
//=====================================================================
li two(li n){return (1LL<<n);}
//=====================================================================
void onbit(li &n,li x){n|=two(x);}
//=====================================================================
void offbit(li &n,li x){n&=~two(x);}
//=====================================================================
li cntbit(li n){li res=0;while(n and ++res)n-=n&-n;return res;}
//=====================================================================
li dx[]={+1,+1,-1,-1,+2,+2,-2,-2};li dy[]={+2,-2,+2,-2,+1,-1,+1,-1};
//=====================================================================
/*------------------------MAIN CODE BEGINS NOW!------------------------*/
 
li n,k,a[45];
vli res1,v;
unordered_map<li,li> mpp;
 
void solve(){
  li i,j;cin>>n>>k;
  rep(i,0,n) cin>>a[i];
  li m=n/2;
  li l=n-m;
  rep(i,0,m) v.pb(a[i]);
  rep(i,0,(1LL<<m)){
    li sum=0;
    rep(j,0,m){
      if(i&(1LL<<j)){
        sum^=v[j];
      }
    }
    res1.pb(sum);
  }
  v.clear();
  rep(i,m,n) v.pb(a[i]);
  rep(i,0,(1LL<<l)){
    li sum=0;
    rep(j,0,l){
      if(i&(1LL<<j)){
        sum^=v[j];
      }
    }
    mpp[sum]++;
  }
  li ans=0;
  rep(i,0,res1.sz){
    ans+=mpp[k^res1[i]];
  }
  cout<<ans;
}
 
int main(){
  //opt
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  li t=1;
  //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}

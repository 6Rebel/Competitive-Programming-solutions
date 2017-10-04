#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define MAX 100005
#define MOD 1000000007
#define sz size()
#define ln length()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n);
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n);
inline ll gcd(ll x,ll y){return x%y==0?y:gcd(y,x%y);}
inline ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
inline ll powmod(ll a,ll b,ll mod)
{
    ll res=1;
    a%=mod;
    assert(b>=0);
    for(;b;b>>=1)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}
inline ll mulmod(ll a, ll b, ll c)
{
    if(!b)return 0;
    ll x = mulmod(a, b/2, c);
    if (b & 1)return (x+x+a)%c;
    return (x+x)%c;
}
 
int p = 1331;
string str;
ull hash[100005],rev_hash[100005],powerr[100005];
 
ull BIT[100005], RBIT[100005];
 
void updat(int ind, ull x) {
   
    while (ind < MAX) {
       
        BIT[ind] += x;
        ind += (ind & -ind);
    }
}
 
ull chan(int ind){
    ull sum = 0;
    while (ind) {
       
        sum += BIT[ind];
        ind -= (ind & -ind);
    }
    return sum;
}
 
void rbp(int ind, ull x) {
   
    while (ind < MAX) {
       
        RBIT[ind] += x;
        ind += (ind & -ind);
    }
}
 
ull var(int ind){
    ull sum = 0;
    while (ind) {
       
        sum += RBIT[ind];
        ind -= (ind & -ind);
    }
    return sum;
}
 
int main()
{
    powerr[0] = 1;
    for(int i = 1; i < 100005; i++) {
        powerr[i] = powerr[i-1]*p;
    }
    int t,n,q,l,r;
    si(n);si(q);
   
    cin >> str;
   
    for(int i = 1; i <= n; i++) {
        updat(i,str[i-1]*powerr[i - 1]);
    }
 
    for(int i = n; i >= 1; i--) {
        rbp(i,str[i-1]*powerr[n - i]);
    }
    for(int i=0;i<15;i++){
    	i++;
    }
    char ch;
    ull val,rval;
    while(q--) {
        //cout<<q<<endl;
        si(t);si(l);
       
        if(t==1) {
           
            cin>>ch;
            val = ch*powerr[l-1] - str[l - 1]*powerr[l-1];
            updat(l,val);
            val = ch*powerr[n - l] - str[l - 1]*powerr[n - l];
            rbp(l,val);
            str[l - 1] = ch;
        }
        else {
           
            si(r);
            val = chan(l -1);
            val = chan(r) - val;
            val *= (powerr[n - r]);
 
            rval = var(l - 1);
            rval = var(r) - rval;
            rval *= (powerr[l - 1]);
 
            if(val == rval)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
#define INF 1000000100
#define INFL 1000000000000000100
#define eps 1e-8
#define endl '\n'
#define sd(n) scanf("%d",&n)
#define slld(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define plld(n) printf("%lld",n)
#define pds(n) printf("%d ",n)
#define pllds(n) printf("%lld ",n)
#define pdn(n) printf("%d\n",n)
#define plldn(n) printf("%lld\n",n)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second
#define clr(a) memset(a,0,sizeof(a))
#define BLOCK 500
using namespace std;
 
int nod[upperlimit+1];
int arr[upperlimit+1];
ll cnt[upperlimit+1];
ll answers[upperlimit+1];
ll answer=0;
struct quer{
    int l,r,i;
};
quer queries[upperlimit+1];
int n,q;
bool cmp(quer a,quer b){
    if((a.l/BLOCK)!=(b.l/BLOCK))return (a.l/BLOCK)<(b.l/BLOCK);
    return (a.r<b.r);
}
void add(int ind){
    answer+=cnt[arr[ind]];
    cnt[arr[ind]]++;
}
void rem(int ind){
    cnt[arr[ind]]--;
    answer-=cnt[arr[ind]];
}
void MO(){
    sort(queries+1,queries+q+1,cmp);
    int l,r,cl=queries[1].l,cr=queries[1].l-1;
    for(int i=1;i<=q;i++){
        l=queries[i].l;
        r=queries[i].r;
        while(cr<r)add(++cr);
        while(cl>l)add(--cl);
        while(cr>r)rem(cr--);
        while(cl<l)rem(cl++);
        answers[queries[i].i]=answer;
    }
    for(int i=1;i<=q;i++)plldn(answers[i]);
}
int main()
{
    int i,j,k,l,r;
    for(i=1;i<=upperlimit;i++)for(j=i;j<=upperlimit;j+=i)nod[j]++;
    sd(n);
    for(i=1;i<=n;i++){
        sd(arr[i]);
        arr[i]=nod[arr[i]];
    }
    sd(q);
    for(i=1;i<=q;i++){
        sd(l);sd(r);
        queries[i].i=i;
        queries[i].l=l;
        queries[i].r=r;
    }
    MO();
    return 0;
}

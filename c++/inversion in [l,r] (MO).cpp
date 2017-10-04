#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
const int M = 1000000007;
const double PI = atan(1) * 4;
const int oo = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define pb push_back 
#define all(c) (c).begin(),(c).end()
int n,q,l,r,sq,v[N],fen[N];
ll ct,ans[N];
struct que{
	int l,r,x;
	que(int a, int b, int c){
		l=a;r=b;x=c;
	}
	bool operator<(const que&e)const{
		if(l/sq!=e.l/sq)
			return l/sq<e.l/sq;
		return r<e.r;
	}
};
void clr(){
	ct=0;
	for(int i=0; i<=n; ++i)
		fen[i]=0;
}
int get(int x, int ret=0){
	for(; x; x-=x&-x)
		ret+=fen[x];
	return ret;
}
void upd(int x, int vl){
	for(; x<=n; x+=x&-x)
		fen[x]+=vl;
}
void add(int x){
	ct+=get(n)-get(x);
	upd(x,1);
}
void rem(int x){
	ct-=get(n)-get(x);
	upd(x,-1);
}
 
vector<que> Q;
int main(){
	cin>>n>>q;
	sq=sqrt(n);
	vi t;
	t.pb(-1);
	for(int i=1; i<n+1; ++i){
		scanf("%d",&v[i]);
		t.pb(v[i]);
	}
	sort(all(t));
	t.resize(unique(all(t))-t.begin());
	for(int i=1; i<n+1; ++i)
		v[i]=lower_bound(all(t),v[i])-t.begin();
	for(int a,b,i=0; i<q; ++i){
		scanf("%d%d",&a,&b);
		Q.pb(que(a,b,i));
	}
	sort(all(Q));
	for(int i=0; i<q; ++i){
		int a=Q[i].l, b=Q[i].r, x=Q[i].x;
		if(b-a+1>sq)
			continue;
		for(int j=a; j<=b; ++j)
			add(v[j]);
		ans[x]=ct;
		for(int j=b; j>=a; --j)
			rem(v[j]);
	}
	int s,e,ls=-1;
	for(int i=0; i<q; ++i){
		int a=Q[i].l, b=Q[i].r, x=Q[i].x;
		if(b-a+1<=sq)
			continue;
		if(ls<a/sq){
			clr();
			ls=a/sq;
			s=(ls+1)*sq;
			e=s-1;
		}
		while(e<b)
			add(v[++e]);
		for(int j=s-1; j>=a; --j){
			ct+=get(v[j]-1);
			upd(v[j],1);
		}
		ans[x]=ct;
		for(int j=a; j<s; ++j){
			ct-=get(v[j]-1);
			upd(v[j],-1);
		}
	}
	for(int i=0; i<q; ++i)
		printf("%lld\n", ans[i]);
}


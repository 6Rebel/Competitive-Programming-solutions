#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);
const int mn = 3e4+9;
int a[mn],bs,aloveg = 0,ans[200005],ag[1000002];

struct pii{
	int l,r,id;
};
pii qu[200005];

bool com(pii& a, pii& g){
	if(a.l/bs != g.l/bs)
		return a.l/bs < g.l/bs;
	return a.r < g.r;
}

void add(int i){
	ag[i] += 1;
	if(ag[i] == 1)
		aloveg += 1;
}

void rem(int i){
	ag[i] -= 1;
	if(ag[i] == 0)
		aloveg -= 1;
}


int main()
{
    Aloveg

    int n; cin>>n;
    bs = (int)sqrt(n);
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    int q,l,r;cin>>q;
    for(int i=0;i<q;i++){
    	cin>>qu[i].l>>qu[i].r;
    	qu[i].id = i;
	}
	sort(qu, qu+q, com);
	int cl = qu[0].l;
	int cr = cl - 1;
	for(int i=0;i<q;i++){
		l = qu[i].l;
		r = qu[i].r;
		while(l < cl) add(a[--cl]);
		while(l > cl) rem(a[cl++]);
		while(r < cr) rem(a[cr--]);
		while(r > cr) add(a[++cr]);
		ans[qu[i].id] = aloveg;
	}
	for(int i=0;i<q;i++)
		cout<<ans[i]<<"\n";
    
    return 0;
}



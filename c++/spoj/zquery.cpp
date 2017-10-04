#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pii pair<pair<int, int >, int>
#define x first
#define y second

const int mn = 1e6+5;
int sz;
bool com(pii a, pii g){
	if(a.x.x/sz != g.x.x/sz)
		return a.x.x/sz < g.x.x/sz;
	return a.x.y < g.x.y;
}

int main()
{
    Aloveg

    int n, m; cin>>n>>m;
    sz = (int)sqrt(n);
	int a[n+1], aloveg[m+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    pii q[m+1];
    int l, r, id;
	for(int i=0;i<m;i++){
    	cin>>l>>r;
    	q[i] = make_pair(make_pair(l, r), i);
	}
	sort(q, q+m, com);
    int cl=q[0].x.x;
    int cr = cl - 1, ag = 0;
    for(int i=0;i<m;i++){
    	l = q[i].x.x;
    	r = q[i].x.y;
    	id = q[i].y;
    	while(l < cl) ag += a[--cl];
		while(l > cl) ag -= a[cl++];
		while(r < cr) ag -= a[cr--];
		while(r > cr) ag += a[++cr];
		aloveg[id] = max(0,(r-l+1 - abs(ag)));
		//cout<<l<<" "<<r<<" "<<id<<" "<<aloveg[id]<<"\n";
	}
	for(int i=0;i<m;i++)
		cout<<aloveg[i]<<"\n";
    return 0;
}



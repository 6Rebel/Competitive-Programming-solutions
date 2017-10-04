#include<bits/stdc++.h>
using namespace std;
const int mn = 1e6+5;
int bit[mn] = {0};
int n;
struct Q{
	int l,r,v,q;
};
Q a[mn];

bool com(Q a,Q g){
	if(a.v == g.v){
		return a.r > g.r;
	}
	return a.v > g.v ;
}

void update(int i,int val){
	while(i<=n){
		bit[i] += val;
		i += (i&-i);
	}
}
int query(int i){
	int ag = 0;
	while(i>0){
		ag += bit[i];
		i -= (i&-i);
	}
	return ag;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		a[i].l = i+1;
		a[i].r = -1;
		cin>>a[i].v;
		a[i].q = -1;
	}
	int m,l,r,v;cin>>m;
	int ag[m+1];
	for(int i=0;i<m;i++){
		cin>>l>>r>>v;
		a[i+n].l = l;
		a[i+n].r = r;
		a[i+n].v = v;
		a[i+n].q = i;
	}
	
	sort(a,a+n+m,com);
	//cout<<"A";
	for(int i=0;i<n+m;i++){
		if(a[i].q==-1)
			update(a[i].l,1);
		else{
			ag[a[i].q] = query(a[i].r) - query(a[i].l-1);
		}
	}
	for(int i=0;i<m;i++)
		cout<<ag[i]<<"\n";
	return 0;
}

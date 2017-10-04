#include<bits/stdc++.h>
using namespace std;
const int m=1e6+5;
vector<int> a[m];
vector<int> ag[4*m];
 
void build(int n,int s,int e){
	if(s==e){
		ag[n] = a[s];
		return ;
	}else{
		int mid=(s+e)>>1;
		int l = n<<1;
		build(l,s,mid);
		build(l+1,mid+1,e);
		merge(ag[l].begin(),ag[l].end(),ag[l+1].begin(),ag[l+1].end(),back_inserter(ag[n]));
	}
}
int query(int cur,int s,int e,int l,int r,int x,int y){
	if(r<s or l>e)
		return 0;
	if(s>=l and e<=r){
		int q1 = lower_bound(ag[cur].begin(),ag[cur].end(),x)-ag[cur].begin();
		int q2 = upper_bound(ag[cur].begin(),ag[cur].end(),y)-ag[cur].begin();
		return q2-q1;
	}else{
		int mid = (s+e)>>1;
		return query(2*cur,s,mid,l,r,x,y)+query(2*cur+1,mid+1,e,l,r,x,y);
	}
}
int main(){
	int n;cin>>n;
	int g;
	for(int i=1;i<=n;i++){
		cin>>g;
		while(g%2==0){
			a[i].push_back(2);
			g/=2;
		}
		for(int j=3;j*j<=g;j+=2)
		{
			while(g%j==0){
				a[i].push_back(j);
				g /= j;
			}
		}
		if(g > 2)
			a[i].push_back(g);
	}
	build(1,1,n);
	int q;cin>>q;
	int l,r,x,y;
	while(q--){
		cin>>l>>r>>x>>y;
		int ans = query(1,1,n,l,r,x,y);
		cout<<ans<<endl;
	}
	return 0;
} 

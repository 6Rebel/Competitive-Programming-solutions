//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<iomanip>
#include<math.h>
#include<limits.h>
#include<string.h>
#include <ctime>
#include <deque>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<bitset>
#include<set>
#include <sstream>
#include <list>
#define mod 1000000007
#define MAX 100000000
using namespace std;
#define scan(a) scanf("%d",&a);
#define print(a) printf("%d\n",a);
#define mem(a,v) memset(a,v,sizeof(a))
#define clr(a) memset(a,0,sizeof(a))
#define pb(x) push_back(x)
#define sort(a) sort(a.begin(),a.end())
#define inf 1e9
#define mp(a,b) make_pair(a,b)
#define V vector
#define S string
#define Gu getchar_unlocked
#define Pu putchar_unlocked
#define Read(n) ch=Gu(); while (ch<'0') ch=Gu(); n=ch-'0'; ch=Gu(); while (!(ch<'0')) {n=10*n+ch-'0'; ch=Gu();}
#define Write(n) r=n; chptr=s; *chptr=r%10+'0'; r/=10; for (; r; r/=10) {++chptr; *chptr=r%10+'0'; } Pu(*chptr); for (; chptr!=s; ) Pu(*--chptr);
typedef long long LL;
typedef long double LD;
typedef long L;
typedef pair<int,int> pii;
const double pi=acos(-1.0);
int arr[100010];
struct T
{
  	LL gc;
}tree[1000050];
LL gcd(LL a,LL b)
{
	if(b==0)	
		return a;
	else
		return gcd(b,a%b);
}
void build(int node,int a,int b)
{
  	if(a==b)
  	{
    	tree[node].gc=arr[a];
		return;
  	}
  	int mid=(a+b)>>1;
  	build(2*node,a,mid);
  	build(2*node+1,mid+1,b);
  	tree[node].gc = gcd(tree[2*node].gc,tree[2*node+1].gc);
  	return;
}
LL query(int node,int i,int j,int a,int b)
{
 	if(a<=i && b>=j)
  	{
    	return tree[node].gc;
  	}
  	if(b<i||a>j)
  	{
    	return -1;
  	}
  	int mid=(i+j)>>1;
  	LL t1=query(2*node,i,mid,a,b);
  	LL t2=query(2*node+1,mid+1,j,a,b);
  	if(t1==-1 && t2==-1)
  		return 1;
  	else if(t1==-1)
  		return t2;
  	else if(t2==-1)
  		return t1;
  	else
  		return gcd(t1,t2);
}
void multiply(LL f[2][2],LL m[2][2])
{
  LL x =  (f[0][0]*m[0][0] + f[0][1]*m[1][0])%mod;
  LL y =  (f[0][0]*m[0][1] + f[0][1]*m[1][1])%mod;
  LL z =  (f[1][0]*m[0][0] + f[1][1]*m[1][0])%mod;
  LL w =  (f[1][0]*m[0][1] + f[1][1]*m[1][1])%mod;
 
  f[0][0] = x;
  f[0][1] = y;
  f[1][0] = z;
  f[1][1] = w;
}
void power(LL f[2][2],LL n)
{
    if(n==0||n==1)
      	return;               
    LL m[2][2]={{1,1},{1,0}};
    power(f,n/2);
    multiply(f,f);
    if(n%2!=0)
      	multiply(f,m);  
}
LL fib(LL n)
{
   	LL f[2][2]={{1,1},{1,0}};
   	if(n==0)
		return 0;
 	power(f,n-1);
   	return (f[0][0]%mod);
}
int main()
{
	/*int ch;
   	int r;
   	char s[12];
   	char *chptr;*/
   	//freopen("in18.txt","r",stdin);
   	//freopen("out18.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int n,q,a,b;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	build(1,0,n-1);
	while(q--)
	{
	  	scanf("%d %d",&a,&b);
	  	a--;
	  	b--;
	  	int t1=query(1,0,n-1,a,b);
	  	cout<<fib(t1)%mod<<endl;
	}	
  	return 0;
}

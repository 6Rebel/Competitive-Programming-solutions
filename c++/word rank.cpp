#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define INF INT_MAX
const int mod=1000000007;
ll fact[20];
void factorial()
{
    ll i,j,k;
    fact[0]=fact[1]=1;
    for (i=2;i<20;++i)
        fact[i]=(i*fact[i-1]);
}
int main()
{
    ll t,n,m,i,j,k,l,x;
    factorial();
    scanf ("%lld",&t);
    getchar();
    while (t--)
    {
        char str[30],res[30];
        scanf ("%s",str);
        scanf ("%lld",&n);
        ll a[26]={0};
        for (i=0;str[i]!='\0';++i)
            a[str[i]-97]++;
        l=strlen(str);
        m=0;
        for (i=0;i<l;++i)
        {
            for (j=0;j<26;++j)
            {
                k=fact[l-i-1];
                if (a[j]>0)
                {
                    for (x=0;x<26;++x)
                    {
                        if (x==j && a[x]>0)
                            k/=fact[a[x]-1];
                        else
                            k/=fact[a[x]];
                    }
                    if (n>k)
                        n-=k;
                    else
                    {
                        res[m++]=(char)(j+97);
                        a[j]--;
                        break;
                    }
                }
            }
        }
        res[m]='\0';
        printf ("%s\n",res);
    }
	return 0;
}

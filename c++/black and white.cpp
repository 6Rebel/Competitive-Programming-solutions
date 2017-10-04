#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <assert.h>
#include <list>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 10000000
#define SQ 317
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,sz,cur,sum,n,c, maxlvl,q,z;
ll a[100500];
ll dp[100500][2];
vector<ll> g[100500], f[100500], ans;
void dfs(ll v, ll p = -1)
{
    if (a[v] == 0)
        dp[v][0] = 1, dp[v][1] = -1;
    else
        dp[v][0] = -1, dp[v][1] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            f[v].push_back(to);
            dfs(to, v);
            if (dp[to][0] > 0)
                dp[v][0] += dp[to][0];
            if (dp[to][1] > 0)
                dp[v][1] += dp[to][1];
        }
    }
}
void dfs2(ll v, ll col)
{
    ans.push_back(v);
    for (int i = 0; i < f[v].size(); i++)
    {
        ll to = f[v][i];
        if (dp[to][col] > 0)
            dfs2(to, col);
    }
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("input.txt","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (i = 1; i <= n; i++)
        for (j = 0; j < 2; j++)
            if (dp[i][j] > m)
            {
                m = dp[i][j];
                l = i;
                r = j;
            }
    cout << m << endl;
    dfs2(l, r);
    cout << ans.size() << endl;
    for (j = 0; j < ans.size(); j++)
        cout << ans[j] << " ";
    return 0;
}

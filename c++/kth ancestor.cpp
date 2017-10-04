#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <algorithm>
#include <cassert>
    
using namespace std;
    
#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back
    
typedef long long int lli;
typedef pair<int,int> pi;
    
int p[100000][40]={{0}};
int a[100005],isnode[100005];
int main ()
{
    
    int q,ch,x,y,t;
    scanf("%d",&t);
    assert(t>=1 && t<=3);
    while(t--)
    {
        memset(p,0,sizeof(p));
        memset(isnode,0,sizeof(isnode));
        int i,n,j;
        scanf("%d",&n);
        assert(n>=1 && n<=100000);
        for(i = 0;i < n;i++)
        {
            scanf("%d %d",&x,&y);
            assert(x>=1 && x<=100000);
            assert(y>=0 && y<=100000);
            a[i] = x;
            if(y!=0)
                assert(isnode[y]==1);
            assert(isnode[x]==0);
            isnode[x] = 1;
            p[x][0] = y;
        }
        int lgn = (int)(log(n)/log(2))+1;
        for(j = 1;j<=lgn;j++)
        {
            for(i = 0;i < n;i++)
            {
                p[a[i]][j] = p[p[a[i]][j-1]][j-1];
            }
        }
    
        scanf("%d",&q);
        assert(q>0 && q<=100000);
        for(i = 0;i < q;i++)
        {
            scanf("%d",&ch);
            assert(ch>=0 && ch<=2);
            if(ch == 0) //Add an edge
            {
                scanf("%d %d",&x,&y);
    
                assert(y>=1 && y<=100000);
                assert(x>=1 && x<=100000);
                
                assert(isnode[x]==1);
                assert(isnode[y]==0);
                isnode[y] = 1;
                p[y][0] = x;
                j = 0;
                while(p[y][j]!=0)
                {
                    p[y][j+1] = p[p[y][j]][j];
                    j++;
                }
                while(j<=lgn)
                {
                    p[y][j] = 0;
                    j++;
                }
            }
            else if(ch == 1) //Remove an edge
            {
                scanf("%d",&x);
                assert(x>=1 && x<=100000);
                assert(isnode[x]==1);
                isnode[x] = 0;
                for(j = 0;j <= lgn;j++)
                {
                    p[x][j] = 0;
                }
            }
            else
            {
                scanf("%d %d",&x,&y);
                assert(x>=1 && x<=100000);
                assert(y>=1 && y<=100000);
                j = 0;
                while(y>0)
                {
                    if(y&1)
                        x = p[x][j];
                    y = y>>1;
                    j++;
                }
                printf("%d\n",x);
            }
        }
    }
    return 0;
}

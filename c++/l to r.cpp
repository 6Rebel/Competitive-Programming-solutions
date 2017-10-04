#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const int mn=1e5+5;

int getFrequency(int tree[mn][27], int idx, int i)
{
    int sum = 0;
 
    while (idx > 0)
    {
        sum += tree[idx][i];
        idx -= (idx & -idx);
    }
 
    return sum;
}
void update(int tree[mn][27], int idx, int val, int i)
{
    while (idx <= mn)
    {
        tree[idx][i] += val;
        idx += (idx & -idx);
    }
}

void qType1(int tree[mn][27], int l, int x, char str[])
{
    update(tree, l, -1, str[l-1]-97+1);
    str[l-1] = x;
    update(tree, l, 1, str[l-1]-97+1);
}

bool qType2(int tree[mn][27], int l, int r, char str[])
{
    int count = 0;
 
    for (int i = 1; i <= 26; i++)
    {
        if (l == 1)
        {
            if (getFrequency(tree, r, i)%2 == 1)
                count++;
        }
        else
        {
            if ((getFrequency(tree, r, i) -
                 getFrequency(tree, l-1, i))%2 == 1)
                count++;
        }
    }
 
    return count<=1;
}

void buildBIT(int tree[mn][27], char str[], int n)
{
    memset(tree,0,sizeof(tree));
 
    for (int i = 0; i < n; i++)
        update(tree, i+1, 1, str[i]-97+1);
}

void love(char str[], int l, int r){
    while(l<r){
        if(str[l] != str[r]){
            cout<<"NO\n";
            return;
        }
        l++; r--;
    }
    cout<<"YES\n";
}
  

int main()
{
    Aloveg
    int n, q;
    cin>>n>>q;
    char str[n+1];
    for(int i=0;i<n;i++)cin>>str[i];
    int tree[mn][27];
    buildBIT(tree, str, n);
    int c, l, r; char ch;
    while(q--){
        cin>>c;
        if(c == 1){
            cin>>l>>ch;
            qType1(tree, l, ch, str);
            
        }else{
            cin>>l>>r;
            bool flag = qType2(tree, 10, 11, str);
            if(flag){
                love(str, l-1, r-1);
            }else{
                cout<<"NO\n";   
            }
        }
    }
    return 0;
}


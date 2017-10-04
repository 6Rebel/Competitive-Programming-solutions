#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 200000;
 
int sparse[20][maxn];
int arr[maxn];
 
int gcd(int a, int b){
    return (b == 0)?(a):(gcd(b,a%b));
}
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        sparse[0][i] = arr[i];
    }
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= n; j++)
            if((j + (1 << i) - 1) <= n)
                sparse[i][j] = gcd(sparse[i - 1][j], sparse[i - 1][j + (1 << (i-1))]);
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        int q = 19;
        while((i + (1 << q) - 1) > n) q--;
        int G = arr[i];
        int r = i;
        while(q >= 0){
            int nr = r + (1 << q) - 1;
            int v = sparse[q][r];
            if(gcd(v, G) > 1 && nr <= n){
                r += (1 << q);
                G = gcd(v,G);
            }
            q--;
        }
        ans += (r - i);
    }
    cout << ans << "\n";
    return 0;
}

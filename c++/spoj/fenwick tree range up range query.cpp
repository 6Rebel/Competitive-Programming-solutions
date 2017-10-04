#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Aloveg ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const int mn = 1e4+5;

int getSum(int BITree[], int index)
{
    int sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}
 
// Returns the sum of array from [0, x]
int sum(int x, int BITTree1[], int BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}
 
 
void updateRange(int BITTree1[], int BITTree2[], int n,
                 int val, int l, int r)
{
    // Update BIT1
    updateBIT(BITTree1,n,l,val);
    updateBIT(BITTree1,n,r+1,-val);
 
    // Update BIT2
    updateBIT(BITTree2,n,l,val*(l-1));
    updateBIT(BITTree2,n,r+1,-val*r);
}
 
int rangeSum(int l, int r, int BITTree1[], int BITTree2[])
{
    return sum(r, BITTree1, BITTree2) -
           sum(l-1, BITTree1, BITTree2);
}
 
 
int *constructBITree(int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    return BITree;
}

int main()
{
    int n = 5;
    int *BITTree1, *BITTree2;
    
    BITTree1 = constructBITree(n);
    BITTree2 = constructBITree(n);
    
	int l = 0 , r = 4 , val = 5;
    updateRange(BITTree1,BITTree2,n,val,l,r);
    
	l = 2 , r = 4 , val = 10;
    updateRange(BITTree1,BITTree2,n,val,l,r);
    
	l = 1 , r = 4;
    cout << "Sum of elements from [" << l
         << "," << r << "] is ";
    cout << rangeSum(l,r,BITTree1,BITTree2) << "\n";
 
    return 0;
}

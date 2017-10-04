#include<bits/stdc++.h>
using namespace std;
 
 
void multiply(long long a[3][3], long long b[3][3])
{
  
    long long mul[3][3];
    for (long long i = 0; i < 3; i++)
    {
        for (long long j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (long long k = 0; k < 3; k++)
                mul[i][j] =(mul[i][j]+ (a[i][k]*b[k][j])%1000000007)%1000000007;
        }
    }
 
  
    for (long long i=0; i<3; i++)
        for (long long j=0; j<3; j++)
            a[i][j] = mul[i][j]; 
}
long long power(long long F[3][3], long long n)
{
    long long M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
 
    if (n==1)
        return ((3*F[0][0])%1000000007 + (2*F[0][1])%1000000007+(1*F[0][2])%1000000007)%1000000007;
 
    power(F, n/2);
 
    multiply(F, F);
 
    if (n%2 != 0)
        multiply(F, M);
 
 
    return ((3*F[0][0])%1000000007 + (2*F[0][1])%1000000007+(1*F[0][2])%1000000007)%1000000007;
}
 
 
long long findNthTerm(long long n)
{
    long long F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
 
    return power(F, n-2);
}
 
 
int main()
{
 	long long t;
 	cin>>t;
 	while(t--)
 	{
 		long long n;
 		cin>>n;
 		n--;
 		cout<<findNthTerm(n)%1000000007<<"\n";
 		
	 }
 
}

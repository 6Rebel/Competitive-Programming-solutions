#include <bits/stdc++.h>
using namespace std;
int A[102];
int main()
{
	int t,n,k;
	cin >> t;
	assert(t<=10);
	while ( t-- ) {
		cin >> n >> k;
		assert(n<=100);
		assert(k<=100);
		int mn;
		for ( int i = 0; i < n; i++ ) {
			cin >> A[i];
			assert(A[i]>=-100000 && A[i]<=100000);
			if ( i == 0 ) mn = A[i];
			else mn = min(mn, A[i]);
		}
		for ( int i = 0; i < n; i++ ) {
			for ( int j = i; j < n; j++ ) {
				priority_queue < int > pq1;
				priority_queue < int, vector<int>, greater<int> > pq2;
				int sum = 0;
				for ( int k = 0; k < n; k++ ) {
					if ( k >= i && k <= j ) pq1.push(A[k]), sum += A[k];
					else pq2.push(A[k]);
				}
				int cnt = 0;
				while ( cnt < k && (!pq1.empty()) && (!pq2.empty()) ) {
					int f1 = pq1.top();
					int f2 = pq2.top();
					if ( sum + f2 - f1 < sum ) {
						sum = sum + f2 - f1;
						pq2.pop();
						pq1.pop();
						pq2.push(f1);
						pq1.push(f2);
						cnt++;
					}
					else break;
				}
				mn = min(mn, sum);
			}
		}
		cout << mn << endl;
	}
	return 0;
}

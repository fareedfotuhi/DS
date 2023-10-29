#include<iostream>
#include <algorithm>  
using namespace std;
int main()
{	
	long long gcd = 0;
	int n, m;
	cin >> n >> m;
	long long a[n];
	long long b[m];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < m; i++)
		cin >> b[i];
		
	sort(a, a + n);
	for(int i = 1; i < n; i++)
		gcd = __gcd(abs(a[i] - a[i - 1]), gcd);
		
	for(int i = 0; i < m; i++)
	{
		cout << __gcd(gcd, abs(a[0] + b[i]))<< " ";
	}
}

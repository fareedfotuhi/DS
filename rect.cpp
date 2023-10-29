#include<iostream>
#include<algorithm>  
#include<vector>
using namespace std;
int main()
{	
	int n;
	cin >> n;
	vector<pair<long long , long long >>a(n);
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y / 2};
	}
	sort(a.rbegin(), a.rend());
	
	long long ans = a[0].first * a[0].second;
	long long  maxW = a[0].second;
	
	for(int i = 1; i < n; i++)
	{
		if(a[i].second > maxW)
		{
			
			ans += (a[i].second - maxW) * a[i].first;
			maxW = a[i].second;
		}
	}
	ans *= 2;
	cout << ans;
}

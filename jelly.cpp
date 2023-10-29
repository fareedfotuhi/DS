#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for(auto &x : a) cin >> x;
	
	int k = 0;
	vector<int>ans(1e6 + 9);

	for(int i = 0; i < n; i++)
	{
		while(a[i] == ans[k])
		{
			k--;
			a[i]++;
		}
		k++;
		ans[k] = a[i];
	}
	for(int i = 1; i <= k; i++)
		cout << ans[i] << " ";
	
}

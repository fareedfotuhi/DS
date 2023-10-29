#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for(auto &x : a)
		cin >> x;
	sort(a.begin(), a.end());
	long long need = 0;
	for(int i = 1; i < n; i += 2)
		need += a[i] - a[i - 1];
	cout << need;
}

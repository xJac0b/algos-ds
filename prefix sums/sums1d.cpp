#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int t[N], n;

int get_sum(int l, int r)
{
	return t[r] - t[l-1];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		cin >> t[i];
		t[i] += t[i-1];
	}

	cout << get_sum(1, n);
}
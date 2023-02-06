#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int n, t[N];

void build()
{
	for(int i = 0; i<n; i++)
		cin >> t[n+i];
	for(int i = n-1; i>0; i--)
		t[i] = t[2*i] + t[2*i+1];
}

void modify(int p, int v)
{
	for(t[p+=n] = v; p>1; p/=2) t[p/2] = t[p] + t[p^1];
}

int query(int l, int r)
{
	int res = 0;
	for(l+=n, r+=n; l<r; l/=2, r/=2)
	{
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	build();
	cout << query(0, n) << '\n';
	modify(1, 20);
	cout << query(0, n) << '\n';
}


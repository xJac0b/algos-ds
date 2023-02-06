#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;

ll power(ll a, ll b)
{
	if(b == 0) return 1;
	ll res = power(a, b/2);
	res = (res*res)%MOD;
	if(b % 2 == 0) return res;
	return (res*a)%MOD;
}

int main()
{
	int a,b;
	cin >> a >> b;
	cout << power(a,b) << '\n';
}
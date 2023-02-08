#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll N = 5*1e5+7;
ll t[N];

ll power(ll a, ll b)
{
	if(b == 0) return 1;
	long long res = power(a, b/2);
	res = (res*res)%MOD;
	if(b%2==0) return res;
	return (res*a)%MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	t[0] = 1;
	for(ll i = 1; i<=n; i++)
	{
		cin >> t[i];
		t[i] = (t[i-1] * t[i])%MOD;
	}
	for(ll i = 1; i<=n; i++)
	{
		cout << (t[i-1] * (t[n] * power(t[i], MOD-2)%MOD)%MOD)%MOD << " ";
	}
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll N = 5*1e5+7;
ll t[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;
	for(ll i = 1; i<=n; i++)
		cin >> t[i];
	for(ll i = 1; i<=n; i++)
	{
		ll res=1;
		for(ll j = 1; j<=n; j++)
		{
			if(j==i)
				continue;
			res = (res*t[j])%MOD;
		}
		cout << res << " ";
	}
}
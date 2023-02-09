#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+7;

void solve()
{
	int v, k, a, b;
	cin >> v >> k;

	vector<int>dist(v+1, INT_MAX);
	vector<pair<int,int>> G[N];

	for(int i = 0; i<k; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		G[a].push_back({b,c});
	}
	priority_queue<pair<int,int>>order;

	cin >> a >> b;

	order.push({0, a});
	dist[a] = 0;

	while(!order.empty())
	{
		int v = order.top().second;
		order.pop();

		for(auto& p: G[v])
		{
			int weight = p.second,
			u = p.first;
			if(dist[u] > dist[v] + weight)
			{
				dist[u] = dist[v] + weight;
				order.push({-dist[u], u});
			}
		}
	}
	if(dist[b] == INT_MAX)
		cout << "NO\n";
	else
		cout << dist[b] << '\n';
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int _;
	cin >> _;
	while(_--)
		solve();
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> G[N];
queue<int>order;
bool visited[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<m; i++)
	{
		int p,q;
		cin >> p >> q;
		G[p].push_back(q);
		G[q].push_back(p);
	}
	order.push(0);
	visited[0] = true;
	while(!order.empty())
	{
		int v = order.front();
		cout << v << ' ';
		order.pop();
		for(auto u : G[v])
		{
			if(!visited[u])
			{
				order.push(u);
				visited[u] = true;
			}
		}
	}
}

/*INPUT
5 4
0 1
0 2
0 3
2 4
*/
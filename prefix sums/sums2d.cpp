#include <bits/stdc++.h>
using namespace std;
const int N = 2507;
int matrix[N][N], n;


int get_sum(int w1, int k1, int w2, int k2)
{
	return matrix[w2][k2] - matrix[w1-1][k2] - matrix[w2][k1-1] + matrix[w1-1][k1-1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
		{
			cin >> matrix[i][j];
			matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
		}
	cout << get_sum(1,1, n,n);
}
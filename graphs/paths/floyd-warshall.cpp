#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>>matrix(n, vector<int>(n, INT_MAX));
	for(int i = 0; i<m; i++)
	{
		int p,q,w;
		cin >> p >> q >> w;
		matrix[p][q] = w;
	}
	for(int i = 0; i<n; i++)
		matrix[i][i] = 0;
	
	for(int k = 0; k<n; k++)
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
			{
				if((matrix[i][k] == INT_MAX ) || (matrix[k][j] == INT_MAX)) continue;
				matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
			}	
	
	
	//Detekcja ujemnego cyklu
	// for (int i = 0; i < n; i++)
        // if (matrix[i][i] < 0)
           // cout<<"ujemny cykl";
	
	
	
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cout << "[" << i << "," <<  j << "]: " << (matrix[i][j] < INT_MAX ? to_string(matrix[i][j]) : "brak")<<'\n';
		}
	}
}

/*
4 6
0 1 8
0 3 1
1 2 1
3 2 9
2 0 4
3 1 2
*/

//Złożoność czasowa O(n^3), miejsca O(n^2)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int s;
	cin >> s;
	srand(s);
	int n = rand()%1000 + 10000;
	cout << n << '\n';
	for(int i = 0; i<n; i++)
	{
		cout << rand()%(int)(1e9+1) << " ";
	}
}
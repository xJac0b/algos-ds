#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
int t[N];


quick_sort(int l, int r)
{
	if(l>=r) continue;
	int x = t[(l+r)/2];
	int l1=l, r1=r;
	while(l<r)
	{
		
	}
	quick_sort(l,r/2);
	quick_sort(r/2+1,)
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i<n; i++)
		cin >> t[i];
	quick_sort(0, n-1);
}
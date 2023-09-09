#include <bits/stdc++.h>

using namespace std;


struct adjEl
{
	int v; // wierzchołek docelowy
	int i; //numer krawedzi
	
	adjEl(int v, int i): v(v), i(i)
	{}
};

void printGraph(vector<vector<adjEl>>&G, bool showEdges = true)
{
	for(int i = 0; i<G.size(); i++)
	{
		cout << i << ": ";
			for(auto&j : G[i])
			{
				cout << j.v;
				if(showEdges)
					cout << "(kr" << j.i <<")";
				cout<<", ";
			}
				 
		cout << '\n';
	}
}


int main()
{
	int n,//wierzchołki
	 	m;//krawędzie
	
	cin >> n >> m;
	
	vector<vector<adjEl>>G(n, vector<adjEl>()),
	//graf wczytywany
	GE(m, vector<adjEl>());
	//graf krawędziowy
	
	//wczytanie grafu
	for(int i = 0; i<m; i++)
	{
		int p, q;
		cin >> p >> q;
		G[p].push_back(adjEl(q,i));
		G[q].push_back(adjEl(p,i));//dla grafu nieskierowanego
	}
	
	cout<<"Graf wczytany:\n";
	printGraph(G);
	
	//tworzenie grafu krawędziowego
	for(int i = 0; i<n; i++) //dla każdego wierzchołka
	{
		int size1 = G[i].size();//pobierz ilość sąsiadów
		for(int j = 0; j<size1; j++) //dla każdego sąsiada
		{
			int neighbor = G[i][j].v,
			size2 = G[neighbor].size();//pobierz ilość sąsiadów sąsiada
			
			for(int k = 0; k<size2; k++)//dla każdego sąsiada sąsiada
			{
				if(G[neighbor][k].v == i)//pomiń 
					continue;
				GE[G[i][j].i].push_back(adjEl(G[neighbor][k].i, 0));
			}
		}
			
	}
	cout << "\n\nGraf krawedziowy:\n";
	printGraph(GE,false);
}

//Złożoność O(2m*(n-1))

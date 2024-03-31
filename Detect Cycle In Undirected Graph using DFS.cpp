// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
	vis[node] = 1;
	for (auto i : adj[node]) {
		if (!vis[i]) {
			if (dfs(i, node, adj, vis))
				return 1;
		}
		else if (parent != i) return 1;
	}
	return 0;
}
bool isCycle(int V, vector<int> adj[]) {
	vector<int> vis(V);
	for (int i = 0; i < V; ++i) {
		if (!vis[i] && dfs(i, -1, adj, vis)) {
			return 1;
		}
	}
	return 0;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int V, E;	cin >> V >> E;
	vector<int> adj[V];
	for (int i = 0; i < E; ++i) {
		int u, v;	cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << isCycle(V, adj);
	return 0;
}
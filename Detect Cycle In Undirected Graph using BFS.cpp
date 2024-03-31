// https://www.naukri.com/code360/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

bool detect(int vis[], vector<int> adj[], int src) {
	queue<pair<int, int>> q;
	vis[src] = 1;
	q.push({src, -1});
	while (!q.empty()) {
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for (auto i : adj[node]) {
			if (!vis[i]) {
				vis[i] = 1;
				q.push({i, node});
			}
			else if (parent != i) return 1;
		}
	}
	return 0;
}
bool isCycle(int V, vector<int> adj[]) {
	int vis[V] = {0};
	for (int i = 0; i < V; ++i) {
		if (!vis[i]) {
			if (detect(vis, adj, i)) return 1;
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

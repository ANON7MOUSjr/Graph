// https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

void dfs(stack<int> &s, vector<int> &vis, vector<int> adj[], int node) {
	vis[node] = 1;
	for (auto i : adj[node]) {
		if (!vis[i]) {
			dfs(s, vis, adj, i);
		}
	}
	s.push(node);
}
vector<int> topoSort(int n, vector<int> adj[]) {
	vector<int> vis(n);
	stack<int> s;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(s, vis, adj, i);
	}
	vector<int> ans;
	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; ++i) {
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<int> res = topoSort(n, adj);
	for(auto i : res) cout << i << " ";
	return 0;
}

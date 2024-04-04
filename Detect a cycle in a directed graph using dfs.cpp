// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

bool dfs(vector<int> &vis, vector<int> &pathVis, vector<int> adj[], int node){
	vis[node] = 1;
	pathVis[node] = 1;
	for(auto i : adj[node]){
		if(!vis[i]){
			if(dfs(vis, pathVis, adj, i)) return true;
		}
		else if(pathVis[i]) return true;
	}
	pathVis[node] = 0;
	return false;
}
bool isCyclic(int n, vector<int> adj[]){
	vector<int> vis(n), pathVis(n);
	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			if(dfs(vis, pathVis, adj, i)) return true;
		}
	}
	return false;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0; i < m; ++i){
		int u, v;	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cout << isCyclic(n, adj);
	return 0;
}

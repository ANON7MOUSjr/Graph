// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
// By using Kahn's Algorithm which makes it really easy to understand
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

bool isCyclic(int n, vector<int> adj[]) {
	vector<int> indegree(n);
	for(int i = 0; i < n; ++i){
		for(auto j : adj[i]) indegree[j]++;
	}
	queue<int> q;
	for(int i = 0; i < n; ++i){
		if(indegree[i] == 0) q.push(i);
	}
	int cnt = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cnt++;
		for(auto i : adj[node]){
			indegree[i]--;
			if(indegree[i] == 0) q.push(i);
		}
	}
	return cnt != n;
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
	cout << isCyclic(n, adj);
	return 0;
}

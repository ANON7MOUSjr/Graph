#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; ++i) {
		int u, v;	cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int vis[n + 1] = {0};
	vis[1] = 1;
	queue<int> q;
	q.push(1);
	vector<int> bfs;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		bfs.push_back(node);
		for (auto i : adj[node]) {
			if (vis[i] == 0) {
				vis[i] = 1;
				q.push(i);
			}
		}
	}
	for (auto i : bfs) cout << i << " ";

	return 0;
}
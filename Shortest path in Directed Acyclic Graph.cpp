// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
// here we have used topoSort(dfs)
void topoSort(int node, int vis[], stack<int> &s, vector<pair<int, int>> adj[]) {
	vis[node] = 1;
	for (auto i : adj[node]) {
		if (!vis[i.first]) topoSort(i.first, vis, s, adj);
	}
	s.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
	// code here
	vector<pair<int, int>> adj[N];
	for (int i = 0; i < M; ++i) {
		int u = edges[i][0];
		int v = edges[i][1];
		int val = edges[i][2];
		adj[u].push_back({v, val});
	}
	stack<int> s;
	int vis[N] = {0};
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) topoSort(i, vis, s, adj);
	}
	vector<int> dis(N, 1e9);
	dis[0] = 0;
	while (!s.empty()) {
		int node = s.top();
		s.pop();
		for (auto i : adj[node]) {
			int next = i.first;
			int wt = i.second;
			if (dis[node] + wt < dis[next])
				dis[next] = dis[node] + wt;
		}
	}
	for (auto &i : dis) if (i == 1e9) i = -1;
	return dis;
}

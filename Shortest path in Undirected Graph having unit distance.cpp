https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
	// code here
	vector<int> adj[N];
	for (int i = 0; i < M; ++i) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	queue<int> q;
	vector<int> dis(N, 1e9);
	dis[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto i : adj[node]) {
			if (1 + dis[node] < dis[i]) {
				dis[i] = dis[node] + 1;
				q.push(i);
			}
		}
	}
	for (auto &i : dis) if (i == 1e9) i = -1;
	return dis;
}

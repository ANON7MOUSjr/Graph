// https://leetcode.com/problems/course-schedule-ii/description/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

vector<int> findOrder(int n, vector<vector<int>> &a) {
	vector<int> adj[n];
	int len = a.size();
	for (int i = 0; i < len; ++i) {
		adj[a[i][1]].push_back(a[i][0]);
	}
	vector<int> indegree(n);
	for (int i = 0; i < n; ++i) {
		for (auto j : adj[i]) indegree[j]++;
	}
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (indegree[i] == 0) q.push(i);
	}
	vector<int> ans;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for (auto i : adj[node]) {
			indegree[i]--;
			if (indegree[i] == 0) q.push(i);
		}
	}
	if (ans.size() == n) return ans;
	return {};
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<vector<int>> a(m, vector<int>(2));
	for (int i = 0; i < 1; ++i) {
		int u, v;	cin >> u >> v;
		a[i][0] = u;
		a[i][1] = v;
	}
	vector<int> res = findOrder(n, a);
	for(auto i : res) cout << i << " ";
	return 0;
}

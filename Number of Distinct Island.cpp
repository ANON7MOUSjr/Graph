// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &coordinate, int r0, int c0) {
	vis[r][c] = 1;
	coordinate.push_back({r0 - r, c0 - c});
	int n = grid.size();
	int m = grid[0].size();
	int dx[4] = { -1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	for (int i = 0; i < 4; ++i) {
		int newR = r + dx[i];
		int newC = c + dy[i];
		if (newR >= 0 && newR < n && newC >= 0 && newC < m && !vis[newR][newC] && grid[newR][newC] == 1) {
			dfs(newR, newC, vis, grid, coordinate, r0, c0);
		}
	}
}
int countDistinctIslands(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	set<vector<pair<int, int>>> ans;
	vector<vector<int>> vis(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j] && grid[i][j] == 1) {
				vector<pair<int, int>> coordinate;
				dfs(i, j, vis, grid, coordinate, i, j);
				ans.insert(coordinate);
			}
		}
	}
	return ans.size();
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}
	cout << countDistinctIslands(grid);
	return 0;
}
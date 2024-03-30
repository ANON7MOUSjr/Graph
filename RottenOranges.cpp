// https://leetcode.com/problems/rotting-oranges/submissions/1218142246/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

int orangesRotting(vector<vector<int>>& grid) {
	queue<pair<pair<int, int>, int>> rottenOranges;
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> vis(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 2) {
				rottenOranges.push({{i, j}, 0});
				vis[i][j] = 1;
			}
		}
	}
	int ans = 0;
	while (!rottenOranges.empty()) {
		int x = (rottenOranges.front()).first.first;
		int y = (rottenOranges.front()).first.second;
		int time = (rottenOranges.front()).second;
		rottenOranges.pop();
		ans = time;
		if (y + 1 < m && grid[x][y + 1] == 1 && !vis[x][y + 1]) {
			vis[x][y + 1] = 1;
			rottenOranges.push({{x, y + 1}, time + 1});
		}
		if (y - 1 >= 0 && grid[x][y - 1] == 1 && !vis[x][y - 1]) {
			vis[x][y - 1] = 1;
			rottenOranges.push({{x, y - 1}, time + 1});
		}
		if (x + 1 < n && grid[x + 1][y] == 1 && !vis[x + 1][y]) {
			vis[x + 1][y] = 1;
			rottenOranges.push({{x + 1, y}, time + 1});
		}
		if (x - 1 >= 0 && grid[x - 1][y] == 1 && !vis[x - 1][y]) {
			vis[x - 1][y] = 1;
			rottenOranges.push({{x - 1, y}, time + 1});
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j] && grid[i][j] == 1) return -1;
		}
	}
	return ans;
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
	cout << orangesRotting(grid);
	return 0;
}
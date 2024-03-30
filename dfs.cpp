#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans){
	vis[node] = 1;
	ans.push_back(node);
	for(auto i : adj[node]){
		if(!vis[i])
			dfs(i, adj, vis, ans);
	}
}
int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);		 

	int n;	cin >> n;
	vector<int> adj[n + 1];
	for(int i = 0; i < n - 1; ++i){
		int u, v;	cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int vis[n + 1] = {0};
	int start = 5;
	vector<int> ans;
	dfs(start, adj, vis, ans);
	for(auto i : ans) cout << i << " ";

	return 0;
}
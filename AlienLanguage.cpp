// https://www.naukri.com/code360/problems/alien-dictionary_630423?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
string getAlienLanguage(vector<string> &dictionary, int k) {
	// Write your code here.
	int n = dictionary.size();
	vector<int> adj[k];
	for (int i = 0; i < n - 1; ++i) {
		string s1 = dictionary[i];
		string s2 = dictionary[i + 1];
		for (int j = 0; j < min(s1.size(), s2.size()); ++j) {
			if (s1[j] != s2[j]) {
				adj[s1[j] - 'a'].push_back(s2[j] - 'a');
				break;
			}
		}
	}
	int indegree[k] = {0};
	for (int i = 0; i < k; ++i) {
		for (auto j : adj[i]) indegree[j]++;
	}
	queue<int> q;
	for (int i = 0; i < k; ++i) if (indegree[i] == 0) q.push(i);
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
	string s = "";
	for (auto i : ans) s += 'a' + i;
	return s;
}

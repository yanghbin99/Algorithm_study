#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec[10002];
bool check_dfs[1001];
bool check_bfs[1001];

int n, m, v, a, b;

void dfs(int node) {

	check_dfs[node] = true;
	cout << node << " ";

	for (int i = 0; i < vec[node].size(); i++) {
		int next = vec[node][i];

		if (check_dfs[next] == false)
			dfs(next);
	}
}

void bfs(int node) {
	queue<int> q;

	check_bfs[node] = true;
	q.push(node);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		
		for (int i = 0; i < vec[node].size(); i++) {
			int next_node = vec[node][i];
			if (check_bfs[next_node] == false) {
				check_bfs[next_node] = true;
				q.push(next_node);
			}
				
		}
	}
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);

	}

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs(v);

	return 0;
}


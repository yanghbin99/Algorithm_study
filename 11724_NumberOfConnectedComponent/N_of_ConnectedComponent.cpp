#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec[500000];
bool check[1001];

int n, m, u, v;

void BFS(int node) {
	queue<int> q;

	check[node] = true;
	q.push(node);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < vec[node].size(); i++) {
			int next_node = vec[node][i];
			if (check[next_node] == false) {
				check[next_node] = true;
				q.push(next_node);
			}
		}
	}
}

int main(void)
{
	bool flag = 1;
	int another_node = 1;
	int component = 1;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);

	}

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	while (flag == 1) {
		BFS(another_node); 

		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				another_node = i;
				component++;
				break;
			}
			else
				another_node = 0;
		}

		if (!another_node)
			flag = 0;
	}

	cout << component;

	return 0;
}

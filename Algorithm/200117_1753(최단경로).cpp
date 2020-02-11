#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
#define MAX 1000000

using namespace std;


int main(void) {
	int V, E, start_v;
	vector<pair<int, int>> adj[MAX];

	cin >> V >> E >> start_v ;
	
	for (int i = 0;i < E;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
	vector<bool> visited(V + 1, false);
	vector<int> dist(V + 1, MAX);

	pq.push(make_pair(0, start_v));
	dist[start_v-1] = 0;

	int now, max_l;

	while (!pq.empty()) {
		now = pq.top().second;
		pq.pop();

		if (visited[now]) continue;
		visited[now] = true;
		for (int i = 0;i < adj[now].size() ;i++) {
			max_l = adj[now][i].second;
			if (visited[i]) continue;
			//if (max_l == MAX) continue;
			if (dist[i] > dist[now-1] + max_l) {
				dist[i] = dist[now-1] + max_l;
				pq.push(make_pair(dist[i], i));
			}
		}
	}
	for (int i = 0;i < V;i++)
		if (dist[i] == MAX) cout << "INF" << "\n";
		else cout << dist[i]<<"\n";
	return 0;
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define MAX 100001
using namespace std;

bool visited[MAX] = { false, };
vector<pair<int,int>> a[MAX];
long long dist[MAX] = { 0, };

void dfs(int x) {
	long long size = a[x].size();
	visited[x] = true;
	for (long long j = 0;j < size;j++) {
		if (!visited[a[x][j].first]) {
			visited[a[x][j].first] = true;
			dist[a[x][j].first] = dist[x] + a[x][j].second;
			dfs(a[x][j].first);
		}
		
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	long long N;
	cin >> N;
	for (int i = 0;i < N-1;i++) {
		long long n, v = 0;
		int dists;
		cin >> n;
		cin >> v;
		cin >> dists;
		a[n].push_back(make_pair(v, dists));
		a[v].push_back(make_pair(n, dists));
	}
	dfs(1);
	long long bigger = 0;
	long long l = 0;
	for (int i = 1;i <= N;i++) {
		if (bigger < dist[i]) {
			bigger = dist[i];
			l = i;
		}
	}
	memset(visited, false, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	dfs(l);
	for (int i = 1;i <= N;i++) {
		bigger = max(bigger, dist[i]);
	}
	cout << bigger;
	return 0;
}

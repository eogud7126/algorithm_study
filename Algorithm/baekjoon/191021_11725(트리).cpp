#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define MAX 100001
using namespace std;

bool visited[MAX] = { false, };
vector<int> a[MAX];
queue<long long> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	long long N;
	long long parent[MAX] = { 0, };
	cin >> N;
	for (long long i = 0;i < N-1;i++) {
		long long u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int x = q.front(); q.pop();
		
			int size = a[x].size();
			for (int i = 0;i < size;i++) {
				if (!visited[a[x][i]]) {
					visited[a[x][i]] = true;
					parent[a[x][i]] = x;
					q.push(a[x][i]);
				}
			}
		
	}
	for (int i = 2;i <= N;i++)
		cout << parent[i]<<"\n";
	return 0;
}

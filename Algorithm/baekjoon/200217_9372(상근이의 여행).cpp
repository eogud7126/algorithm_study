#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

bool visited[1001] = { false, };
queue<int> q;
vector<int> a[1001];
int count_country = 0;

void bfs(int n) {
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int k = 0;k < a[top].size();k++) {
			if (!visited[a[top][k]]) {
				visited[a[top][k]] = true;
				q.push(a[top][k]);
				count_country++;
			}
		}
		
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int country, plane;
		
		cin >> country >> plane;

		for (int i = 0;i < plane;i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		bfs(1);
		cout << count_country << endl;
		//다음 테스트 케이스를 위한 초기화
		memset(visited, false, sizeof(visited));
		memset(a, 0, sizeof(a));
		count_country = 0;
	}


	return 0;
}
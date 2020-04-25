#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 301
int dx[8] = { -2,-1,1,2,-1,-2,2,1 };
int dy[8] = { -1,-2,-2,-1,2,1,1,2 };
bool visited[MAX][MAX];
int N, cnt = 0;

int bfs(int p1,int q1,int p2,int q2) {
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(p1, q1),cnt));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int qcnt = q.front().second;
		q.pop();
		if (x == p2 && y == q2) {
			return qcnt;
		}
		qcnt++;
		for (int i = 0;i < 8;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visited[nx][ny] && nx >= 0 && ny >= 0 && nx < N && ny < N) {
				visited[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny),qcnt));
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		memset(visited, false, sizeof(visited));
		cnt = 0;

		cin >> N;
		int p1, q1, p2, q2;
		cin >> p1 >> q1;
		cin >> p2 >> q2;
		cout<<bfs(p1, q1, p2, q2)<<"\n";

	}
	return 0;
}
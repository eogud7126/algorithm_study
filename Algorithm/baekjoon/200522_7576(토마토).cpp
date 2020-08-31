#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int n, m;
int tom[1001][1001];
bool visited[1001][1001] = { false, };
queue<pair<pair<int, int>,int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int BFS() {
	int day = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		day = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					if (tom[nx][ny] == 0) {
						tom[nx][ny] = 1;
						q.push({ {nx,ny},day + 1 });
					}
				}
			}
		}
	}
	return day;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> tom[i][j];
			if (tom[i][j] == 1) {
				q.push({{ i,j }, 0});
			}
		}
	}
	int answer = BFS();
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			if (tom[i][j] == 0)
				answer = -1;
	}

	cout << answer;
	//모든 토마토 익어잇을때 0
	//모두 익지 않은상태면 -1
	return 0;
}
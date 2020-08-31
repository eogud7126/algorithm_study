#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

int N, L, R;
int A[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;
bool flag = false;
bool visited[51][51] = { false, };

void BFS(int m, int n) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> coord;
	q.push(make_pair(m, n));
	coord.push_back(make_pair(m, n));
	visited[m][n] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int gap = abs(A[nx][ny] - A[x][y]);
			if (0 <= nx && 0 <= ny && nx < N && ny < N) {
				if (!visited[nx][ny] && gap>=L && gap<=R) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
					coord.push_back(make_pair(nx, ny));
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0;i < coord.size();i++) {
		sum += A[coord[i].first][coord[i].second];
	}
	//인구이동
	for (int i = 0;i < coord.size();i++) {
		A[coord[i].first][coord[i].second] = sum/coord.size();
	}
	//인구이동 했으면,
	if (coord.size() > 1) {
		//for (int x = 0;x < N;x++) {
		//	for (int y = 0;y < N;y++) {
		//		cout << A[x][y] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		flag = true;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L >> R;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> A[i][j];
		}
	}
	while (1) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if(!visited[i][j])
					BFS(i, j);
			}
		}
		memset(visited, false, sizeof(visited));
		if (flag) {
			answer++;
			flag = false;
		}
		else break;
	}
	cout << answer << endl;
	return 0;
}

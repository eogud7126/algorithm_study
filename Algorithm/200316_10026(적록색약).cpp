#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int N;
char colors[101][101];
bool visited[101][101] = { false, };
bool visited_b[101][101] = { false, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt_normal = 0;
int cnt_abnormal = 0;
void bfs_normal(int p,int q) {
	queue<pair<int,int>> q_normal;
	q_normal.push(make_pair(p, q));
	while (!q_normal.empty()) {
		int x = q_normal.front().first;
		int y = q_normal.front().second;
		q_normal.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visited[nx][ny] && nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (colors[nx][ny] == colors[x][y]) {	//색 비교
					q_normal.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}

	}
}

void bfs_abnormal(int abp, int abq) {
	queue<pair<int, int>> q_abnormal;
	q_abnormal.push(make_pair(abp, abq));
	while (!q_abnormal.empty()) {
		int abx = q_abnormal.front().first;
		int aby = q_abnormal.front().second;
		q_abnormal.pop();
		for (int i = 0;i < 4;i++) {
			int abnx = abx + dx[i];
			int abny = aby + dy[i];
			if (!visited_b[abnx][abny] && abnx >= 0 && abny >= 0 && abnx < N && abny < N) {
				if ((colors[abnx][abny] == colors[abx][aby]) ||
					((colors[abnx][abny] == 'R') && (colors[abx][aby] == 'G')) ||
					((colors[abnx][abny] == 'G') && (colors[abx][aby] == 'R'))) {	//색 비교
					visited_b[abnx][abny] = true;
					q_abnormal.push(make_pair(abnx, abny));
				}
			}
		}

	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	string s;
	for (int i = 0;i < N;i++) {
		cin >> s;
		for (int j = 0;j < N;j++) {
			colors[i][j] = s[j];
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!visited[i][j]) {
				bfs_normal(i, j);
				cnt_normal++;
			}
			if (!visited_b[i][j]) {
				bfs_abnormal(i, j);
				cnt_abnormal++;
			}
		}
	}
	cout << cnt_normal<<" "<<cnt_abnormal << "\n";
	return 0;
}
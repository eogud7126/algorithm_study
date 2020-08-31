#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int N;
int map[101][101];
bool visited[101][101] = { false, };
int newMap[101][101] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 10001;

void BFS(int r,int c, int pin){
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visited[r][c] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					if (map[nx][ny] == 1) {
						newMap[nx][ny] = pin;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

void DFS(int r, int c, int pin, int cnt) {
	for (int i = 0;i < 4;i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (newMap[nx][ny] == pin) {
				continue;
			}
			else if (newMap[nx][ny] != pin && newMap[nx][ny] != 0 && newMap[nx][ny] != 1) {	//다른섬
				if (answer > cnt) {
					answer = cnt;
				}
			}
			else if(!visited[nx][ny]){
				visited[nx][ny] = true;
				newMap[nx][ny] = 1; //다리
				DFS(nx, ny, pin, cnt+1);
			}
			cnt++;

		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
		}
	}
	int pin = 2;
	//섬 번호 붙이기.
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!visited[i][j] && map[i][j] != 0) {
				newMap[i][j] = pin;
				BFS(i, j, pin);
				pin++;
			}
		}
	}
	//다리 만들기
	int newnewMap[101][101];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			newnewMap[i][j] = newMap[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			//for (int m = 0;m < N;m++) {
			//	for (int n = 0;n < N;n++) {
			//		newMap[m][n] = newnewMap[m][n];
			//	}
			//}
			int cnt = 0;
			if (newMap[i][j] != 0 && !visited[i][j]) {
				visited[i][j] = true;
				cout << i << " " << j << endl;
				DFS(i, j, newMap[i][j], cnt);
			}
		}
	}
	cout << answer << endl;

	return 0;
}

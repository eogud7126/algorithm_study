#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int T, m, n;
char building[1002][1002];
bool visited[1002][1002];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int fireMoves[1002][1002];
int humanMoves[1002][1002];
int startR, startC;	//시작위치
int firecnt;
bool isok = true;
queue<pair<pair<int, int>, int>> q;

void BFS() {
	//firecnt = 1;
	//q.push(make_pair(make_pair(r, c),firecnt));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m&& ny >= 0 && ny < n) {
				if (!visited[nx][ny] && building[nx][ny] != '#' && building[nx][ny] != '*') {
					visited[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny),cnt+1));
					if (fireMoves[nx][ny] != 0) {
						if (fireMoves[nx][ny] > cnt)
							fireMoves[nx][ny] = cnt;
					}
					else {
						fireMoves[nx][ny] = cnt;
					}
				}
			}
		}
	}
}

void forEscape(int r, int c) {
	queue<pair<pair<int, int>,int>> hq;
	firecnt = 1;
	hq.push(make_pair(make_pair(r, c),firecnt));
	while (!hq.empty()) {
		int x = hq.front().first.first;
		int y = hq.front().first.second;
		int cnt = hq.front().second;
		hq.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m&& ny >= 0 && ny < n) {
				if (!visited[nx][ny] && building[nx][ny] == '.') {
					visited[nx][ny] = true;
					hq.push(make_pair(make_pair(nx, ny), cnt + 1));
					if (fireMoves[nx][ny] == 0)
						humanMoves[nx][ny] = cnt;
					if (fireMoves[nx][ny] > cnt)
						humanMoves[nx][ny] = cnt;					
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				cin >> building[i][j];
				if (building[i][j] == '@') {
					startR = i;
					startC = j;
				}

			}
		}
		//fire
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				if (building[i][j] == '*') {
					firecnt = 1;
					q.push(make_pair(make_pair(i, j), firecnt));
				}
			}
		}
		BFS();
		memset(visited, false, sizeof(visited));
		forEscape(startR, startC);

		int answer = 9876532;
		if (startR == 0 || startR == m - 1 || startC == 0 || startC == n - 1) {
			answer = 0;
			isok = false;
		}
		for (int i = 0;i < n;i++) {
			if (humanMoves[0][i] != 0) {
				isok = false;
				if (answer > humanMoves[0][i]) {
					answer = humanMoves[0][i];
				}
			}
		}
		for (int i = 0;i < n;i++) {
			if (humanMoves[m-1][i] != 0) {
				isok = false;
				if (answer > humanMoves[m-1][i]) {
					answer = humanMoves[m-1][i];
				}
			}
		}
		for (int i = 0;i < m;i++) {
			if (humanMoves[i][0] != 0) {
				isok = false;
				if (answer > humanMoves[i][0]) {
					answer = humanMoves[i][0];
				}
			}
		}
		for (int i = 0;i < m;i++) {
			if (humanMoves[i][n-1] != 0) {
				isok = false;
				if (answer > humanMoves[i][n-1]) {
					answer = humanMoves[i][n-1];
				}
			}
		}

		if (!isok) {
			cout << answer+1 << "\n";
		}
		else {
			cout << "IMPOSSIBLE\n";
		}

		//for (int i = 0;i < m;i++) {
		//	for (int j = 0;j < n;j++) {
		//		cout << humanMoves[i][j];
		//	}
		//	cout << endl;
		//}
		isok = true;
		memset(visited, false, sizeof(visited));
		memset(fireMoves, 0, sizeof(fireMoves));
		memset(humanMoves, 0, sizeof(humanMoves));
	}
	
	return 0;
}

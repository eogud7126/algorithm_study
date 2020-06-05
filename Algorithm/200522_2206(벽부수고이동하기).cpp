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
int MAP[1001][1001];
bool visited[1001][1001] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 987654321;

void DFS(int r, int c, int cnt,int wall) {
	if (wall <2) {
		if (answer < cnt) return;
		if (r == n - 1 && c == m - 1) {
			if (answer > cnt) {
				answer = cnt;
			}
			return;
		}
	}
	else return;
	for (int i = 0;i < 4;i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				if (MAP[nx][ny] == 0) {
					DFS(nx, ny, cnt + 1, wall);
				}
				else {
					MAP[nx][ny] = 0;
					DFS(nx, ny, cnt + 1, wall + 1);
					MAP[nx][ny] = 1;
				}
				visited[nx][ny] = false;
			}
		}
	}

}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		string t;
		cin >> t;
		for (int j = 0;j < m;j++) {
			MAP[i][j] = t[j]-'0';
		}
	}
	int c = 1;
	DFS(0, 0, c,0);
	if (answer == 987654321)
		answer = -1;
	cout << answer;
	return 0;
}
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int N, M;
char board[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = -1;
int searching(int x1, int y1, int x2, int y2, int cnt) {
	int isout = 0;
	if (cnt == 11) return -1;
	if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M) isout++;
	if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) isout++;
	if (isout == 1) return cnt;
	if (isout == 2) return -1;

	for (int i = 0;i < 4;i++) {
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		if (nx1 >= 0 && nx1 < N&&ny1 >= 0 && ny1 < M&& board[nx1][ny1] == '#') {
			nx1 = x1;
			ny1 = y1;
		}
		if (nx2 >= 0 && nx2 < N&&ny2 >= 0 && ny2 < M&&board[nx2][ny2] == '#') {
			nx2 = x2;
			ny2 = y2;
		}
		int tmp = searching(nx1, ny1, nx2, ny2, cnt + 1);
		if (tmp == -1) continue;
		if (answer == -1 || answer>tmp) {
			answer = tmp;
		}
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int x, y;
	vector<pair<int, int>> coinCoord;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				x = i;
				y = j;
				coinCoord.push_back({ i,j });
			}
		}
	}
	cout << searching(coinCoord[0].first, coinCoord[0].second, coinCoord[1].first, coinCoord[1].second, 0) << "\n";
	return 0;
}
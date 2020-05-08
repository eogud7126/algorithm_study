#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

vector<vector<char>> Board(12,vector<char>(6));
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[13][7] = { false, };
bool ispop = false;

void BFS(int r, int c, char n) {
	int cnt = 0;
	vector<pair<int, int>> coord;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	coord.push_back(make_pair(r, c));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6) {
				if (Board[nx][ny] == n && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
					coord.push_back(make_pair(nx, ny));
					cnt++;
				}
			}
		}
	}
	if (cnt >= 4) {
		for (int i = 0;i < coord.size();i++) {
			Board[coord[i].first][coord[i].second] = '.';
		}
		ispop = true;
	}
}

void refreshBoard() {
	memset(visited, false, sizeof(visited));
	for (int i = 0;i < 6;i++) {
		int cnt_star = 0;
		for (int j = 11;j >= 0;j--) {
			if (Board[j][i] == '.') {
				cnt_star++;
			}
			else {
				if (cnt_star != 0) {
					Board[j + cnt_star][i] = Board[j][i];
					Board[j][i] = '.';
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int seq = 0;
	for (int i = 0;i < 12;i++) {
		string inp;
		cin >> inp;
		for (int j = 0;j <6;j++) {
			Board[i][j] = inp[j];
		}
	}
	while (1) {
		ispop = false;
		for (int i = 0;i < 12;i++) {
			for (int j = 0;j < 6;j++) {
				if (Board[i][j] != '.')
					BFS(i, j, Board[i][j]);
			}
		}
		if (!ispop) break;
		//³»¸®±â
		refreshBoard();

		seq++;
	}



	cout << seq << endl;
	return 0;
}

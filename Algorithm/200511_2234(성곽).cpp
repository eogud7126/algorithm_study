#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int n, m, castle[51][51];
bool visited[51][51] = { false, };
int Room[2501];
int sector[51][51];
string castlebinary[51][51];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

string getBinary(int k) {
	string binar = "";
	while (k != 0) {
		binar.append(to_string(k % 2));
		k /= 2;
	}
	int sz = binar.size();
	while (sz < 4) {
		binar.append("0");
		sz++;
	}
	reverse(binar.begin(), binar.end());
	return binar;
}

void BFS(int r, int c,int sec) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	sector[r][c] = sec;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			if (castlebinary[x][y][i] == '0') {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
					if (!visited[nx][ny]) {
						visited[nx][ny] = true;
						sector[nx][ny] = sec;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> castle[i][j];
			castlebinary[i][j] = getBinary(castle[i][j]);
		}
	}
	int idx = 1;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (!visited[i][j]) {
				BFS(i, j, idx);
				idx++;
			}
		}
	}
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			Room[sector[i][j]]++;
		}
	}
	int answer = 0;
	int maxroom = 0;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			for (int bit = 0;bit < 4;bit++) {
				if (castlebinary[i][j][bit] == '1') {
					int a = sector[i][j];
					int nx = i + dx[bit];
					int ny = j + dy[bit];
					if (nx >= 0 && nx < m && ny >= 0 && nx < n) {
						if (a != sector[nx][ny]) {
							if (answer < Room[a] + Room[sector[nx][ny]]) {
								answer = Room[a] + Room[sector[nx][ny]];
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1;i < idx;i++) {
		if (maxroom < Room[i]) {
			maxroom = Room[i];
		}
	}
	cout << idx - 1 << "\n";
	cout << maxroom << "\n";
	cout << answer << "\n";
	return 0;
}

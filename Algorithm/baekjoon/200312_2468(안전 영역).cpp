#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 101
int N;
int arr[MAX][MAX];
bool visited[MAX][MAX] = { false, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt = 0;
vector<int> areasize;

void bfs(int i, int j, int rain) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	cnt++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int n = 0;n < 4;n++) {
			int nx = x + dx[n];
			int ny = y + dy[n];
			if (!visited[nx][ny] && 0 <= nx && 0 <= ny && nx < N && ny < N) {
				visited[nx][ny] = true;
				if (arr[nx][ny] > rain) {
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	areasize.push_back(cnt);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int max = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	for (int k = 1;k <= max;k++) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (!visited[i][j] && arr[i][j]>k) bfs(i, j, k);
			}
		}
	}
	if (areasize.empty())
		cout << "1" << "\n";
	else {
		sort(areasize.begin(), areasize.end());
		cout << areasize[areasize.size() - 1] << "\n";
	}
	return 0;
}
#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

int R, C;
char world[51][51];
bool visited[51][51] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int maxcnt = 0;
vector<int> maxvec;

void bfs(int r, int c) {
	queue<pair<pair<int, int>, int> > q;
	visited[r][c] = true;
	q.push(make_pair(make_pair(r, c),0));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second + 1;
		q.pop();
		for (int k = 0;k < 4;k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (!visited[nx][ny] && world[nx][ny] == 'L' && nx>=0 && nx<R && ny>=0 && ny<C) {
				visited[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny),cnt));
				if (maxcnt < cnt) {
					maxcnt = cnt;
				}
			}

		}
		
	}
	maxvec.push_back(maxcnt);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < C;j++) {
			world[i][j] = str[j];
		}
	}

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			//여기서 L 체크해주는걸 왜 뒤늦게 알았을까..
			if (world[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				bfs(i, j);
			}
		}
	}
	cout << *max_element(maxvec.begin(), maxvec.end())<<endl;

	return 0;
}

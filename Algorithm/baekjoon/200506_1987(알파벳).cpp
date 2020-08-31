#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int R, C;
char alpha[21][21];
bool visited[26] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;

void DFS(int r, int c, int cnt) {
	for (int i = 0;i < 4;i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx >= 0 && nx < R&&ny >= 0 && ny < C) {
			if (!visited[alpha[nx][ny] - 65]) {
				visited[alpha[nx][ny] - 65] = true;
				DFS(nx, ny, cnt+1);
				visited[alpha[nx][ny] - 65] = false;
			}
			else ;
		}
	}
	if (answer < cnt) answer = cnt;
	//set<char>::iterator iter = s.begin();
	//for (iter = s.begin();iter != s.end();++iter) {
	//	cout << *iter;
	//}
	//cout << endl;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0;i < R;i++)
		for (int j = 0;j < C;j++)
			cin >> alpha[i][j];
	visited[alpha[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	cout << answer;
	return 0;
}

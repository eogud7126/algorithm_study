#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 26
bool visited[MAX][MAX] = { false, };
int arr[MAX][MAX];
int N;

vector<int> daange;
queue<pair<int, int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int m,int n) {
	int cnt = 0;
	if(arr[m][n]==1)
		q.push(make_pair(m, n));
	visited[m][n] = true;
	while (!q.empty()) {
		cnt++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visited[nx][ny] && 0 <= nx && 0 <= ny && nx < N && ny < N) {
				visited[nx][ny] = true;
				if(arr[nx][ny] == 1)
					q.push(make_pair(nx, ny));
			}
		}
	}
	if(cnt!=0)
		daange.push_back(cnt);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < N;j++) arr[i][j] = s[j]-48;
	}
	
	for (int k = 0;k < N;k++) {
		for (int l = 0;l < N;l++) {
			if (!visited[k][l]) bfs(k, l);
		}
	}
	sort(daange.begin(), daange.end());
	cout << daange.size()<<"\n";
	for (int i = 0;i < daange.size();i++)
		cout << daange[i] << "\n";
	return 0;
}
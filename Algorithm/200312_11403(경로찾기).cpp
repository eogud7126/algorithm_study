#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 101
int N;
int arr[MAX][MAX];
bool visited[MAX];
vector<int> a[MAX];

bool bfs(int m, int n) { // m에서 n으로 경로가 있는지 찾기 위한 bfs
	queue<int> q;
	memset(visited, false, sizeof(visited));
	q.push(m);
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0;i < a[k].size();i++) {
			if (!visited[a[k][i]]) {
				if (a[k][i] == n) {
					return true;
				}
				visited[a[k][i]] = true;
				q.push(a[k][i]);
			}
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i=0;i<N;i++)
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				a[i].push_back(j);
			}
		}
	
	for (int idx1 = 0;idx1 < N;idx1++) {
		for (int idx2 = 0;idx2 < N;idx2++) {
			if (bfs(idx1, idx2)) cout << 1 << " ";//answer[idx1][idx2] = 1;
			else cout << 0 << " ";//answer[idx1][idx2] = 0;
		}
		cout << "\n";
	}
	return 0;
}
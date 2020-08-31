#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int answer = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[501][501] = { false, };
int n,m;
int S[501][501];

void DFS(int r, int c, int cnt, int sum) {
	if (cnt == 4) {
		if (answer < sum) {
			answer = sum;
		}
		return;
	}
	for (int i = 0;i < 4;i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				DFS(nx, ny, cnt + 1, sum+ S[nx][ny]);
				visited[nx][ny] = false;
			}
		}
	}
	return;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> S[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			memset(visited, false, sizeof(visited));
			visited[i][j] = true;
			DFS(i, j, 0, 0);
			//¹ý±Ô
			int tmp1=0, tmp2=0,tmp3=0,tmp4=0;
			if(i+2<n && j+1<m)
				tmp1 = S[i][j] + S[i + 1][j] + S[i + 2][j] + S[i + 1][j + 1];
			if (i + 2<n && j -1>=0)
				tmp2 = S[i][j] + S[i + 1][j] + S[i + 2][j] + S[i + 1][j - 1];
			if (i +1<n && j +2 < m)
				tmp3 = S[i][j] + S[i][j+1] + S[i][j+2] + S[i + 1][j + 1];
			if (i -1>=0 && j + 2 < m)
				tmp4 = S[i][j] + S[i][j+1] + S[i][j + 2] + S[i - 1][j + 1];
			vector<int> getMax;
			getMax.push_back(tmp1);
			getMax.push_back(tmp2);
			getMax.push_back(tmp3);
			getMax.push_back(tmp4);
			int mx = *max_element(getMax.begin(), getMax.end());
			if (answer < mx) {
				answer = mx;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}



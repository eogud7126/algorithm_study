#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

int A[50][50] = { 0, };
bool visited[50][50] = { false, };
int mX[4] = { 1,-1,0,0 };	//x축
int mY[4] = { 0,0,1,-1 };	//y축
int count_conn = 0;		//연결요소

void dfs(int x, int y, int X, int Y) {
	if (visited[x][y] == false) {
		visited[x][y] = true;
		for (int j = 0;j < 4;j++) {
			int nx = x + mX[j];
			int ny = y + mY[j];
			if (nx < X && ny < Y && nx >= 0 && ny >= 0) {
				if(A[nx][ny] == 1 &&visited[nx][ny]==false)
					dfs(nx, ny, X, Y);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T, M, N, K;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			A[x][y] = 1;
		}
		for (int m = 0;m < M;m++) {
			for (int n = 0;n < N;n++) {
				if (visited[m][n] == false) {
					if (A[m][n] == 1) {
						dfs(m, n, M, N);
						count_conn++;
					}
				}		
			}
		}
		cout << count_conn<<endl;

		count_conn = 0;
		memset(A, 0, sizeof(A));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
	
#include<iostream>
#include<string>
#include<cstdio>
#include<queue>

using namespace std;

int A[101][101];
bool visited[101][101];
int length[101][101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, M;
	scanf_s("%d %d", &N, &M);
	queue<pair<int,int>> q;

	int x_move[4] = { 0,0,1,-1 };
	int y_move[4] = { 1,-1,0,0 };


	//입력값 삽입.
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			scanf_s("%1d", &A[i][j]);
		}
	}	
	q.push(make_pair(0, 0));	
	visited[0][0] = true;
	length[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first ;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int mx = x + x_move[i];
			int my = y + y_move[i];
			if (0 <= mx && mx < N && 0 <= my && my < M) {
				if (A[mx][my] == 1 && visited[mx][my] == false) {
					q.push(make_pair(mx, my));
					length[mx][my] = length[x][y] + 1;
					visited[mx][my] = true;
				}
			}
		}
		
	}


	cout << length[N-1][M-1];

	

	return 0;
}
	
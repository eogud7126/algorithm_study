#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
//N세로,M 가로인데 세로 = 행/ 가로 = 열 헷갈리지말자.
//wallfall[ny][nx] y는 행, x는 열 헷갈리지말자


/*
1. 모든 경우를 해봐야함 (브루트포스)
2. 빈 공간에 벽 하나 세우고 다른 2개의 벽을 세우는 로직(벽을 세우고 다시 허무는 것 중요..)
3. 벽이 3개 되면 bfs를 통해 바이러스 전파 시킨 후 남아 있는 빈공간 계산.
*/
using namespace std;

int N, M;
int lab[8][8];
int templab[8][8];


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

int max_empty = 0;

void bfs() {
	int fullwall[8][8];
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			fullwall[i][j] = templab[i][j];

	queue<pair<int,int> > q;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			//바이러스 발견시 퍼뜨리기
			if (fullwall[i][j] == 2) {
				q.push(make_pair(i,j));
			}
		}
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && 0 <= ny && nx < M && ny < N) {
				if (fullwall[ny][nx] == 0) {
					fullwall[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	int empty = 0;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			if (fullwall[i][j] == 0)
				empty++;
	max_empty = max(max_empty,empty);
}
void setWall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if (templab[i][j] == 0) {
				templab[i][j] = 1;
				setWall(cnt+1);
				templab[i][j] = 0;
			}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> lab[i][j];

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (lab[i][j] == 0) {
				//temp에 복사
				for (int p = 0;p < N;p++) 
					for (int q = 0;q < M;q++) 
						templab[p][q] = lab[p][q];
				templab[i][j] = 1;
				setWall(1);
				templab[i][j] = 0;
			}
		}

	}
	cout << max_empty<<endl;
	return 0;
}
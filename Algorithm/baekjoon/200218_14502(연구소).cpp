#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
//N����,M �����ε� ���� = ��/ ���� = �� �򰥸�������.
//wallfall[ny][nx] y�� ��, x�� �� �򰥸�������


/*
1. ��� ��츦 �غ����� (���Ʈ����)
2. �� ������ �� �ϳ� ����� �ٸ� 2���� ���� ����� ����(���� ����� �ٽ� �㹫�� �� �߿�..)
3. ���� 3�� �Ǹ� bfs�� ���� ���̷��� ���� ��Ų �� ���� �ִ� ����� ���.
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
			//���̷��� �߽߰� �۶߸���
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
				//temp�� ����
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
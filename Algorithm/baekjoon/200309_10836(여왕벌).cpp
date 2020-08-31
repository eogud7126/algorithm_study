//못풀었다..........................................................
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int beehouse[701][701] = { 1, };
bool visit[701][701] = { false, };
int M, T;
int getMax(int x, int y) {
	int max = beehouse[x-1][y-1];
	if (max < beehouse[x - 1][y]) max = beehouse[x - 1][y];
	if (max < beehouse[x][y - 1]) max = beehouse[x][y - 1];
	return max;
}
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
queue<pair<int, int>> q;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> M >> T;

	fill(&beehouse[0][0], &beehouse[M][M], 1);

	while (T--) {
		int growthSize[3] = { 0, };
		vector<int> size(1401) ;
		for (int i = 0;i < 3;i++) {
			cin >> growthSize[i];
		}
		fill(size.begin(), size.begin() + growthSize[0], 0);
		fill(size.begin() + growthSize[0], size.begin() + growthSize[0] + growthSize[1], 1);
		fill(size.begin() + growthSize[0] + growthSize[1], size.begin() + growthSize[0] + growthSize[1] + growthSize[2], 2);

		reverse(size.begin(), size.end());

		for (int i = 0;i <= 2 * M - 1;i++) {
			if (i == M) continue;
			if (M - i > 0) {
				beehouse[M - i][1] += size.back();
				size.pop_back();
			}
			else {
				beehouse[1][i - M + 1] += size.back();
				size.pop_back();
			}
		}

	}

	for (int i = 2;i <= M;i++)	
		for (int j = 2;j <= M;j++)
			beehouse[i][j] = beehouse[1][j];

	for (int i = 1;i <= M;i++) {
		for (int j = 1;j <= M;j++)
			cout << beehouse[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
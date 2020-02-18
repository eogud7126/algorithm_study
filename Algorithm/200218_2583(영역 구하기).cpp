#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int arr[101][101] = { 0, };
bool visited[101][101] = { false, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int M, N, K;
vector<int> width;
int cnt = 0;

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visited[nx][ny] && nx < M && ny < N && arr[nx][ny] == 0 && 0 <= nx && 0<=ny) {
			dfs(nx, ny);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> M >> N >> K;
	for (int i = 0;i < K;i++) {
		int m, n;
		int p, q;
		cin >> n >> m >> q >> p;
		//직사각형 넓이를 배열에서 1로 바꾸기
		int garo = p - m;
		int sero = q - n;
		for (int y = n;y < n + sero;y++) {
			for (int x = m;x < m + garo;x++)
				arr[x][y] = 1;
		}
	}
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			if (!visited[i][j] && arr[i][j] == 0) {
				dfs(i, j);
				width.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(width.begin(), width.end());
	
	cout << width.size() << "\n";
	for (int i = 0;i < width.size();i++)
		cout << width[i] << " ";
	cout << "\n";

	//잘 들어갔는지 확인을 위한 출력
	//for (int i = 0;i < M;i++) {
	//	for (int j = 0;j < N;j++)
	//		cout << arr[i][j];
	//	cout << "\n";
	//}

	return 0;
}
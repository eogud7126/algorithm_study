#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int R, C;
char map[51][51];
pair<int, int> D;
queue<pair<pair<int, int>,int>> water;
queue<pair<pair<int, int>,int>> S;
vector<int> answer ;
int cntWater[52][52] = { 0, };
int cntS[52][52] = { 0, };
bool visited_W[51][51] = { false, };
bool visited_S[51][51] = { false, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool flag = false;
void bfs() {
	//¹°
	while (!water.empty()) {
		int wx = water.front().first.first;
		int wy = water.front().first.second;
		int wcnt = water.front().second;
		water.pop();
		for (int i = 0;i < 4;i++) {
			int nwx = wx + dx[i];
			int nwy = wy + dy[i];
			if (cntWater[nwx][nwy] > 0) continue;
			if (nwx < 0 || nwx >= R) continue;
			if (nwy < 0 || nwy >= C) continue;
			if (map[nwx][nwy] == 'D') continue;
			if (map[nwx][nwy] == 'X') continue;
			if (visited_W[nwx][nwy]) continue;
			water.push({{ nwx,nwy }, wcnt+1});
			cntWater[nwx][nwy] = wcnt;
			visited_W[nwx][nwy] = true;
		}
	}
	while (!S.empty()) {
		int sx = S.front().first.first;
		int sy = S.front().first.second;
		int scnt = S.front().second;
		S.pop();
		if (cntS[sx][sy] >0 && cntS[sx][sy] >= cntWater[sx][sy] && cntWater[sx][sy] != 0) continue;
		for (int i = 0;i < 4;i++) {
			int nsx = sx + dx[i];
			int nsy = sy + dy[i];

			if (cntS[nsx][nsy] > 0 && cntS[nsx][nsy] >= cntWater[nsx][nsy]  && cntWater[nsx][nsy] != 0) continue;
			if (nsx < 0 || nsx >= R) continue;
			if (nsy < 0 || nsy >= C) continue;
			if (map[nsx][nsy] == '*') continue;
			if (map[nsx][nsy] == 'X') continue;
			if (visited_S[nsx][nsy]) continue;
			if (map[nsx][nsy] == 'D') {
				answer.push_back(scnt);
				flag = true;
				break;
			}
			visited_S[nsx][nsy] = true;
			S.push({ { nsx,nsy }, scnt+1 });
			cntS[nsx][nsy] = scnt;
		}
	}
	sort(answer.begin(), answer.end());
	if(flag)
		cout << answer[0] << "\n";
	else cout << "KAKTUS" << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < C;j++) {
			map[i][j] = s[j];
			if (s[j] == 'D') {
				D.first = i;
				D.second = j;
			}
			if (s[j] == '*') {
				water.push({ {i,j},1 });
				visited_W[i][j] = true;
			}
			if (s[j] == 'S') {
				S.push({ {i,j},1 });
				visited_S[i][j] = true;
			}
		}
	}
	bfs();

	return 0;
}
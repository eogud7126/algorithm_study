#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<functional>

#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cost,x,y;
bool visited[30][30][4];

int solution(vector<vector<int>> a) {
	priority_queue<pair<int, pair<pair<int, int>, int>>,vector<pair<int, pair<pair<int, int>, int>>>,greater<pair<int, pair<pair<int, int>, int>>>> q;
	q.push({ 0,{{0,0},4 } }); //cost, coord, dir
	while (!q.empty()) {
		auto top = q.top();
		q.pop();
		cost = top.first;
		x = top.second.first.first;
		y = top.second.first.second;
		int dir = top.second.second;
		if (visited[x][y][dir]) {
			continue;
		}
		int n = a.size();
		visited[x][y][dir] = true;
		if (x == a.size() - 1 && y == a.size() - 1) {
			return cost-500; //시작할때 직진으로 시작
		}
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < a.size() && ny >= 0 && ny < a.size() && a[nx][ny] != 1) {
				//cout << "nx: " << nx << " ny: " << ny << " cost: " << -cost - 100 - 500 * (i != dir) <<endl;
				q.push(make_pair(cost + 100 + 500 * (i != dir), make_pair(make_pair(nx, ny), i)));
			}
		}
	}
}


int main() {
	vector<vector<int>> board = { { 0,0,0,0,0,0,0,1 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0 },{ 0,0,0,0,1,0,0,0 },{ 0,0,0,1,0,0,0,1 },{ 0,0,1,0,0,0,1,0 },{ 0,1,0,0,0,1,0,0 },{ 1,0,0,0,0,0,0,0 } };

	cout << solution(board) << endl;

	return 0;
}
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

bool visited[10000] = { false, };
int A, B;
string change;
string bfs() {
	queue<pair<int, string>> q;
	q.push(make_pair(A, ""));
	visited[A] = true;

	while (!q.empty()) {
		int num = q.front().first;
		change = q.front().second;
		q.pop();
		if (num == B) return change;

		//D
		int changeNum = 2 * num % 10000;
		if (!visited[changeNum]) {
			visited[changeNum] = true;
			q.push(make_pair(changeNum, change+"D"));
		}
		//S
		changeNum = num - 1;
		if (changeNum == -1) changeNum = 9999;
		if (!visited[changeNum]) {
			visited[changeNum] = true;
			q.push(make_pair(changeNum, change + "S"));
		}
		//L
		changeNum = num % 1000 * 10 + (num / 1000);
		if (!visited[changeNum]) {
			visited[changeNum] = true;
			q.push(make_pair(changeNum, change + "L"));
		}
		//R
		changeNum = (num % 10) * 1000 + (num / 10);
		if (!visited[changeNum]) {
			visited[changeNum] = true;
			q.push(make_pair(changeNum, change + "R"));
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		memset(visited, false, sizeof(visited));
		
		cout << bfs() << "\n";

	}
	return 0;
}
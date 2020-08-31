#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

vector<int> numbers = {};
string hand = "left";

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[4][3] = { false, };
int keypad[4][3] = { {1,2,3},{ 4,5,6 } ,{ 7,8,9 } ,{ -1,0,-1 } };

int BFS(int r, int c, int key) {
	if (keypad[r][c] == key)
		return 0;
	queue<pair<pair<int, int>, int>> q;
	int cnt = 0;
	q.push(make_pair(make_pair(r, c),cnt));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cntq = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 3) {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					if (keypad[nx][ny] == key) {
						//????
						return ++cntq;
					}
					q.push(make_pair(make_pair(nx, ny),cntq+1));
				}
			}
		}
	}
}
pair<int,int> match(int num) {
	int r = 0, c = 0;
	switch (num) {
	case 1:
		r = 0, c = 0;
		break;
	case 2:
		r = 0, c = 1;
		break;
	case 3:
		r = 0, c = 2;
		break;
	case 4:
		r = 1, c = 0;
		break;
	case 5:
		r = 1, c = 1;
		break;
	case 6:
		r = 1, c = 2;
		break;
	case 7:
		r = 2, c = 0;
		break;
	case 8:
		r = 2, c = 1;
		break;
	case 9:
		r = 2, c = 2;
		break;
	case 0:
		r = 3, c = 1;
		break;
	default: break;
	}
	return make_pair(r, c);
}
string solution(vector<int> numbers, string hand) {
	string answer = "";
	char curL, curR;
	int Lr=3, Ll=0;
	int Rr=3, Rl=2;
	for (int i = 0;i < numbers.size();i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer += 'L';
			curL = numbers[i];
			Lr = match(numbers[i]).first;
			Ll = match(numbers[i]).second;
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer += 'R';
			curR = numbers[i];
			Rr = match(numbers[i]).first;
			Rl = match(numbers[i]).second;
		}
		else {
			int cntL = BFS(Lr,Ll,numbers[i]);
			memset(visited, false, sizeof(visited));
			int cntR = BFS(Rr, Rl, numbers[i]);
			memset(visited, false, sizeof(visited));
			//cout << cntL << " " << cntR << endl;
			if (cntL > cntR) {
				answer += 'R';
				Rr = match(numbers[i]).first;
				Rl = match(numbers[i]).second;
			}
			else if (cntL < cntR) {
				Lr = match(numbers[i]).first;
				Ll = match(numbers[i]).second;
				answer += 'L';
			}
			else {
				if (hand == "left") {
					Lr = match(numbers[i]).first;
					Ll = match(numbers[i]).second;
					answer += 'L';
				}
				else {
					answer += 'R';
					Rr = match(numbers[i]).first;
					Rl = match(numbers[i]).second;
				}
			}
		}
	}
	return answer;
}

int main() {
	
	cout << solution(numbers,hand) << endl;

	return 0;
}
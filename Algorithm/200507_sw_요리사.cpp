#include <iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<map>

using namespace std;

int Arr[17][17];
bool visited[17];
vector<int> foodarrA, foodarrB;
int N;
int answer;

void makeSub() {
	int foodA = 0;
	int foodB = 0;

	for (int i = 0;i < N / 2 - 1;i++) {
		for (int j = i + 1;j < N / 2;j++) {
			foodA += Arr[foodarrA[i]][foodarrA[j]] + Arr[foodarrA[j]][foodarrA[i]];
			foodB += Arr[foodarrB[i]][foodarrB[j]] + Arr[foodarrB[j]][foodarrB[i]];
		}
	}
	foodarrA.clear();
	foodarrB.clear();
	int subs = abs(foodA - foodB);
	if (answer > subs) {
		answer = subs;
	}
}
void DFS(int idx, int howmany) {
	if (howmany == N / 2) {
		for (int i = 0;i < N;i++) {
			if (visited[i]) foodarrA.push_back(i);
			else foodarrB.push_back(i);
		}
		makeSub();
		return;
	}
	for (int i = idx;i < N ;i++) {
		if (!visited[i]) {
			visited[i] = true;
			DFS(i, howmany + 1);
			visited[i] = false;
		}
	}
}
int main(void) {
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		answer = 40001;
		memset(visited, false, sizeof(visited));

		for (int i = 0;i < 17;i++) {
			for (int j = 0;j < 17;j++) {
				Arr[i][j] = 0;
			}
		}
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				cin >> Arr[i][j];
			}
		}

		DFS(0, 0);
		cout<<"#"<<test_case<<" " << answer <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
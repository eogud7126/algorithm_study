#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<set>

using namespace std;

vector<vector<int>> key = { {1,1},{1,1} };
vector<vector<int>> lock = { {1, 0, 0},{1, 0, 0},{1, 1, 1} };

//90도 시계방향 회전
vector<vector<int>> rotateKey(vector<vector<int>> key) {
	vector<vector<int>> newKey(key.size(),vector<int>(key[0].size())); //NXN 공간만들기
	for (int i = 0;i < key.size();i++) {
		for (int j = key[0].size() - 1;j >= 0;j--) {
			newKey[i][key.size()-1 - j] = key[j][i];
		}
	}
	return newKey;
}
bool checkIsunlock(vector<vector<int>> lock, int N, int M) {
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < M;j++) {
			if (lock[i + N][j + N] == 0) 
				return false;
		}
	}
	cout << "★★★★★★★★★★★풀렸당★★★★★★★★★★★★" << endl;
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	int N = key.size();
	int M = lock.size();
	vector<vector<int>> newLock(2 * N + M, vector<int>(2 * N + M));
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < M;j++) {
			newLock[N + i][N + j] = lock[i][j];
		}
	}
	vector<vector<int>> tmp(2 * N + M, vector<int>(2 * N + M));
	for (int i = 0;i < 4;i++) {//3해주니깐 틀림
		for (int m = 0;m < N + M;m++) {
			for (int n = 0;n < N + M;n++) {
				tmp = newLock;
				bool flag1 = true;
				for (int p = 0;p < N;p++) {
					bool flag2 = true;
					for (int q = 0;q < N;q++) {
						if (tmp[p+m][q+n] == 0)
							tmp[p+m][q+n] = key[p][q];
						else { //1인경우 겹치는지 확인
							if (key[p][q] == 1) {
								flag2 = false;
								flag1 = false;
								break;
							}
						}
					}
					if (!flag2) {
						break;
					}
				}
				for (int i = 0;i < tmp.size();i++) {
					for (int j = 0;j < tmp.size();j++)
						cout << tmp[i][j];
					cout << endl;
				}
				cout << endl;
				if (flag1)
					if (checkIsunlock(tmp, N, M)) {
						answer = true;
						break;
					}
			}
			if (answer) break;
		}
		if (answer) break;
		key = rotateKey(key);
		cout << "================회전===============" << endl;
	}


	return answer;
}

int main(void) {
	cout << solution(key,lock) << endl;
	return 0;
}

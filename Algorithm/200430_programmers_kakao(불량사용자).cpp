#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<set>

using namespace std;

vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
vector<string> banned_id = { "*rodo", "*rodo", "******" };
vector<string> island[8];
int answer = 0;

bool visited[8] = { false, };
set<set<string>> setAnswer;	//�ߺ��˻縦 ���Ѱ�.

void DFS(int idx, set<string> s) {
	for (int i = 0;i < island[idx].size();i++) {
		set<string> tmp = s;
		tmp.insert(island[idx][i]);
		//�ߺ��� tmp������ �״��
		if (tmp.size() == idx) continue;
		if (tmp.size() == banned_id.size()) {
			setAnswer.insert(tmp);
		}
		if (idx<banned_id.size())
			DFS(idx + 1, tmp);
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	for (int i = 0;i < banned_id.size();i++) {
		for (int j = 0;j < user_id.size();j++) {
			bool flag = true;
			if (banned_id[i].size() != user_id[j].size())
				continue;
			for (int k = 0;k < user_id[j].size();k++) {
				if (banned_id[i][k] == '*') continue;
				if (user_id[j][k] != banned_id[i][k]) {
					flag = false;
					break;
				}
			}
			//��� ���ڰ� ��ġ�Ѵٸ�
			if (flag) {
				island[i].push_back(user_id[j]);
			}
		}
	}
	set<string> s;
	DFS(0,s);
	answer = setAnswer.size();
	return answer;
}

int main(void) {
	cout << solution(user_id, banned_id) << endl;
	return 0;
}

#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

int N = 5;
vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

vector<int> fails(N+2);
vector<int> total(N+2);
vector<pair<double,int>> failper ;

bool cmp(const pair<double, int> &u, const pair<double, int> &v) {
	if (u.first < v.first) return false;
	else if (u.first == v.first) {
		if (u.second < v.second) return true;
		else return false;
	}
	else return true;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	sort(stages.begin(), stages.end());
	for (int i = 0;i < stages.size();i++) {
		fails[stages[i]]++;
		int howManyPeopleReachStage = 0;
		int howManyPeopleReachStageidx = 0;
		howManyPeopleReachStageidx = lower_bound(stages.begin(), stages.end(), stages[i]) - stages.begin();
		howManyPeopleReachStage = stages.size() - howManyPeopleReachStageidx;
		total[stages[i]] = howManyPeopleReachStage;
	}
	for (int i = 1;i <= N;i++) {
		if (total[i] == 0) total[i] = 1;
		failper.push_back(make_pair(((double)fails[i] / total[i]),i));
	}
	sort(failper.begin(), failper.end(),cmp);
	
	for (int i = 0;i<failper.size();i++) {
		answer.push_back(failper[i].second);
		cout << answer[i] << endl;
	}
	return answer;
}

int main(void) {
	solution(N,stages);
	return 0;
}




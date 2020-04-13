#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> time;
	for (int i = 0;i < progresses.size();i++) {
		int ftime = 0;
		ftime = (100 - progresses[i]) / speeds[i];
		if ((100 - progresses[i]) % speeds[i] != 0)
			ftime++;
		time.push(ftime);
	}
	while(!time.empty()) {
		int cntbaeppo = 1;
		int front = time.front();
		time.pop();
		while (!time.empty() && time.front() <= front) {
			cntbaeppo++;
			time.pop();
		}
		answer.push_back(cntbaeppo);
	}
	return answer;
}


int main(void) {
	//º¯¼ö
	vector<int> progresses = { 93,30,55 };
	vector<int> speeds{1,30,5};
	cout << solution(progresses, speeds)[0];
	return 0;
}

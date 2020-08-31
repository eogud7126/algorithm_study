//18번 테스트케이스 빼고 정답.
#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<sstream>
#include<algorithm>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")

using namespace std;


string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int answerToint;
	vector<int> busTime;
	vector<int> crewTime;
	queue<int> q;
	int bt = 9 * 60 + 0;
	int idx = 0;
	int p = 0, busIdx = 0;
	int tmpT;
	bool flag = false;
	//버스 시간
	while (n--) {
		busTime.push_back(bt + idx * t);
		idx++;
	}

	for (int i = 0;i < timetable.size();i++) {
		int hh = stoi(timetable[i].substr(0, 2));
		int mm = stoi(timetable[i].substr(3, 5));
		//cout << hh << " " << mm<<endl;
		crewTime.push_back(hh * 60 + mm);
	}
	sort(crewTime.begin(), crewTime.end());
	for (int i = 0;i < crewTime.size();i++)
		q.push(crewTime[i]);
	int qfront = q.front();
	while (1) {
		if (q.empty()) {
			cout << "q비움" << endl;
			if (busIdx < busTime.size()) {
				answerToint = busTime[busTime.size()-1];
			}
			else {
				if (p < m) {
					if (p == 0) {
						answerToint = qfront - 1;
					}
					else
						answerToint = busTime[busIdx - 1];
				}
				else {
					answerToint = busTime[busIdx];
				}
			}
			break;
		}
		if (busIdx == busTime.size()) {
			cout << "태울 버스 없음" << endl;
			if (p == 0) {
				if (!flag)//한명이라도 탄 사람이 있으면..
					answerToint = busTime[busIdx - 1];
				else
					answerToint = qfront - 1;
			}
			else
				answerToint = busTime[busIdx - 1];	
			break;
		}
		if (busTime[busIdx] >= q.front()) {
			qfront = q.front();
			q.pop();
			flag = true;
			p++;
		}
		else {
			//시간 안맞으면 다음버스
			p = 0;
			busIdx++;
		}
		if (m == p) {
			//인원 다 차면 다음 버스
			p = 0;
			busIdx++;
		}
	}
	string ahh = to_string(answerToint / 60);
	if (ahh.size() == 1) ahh = "0" + ahh;
	string amm = to_string(answerToint % 60);
	if (amm.size() == 1) amm = "0" + amm;
	answer = ahh + ":"+amm;
	return answer;
}

int main() {

	int n = 2,  t = 10,  m = 2;
	vector<string> timetable = { "09:00", "09:00", "09:10", "09:10" };

	cout << solution(n, t,  m, timetable) << endl;

	return 0;
}
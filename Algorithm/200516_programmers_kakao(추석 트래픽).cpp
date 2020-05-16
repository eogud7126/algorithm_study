#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<functional>
#include<sstream>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")

using namespace std;
/*
1. 시간을 ms단위로 계산한다.
2. 구간을 Time 구조체에 저장
3. start +999 , end +999 각각 범위 안에 있는 것들 계산
*/
struct Time {
	long long start;
	long long end;
};

int solution(vector<string> lines) {
	int answer = 0;
	vector<Time> times;
	//시간을 ms단위로 바꾸기
	for (int i = 0;i < lines.size();i++) {
		Time T;
		long long ihh, imm, iss, ims;
		long long term;
		ihh = stoll(lines[i].substr(11, 13));
		imm = stoll(lines[i].substr(14, 16));
		iss = stoll(lines[i].substr(17, 19));
		ims = stoll(lines[i].substr(20, 22));

		istringstream sstream(lines[i]);
		string buffer;
		vector<string> tmp;
		while (getline(sstream, buffer, ' ')) {
			tmp.push_back(buffer);
		}
		term = stof(tmp[2]) *1000;

		T.start = (ihh * 3600 + imm * 60 + iss)*1000  + ims - term + 1;
		T.end = (ihh * 3600 + imm  * 60 + iss)*1000 + ims;
		times.push_back(T);
		//cout << ihh << " " << imm << " " << iss << " " << ims <<" "<<term<<endl;
		cout << T.start << " " << T.end << endl;
	}
	for (int i = 0;i < times.size();i++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int j = 0;j < times.size();j++) {
			//범위 밖에 있는것 빼기 위한 cnt1,2
			if (!(times[i].start + 999 <times[j].start || times[i].start>times[j].end)) {
				cnt1++;
			}
			if (!(times[i].end + 999 < times[j].start || times[i].end > times[j].end)) {
				cnt2++;
			}
		}
		int maxcnt = max(cnt1, cnt2);
		//cout << maxcnt << endl;
		int tmp = maxcnt;
		if (answer < tmp) {
			answer = tmp;
		}
	}
	return answer;
}


int main(){
	vector<string> lines = { "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"};

	cout << solution(lines) << endl;

	return 0;
}
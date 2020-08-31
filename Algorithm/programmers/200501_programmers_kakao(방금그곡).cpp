//틀렸습니다.

#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<set>

using namespace std;

string m = "C#A#A#";
vector<string> musicinfos = {"13:00,13:06,sss,C#A#A#", "13:00,13:04,HIHI,AC#A#A#", "13:00,13:04,WORLD,A#C#A#A#" };

struct Music {
	string start;
	string end;
	string title;
	string fullfons;
};

bool cmp(const pair<Music, int> &u, const pair<Music, int> &v) {
	if (u.first.fullfons.size() < v.first.fullfons.size()) return false;
	else if (u.first.fullfons.size() == v.first.fullfons.size()) {
		if (u.second < v.second) return true;
		else return false;
	}
	else return true;
}
int getTimeGap(string start, string end) {
	int startHour = stoi(start.substr(0, 2));
	int startMin = stoi(start.substr(3, 2));
	int startTotal = startHour * 60 + startMin;

	int endHour = stoi(end.substr(0, 2));
	int endMin = stoi(end.substr(3, 2));
	int endTotal = endHour * 60 + endMin;

	return endTotal - startTotal;
}
Music parseMusic(string musicInfo) {
	Music mus;
	vector<string> m;
	string tmpstr = "";
	musicInfo += ",";
	for (int i = 0;i < musicInfo.size();i++) {
		if (musicInfo[i] != ',') {
			tmpstr += musicInfo[i];
			continue;
		}
		//쉼표 나오면
		m.push_back(tmpstr);
		tmpstr = "";
	}
	mus.start = m[0];
	mus.end = m[1];
	mus.title = m[2];
	int playtime = getTimeGap(mus.start, mus.end);
	cout<<"play:" << playtime << endl;
	string fons = "";
	for (int i = 0, j = 0;i < playtime;i++,j++) {
		char c = m[3][j%(m[3].size())]; //j가만약에 4 %3 =1
		if (c == 'C' || c == 'D' || c == 'F' || c == 'G' || c == 'A') {
			if ((j%m[3].size()) + 1 < m[3].size()) 
				if (m[3][(j%m[3].size()) + 1] == '#') {//#확인
					fons += c;
					fons += "#";
					j++;
					continue;
				}
			fons += c;			
		}else
			fons += c; //초과시 처음부터
	}
	mus.fullfons = fons;
	cout << mus.fullfons << endl;
	return mus;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	vector<pair<Music,int>> setAnswer;	//MUsic구조체와 인덱스
	Music musics[101];
	for (int i = 0;i < musicinfos.size();i++)
		musics[i] = parseMusic(musicinfos[i]);

	for (int i = 0;i < musicinfos.size();i++) {
		string full = musics[i].fullfons;
		for (int j = 0;j < full.size();j++) {
			if (j + m.size() <= full.size()) {
				cout<<"비교합니다: " << full.substr(j, m.size()) << endl;
				if (m == full.substr(j, m.size())) {
					if (full[j + m.size()] == '#')
						continue;
					setAnswer.push_back(make_pair(musics[i], i));
				}
			}
		}
	}

	if (setAnswer.size() > 1) {
		sort(setAnswer.begin(), setAnswer.end(), cmp);
	}
	if (setAnswer.size() == 0) answer = "None";
	else answer = setAnswer[0].first.title;
	return answer;
}

int main(void) {
	cout << solution(m,musicinfos) << endl;
	return 0;
}

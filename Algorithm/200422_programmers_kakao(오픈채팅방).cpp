#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<sstream>
#include<map>


using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> user;

	for (int i = 0;i < record.size();i++) {
		if (record[i][0] != 'L') {
			vector<string> splited;
			istringstream ss(record[i]);
			string stringbuffer;
			while (getline(ss, stringbuffer, ' ')) {
				splited.push_back(stringbuffer);
			}
			user[splited[1]] = splited[2];
		}
	}

	for (int i = 0;i < record.size();i++) {
		//ù���� ����
		char firstLetter = record[i][0];
		string sample;
		vector<string> splited;
		istringstream ss(record[i]);
		string stringbuffer;
		while (getline(ss, stringbuffer, ' ')) {
			splited.push_back(stringbuffer);
		}
		switch (firstLetter) {
		case 'E':
			sample = user[splited[1]] + "���� ���Խ��ϴ�.";
			break;
		case 'L':
			sample = user[splited[1]] + "���� �������ϴ�.";
			break;
		default:
			break;
		}
		if (sample != "")
			answer.push_back(sample);
		cout << sample << endl;
	}
	return answer;
}


int main(void) {
	//����
	int n = 5;
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	solution(record);

	return 0;
}




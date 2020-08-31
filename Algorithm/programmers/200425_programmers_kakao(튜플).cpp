#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;
//진짜 간단한방법은 각 배열의 인덱스 처리..
//난 노가다

string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";

vector<int> solution(string s) {
	vector<int> answer;
	vector<pair<int, vector<int>>> part_size;	//부분집합, 갯수
	vector<int> part_list[501];
	int idx = 0;
	string sample = "";
	for (int i = 1;i < s.size() - 1;i++) {
		//문자열을 나누기 위한 조건 나눈 숫자들을 part_list 에 넣기 위함
		if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
			if (s[i] == '}') {
				//다음 part_list 인덱스로 넘어간다
				part_size.push_back(make_pair(part_list[idx].size(), part_list[idx]));
				idx++;
				
			}
			continue;
		}
		else {
			//두자리 이상일수도 있으니 sample에 누적했다가
			sample += s[i];
			//part_list에 저장
			if (s[i + 1] == '}' || s[i + 1] == ',') {
				part_list[idx].push_back(stoi(sample));
				sample = "";
			}
		}
	}

	sort(part_size.begin(), part_size.end());
	//정렬 잘 됬는지 확인하는 구문
	/*for (int i = 0;i < part_size.size();i++) {
		cout << part_size[i].first << endl;
	}*/
	//key: 우선순위 value: 원소
	map<int, int> for_seq;
	//map을 굳이 쓴 이유는 key값에 따라 자동정렬 되기 때문에 vector<pair>을 하나 만들어줌
	vector<pair<int, int>> tmpvc;//first:우선순위 second:값
	for (int i = 0;i < part_size.size();i++) {
		for (int j = 0;j < part_size[i].second.size();j++) {
			//cout<< part_size[i].second.size()<<" part_size[i].second[j](key):"<< part_size[i].second[j] <<" i: "<<i<<" " << for_seq[part_size[i].second[j]] << endl;
			if (for_seq[part_size[i].second[j]] == 0) {//처음 접하는 키일경우
				//key를 part_size[i].second[j]. 즉, i번째 부분집합의 j번째 원소.
				for_seq[part_size[i].second[j]] = part_size[i].second.size(); //크기 1234-> = 우선순위
				tmpvc.push_back(make_pair(part_size[i].second.size(), part_size[i].second[j]));
			}
		}
	}
	//원소우선순위대로 정렬
	sort(tmpvc.begin(), tmpvc.end());
	//크기가 가장 큰 부분집합만큼 for문 돌리고 map 키 순으로 answer에 대입. map은 자동정렬.
	for (int i = 0;i < tmpvc.size() ;i++) {
		answer.push_back(tmpvc[i].second);
		//cout << tmpvc[i].first<<" "<<tmpvc[i].second << endl;
	}
	return answer;
}
int main(void) {
	solution(s);
	return 0;
}




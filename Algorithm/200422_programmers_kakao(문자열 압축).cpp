#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;


int solution(string s) {
	int answer = s.size();
	vector<int> stringlen;
	//1개 단위부터 n/2까지 탐색
	for (int i = 1;i <= s.size() / 2;i++) {
		int count = 1;
		string tmp_answer="";
		string tmp = s.substr(0, i);
		for(int j=i;j<s.size();j+=i){
			string sub = s.substr(j, i);
			if (tmp == sub) {
				count++;
			}
			else {
				//TODO: 달랐을 때 숫자를 앞에 쓰고 뒤에 sub, 근데 1이면 1생략해야됨.//그리고 비교 대상 바꾸기
				if (count == 1) {
					tmp_answer.append(tmp);
				}
				else {
					tmp_answer.append(to_string(count)).append(tmp);
					count = 1;
				}
				tmp = sub;
			}
		//오버플로
			if (j + i >= s.size()) {
				if (count == 1) {
					tmp_answer.append(s.substr(j));
				}
				else {
					tmp_answer.append(to_string(count)).append(tmp);
				}
				break;
			}
		}
		stringlen.push_back(strlen(tmp_answer.c_str()));
		cout << tmp_answer << endl;
	}
	answer = *min_element(stringlen.begin(), stringlen.end());
	return answer;
}

int main(void) {
	//변수
	string s = "ababcdcdababcdcd";
	cout << solution(s);
	return 0;
}




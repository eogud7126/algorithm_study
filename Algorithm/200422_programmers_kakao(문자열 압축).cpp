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
	//1�� �������� n/2���� Ž��
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
				//TODO: �޶��� �� ���ڸ� �տ� ���� �ڿ� sub, �ٵ� 1�̸� 1�����ؾߵ�.//�׸��� �� ��� �ٲٱ�
				if (count == 1) {
					tmp_answer.append(tmp);
				}
				else {
					tmp_answer.append(to_string(count)).append(tmp);
					count = 1;
				}
				tmp = sub;
			}
		//�����÷�
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
	//����
	string s = "ababcdcdababcdcd";
	cout << solution(s);
	return 0;
}




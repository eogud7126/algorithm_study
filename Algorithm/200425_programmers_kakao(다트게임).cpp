#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

string dartResult = "1S2D*3T";
//S D���� T ������
//*���� ���� + (����+����)*2
//# �������� - ����
int solution(string dartResult) {
	int answer = 0;
	int eachscore[4];
	int tmp, idx = 0;//idx�� eachscore�� �ε��� (123)
	eachscore[0] = 0;
	for (int i = 0;i < dartResult.size() ;i++) {
		if (0 <= dartResult[i] - '0' && dartResult[i] - '0' <= 9) {
			tmp = 0;
			idx++;
			if (dartResult[i] - '0' == 1) {
				if (dartResult[i + 1] - '0' == 0) {
					tmp = 10;
					i++; //0 �پ�ѱ�
				}
				else tmp = 1;
			}
			else tmp = dartResult[i] - '0';
			eachscore[idx] = tmp;
		}
		else if (dartResult[i] == 'D') {
			//TODO ����
			eachscore[idx] = pow(eachscore[idx], 2);
		}
		else if (dartResult[i] == 'T') {
			//TODO ������
			eachscore[idx] = pow(eachscore[idx], 3);
		}
		else if (dartResult[i] == '*') {
			//TODO 1. ��������*2 ��������*2(ù��°�� ��� ����������)
			eachscore[idx] *= 2;
			eachscore[idx - 1] *= 2;
		}
		else if (dartResult[i] == '#') {
			//TODO
			eachscore[idx] *= (-1);
		}
	}
	for (int i = 1;i < 4;i++)
		answer += eachscore[i];
//	cout << answer;
	return answer;
}
int main(void) {
	solution(dartResult);
	return 0;
}




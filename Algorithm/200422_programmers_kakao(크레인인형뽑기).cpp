#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> bd[31];
	stack<int> answerStack;
	int sizecol = board[0].size();
	//�� ���ÿ� �ױ�.
	for (int i = board.size()-1;i >= 0;i--) {
		for (int j = 0;j < sizecol;j++) {
			if (board[i][j] == 0)
				continue;
			bd[j].push(board[i][j]);
		}
	}

	for (int i = 0;i < moves.size();i++) {
		int idx = moves[i] - 1; // 0���� �����ϴ°� ��� 0~4
		if (bd[idx].empty()) continue;
		int popboard = bd[idx].top(); //�ش� �ε����� ���� �̰�
		bd[idx].pop();	//pop��Ű��
		
		if (!answerStack.empty()) { 
			//���� ������� ������ ��
			if (answerStack.top() == popboard) {
				answerStack.pop();
				answer += 2;
			}
			else
				answerStack.push(popboard);	//������ ���ÿ� �ֱ�
		}
		else {
			//���� ���������
			answerStack.push(popboard);	//������ ���ÿ� �ֱ�
		}
	}

	return answer;
}


int main(void) {
	//����
	vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	cout << solution(board,moves);
	return 0;
}




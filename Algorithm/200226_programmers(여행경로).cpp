#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
//���� �ٽ� Ǯ�����.
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	return answer;
}



int main() {
	vector<vector<string>> a = { {  "ICN","SFO" },{ "ICN","ATL" },{ "SFO","ATL" },{ "ATL","ICN" },{ "ATL","SFO" }  };
	vector<string> answer = solution(a);
	
	for (int i = 0;i < answer.size();i++)
		cout << answer[i]<<" ";
	return 0;
}
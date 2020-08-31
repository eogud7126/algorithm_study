#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
//문제 다시 풀어야함.
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
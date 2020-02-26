#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>

/*
�Ű������� ������ڰ� �־����� onefive => 15
*/
using namespace std;

map<string, string> alphatonum = { {"zero","0"},{ "one","1" },{ "two","2" },{ "three","3" },{ "four","4" },
{ "five","5" },{ "six","6" },{ "seven","7" },{ "eight","8" },{ "nine","9" } };

string answer = "";
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string input;
	string check="";
	cin >> input;
	queue<char> q;
	
	for (int i = 0; i < input.size();i++)
		q.push(input[i]);
	for (int i = 0;i < input.size();i++) {
		char q_front;
		q_front = q.front();
		q.pop();

		check += q_front;
		//ã�� ���ڰ� ������
		if (alphatonum.find(check) != alphatonum.end()) {
			cout << alphatonum[check] ;
			check = "";
		}
		
	}

	return 0;
}
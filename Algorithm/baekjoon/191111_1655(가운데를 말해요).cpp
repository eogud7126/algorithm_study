#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	priority_queue<int, vector<int>, less<int> > pqbigger;
	priority_queue<int, vector<int>, greater<int> > pqsmaller;

	int N;
	int first,second;
	cin >> N;
	cin >> first;
	cout << first << "\n";
	cin >> second;
	pqbigger.push(first);
	if (first <= second) pqsmaller.push(second);
	else {
		pqsmaller.push(first);
		pqbigger.pop();
		pqbigger.push(second);
	}
	cout << pqbigger.top()<<"\n";
	//시작~
	for (int i = 0;i < N-2;i++) {
		int input;
		cin >> input;

		if (pqbigger.top() < input) {
			pqsmaller.push(input);
		}
		else pqbigger.push(input);
		
		int size_bigger = pqbigger.size();	//오름차순 큐 사이즈
		int size_smaller = pqsmaller.size(); //내림차순 큐 사이즈

		if (size_bigger < size_smaller) { //양 사이즈 비교 후 대입
			pqbigger.push(pqsmaller.top());
			pqsmaller.pop();
		}
		else if (size_bigger  > size_smaller+1) {
			pqsmaller.push(pqbigger.top());
			pqbigger.pop();
		}
		cout <<pqbigger.top() << "\n";

		
	}
	return 0;
}

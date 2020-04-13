#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;


int solution(int n) {
	int answer = 1;
	for (int i = 1;i <= (n + 1) / 2;i++) {
		int sum = i;
		for (int j = i + 1;j <= (n + 1) / 2;j++) {
			sum += j;
			if (sum>n) break;
			if (sum == n) {
				answer++;
				break;
			}
		}
	}
	return answer;
}


int main(void) {
	//º¯¼ö
	int n = 15;
	cout << solution(n);
	return 0;
}




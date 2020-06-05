#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<stack>

#include<map>

using namespace std;

int a = 2, b = 5;
string yoil[7] = { "FRI","SAT","SUN","MON","TUE","WED","THU" };

string solution(int a, int b) {
	//2016년 1/1 금요일
	string answer = "";
	int day = -1;
	switch (a) {
	case 1:
		day += 0;
		break;
	case 2:
		day += 31;
		break;
	case 3:
		day += (31 + 29);
		break;
	case 4:
		day += (31 + 29+31);
		break;
	case 5:
		day += (31 + 29 + 31+30);
		break;
	case 6:
		day += (31 + 29 + 31 + 30+31);
		break;
	case 7:
		day += (31 + 29 + 31 + 30 + 31+30);
		break;
	case 8:
		day += (31 + 29 + 31 + 30 + 31 + 30 + 31);
		break;
	case 9:
		day += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31);
		break;
	case 10:
		day += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30);
		break;
	case 11:
		day += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30+31);
		break;
	case 12:
		day += (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31+30);
		break;
	}
	day += b;
	answer = yoil[day % 7];
	return answer;
}


int main(void) {
	//변수
	int n = 15;
	cout << solution(5,24);
	return 0;
}




//#include <string>
//#include <vector>
//#include<queue>
//#include<iostream>
//
//using namespace std;
//
//int solution(int bridge_length, int weight, vector<int> truck_weights) {
//	int answer = 0;
//	int sumW = 0;
//	queue<int> bridgeQ;
//	int truckIdx = 0;
//	while (1) {
//		answer++;
//		if (bridgeQ.size() == bridge_length) {
//			sumW -= bridgeQ.front();
//			bridgeQ.pop();
//		}
//		if (sumW + truck_weights[truckIdx] <= weight) {
//			if (truckIdx == truck_weights.size() - 1) {
//				answer += bridge_length;
//				break;
//			}
//			bridgeQ.push(truck_weights[truckIdx]);
//			sumW += truck_weights[truckIdx];
//			truckIdx++;
//		}
//		else {
//			bridgeQ.push(0);
//		}
//
//
//	}
//	return answer;
//}



#include <string>
#include <vector>
#include<queue>
#include<map>
#include<iostream>

using namespace std;


struct S {
	char c;
	int v;
};
S getMax(S s1, S s2, S s3) {
	S max ;
	max.v = 0;
	if (max.v < s1.v) {
		max.c = s1.c;
		max.v = s1.v;
	}
	if (max.v < s2.v) {
		max.c = s2.c;
		max.v = s2.v;
	}
	if (max.v < s3.v) {
		max.c = s3.c;
		max.v = s3.v;
	}
	return max;
}
string solution(int a,int b, int c) {
	string answer = "";
	S Sa, Sb, Sc;
	Sa.c = 'a';
	Sa.v = a;
	Sb.c = 'b';
	Sb.v = b;
	Sc.c = 'c';
	Sc.v = c;

	int sum = a + b + c;
	int mc = getMax(Sa, Sb, Sc).c;
	int mv = getMax(Sa, Sb, Sc).v;
	sum -= mv;
	int maxlength = 3 * sum + 2;

	if (maxlength <= mv) {
		int i = 1;
		while (maxlength--) {
			if (i % 2 == 1) {
				if (mc < 2) {
					answer = answer + to_string(mv-'0');
				}
				else {
					answer = answer + to_string(mv - '0') + to_string(mv - '0');
					maxlength--;
				}
				i++;
			}
			else {
				if (Sb.v > 0) {
					answer += to_string('b'-'0');
				}
				else if (Sc.v > 0) {
					answer += to_string('c'-'0');
				}
				else break;
				i++;
			}
		}
	}
	return answer;
}

int main() {
	cout<< solution(8, 0, 1);
}
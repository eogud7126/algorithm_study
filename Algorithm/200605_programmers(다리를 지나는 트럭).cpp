#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int sumW = 0;
	queue<int> bridgeQ;
	int truckIdx = 0;
	while (1) {
		answer++;
		if (bridgeQ.size() == bridge_length) {
			sumW -= bridgeQ.front();
			bridgeQ.pop();
		}
		if (sumW + truck_weights[truckIdx] <= weight) {
			if (truckIdx == truck_weights.size() - 1) {
				answer += bridge_length;
				break;
			}
			bridgeQ.push(truck_weights[truckIdx]);
			sumW += truck_weights[truckIdx];
			truckIdx++;
		}
		else {
			bridgeQ.push(0);
		}


	}
	return answer;
}
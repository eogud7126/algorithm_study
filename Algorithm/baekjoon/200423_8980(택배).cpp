//틀렸습니다. 다시 한번 풀어야함;
#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

struct Truck {
	int start;
	int end;
	int weight;
};

bool cmp(const Truck &u, const Truck &v) {
	if (u.end < v.end) return true;
	else {
		if (u.end == v.end) {
			if (u.start < v.start) return true;
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, C, K, answer = 0;
	cin >> N >> C >> K;
	vector<Truck> truck;
	for (int i = 0;i < K;i++) {
		Truck t;
		cin >> t.start >> t.end >> t.weight;
		truck.push_back(t);
	}
	sort(truck.begin(), truck.end(), cmp);
	int destination = truck[0].start;
	int idx = 0, baggage = 0;
	bool for_once = false; // 도착했을 떄 한번만 실행하기 위함
	while (idx<truck.size() && destination != truck[truck.size() - 1].end) {
		//먼저 비우고(도착했을때 한번만 실행)
		if (!for_once) {
			for (int d = 0;d < idx;d++) {
				if (truck[d].end == destination) {
					baggage -= truck[d].weight;
				}
			}
			for_once = true;
		}
		if (truck[idx].start == destination) {
			//채우기
			if (baggage + truck[idx].weight <= C) {
				baggage += truck[idx].weight;
			}
			//상자 일부분만 가져갈때
			else {
				int leftWeight = C - baggage;
				if (leftWeight == 0)
					truck[idx].weight = 0;
				else {
					truck[idx].weight = leftWeight;
					baggage += leftWeight;
				}
			}
		}
		if(idx+1<truck.size())
			if (truck[idx + 1].start != destination) {
				destination++;
				for_once = false;
			}
		idx++;
	}
	for (int i = 0;i < truck.size();i++) {
		answer += truck[i].weight;
	}
	cout << answer <<"\n";
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

long long k = 10;
vector<long long> room_number = { 1,3,4,1,3,1 };

//vector<long long> solution(long long k, vector<long long> room_number) {
//	vector<long long> answer;
//	vector<long long> tmpanswer;
//	for (int i = 0;i < room_number.size();i++) {
//		bool flag = true;
//		if (i == 0) {
//			tmpanswer.push_back(room_number[i]);
//			answer.push_back(room_number[i]);
//			continue;
//		}
//		sort(tmpanswer.begin(), tmpanswer.end());
//
//		while (flag) {
//			if (room_number[i] > tmpanswer[tmpanswer.size() - 1]) {
//				tmpanswer.push_back(room_number[i]);
//				answer.push_back(room_number[i]);
//				break;
//			}
//			int idx = lower_bound(tmpanswer.begin(), tmpanswer.end(), room_number[i]) - tmpanswer.begin();
//			if (tmpanswer[idx] == room_number[i]) {
//				room_number[i]++;	
//			}
//			else {
//				answer.push_back(room_number[i]);
//				tmpanswer.push_back(room_number[i]);
//				flag = false;
//			}
//		}
//	}
//	return answer;
//}



//vector<long long> solution(long long k, vector<long long> room_number) {
//	vector<long long> answer;
//	map<long long,long long> tmpanswer;
//	for (int i = 0;i < room_number.size();i++) {
//		bool flag = true;
//		if (i == 0) {
//			tmpanswer.insert(make_pair(room_number[i],i));
//			answer.push_back(room_number[i]);
//			continue;
//		}
//		while (flag) {
//			int mapsize = tmpanswer.size();
//			tmpanswer.insert(make_pair(room_number[i], i));
//			if (mapsize == tmpanswer.size()) {
//				//중복됬다는 뜻
//				room_number[i]++;
//			}
//			else {
//				answer.push_back(room_number[i]);
//				flag = false;
//			}
//		}
//	}
//
//	return answer;
//}

//유니온 파인드를 이용한 풀이
map<long long, long long> p;

int Find(int x) {
	if (p[x] == 0) return x;
	return p[x] = Find(p[x]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (long long i = 0;i < room_number.size();i++) {
		long long emptyRoom = Find(room_number[i]);
		answer.push_back(emptyRoom);
		p[emptyRoom] = emptyRoom+1;
	}
	return answer;
}
int main() {
	vector<long long> solution2 = solution(k, room_number);
	for (int i = 0;i < solution2.size();i++)
		cout << solution2[i];
	
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>

using namespace std;

vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
int k = 3;

bool isZeroOk(int mid, int k, vector<int> v) {
	int cnt = 0;
	for (int i = 0;i < v.size();i++) {
		if (v[i] - mid <= 0) {
			cnt++;
		}
		else {
			cnt = 0;
		}
		if (cnt >= k) return false;
	}
	
	return true;
}
int solution(vector<int> stones, int k) {
	int answer = 0;
	int first = *min_element(stones.begin(), stones.end());
	int last = *max_element(stones.begin(), stones.end());
	int mid = (first + last) / 2;
	while (first <= last) {
		if (!isZeroOk(mid, k, stones)) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
		mid = (first + last) / 2;
	}
	return first;	//isZeroOk 가 true 여야 가능한것 true면 first 변경하기. 따라서 first 반환
}

int main() {
	cout << solution(stones, k);
	return 0;
}
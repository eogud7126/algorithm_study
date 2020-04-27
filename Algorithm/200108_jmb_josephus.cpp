#include<iostream>
#include<vector>
#include<list>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		list<int> survivors;
		for (int i = 1;i <= N;i++) survivors.push_back(i);
		list<int>::iterator pointer = survivors.begin(); //첫번째 위치
		int n = survivors.size();
		while (n > 2) {
			pointer = survivors.erase(pointer); //pointer는 제거된 원소 다음 위치로 이동
			//만약 원소의 end를 가리킨다면 begin으로 바꿔줌.(원형 순환이 되도록)
			if (pointer == survivors.end()) pointer = survivors.begin();
			n--;
			//다음 차례를 구하기위한 for문
			for (int i = 0;i < K - 1;i++) {
				pointer++;
				if (pointer == survivors.end()) pointer = survivors.begin();
			}
			
		}
		cout << survivors.front() << " " << survivors.back() << endl;
	}

	return 0;
}
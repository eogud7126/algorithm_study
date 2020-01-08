#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<algorithm>
#define MAX 100001
using namespace std;

int howmanyL(vector<long long> v, int n) {
	int count = 0;
	for (int m = 0;m < v.size();m++)
		count += (int)(v[m] / n);
	
	return count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	long long K, N;
	vector<long long> L;
	vector<long long> maxL;
	cin >> K;
	cin >> N;
	for (int i = 0;i < K;i++) {
		long long input;
		cin >> input;
		L.push_back(input);
	}
	if (L.size() == 1) {
		cout << (int)(L[0] / N) << "\n";
	}
	else {
		sort(L.begin(), L.end());
		long long max1 = L[L.size() - 1];
		int i = 1;
		long long max_tmp = max1;
		while (howmanyL(L, (int)max1 / i) < N) {
			i++;
			max_tmp = (int)max1 / i;	//while문 종료전의 max값;
		}

		maxL.push_back(max_tmp);
		//cout<<"max: " << max_tmp << endl;

		for (int j = L.size() - 2;j >= 0;j--) {	//큰것부터
			int R;	//tmpMax로 나눴을때의 몫
			int Rmax; //L에서 R을 나눴을때 의 몫 (최대) 이 값은 for문이 돌수록 커짐;
			if (max_tmp != 0) {
				R = (int)L[j] / max_tmp;
				if (R != 0) {
					Rmax = (int)L[j] / R;
					if (howmanyL(L, Rmax) >= N) {
						maxL.push_back(Rmax);
					}
				}
				else break;
			}
			else break;
		}

		cout << *max_element(maxL.begin(), maxL.end());
	}
	return 0;
}

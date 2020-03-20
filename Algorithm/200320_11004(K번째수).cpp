#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define MAX 100001
using namespace std;
long long N, K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	vector<long long> number(N);
	for (int i = 0;i < N;i++) {
		cin >> number[i];
	}
	nth_element(number.begin(), number.begin() + K - 1, number.end()); //Äü¼ÒÆ® ÀÀ¿ë
	
	cout << number[K - 1] << "\n";
	return 0;
}
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int sum[101];
	for(int i=0;i<n;i++) {
		int school;
		int apple;

		cin >> school >> apple;
		sum[i] = apple % school;
	}
	int answer = 0;
	for (int i = 0;i < n;i++)  answer += sum[i];

	cout << answer << "\n";
	return 0;
}
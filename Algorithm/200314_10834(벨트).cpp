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
	vector<pair<int, int>> rotation; //2¹ø¹ÙÄûºÎÅÍ
	long long initrotation = 1; //1¹ø ¹ÙÄûºÎÅÍ (1¹ÙÄû)
	long long n;
	cin >> n;
	rotation.push_back(make_pair(-1, 1));
	long long ssum = 0;
	for (long long i = 1;i <= n;i++) {
		int a, b, s;
		cin >> a >> b >> s;
		initrotation = (initrotation * b) / a;
		ssum += s;
		if (ssum % 2 == 0) {
			rotation.push_back(make_pair(0,initrotation));
		}
		else 
			rotation.push_back(make_pair(1, initrotation));

	}
	cout << rotation[n].first << " " << rotation[n].second << "\n";
	return 0;
}
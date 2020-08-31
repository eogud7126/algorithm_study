//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//#include<map>
//
//using namespace std;
//int N, M;
//vector<string> answer;
//map<string, int> n;
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> N >> M;
//
//	for (int i = 0;i < N;i++) {
//		string dj;
//		cin >> dj;
//		n.insert(make_pair(dj,i));
//	}
//	for (int i = 0;i < M;i++) {
//		string bj;
//		cin >> bj;
//		if (n.find(bj) != n.end())
//			answer.push_back(bj);
//	}
//	sort(answer.begin(), answer.end());
//	cout << answer.size() << "\n";
//	for (int i = 0;i < answer.size();i++)
//		cout << answer[i] << endl;
//		
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

using namespace std;
int N, M;
vector<string> answer;
set<string> n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		string dj;
		cin >> dj;
		n.insert(dj);
	}
	for (int i = 0;i < M;i++) {
		string bj;
		cin >> bj;
		if (n.find(bj) != n.end())
			answer.push_back(bj);
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0;i < answer.size();i++)
		cout << answer[i] << endl;

	return 0;
}
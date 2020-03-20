//
////풀어야할 문제..이분탐색
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//#define MAX 100001
//using namespace std;
//int N, H;
//
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> N >> H;
//	vector<int> top;
//	vector<int> bottom;
//	for (int i = 0;i < N;i++) {
//		int k;
//		cin >> k;
//		if (i % 2 == 0) bottom.push_back(k);
//		else top.push_back(k);
//	}
//	sort(bottom.begin(), bottom.end());
//	sort(top.begin(), top.end());
//
//	for (int i = 0;i < bottom.size();i++)
//		cout << bottom[i] << " " << top[i] << endl;
//	return 0;
//}


//#include <iostream>
//
//#include <vector>
//
//#include <algorithm>
//
//using namespace std;
//
//
//
//const int INF = 987654321;
//
//
//
//int main(void)
//
//{
//
//	ios_base::sync_with_stdio(0);
//
//	cin.tie(0);
//
//	int N, H;
//
//	cin >> N >> H;
//
//
//
//	vector<int> bottom(N / 2), top(N / 2);
//
//	for (int i = 0; i < N / 2; i++)
//
//		cin >> bottom[i] >> top[i];
//
//
//
//	sort(bottom.begin(), bottom.end());
//
//	sort(top.begin(), top.end());
//
//
//
//	int result = INF;
//
//	int cnt = 1;
//
//	for (int i = 1; i <= H; i++)
//
//	{
//
//		//해당 높이에 겹치는 석순
//
//		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
//	
//		//해당 높이에 겹치는 종유석
//
//		temp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());
//
//
//
//		if (result == temp)
//
//			cnt++;
//
//		else if (result > temp)
//
//		{
//
//			result = temp;
//
//			cnt = 1;
//
//		}
//
//	}
//
//	cout << result << " " << cnt << "\n";
//
//	return 0;
//
//}
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


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	priority_queue<int,vector<int>,less<int> > pq;
	int N;
	cin >> N;
	
	while(N--) {
		int num;
		cin >> num;
		if (num == 0) {
			pq.push(num);
			cout<< pq.top() << "\n";
			pq.pop();
		}
		else pq.push(num);	
	}
	return 0;
}

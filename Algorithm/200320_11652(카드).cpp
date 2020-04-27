#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define MAX 100001
using namespace std;
int N;
int tmp=0;
struct Card {
	long long n, cnt=0;
};

bool cmp(const Card &c1, const Card &c2) {
	if (c1.cnt > c2.cnt) return true;
	else if (c1.cnt == c2.cnt) {
		if (c1.n < c2.n) return true;
	}
	else return false;
	return false;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<long long> card;
	vector<Card> cards(N);
	for (int i = 0;i < N;i++) {
		long long k;
		cin >> k;
		card.push_back(k);
	}
	sort(card.begin(), card.end());

	for (int i = 0;i < N;i++) {
		
		if (i == 0) {
			tmp = i;
			cards[i].n = card[i];
			cards[i].cnt++;
			continue;
		}
		if (card[i] == card[i - 1]) {
			cards[tmp].cnt++;
		}
		else {
			tmp = i;
			cards[i].n = card[i];
			cards[i].cnt++;
		}
		
	}

	sort(cards.begin(), cards.end(), cmp);
	cout << cards[0].n << "\n";
	return 0;
}